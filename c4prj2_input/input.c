#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "future.h"
#include "deck.h"

void rmnlff(char *line)
{
  if(line[strlen(line)-1]=='\n')
    {
      line[strlen(line)-1]='\0';
    }
}
deck_t * hand_from_string(const char * line,future_cards_t * fc)
{
  int i,j;
  size_t index1,index2;
  deck_t * d;
  card_t c;
  d = (deck_t *)malloc(sizeof(deck_t));
  d->n_cards=0;
  d->cards=NULL;
      for (i=0;i<strlen(line);i++)
	{
	  if(line[i]==';')
	    {
	      break;
	    }
	  else if(line[i]==' '||line[i]==',')
	    {
	      continue;
	    }
	  else if(line[i]=='?')
	    {
	      j=0;
	      index2=0;
	      while((line[j+i+1]>='0')&&(line[j+i+1]<='9'))
		{
	      index1=line[i+1+j] - '0';
	      index2=index2*10+index1;
	      j++;
		}
	      add_future_card(fc,index2,add_empty_card(d));
	      i++;
	      continue;
	    }
	  else
	    {
	      c=card_from_letters(line[i],line[i+1]);
	      assert_card_valid(c);
	      add_card_to(d,c);
	      i++;
	      continue;
	    }
	}
    
  if(d->n_cards<5)
    {
      fprintf(stderr,"Insufficient number of cards in the hand\n");
      exit(EXIT_FAILURE);
    }
  return d;
}

deck_t ** read_input (FILE *f, size_t * n_hands, future_cards_t * fc)
{
  deck_t ** deck = NULL;
  size_t sz =0;
  ssize_t len =0;
  char * line =NULL;
  *n_hands=0;
  while((len=getline(&line,&sz,f))>=0)
    {
      rmnlff(line);
      if(strlen(line)>0)
	{
	  if(line[0]!='\n')
	    {
	    (*n_hands)++;
      deck=(deck_t **)realloc(deck, (*n_hands)*sizeof(deck_t *));
      deck[(*n_hands)-1]=hand_from_string(line,fc);
	    }
	}
	
	}
  free(line);
  return deck;
}
