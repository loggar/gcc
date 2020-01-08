#include <stdio.h>
#include <stdlib.h>

/*
Reading formatted input from a file
*/
int main()
{
  // create a character array (i.e. string) to hold the values from fscanf()
  char *thisString[50];

  // create a pointer to the file that will be opened
  FILE *filePointer = NULL;

  // assign the pointer to the result of opening the file with fopen()
  filePointer = fopen("names.txt", "w+");

  // check there are no errors when opening the file
  if (filePointer != NULL)
  {
    // check the file and print out the result
    while (fscanf(filePointer, "%s", thisString) == 1)
    {
      printf("%s \n", thisString);
    }
  }

  fclose(filePointer);
  filePointer = NULL;

  return 0;
}