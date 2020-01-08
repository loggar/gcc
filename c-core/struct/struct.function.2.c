#include <stdbool.h>

struct Family
{
  char name[20];
  int age;
  char father[20];
  char mother[20];
};

bool siblings(struct Family *pointerToMember1, struct Family *pointerToMember2)
{
  if (strcmp(pointerToMember1->mother, pointerToMember2->mother) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Alternative: don't allow the members of struct to be changed by the function
// use the const modifier (in front of the pointer) if you don't want to allow changes to
// be made to the members of the struct
bool siblings(struct Family const *pointerToMember1, struct Family const *pointerToMember2)
{
  if (strcmp(pointerToMember1->mother, pointerToMember2->mother) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Another alternative: don't allow the pointer address to change
// this is less useful because it is a copy of the address (passed by value),
// but if you wanted to, put the asterisk in front of the const keyword as below
bool sibling(struct Family *const pointerToMember1, struct Family *const pointerToMember2)
{
  // ... your code
}