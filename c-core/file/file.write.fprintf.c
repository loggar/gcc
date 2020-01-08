#include <stdio.h>
#include <stdlib.h>

/*
Writing formatted input to a file
*/
int main()
{
  // create a pointer to the file that will be opened
  FILE *filePointer = NULL;

  // assign the pointer to the result of opening the file with fopen()
  filePointer = fopen("test-fprintf.txt", "w+");

  // check there are no errors when opening the file
  if (filePointer != NULL)
  {
    perror("Error: ");
    return (-1);
  }

  // write the formatted data to the file
  fprintf("%s %s %s %s %d", "Happy", "New", "Year! ", "It's ", 2020);

  fclose(filePointer);
  filePointer = NULL;

  return 0;
}