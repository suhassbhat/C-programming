#include<stdio.h>
#include<stdlib.h>
unsigned power(unsigned x,unsigned y)
{
  if (y==0)
    {
      return 1;
    }
  if (y==1)
    {
      return x;
    }
  
  return power(x*x,y-1);
  
}
