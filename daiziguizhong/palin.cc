#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void isPalin(const char *str) {
  int n = strlen(str);
  bool P[n][n];
  int i, j, L; // 表示字串的长度

  // 长度为1的都是回文
  for (i = 0; i < n; i++) {
    P[i][i] = true;
  }

  // 长度可能从2开始
  for (L = 2; L <= n; L++) {
    for (i = 0; i < n - L + 1; i++) {
      j = i + L - 1; // 设置结束的位置
      if (L == 2) // 长度为2的情况
        P[i][j] = (str[i] == str[j]);
      else //其他情况
        P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
    }
  }

  return;
}

int main() {
  isPalin(string("abccba").c_str());

}
