#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"



int main(int argc, char ** argv) {
  int trials=10000;
  int j,max,f1;
  size_t i;
  float p;
  int index1,index2;
  deck_t ** hands;
  size_t n_hands;
  future_cards_t *fc;
  deck_t * deck;
  unsigned * u=NULL;
  if(argc>3||argc<2)
    {
      fprintf(stderr,"Incorrect input format\n");
      exit(EXIT_FAILURE);
    }
  if(argc==3)
    {
      index2=0;
      for(i=0;i<strlen(argv[2]);i++)
	{
	  if((argv[2][i]>='0')&&(argv[2][i]<='9'))
	    {
	      index1=argv[2][i]-'0';
	      index2=index2*10+index1;
	    }
	  else
	    {
	      fprintf(stderr,"Incorrect input format\n");
	      exit(EXIT_FAILURE);
	    }
	}
      trials=index2;
    }
  FILE * f =fopen(argv[1],"r");
  if (f==NULL)
    {
      fprintf(stderr,"File did not open\n");
      exit(EXIT_FAILURE);
    }
  fc = (future_cards_t *)malloc(sizeof(future_cards_t));
  hands = read_input (f,&n_hands,fc);
  deck =build_remaining_deck(hands,n_hands);
  u = (unsigned *)malloc((n_hands+1)*sizeof(unsigned));
  for(i=0;i<n_hands+1;i++)
    {
      u[i]=0;
    }
  for(i=0;i<trials;i++)
    {
      shuffle(deck);
      future_cards_from_deck(deck,fc);
      j=1;
      max=0;
      f1=0;
      for(j=1;j<n_hands;j++)
	{
	  if(compare_hands(hands[max],hands[j])==-1)
	    {
	      max=j;
	      f1=0;
	    }
	  if(compare_hands(hands[max],hands[j])==0)
	    {
	      f1=1;
	    }
	}
      if(f1==1)
	{
	  u[n_hands]++;
	  
	}
      else
	{
	  u[max]++;
	}
   
      
    }
  for(i=0;i<n_hands;i++)
    {
      p=(float)u[i]/trials;
      printf("Hand %zu won %u / %u times (%.2f%%)\n",i,u[i],trials,p);
    }
  printf("And there were %u ties\n",u[n_hands]);
  free(u);
  if(fclose(f)!=0)
    {
      fprintf(stderr,"File did not close\n");
      exit(EXIT_FAILURE);
    }
  free_deck(deck);
  for(i=0;i<n_hands;i++)
    {
      free(hands[i]);
    }
  free(hands);
  for(i=0;i<fc->n_decks;i++)
    {
      free(fc->decks[i].cards);
    }
  free(fc->decks);
  free(fc);
  
  return EXIT_SUCCESS;
}
