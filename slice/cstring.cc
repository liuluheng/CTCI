#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

// it is confirmed that strcpy(p + 1, p) is not support in glibc;
char* strcpy(char* d, const char* s)
{
  char* tmp = d;
  while ((*d++ = *s++) != 0 );

  return tmp;
}

char* strncpy(char* d, const char* s, size_t n)
{
  const char *src = s;
  char *dest = d;

  while (n-- != 0 && (*dest++ = *src++) != 0);

  return d;
}

int strcmp(const char *a, const char *b)
{
  const char *p1 = a;
  const char *p2 = b;
  while (*p1 && *p2) {
    if (*p1 > *p2)
      return 1;
    else if (*p1 < *p2)
      return -1;
    else 
      p1++; p2++;
  }

  if (*p1)
    return 1;
  if (*p2)
    return -1;

  return 0;
}

int strcmp2(const char *a, const char *b)
{
  const char *p1 = a;
  const char *p2 = b;

  int result = 0;
  while (1) {
    result = *p1 - *p2++;
    if (result != 0 || *p1++ == 0)
      break;
  }

  return result;
}

int strncmp(const char *a, const char *b, int n)
{
  const char *p1 = a;
  const char *p2 = b;

  int result = 0;
  while (n != 0) {
    result = *p1 - *p2++;
    n--;
    if (result != 0 || *p1++ == 0 || n == 0)
      break;
  }

  return result;
}

size_t strlen(const char *str)
{
  const char *p = str;
  size_t n = 0;
  while (*p++) {
    n++;
  }

  return n;
}

char* strcat(char *dest, const char *src)
{
  char *p = dest + strlen(dest);
  strcpy(p, src);

  return dest;
}

char* strncat(char *dest, const char *src, size_t n)
{
  char *p = dest + strlen(dest);
  strncpy(p, src, n);
  *(p + n) = '\0';

  return dest;
}

char* strdup(const char* src)
{
  const int n = strlen(src);
  char *dest = (char *)malloc((n + 1) * sizeof(int));
  char *p = dest;
  while ((*p++ = *src++) != 0);

  return dest;
}

char* strstr(const char *haystack, const char *needle)
{
  const char *p1 = haystack;
  const int n = strlen(needle);
  while (*p1 && strncmp(p1, needle, n) != 0)
    p1++;

  return const_cast<char *>(p1);
}

void* memset(void *s, int c, size_t n)
{
  char *dest = static_cast<char *>(s);
  while (n--) {
    *dest++ = static_cast<char>(c);
  }

  return s;
}

int main()
{
  char a[20] = "hello, world";
  char b[20];

  // strcpy
  cout << "TEST strcpy" << endl;
  cout << strcpy(b, a) << endl;

  // strcpy
  cout << "TEST strncpy" << endl;
  memset(b, 0, sizeof(b));
  cout << strncpy(b, a, 5) << endl;

  // strlen
  cout << "TEST strlen" << endl;
  cout << strlen(a) << endl;

  // strcmp
  cout << "TEST strcmp" << endl;
  assert(strcmp("test", "test") == 0);
  cout << strcmp("test", "test") << endl;
  cout << strcmp("test0", "test") << endl;
  cout << strcmp("Test0", "test") << endl;
  cout << strcmp("tesa0", "test") << endl;

  // strncmp
  cout << "TEST strncmp" << endl;
  cout << strncmp("test", "test", 3) << endl;
  cout << strncmp("test0", "test", 5) << endl;
  cout << strncmp("Test0", "test", 2) << endl;
  cout << strncmp("tesa0", "test", 2) << endl;

  // strcmp2
  cout << "TEST strcmp2" << endl;
  cout << strcmp2("test", "test") << endl;
  cout << strcmp2("test0", "test") << endl;
  cout << strcmp2("Test0", "test") << endl;
  cout << strcmp2("tesa0", "test") << endl;

  // strcat
  cout << "TEST strcat" << endl;
  char dest[10] = "test";
  cout << strcat(dest, "test") << endl;

  // strcat
  cout << "TEST strncat" << endl;
  char dest_strncat[5] = { 0 };
  cout << strncat(dest_strncat, "test", 3) << endl;

  // strstr
  cout << "TEST strstr" << endl;
  cout << strstr("testttttaskaaaa", "task") << endl;
  cout << strstr("testttttaskaaaa", "") << endl;

  // strdup
  cout << "TEST strdup" << endl;
  char *dup = strdup("testttttaskaaaa"); 
  cout << dup << endl;
  free(dup);

  return 0;
}
