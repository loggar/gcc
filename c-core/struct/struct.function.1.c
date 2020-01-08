#include <stdbool.h>

struct Family
{
  char name[20];
  int age;
  char father[20];
  char mother[20];
};

// use a function to compare two family members and check if they're siblings
bool siblings(struct Family member1, struct Family member2)
{
  // if they have the same mother (i.e. the names are equal), then return true
  if (strcmp(member1.mother, member2.mother) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}