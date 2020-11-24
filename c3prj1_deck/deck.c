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
void add_card_to (deck_t * deck, card_t c)
{
 
  deck->n_cards++;
  deck->cards = (card_t **)realloc(deck->cards,deck->n_cards*sizeof(card_t *));
  deck->cards[(deck->n_cards)-1] = (card_t *) malloc(sizeof(card_t));
  *(deck->cards[(deck->n_cards)-1])=c;
}
card_t * add_empty_card (deck_t *deck)
{
  card_t c;
  c.value=0;
  c.suit=0;
  add_card_to(deck,c);
  return deck->cards[(deck->n_cards)-1];

}
deck_t * make_deck_exclude (deck_t * excluded_cards)
{
  deck_t *d=NULL;
  d=(deck_t *)malloc(sizeof(deck_t));
  d->n_cards=0;
  d->cards=NULL;
  int i;
  card_t c;
  for (i=0;i<52;i++)
    {
      c=card_from_num(i);
      if(!deck_contains(excluded_cards,c))
	{
	  add_card_to(d,c);
	}
    }
  return d;
}
deck_t * build_remaining_deck (deck_t **hands, size_t n_hands)
{
  int i,j;
  deck_t * d=NULL;
  deck_t * e=NULL;
  e=(deck_t *) malloc(sizeof(deck_t));
  e->n_cards=0;
  e->cards=NULL;
  for (i=0;i<n_hands;i++)
    {
      for (j=0;j<hands[i]->n_cards;j++)
	{
	  add_card_to(e,*(hands[i]->cards[j]));
	}
    }
  d=make_deck_exclude(e);
  free_deck(e);
  return d;
}
void free_deck(deck_t * deck)
{
  int i;
  for(i=0;i<deck->n_cards;i++)
    {
      free(deck->cards[i]);
    }
  free(deck->cards);
  free(deck);
  deck=NULL;
}
