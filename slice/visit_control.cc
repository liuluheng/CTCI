// A small wrapper to control the visit of g(), limit to 5 times in 
// one second
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
using namespace std;

void g(int times)
{
  cout << times << ": I'm fucking g.." << endl;
}

static const int TIMES = 5;
static int times = TIMES;
static int64_t start = 0;
bool visit_card = true;
static int64_t last_visit = 0;

void f()
{
  struct timeval tv;
  if (times == TIMES) {
    gettimeofday(&tv, NULL);
    start = tv.tv_sec;
    //cout << last_visit << " " << start << endl;
    if (start - last_visit < 1) {
      return;
    } else {
      visit_card = true;
    }
  }

  if (visit_card) {
    g(times--);
  }

  if (times == 0) {
    times = TIMES;
    gettimeofday(&tv, NULL);
    int64_t end = tv.tv_sec;
    //cout << end << " " << start << endl;
    if (end - start <= 1) {
      cout << ">>> you visit g() too much!!! visit after 1 second " 
          << endl;
      visit_card = false;
      last_visit = end;
    }
  }
}

int main()
{
  for (int i = 0; i < 10; i++) {
    f();
  }
  sleep(1);
  for (int i = 0; i < 10; i++) {
    f();
  }

  return 0;
}
