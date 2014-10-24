#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <set>
using namespace std;

int x = -4;
int y = 0;
int z = -2;

// thread1 first
// x = -2
// thread2 first
// x = -1
// joint
// x = 1 (exist) or 7 (not find)

void* thread1(void *)
{
  if (z > 0)
    x = y - z;
  else 
    x = y + z;

  // int *p = NULL;
  // coredump in one thread will coredump the whole process
  //cout << "coredump" << endl;
  //*p = 0;
  //cout << "coredump" << endl;

  return NULL;
}

void* thread2(void *)
{
  y = 3;
  z = y + 1;

  return NULL;
}

int main(void)
{
  pthread_t pid1;
  pthread_t pid2;
  set<int> s;

  for (int i = 0; i < 1000000; ++i) {
    pthread_create(&pid1, NULL, thread1, NULL);
    pthread_create(&pid2, NULL, thread2, NULL);

    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);

    s.insert(x);

    x = -4;
    y = 0;
    z = -2;
  }

  for (auto iter : s) {
    cout << iter << endl;
  }

  return 0;
}
