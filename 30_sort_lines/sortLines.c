#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

int main(int argc, char ** argv) {

  char ** data=NULL;
  char *line=NULL;
  size_t size=0;
  size_t i=0;
  int j,k=1;
  if (argc<1)
    {
      return EXIT_FAILURE;
    }
  if (argc==1)
    {
	  //WRITE YOUR CODE HERE!
      while(getline(&line,&size,stdin)>=0)
	{
	  data=realloc(data,(i+1)*sizeof(*data));
	  data[i]=line;
	  line =NULL;
	  i++;
	}
      free(line);
      size=0;
      sortData(data,i);
      for(j=0;j<i;j++)
	{
	  printf("%s",data[j]);
	  free(data[j]);
	}
      free(data);
      
	}
  if (argc>1)
    {
      while(argc>k)
	{
	  i=0;
	  line=NULL;
	  data=NULL;
	  FILE *f =fopen(argv[k],"r");
	  if (f==NULL)
	    {
	      perror("File couldn't open\n");
	      return EXIT_FAILURE;
	    }
		
	    while(getline(&line,&size,f)>=0)
	      {
		data=realloc(data,(i+1)*sizeof(*data));
		data[i]=line;
		line =NULL;
		i++;
	      }
	  free(line);
	  size=0;
	  sortData(data,i);
	  for(j=0;j<i;j++)
	    {
	      printf("%s",data[j]);
	      free(data[j]);
	    }
	  free(data);
	  k++;
	  if (fclose(f)!=0)
	    {
	      perror("File did not close\n");
	      return EXIT_FAILURE;
	    }
	
	}
    }
	  
	   
  return EXIT_SUCCESS;
}
