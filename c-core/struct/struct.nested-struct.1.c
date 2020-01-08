struct date
{
  int year;
  int month;
  int day;
};

struct time
{
  int hour;
  int minutes;
  int seconds;
};

struct dateAndTime
{
  struct date sDate;
  struct time sTime;
};

int main()
{
  struct dateAndTime timestamp;

  // to access the members, dot notation is used as usual:
  timestamp.sDate;

  // to reference a particular member inside one of these structures, the same syntax is used:
  timestamp.sDate.month = 10;

  // increments the seconds inside the sTime member of dateAndTime
  ++timestamp.sTime.seconds;

  // initialization of both date and time inside timestamp
  // sets the date to February 1st, 2018 at 3:30:00
  struct dateAndTime timestamp = {{2, 1, 2018}, {3, 30, 0}};

  // just like other structures, the dot notation can be used to initialize specific member's variables
  // and, though it is more typing, is more readable. It is order independent:
  struct dateAndTime timestamp = {
      {.month = 2, .day = 1, .year = 2018},
      {.hour = 3, .minutes = 30, .seconds = 0}};
}

void fn_array()
{
  struct dateAndTime timestamp[100];

  timestamp[0].sTime.hour = 3;
  timestamp[0].sTime.minutes = 30;
  timestamp[0].sTime.seconds = 0;
}