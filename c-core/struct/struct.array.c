#include <stdio.h>
#include <time.h>

struct date
{
  int year;
  int month;
  int day;
};

int main()
{
  // declares an array of ten items of structure type date
  struct date myDates[10];

  myDates[1].month = 7;
  myDates[1].day = 9;
  myDates[1].year = 1979;
}

void fn1()
{
  struct date myDates[3] =
      {
          {7, 9, 1979},
          {11, 26, 2019},
          {12, 26, 2019},
      };
}

void fn2()
{
  // to initialize values besides the one declared in the initial initialization, the curly brackets can be used inside the declaration
  struct date myDates[3] =
      {
          [2] = {1, 1, 2020}
      };
}

void fn3()
{
  // ...and dot notation can be used to assign specific elements as well
  struct date myDates[3] = {[1].month = 12, [1].day = 30};
}