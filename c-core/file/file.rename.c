#include <stdio.h>

int main()
{
  // int rename(const char *oldName, const char *newName);
  // check for failure
  if (rename("~/coding/c/oldName.txt", "~/coding/c/newName.txt"))
  {
    printf("File renamed.");
  }
  else
  {
    printf("Failed to rename file.");
  }
}