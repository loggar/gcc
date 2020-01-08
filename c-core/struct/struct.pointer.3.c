// declare a structure type intPtrs
struct intPtrs
{
  int *pointer1;
  int *pointer2;
};

// create an instance of intPtrs called myPointers
struct intPtrs myPointers;

// declare two int variables to store inside myPointers
int int1 = 100, int2;

myPointers.pointer1 = &int1;
myPointers.pointer2 = &int2;

// dereference the pointer and assign the value to int2
*myPointers.pointer2 = 97;

printf("int1: %i, *myPointers.pointer1: %i \n", int1, *myPointers.pointer1);

printf("int2: %i, *myPointers.pointer2: %i \n", int2, *myPointers.pointer2);