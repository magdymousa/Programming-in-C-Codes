#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

deck_t * hand_from_string(const char * str, future_cards_t * fc){
  size_t i = 0;
  card_t *temp_ptr = NULL;
  card_t temp = { 0, 0};

  deck_t * hand = malloc(sizeof(*hand));
  hand->cards = NULL;
  hand->n_cards = 0;
  //  char dum_str[3] = {'0','\0','\0'};
  //  fprintf(stderr,"%s",str);
  while(str[i] != '\0' && str[i] != '\n' ){
    if(str[i] != ' '){
      if(str[i] == '?'){
	char dum_str[3] = {'0','\0','\0'};
	dum_str[0] = str[i+1];
	if(str[i+2] != ' ' && str[i+2] != '\n' && str[i+2] != '\0'){
	  dum_str[1] = str[i+2];
	  i++;
	}
	int j = atoi(dum_str);
	//	fprintf(stderr,"dum->%s  int->%d\n",dum_str,j);
	//fprintf(stderr,"unknown ?%s\n",dum_str);
	temp_ptr = add_empty_card(hand);
	add_future_card(fc,j, temp_ptr) ;
      }
      else{
	//fprintf(stderr,"known %c%c\n",str[i],str[i+1]);
	temp = card_from_letters(str[i], str[i+1]);
	/*hand->cards = realloc(hand->cards,(hand->n_cards+1)sizeof(*(hand->cards)));
                    hand->cards[hand->n_cards]->value = temp.value;
                    hand->cards[hand->n_cards]->suit = temp.suit;
                    hand->n_cards++;*/
	add_card_to(hand, temp);
      }
      i++;
    }
    else{

    }
    i++;
  }
  if(hand->n_cards < 5){
    fprintf(stderr,"not enough cards for a hand\n");
    exit(EXIT_FAILURE);
  }

  return hand;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){

  char *curr = NULL;
  size_t allocated_mem = 0;
  deck_t **decks_array = NULL;
  *n_hands = 0;

  while(getline(&curr,&allocated_mem,f) >= 0){
    decks_array = realloc(decks_array,((*n_hands) + 1)*sizeof(*decks_array));
    decks_array[*n_hands] = hand_from_string(curr, fc);
    (*n_hands)++;
    curr = NULL;
  }
  return decks_array;
}
