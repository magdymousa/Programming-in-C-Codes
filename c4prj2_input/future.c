#include <stdio.h>
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  if(index < fc->n_decks){
    fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards + 1)*sizeof(*(fc->decks[index].cards)));
    fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
    fc->decks[index].n_cards++;
  }
  else{
    for(int i = fc->n_decks;i <= index;i++){
      fc->decks = realloc(fc->decks,(fc->n_decks + 1)*sizeof(*(fc->decks)));
      //fc->decks[fc->n_decks] = NULL;
      // fc->decks[fc->n_decks] = realloc(fc->decks[fc->n_decks],(fc->decks[fc->n_decks].n_cards + 1)*sizeof(*(fc->decks[fc->n_decks])));
      fc->decks[fc->n_decks].cards = NULL;
      fc->decks[fc->n_decks].n_cards = 0;
      fc->n_decks++;
    }

    fc->decks[index].cards = realloc(fc->decks[index].cards,(fc->decks[index].n_cards + 1)*sizeof(*(fc->decks[index].cards)));
    fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
    fc->decks[index].n_cards++;
  }
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  size_t ccount = deck->n_cards;
 //if(deck->n_cards < fc->n_decks){fprintf(stderr,"not enough cards in the deck\n"); }
  for(int i = 0;i < fc->n_decks;i++){
    if(ccount == 0){ccount = 99; fprintf(stderr,"not enough cards in the deck\n");}
    for(int j = 0;j < fc->decks[i].n_cards;j++){
      *(fc->decks[i].cards[j]) = *(deck->cards[i]);
      ccount--;

    }
  }
}
