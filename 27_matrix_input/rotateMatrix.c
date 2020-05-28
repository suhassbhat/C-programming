include<stdio.h>
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
int main(int argc,char **argv)
{
  char a[100],b,c[10][10];
  int i,j;
  if (argc!=2)
    {
      fprintf(stderr,"Usage: rotateMatrix Inputfilename\n");
      return EXIT_FAILURE;
    }
  FILE *f =fopen(argv[2],"r");
  if (f=NULL)
    {
      fprintf(stderr,"%s does not exist\n",argv[2]);
      return EXIT_FAILURE;
    }
  while((a=fgets(f))!=EOF)
    {
      FILE *g = fopen(a,"r");
      for(i=0;i<10;i++)
	{
	  for(j=0;j<11;j++)
	    {
	      if((b=fgetc(g))==EOF)
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
      if((b=fgetc(g))!=EOF)
	{
	  fprintf(stderr,"File too big\n");
	  return EXIT_FAILURE;
	}
      rotate(c);
    }
  return EXIT_FAILURE;
}
    
      