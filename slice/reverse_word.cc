#include <iostream>
using namespace std;

void swap(char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

char* reverse_word(char *str)
{
  char *begin = str;
  char *end = str;

  while (*end) {
    end++;
  }
  end--;
  while (begin < end) 
    swap(begin++, end--);

  begin = end = str;

  while (*end) {
    while (*end != ' ' && *end)
      end++;

    if (!*end)
      break;

    char *space = end;
    end--;
    while (begin < end) 
      swap(begin++, end--);

    end = space + 1;
    begin = end;
  }

  end--;
  while (begin < end) 
    swap(begin++, end--);

  return str;
}

int main()
{
  char str[] = "hello the shit world";
  char *result = reverse_word(str);
  cout << result << endl;

  return 0;
}
