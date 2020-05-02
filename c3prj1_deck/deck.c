#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
  int i;
  for(i=0;i<(*hand).n_cards;i++)
    {
      print_card(*(*hand).cards[i]);
      printf(" ");
    }
}

int deck_contains(deck_t * d, card_t c) {
  int i;
  for (i=0;i<(*d).n_cards;i++)
    {
      if(((*(*d).cards[i]).value==c.value)&&((*(*d).cards[i]).suit==c.suit))
	{return 1;}
    }
  
  return 0;
}

void shuffle(deck_t * d){
  int e[(*d).n_cards],i;
  card_t *temp;
  for(i=0;i<(*d).n_cards;i++)
    {
      e[i]=random()%((*d).n_cards);
    }
  for(i=0;i<(*d).n_cards;i++)
    {
      temp=(*d).cards[i];
      (*d).cards[i]=(*d).cards[e[i]];
      (*d).cards[e[i]]=temp;

    }
}

void assert_full_deck(deck_t * d) {
  int i,j,k,f=0;
  card_t a;
  for(k=0;k<(*d).n_cards;k++)
    {
  for(i=0;i<4;i++)
    {
      a.suit=i;
      for(j=2;j<15;j++)
	{
	  a.value=j;
	  if(deck_contains(d,a)==1)
	    {f++;}
	}
    }
    }
  assert(f==(*d).n_cards);
}
