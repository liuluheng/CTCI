#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int getKthMagicNumber(int k)
{
  if (k < 0)
    return 0;

  int val = 0;
  queue<int> q3, q5, q7;
  q3.push(1);

  for (int i = 0; i < k; i++) {
    int v3 = q3.empty() ? INT_MAX : q3.front();
    int v5 = q5.empty() ? INT_MAX : q5.front();
    int v7 = q7.empty() ? INT_MAX : q7.front();

    val = min(v3, min(v5, v7));

    if (val == v3) {
      q3.pop();
      q3.push(3 * val);
      q5.push(5 * val);
    } else if (val == v5) {
      q5.pop();
      q5.push(5 * val);
    } else {
      q7.pop();
    }
    q7.push(7 * val);
  }

  return val;
}

int main()
{
  for (int i = 1; i != 40; i++) {
    cout << getKthMagicNumber(i) << " ";
  }
  cout << endl;

  return 0;
}
