#include<stdio.h>
#include<stdlib.h>
size_t maxSeq(int * array,size_t n)
{
  int i;
  size_t c=1,max=0;
  if (n<=0)
    {
      return max;}
  if (n==1)
    {
      return c;
    }
  for(i=1;i<n;i++)
    {
      if(array[i]>array[i-1])
	{
	  c++;
	}
      else
	{
	  c=1;
	}
      if (c>max)
	{
	  max=c;
	}
    }
  return max;
}
