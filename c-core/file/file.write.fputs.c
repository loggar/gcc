#include <stdio.h>

/*
Writing strings to files with "file put string" - fputs()
*/
int main()
{
  // create the pointer to the file to be read
  FILE *filePointer = NULL;

  filePointer = fopen("test-fputs.txt", "w+");

  // check there is no error opening the file
  if (filePointer == NULL)
  {
    perror("Error: ");
    return (-1);
  }

  fputs("Testing the fputs function", filePointer);
  fputs("This is the second string to write to a file.", filePointer);

  fclose(filePointer);
  filePointer = NULL;

  return 0;
}