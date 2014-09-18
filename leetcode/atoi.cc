#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

int atoi(const char *str)
{
  int sign = 1;
  int i = 0;
  int n = strlen(str);
  int num = 0;
  while (str[i] == ' ' && i < n) {
    i++;
  }
  if (str[i] == '+' && i < n) {
    i++;
  }
  if (str[i] == '-' && i < n) {
    sign = -1;
    i++;
  }

  for (; i < n; i++) {
    if (str[i] < '0' || str[i] > '9') {
      break;
    }
    if (num > INT_MAX/10 || 
        (num == INT_MAX/10 && str[i] > INT_MAX%10)) {
      return sign == -1 ? INT_MIN : INT_MAX;
    }

    num = num * 10 + (str[i] - '0');
  }

  return sign * num;
}

int main()
{
  cout << atoi("  -0932sf3") << endl;
  cout << atoi("  --c") << endl;
  cout << atoi("2147483648") << endl;
  cout << atoi("-2147483748") << endl;

  return 0;
}
