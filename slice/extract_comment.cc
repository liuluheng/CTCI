#include <iostream>
#include <vector>
#include <string>
using namespace std;

//only consider the /* ... */ comment
vector<string> extract(string pro)
{
  vector<string> result;
  while (1) {
    size_t splash = pro.find('/');
    while (pro[splash + 1] != '*'
        && splash != std::string::npos) {
      splash = pro.find('/', splash + 1);
    }
    if (splash == string::npos)
      break;
    string comment = pro.substr(splash + 2);
    size_t star = comment.find('*');
    while (comment[star + 1] != '/') {
      star = comment.find('*', star + 1);
    }
    result.push_back(string(comment, 0,  star - 1));
    pro = comment.substr(star + 2);
  }

  return result;
}


int main()
{
  string str("/////* /* fuck shit * * * world... */ heie /* helell wor*/");

  auto vec = extract(str);

  for (auto str : vec)
    cout << str << endl;

  return 0;
}

