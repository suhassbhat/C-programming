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
  deck_t d1;
  int i;
  d1.n_cards=(*d).n_cards;
  for(i=0;i<(*d).n_cards-1;i++)
    {
      d1.cards=&(*d).cards[i+1];
      d1.n_cards--;
      assert(deck_contains(&d1,*(*d).cards[i])==0);
    }
  
 
}
