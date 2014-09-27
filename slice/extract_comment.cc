#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> extract(string pro)
{
  vector<string> result;
  while (1) {
    size_t splash = pro.find('/');
    if (splash == std::string::npos)
      break;
    if (pro[splash + 1] == '*') {
      string comment = pro.substr(splash + 2);
      size_t star = comment.find('*');
      if (comment[star + 1] == '/') {
        result.push_back(string(comment, 0,  star--));
        pro = comment.substr(star + 2);
        break;
      } else {
      }
    } else {
    }
  }

  return result;
}


int main()
{
  string str(" /* fuck shit world... */ ");

  auto vec = extract(str);

  for (auto str : vec)
    cout << str << endl;

  return 0;
}

