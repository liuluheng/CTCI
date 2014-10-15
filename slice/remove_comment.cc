#include <iostream>
#include <cstring>
using namespace std;

size_t remove_comment(char *input, size_t input_size, char *output)
{
  strncpy(output, input, input_size);
  size_t output_size = input_size;
  char *comment_start = nullptr;
  char *comment_end = nullptr;

  while (1) {
    char *splash = strchr(output, '/');
    while (splash != nullptr 
           && (*(splash + 1) != '/') 
           && (*(splash + 1) != '*')) {
      splash = strchr(splash + 1, '/');
    }
    if (!splash) {
      return output_size;
    }

    comment_start = splash;
    if (*(splash + 1) == '/') {
      comment_end = strchr(splash + 2, '\n');
    }

    if (*(splash + 1) == '*') {
      char *star = strchr(splash + 2, '*');
      while (*(star + 1) != '/') {
        star = strchr(star + 1, '*');
      }
      comment_end = star + 1;
    }

    if (!comment_start || !comment_end) {
      cout << "invalid comments" << endl;
      return output_size;
    }

    output_size -= comment_end - comment_start + 1;
    strcpy(comment_start, comment_end + 1);
  }

  return output_size;
}

int main()
{
  char input[500] = " int main() \
  {\
    //fucking easy...\n\
    /* oh shit... */\
    printf(\"hello, world\");\
  }";

  char output[500] = { 0 };
  auto output_size = remove_comment(input, strlen(input), output);

  cout << "output size: " << output_size << endl
       << "outputs: \n" << output << endl;
  
  return 0;
}
