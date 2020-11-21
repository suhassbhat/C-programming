#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
int legit (char * line)
{
  int i;
  int n=strlen(line);
  if (strlen(line)<=0){
    return 0;
  }
  for (i=0;i<n;i++)
    {
      if(line[i]=='=')
	{
	  return 1;
	}
    }
  return 0;
}
void rmnl (char * line)
{
  if(line[strlen(line)-1]=='\n')
    {
  line[strlen(line)-1]= '\0';
    }
}
char * getkey(char * line)
{
  int i,n=strlen(line);
  char * key=NULL;
  for(i=0;i<n;i++)
    {
      if (line[i]=='=')
	{
	  break;
	}
    }
  key=(char *)malloc((i+1)*sizeof(char));
  n=0;
  for (n=0;n<i;n++)
    {
      key[n]=line[n];
    }
  key[i]='\0';
  return key;
}
char * getvalue (char * line)
{
  char * value=NULL;
  int i,n=strlen(line),j;
  for (i=0;i<n;i++)
    {
      if(line[i]=='=')
	{
	  i++;
	  break;
	}
    }
  value= (char *) malloc((n-i+1)*sizeof(char));
  for(j=0;i<n;i++,j++)
    {
      value[j]=line[i];
    }
  value[j]='\0';
  return value;
  
}
kvarray_t * readKVs(const char * fname) {
  size_t sz=0;
  ssize_t len=0;
  char* line=NULL;
  kvarray_t * arr;
  FILE *f= fopen(fname,"r");
  if (f==NULL)
    {
      fprintf(stderr, "File does not exist");
      exit(EXIT_FAILURE);
    }
  arr=(kvarray_t *)malloc(sizeof(kvarray_t));
  arr->n=0;
  while ((len=getline(&line,&sz,f))>=0)
    {
      if(legit(line))
	{
      arr->n++;
      arr->a=(kvpair_t *)realloc(arr->a,(arr->n)*sizeof(kvpair_t));
      rmnl(line);
      arr->a[(arr->n)-1].key=getkey(line);
      arr->a[(arr->n)-1].value=getvalue(line);
    }
    }
  free(line);
  if (fclose(f)!=0)
    {
      fprintf(stderr,"File did not close\n");
      exit(EXIT_FAILURE);
    }
  return arr;

  
}

void freeKVs(kvarray_t * pairs) {
  int i;
  for (i=0;i<(pairs->n);i++)
    {
      free(pairs->a[i].key);
      free(pairs->a[i].value);
    }
  free(pairs->a);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  int i;
  for (i=0;i<(pairs->n);i++)
    {
      printf("key = '%s' value = '%s'\n", pairs->a[i].key, pairs->a[i].value);
    }
      
}


char * lookupValue(kvarray_t * pairs, const char * key) {
  int i;
  for(i=0;i<(pairs->n);i++)
    {
      if(strcmp((pairs->a[i].key),key)==0)
	{
	  return pairs->a[i].value;
	}
    }
  return NULL;
}
