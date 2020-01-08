#include <stdio.h>

/*
Writing characters to files with "file put character" function fputc()
*/
int main()
{
  // pointer to the file to be read
  FILE *filePointer = NULL;

  // declare an int to hold the value of the current character to write
  int characterToWrite;

  // open the file to be read, in read-write mode "w+"
  filePointer = fopen("test-fputc.txt", "w+");

  // check the result of opening the file for errors
  if (filePointer == NULL)
  {
    // perror displays the system error message after whatever text is in the parentheses
    perror("Error: ");
    return (-1);
  }

  // will write lowercase a-z
  for (characterToWrite = 97; characterToWrite <= 122; characterToWrite++)
  {
    fputc(characterToWrite, filePointer);
  }

  // close the file
  fclose(filePointer);

  // set the pointer to null to reset it and free the memory
  filePointer = NULL;

  return 0;
}