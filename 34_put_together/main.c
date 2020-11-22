#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"
void rmnlf (char * line)
{
  if(line[strlen(line)-1]=='\n')
    {
      line[strlen(line)-1]= '\0';
    }
}
counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  size_t sz=0;
  ssize_t len=0;
  char * line=NULL;
  char * a;
  counts_t * c;
  c=createCounts();
  FILE *f = fopen(filename,"r");
  if (f==NULL)
    {
      fprintf(stderr,"File does not exist\n");
      exit(EXIT_FAILURE);
    }
  while((len=getline(&line,&sz,f))>=0)
    {
      if (strlen(line)>0);
      {
      rmnlf(line);
      a=lookupValue(kvPairs,line);
      addCount(c,a);
      }}
  free(line);
  if(fclose(f)!=0)
    {
      fprintf(stderr,"File did not close\n");
      exit(EXIT_FAILURE);
    }
  return c;
}

int main(int argc, char ** argv) {
  if(argc<3)
    {
      fprintf(stderr,"Incorrect input format\n");//WRITE ME (plus add appropriate error checking!)
      exit(EXIT_FAILURE);
    }
  int i;
  kvarray_t * k;
  counts_t * c;
  char * fname;
  k=readKVs(argv[1]);
  for(i=2;i<argc;i++)
    {
      fname=NULL;
      c=countFile(argv[i],k);
      fname=(char *) malloc(sizeof(char)*(strlen(argv[i])+8));
      strcpy(fname,argv[i]);
      strcat(fname,".counts");
      FILE *f = fopen(fname,"w");
      if (f==NULL)
	{
	  fprintf(stderr,"File did not open\n");
	  exit(EXIT_FAILURE);
	}
      printCounts(c,f);
      freeCounts(c);
      free(fname);
      if(fclose(f)!=0)
	{
	  fprintf(stderr,"File did not close\n");
	  exit(EXIT_FAILURE);
	}
    }
  freeKVs(k);
      
  
 //read the key/value pairs from the file named by argv[1] (call the result kv)

 //count from 2 to argc (call the number you count i)

    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)

    //compute the output file name from argv[i] (call this outName)


    //open the file named by outName (call that f)

    //print the counts from c into the FILE f

    //close f

    //free the memory for outName and c



 //free the memory for kv

  return EXIT_SUCCESS;
}
