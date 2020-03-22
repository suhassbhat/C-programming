#include<stdio.h>
#include<stdlib.h>
struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
  typedef struct _retire_info retire_info;
void retirement (int startAge, double initial, retire_info working, retire_info retired)
{
  for(;working.months>0;working.months--,startAge++)
    {
      printf("Age %3d month %2d you have $%.2lf\n",startAge/12,startAge%12,initial);

      initial=initial+initial*working.rate_of_return/1200+working.contribution;
    }
  for(;retired.months>0;retired.months--,startAge++)
    {
      printf("Age %3d month %2d you have $%.2lf\n", startAge/12,startAge%12,initial);
      initial=initial+initial*retired.rate_of_return/1200+retired.contribution;
    }
}
int main()
{
  retire_info working,retired;
  int startAge;
  double initial;
  startAge=327;
  initial=21345;
  working.months=489;
  working.contribution=1000;
  working.rate_of_return=4.5;
  retired.months=384;
  retired.contribution=-4000;
  retired.rate_of_return=1;
  retirement(startAge,initial,working,retired);
  return EXIT_SUCCESS;
}
      
