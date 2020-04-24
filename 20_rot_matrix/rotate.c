#include<stdio.h>
#include<stdlib.h>
void rotate (char matrix[10][10])
{
  char temp[10][10];
  int i,j,k;
  if (matrix==NULL)
    {
     return;}
  for(j=0;j<10;j++)
    {
      for(i=0;i<10;i++)
	{
	  temp[i][j]=matrix[i][j];
	}
    }
  for (j=9,k=0;j>=0;j--,k++)
    {
      for(i=0;i<10;i++)
	{
	  matrix[i][j]=temp[k][i];
	}
    }
}
