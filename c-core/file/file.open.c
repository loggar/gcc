#include <stdio.h>

int main()
{
  // write mode
  FILE *pfile = NULL;
  char *filename = "myFile.txt";
  //open myFile to write to it
  pfile = fopen(filename, "W");
  // if the file does not exist, then it will be created. It is still a good idea
  // to check that it does not return NULL (an error) with an if statement
  if (!filename)
  {
    printf("Failed to open %s", filename);
  }

  // read mode
  pfile = fopen(filename, "R");
  // check that it does not return NULL (an error) with an if statement
  if (!filename)
  {
    printf("Failed to open %s", filename);
  }

  // append mode
  pfile = fopen(filename, "A");
  // if the file does not exist, then it will be created. It is still a good idea
  // to check that it does not return NULL (an error) with an if statement
  if (!filename)
  {
    printf("Failed to open %s", filename);
  }

  // closing
  fclose(pfile);
  // set the value of the pointer to NULL after the file is closed
  pfile = NULL;
}