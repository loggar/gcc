// declare a structure called name, that holds pointers
struct name
{
  // using pointers instead of  character arrays (j.e. strings)
  char *firstName;
  char *lastName;
};

// hardcode the length of the character array so it can be passed in as a variable
const int SLEN = 50;

// declare a function getInfo that takes a pointer, and an instance
// of the structure declared in the previous example is passed in as an argument
void getInfo(struct name *pointerToNameStruct)
{
  char temp[SLEN];
  printf("Please enter your first name: ");
  s_gets(temp, SLEN);

  //allocate memory to hold name
  pointerToNameStruct->firstName = (char *)malloc(strlen(temp) + 1);

  //copy the name to allocated memory
  strcpy(pointerToNameStruct->firstName, temp);

  printf("Please enter your last name: ");
  s_gets(temp, SLEN);

  pointerToNameStruct->lastName = (char *)malloc(strlen(temp) + 1);
  strcpy(pointerToNameStruct->lastName, temp);
}