#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void mac_addr_unify(char *mac)
{
  for (char *p = mac; *p; p++) {
    while (!::isalnum(*p))
      ::strcpy(p, p + 1);
    if (::isalpha(*p))
      *p = ::toupper(*p);
  }

  cout << mac << endl;
}

int main()
{
  char mac[] = "00:25:64:cb:21:8c";
  mac_addr_unify(mac);

  return 0;
}
