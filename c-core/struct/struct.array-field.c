struct month
{
  int numberOfDays;
  char name[3];
};

int main()
{
  struct month aMonth;
  aMonth.numberOfDays = 31;
  aMonth.name[0] = 'J';
  aMonth.name[1] = 'a';
  aMonth.name[2] = 'n';

  // a quicker way to do the above for the name would be to use a shortcut
  struct month aMonth = {31, {'J', 'a', 'n'}};
}
