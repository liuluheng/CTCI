char* strcpy( char* d, const char* s ) {
  char* tmp = d;
  while ((*d++ = *s++) != 0 );

  return tmp;
}

int main()
{
  char a[20] = "hello, world";
  char b[20];

  strcpy(b, a);

  return 0;
}
