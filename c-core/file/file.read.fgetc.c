#include <stdio.h>

/*
Reading characters from files with "file get character" function fgetc()
*/
int main()
{
  // pointer to the file to be read
  FILE *filePointer = NULL;

  // declare an int to hold the value of the current character being read
  int thisCharacter;

  // open the file to be read, in read mode "r"
  filePointer = fopen("test-fgetc.txt", "r");

  // check the result of opening the file for errors
  if (filePointer == NULL)
  {
    // perror displays the system error message after whatever text is in the parentheses
    perror("Error: ");
    return (-1);
  }

  // read a single char in for each loop iteration
  while ((thisCharacter = fgetc(filePointer)) != EOF)
  {
    //print the character to a string
    printf("%c", thisCharacter);
  }

  // close the file
  fclose(filePointer);

  // set the pointer to null to reset it and free the memory
  filePointer = NULL;

  return 0;
}