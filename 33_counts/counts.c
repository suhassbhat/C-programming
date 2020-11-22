#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t * c=NULL;
  c = (counts_t *) malloc(sizeof(counts_t));
  c->n=1;
  c->a=NULL;
  c->a = (one_count_t *) malloc(sizeof(one_count_t));
  c->a->nvalue=NULL;
  c->a->nvalue= (char *) malloc(11*sizeof(char));
  strcpy((c->a->nvalue),"<unknown> ");
  c->a->count=0;
  return c;
}
void addCount(counts_t * c, const char * name) {
  int i;
  if (name==NULL)
    {
      c->a[0].count++;
      return;
    }
  
      for (i=1;i<c->n;i++)
    {
      if(strcmp(c->a[i].nvalue,name)==0)
	{
	  c->a[i].count++;
	  return;
	}
    }
      c->n++;
      c->a = (one_count_t *) realloc(c->a,(c->n)*sizeof(one_count_t));
      c->a[(c->n)-1].nvalue = (char *) malloc((strlen(name)+1)*sizeof(char));
      strcpy(c->a[(c->n)-1].nvalue,name);
      c->a[(c->n)-1].count = 1;
      return;      
}
void printCounts(counts_t * c, FILE * outFile) {
  int i;
  for(i=1;i<c->n;i++)
    {
      fprintf(outFile,"%s: %d\n",c->a[i].nvalue,c->a[i].count);
    }
  if(c->a[0].count>0)
    {
      fprintf(outFile,"%s: %d\n",c->a[0].nvalue,c->a[0].count);
    }
}

void freeCounts(counts_t * c) {
  int i;
  for(i=0;i<c->n;i++)
    {
      free(c->a[i].nvalue);
    }
  free(c->a);
  free(c);
}
