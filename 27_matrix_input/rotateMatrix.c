#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int main(int argc,char **argv)
{
  char c[10][10];
  int i,j,b;
  if (argc!=2)
    {
      fprintf(stderr,"Usage: rotateMatrix Inputfilename\n");
      return EXIT_FAILURE;
    }
  FILE *f =fopen(argv[1],"r");
  if (f==NULL)
    {
      fprintf(stderr,"%s does not exist\n",argv[1]);
      return EXIT_FAILURE;
    }
  for (i=0;i<10;i++)
    {
  for(j=0;j<11;j++)
	    {
	      if((b=fgetc(f))==EOF)
		{
		  fprintf(stderr,"EOF encountered File too short\n");
		  return EXIT_FAILURE;
		}
	      if(j==10)
		{
		  if(b!='\n')
		    {
		      fprintf(stderr,"Line too long\n");
		      return EXIT_FAILURE;
		    }
		}
	      else
		{
		  if(b=='\n')
		    {
		      fprintf(stderr,"Line too short\n");
		      return EXIT_FAILURE;
		    }
		  c[i][j]=b;
		}
	    }
	}
      if((b=fgetc(f))!=EOF)
	{
	  fprintf(stderr,"File too big\n");
	  return EXIT_FAILURE;
	}
      
      rotate(c);
      for(i=0;i<10;i++)
	{
	  for(j=0;j<10;j++)
	    {
	      fprintf(stdout,"%c",c[i][j]);
	    }
	  fprintf(stdout,"\n");
	}
      if(fclose(f)!=0)
	{
	  fprintf(stderr,"%s did not close",argv[1]);
	  return EXIT_FAILURE;
	}
  return EXIT_SUCCESS;
}
    
      
