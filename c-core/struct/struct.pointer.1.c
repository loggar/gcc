#include <stddef.h>

struct date
{
  int year;
  int month;
  int day;
};

struct date todaysDate;

// declare the pointer
struct date *datePtr = NULL;

// assign the pointer to the address of a strcture variable
datePtr = &todaysDate;

// use dereferencing to access any member of the date structure declared by datePtr
(*datePtr).day = 21;
// the parentheses above are required because the dot notation has higher precedence than
// the indirection operator (asterisk). This ensures that the dereferencing takes place
// before the assignment, otherwise it would try to access date with a null pointer