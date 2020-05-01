#include <stdio.h>
#include<stdlib.h>
unsigned power (unsigned x,unsigned y);
int main()
{
  if (power(5,2)!=25)
    {
      printf("5,2");
      exit(EXIT_FAILURE);
    }
  if (power(5,0)!=1)
    {
      printf("5,0");
      exit(EXIT_FAILURE);
    }
  if (power(1,2)!=1)
    {
      printf("1,2");
      exit(EXIT_FAILURE);
    }
  if (power(1,1)!=1)
    {
      printf("1,1");
      exit(EXIT_FAILURE);
    }
  if (power(1,0)!=1)
    {
      printf("1,0");
      exit(EXIT_FAILURE);
    }
  if (power(0,2)!=0)
    {
      printf("0,2");
      exit(EXIT_FAILURE);
    }
  if (power(0,1)!=0)
    {
      printf("0,1");
      exit(EXIT_FAILURE);
    }
  if (power(0,0)!=1)
    {
      printf("0,0");
      exit(EXIT_FAILURE);
    }
  if (power(2,4)!=16)
    {
      printf("2,4");
      exit(EXIT_FAILURE);
    }
  if (power(9,7)!=4782969)
    {
      printf("9,7");
      exit(EXIT_FAILURE);
    }
  return EXIT_SUCCESS;
}
