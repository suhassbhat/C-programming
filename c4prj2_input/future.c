#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "future.h"
#include "eval.h"

void add_future_card (future_cards_t *fc, size_t index, card_t *ptr)
{
  int i;
  if (index>=fc->n_decks)
    {
      fc->decks=(deck_t *)realloc(fc->decks,(index+1)*sizeof(deck_t));
      for(i=fc->n_decks;i<=index;i++)
	{
	  fc->decks[i].n_cards=0;
	  fc->decks[i].cards=NULL;
	}
      fc->n_decks=index+1;
    }
  fc->decks[index].n_cards++;
  fc->decks[index].cards=(cards_t **)realloc(fc->decks[index].cards,(fc->decks[index].n_cards)*sizeof(card_t *));
  fc->decks[index].cards[(fc->decks[index].n_cards)-1]=ptr;
  
}
void future_cards_from_deck (deck_t * deck, future_cards_t *fc)
{
  int i,j;
  if (deck->n_cards<fc->n_decks)
    {
      fprintf(stderr,"Number of cards in deck is insufficient\n");
      exit(EXIT_FAILURE);
    }
  for (i=0;i<fc->n_decks;i++)
    {
      for(j=0;j<fc->decks[i].n_cards;j++)
	{
	  fc->decks[i].cards[j]->value=deck->cards[i]->value;
	  fc->decks[i].cards[j]->suit=deck->cards[i]->suit;
	}
    }
}
