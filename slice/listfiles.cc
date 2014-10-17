#include <iostream>
#include <cstring>
#include <queue>
#include <dirent.h>
using namespace std;

bool isdir(const dirent *file)
{
  return file->d_type == DT_DIR;
}

vector<dirent *> listdir(const string path)
{
  vector<dirent *> files;
  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir(path.c_str())) != NULL) {
    /* push all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL) {
      if (!strcmp(ent->d_name, ".") 
          || !strcmp(ent->d_name, "..")
          || ent->d_name[0] == '.')
        continue;
      files.push_back(ent);
    }
    closedir (dir);
  } else {
    /* could not open directory */
    perror(path.c_str());
  }

  return files;
}

void listfiles(string path)
{
  queue<string> q;
  q.push(path);

  while (!q.empty()) {
    path = q.front();
    q.pop();

    vector<dirent *> vd = listdir(path);
    for (auto d : vd) {
      if (isdir(d))
        q.push(path + "/" + d->d_name);
      else 
        cout << path << "/" << d->d_name << endl;
    }
  }
}

int main()
{
  listfiles("..");

  return 0;
}
