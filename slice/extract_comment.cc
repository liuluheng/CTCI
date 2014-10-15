#include <iostream>
#include <vector>
#include <string>
using namespace std;

// consider the /* ... */ and // comments
vector<string> extract(string pro)
{
  vector<string> result;
  while (1) {
    size_t splash = pro.find('/');
    while (splash != std::string::npos
        && pro[splash + 1] != '*'
        && pro[splash + 1] != '/') {
      splash = pro.find('/', splash + 1);
    }
    if (splash == string::npos)
      break;

    string comment = pro.substr(splash + 2);
    if (pro[splash + 1] == '/') {
      size_t new_line = comment.find('*');
      result.push_back(string(comment, 0, new_line - 1));
      pro = comment.substr(new_line + 2);
    }

    if (pro[splash + 1] == '*') {
      size_t star = comment.find('*');
      while (comment[star + 1] != '/') {
        star = comment.find('*', star + 1);
      }
      result.push_back(string(comment, 0,  star - 1));
      pro = comment.substr(star + 2);
    }
  }

  return result;
}


int main()
{
  string str("////\n"
             "/* /* fuck shit * * * world... */ heie /* helell wor*/");

  auto vec = extract(str);

  for (auto str : vec)
    cout << str << endl;

  return 0;
}

