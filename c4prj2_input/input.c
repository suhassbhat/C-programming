#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "future.h"
#include "deck.h"

deck_t * hand_from_string(const char * line,future_cards_t * fc)
{
  int i;
  size_t index;
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
	  if(line[i]==' '||line[i]==',')
	    {
	      continue;
	    }
	  else if(line[i]=='?')
	    {
	      index=line[i+1] - '0';
	      add_future_card(fc,index,add_empty_card(d));
	      i++;
	      continue;
	    }
	  else
	    {
	      c=card_from_letters(line[i+1],line[i]);
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
      (*n_hands)++;
      deck=(deck_t **)realloc(deck, (*n_hands)*sizeof(deck_t *));
      deck[(*n_hands)-1]=hand_from_string(line,fc);
    }
  free(line);
  return deck;
}
