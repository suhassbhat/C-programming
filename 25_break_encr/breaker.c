#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int largest(int a[26])
{
  int largest=0,i;
  for(i=0;i<26;i++)
    {
      if (a[i]>largest)
	{largest=a[i];
	}
    }
  return largest;
}
int pointer(int a[26],int l)
{
  int f=0,b,i;
  for(i=0;i<26;i++)
    {
      if (l==a[i])
	{
	  f++;
	  b=i;
	}
    }
  if (f>1)
    {
      return -1;
    }
  else
    {
      return b;
    }
}
int main(int argc, char **argv)
{
  int c,a[26]={0},l,fl,key;
  if (argc!=2)
    {
      fprintf(stderr,"Usage: breaker inputFilename");
      return EXIT_FAILURE;
    }
  FILE * f= fopen(argv[1],"r");
  if (f==NULL)
    {
      fprintf(stderr,"Could not open file");

      return EXIT_FAILURE;
    }
  while ((c=fgetc(f))!=EOF)
    {
      if(isalpha(c))
	{
	  c=tolower(c);
	  c=c-'a';
	  a[c]++;
	}
    }
  l=largest(a);
  fl=pointer(a,l);
  if(fl==-1)
    {
      fprintf(stderr,"More than one letter has maximum frequency\n");
      return EXIT_FAILURE;
    }
  else
    {
      key=fl-4;
    }
  printf("%d\n",key);
    if (fclose(f) != 0) {
      perror("Failed to close the input file!");
      return EXIT_FAILURE;
    }  
    return EXIT_SUCCESS;
}
