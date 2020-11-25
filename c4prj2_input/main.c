#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "deck.h"
#include "eval.h"
#include "cards.h"
#include "future.h"
#include "input.h"
int main()
{
  int i;
  FILE *f =fopen("tests.txt","r");
  size_t n_hands;
  future_cards_t * fc = (future_cards_t *)malloc(sizeof(future_cards_t));
  deck_t ** hands;
  hands=read_input(f,&n_hands,fc);
  for(i=0;i<n_hands;i++)
    {
      free_deck(hands[i]);
    }
  free(hands);
  for(i=0;i<fc->n_decks;i++)
    {
      free(fc->decks[i].cards);
    }
  free(fc->decks);
  free(fc);
  fclose(f);
  return EXIT_FAILURE;
}
