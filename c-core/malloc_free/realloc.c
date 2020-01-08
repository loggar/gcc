#include <stdio.h>

int main()
{
  char *str = NULL;

  //initial memory allocation
  str = (char *)malloc(15 * sizeof(char));
  strcpy(str, "mikkel");
  printf("String: %s, Address: %p \n", str, str);

  //reallocating the memory to make it larger
  str = (char *)realloc(str, 25 * sizeof(char));
  //check the string and memory address after reallocation
  printf("String: %s, Address: %p \n", str, str);

  free(str);

  return 0;
}