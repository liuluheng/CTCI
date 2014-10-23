// http://blog.csdn.net/ojshilu/article/details/11762033
// 
#include <iostream>
#include <vector>
using namespace std;

bool interleave(string s1, string s2, string s3)
{
  bool r1 = false;
  bool r2 = false;

  //if (s1 == "" && s2 == "" && s3 == "")
  if (s1.empty() && s2.empty() && s3.empty())
    return true;
  if (!s1.empty() && !s3.empty() && s1[0] == s3[0])
    r1 = interleave(s1.substr(1), s2, s3.substr(1));
  if (!s2.empty() && !s3.empty() && s2[0] == s3[0])
    r2 = interleave(s1, s2.substr(1), s3.substr(1));

  return r1 || r2;
}

bool interleaveDP(string s1, string s2, string s3)
{
  if (s3.length() != s1.length() + s2.length())
    return false;

  vector<vector<bool>> f(s1.length() + 1,
                         vector<bool>(s2.length() + 1, true));

  for (size_t i = 1; i <= s1.length(); i++)
    f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
  for (size_t i = 1; i <= s2.length(); i++)
    f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];

  for (size_t i = 1; i <= s1.length(); i++) 
    for (size_t j = 1; j <= s2.length(); j++) 
      f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j]) 
             || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);


  return f[s1.length()][s2.length()];
}

int main()
{
  string s1("aabcc");
  string s2("dbbca");
  string s3("aadbbcbcac");
  string s4("aadbbbacc");

  cout << interleave(s1, s2, s3) << endl;
  cout << interleave(s1, s2, s4) << endl;

  cout << interleaveDP(s1, s2, s3) << endl;
  cout << interleaveDP(s1, s2, s4) << endl;

  return 0;
}
