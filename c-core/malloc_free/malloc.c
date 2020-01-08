#include <stddef.h>

int main()
{
  int *pNumber = (int *)malloc(100);

  int *pNumber2 = (int *)malloc(25 * sizeof(int));

  int *pNumber3 = (int *)malloc(25 * sizeof(int));
  if (!pNumber3)
  {
    // code to deal with the failure, such as an error message and program exit/abort
  }

  free(pNumber);
  pNumber = NULL;

  free(pNumber2);
  pNumber2 = NULL;

  free(pNumber3);
  pNumber3 = NULL;
}