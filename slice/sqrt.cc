#include <iostream>
using namespace std;

int sqrt(int x) {
  int left = 1;
  int right = x / 2;
  int last_mid = 0;

  if (x < 2)
    return x;

  while (left <= right) {
    const int mid = (left + right) / 2;
    if (x / mid > mid) {
      left = mid + 1;
      last_mid = mid;
    } else if (x / mid < mid) {
      right = mid - 1;
    } else {
      return mid;
    }
  }

  return last_mid;
}

// inline double abs(double a)
// {
//   return a > 0 ? a : -a;
// }

// msleep
#include <sys/time.h>
void msleep(unsigned int ms) {
  int microsecs;
  struct timeval tv;
  microsecs = ms * 1000;
  tv.tv_sec = microsecs / 1000000;
  tv.tv_usec = microsecs % 1000000;
  select(0, NULL, NULL, NULL, &tv);
}

double sqrt2(double x) {
  if (x == 0)
    return 0;
  double last = 0.0;
  double result = 1.0;
  while (abs(result - last) > 0.00001) {
    last = result;
    // cout << result << endl;
    // msleep(100);
    result = (result + x / result) / 2;
  }

  return last;
}

double sqrt3(double cur, double prev, double N) {
  if (abs(cur - prev) > 0.00001) {
    prev = cur;
    cur = (cur + N / cur) / 2;
    return sqrt3(cur, prev, N);
  }

  return cur;
}

int main() {
  cout << "BSEARCH VERSION" << endl;
  cout << sqrt(9) << endl;
  cout << sqrt(4) << endl;
  cout << sqrt(3) << endl;

  cout << "NEWTON ITER VERSION" << endl;
  cout << sqrt2(9) << endl;
  cout << sqrt2(4) << endl;
  cout << sqrt2(3) << endl;

  cout << "NEWTON RECUR VERSION" << endl;
  cout << sqrt3(1.0, 9, 9) << endl;
  cout << sqrt3(1.0, 4, 4) << endl;
  cout << sqrt3(1.0, 3, 3) << endl;

  return 0;
}
