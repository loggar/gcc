#include <stdio.h>
#include <stdlib.h>

// declaring a struct outside of any function allows it to be used
// by any subsequent function, like a global variable

struct date
{
  int month;
  int day;
  int year;
};

int main(void)
{
  // create an instance of the structure called name, and the pointer variable
  struct date today, *datePtr;

  // immediately assign the pointer to point to the structure address
  datePtr = &today;

  datePtr->month = 8;
  datePtr->day = 25;
  datePtr->year = 2018;

  printf("Today's date is %i/%i/%i \n", datePtr->month, datePtr->day, datePtr->year);

  return 0;
};