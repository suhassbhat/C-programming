#include<stdio.h>
#include<stdlib.h>
size_t maxSeq(int*array, size_t n);
int main()
{
  int a[]={5,1,2,3};
  int b[]={};
  int c[]={-20,-15,-30,5};
  int d[]={-5,-4,-3,-2,-1,0};
  int e[]={95,10001,10001,32,45};
  if (maxSeq(a,3)!=2)
    { printf("a1");
      exit(EXIT_FAILURE);}
  if(maxSeq(a,0)!=0)
    {printf("a2");
      exit(EXIT_FAILURE);}
  if(maxSeq(b,0)!=0)
    {printf("b");
      exit(EXIT_FAILURE);}
  if(maxSeq(c,4)!=2)
    {printf("c");
      exit(EXIT_FAILURE);}
  if(maxSeq(d,6)!=6)
    {printf("d1");
      exit(EXIT_FAILURE);}
  if(maxSeq(e+1,2)!=1)
    {printf("d2");
      exit(EXIT_FAILURE);}
  return EXIT_SUCCESS;
}
