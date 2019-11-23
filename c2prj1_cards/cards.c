#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value <= VALUE_ACE);
  assert(c.value > 1);
  assert(c.suit <= CLUBS);
  assert(c.suit >= SPADES);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  default : return "no sense";
  }
  return "";
}

char value_letter(card_t c) {
  char ret = '0';
  if(c.value < 10 && c.value > 1){
    ret = '0' + c.value;
  }
  else if(c.value == 10) ret = '0';
  else if(c.value == 11) ret = 'J';
  else if(c.value == 12) ret = 'Q';
  else if(c.value == 13) ret = 'K';
  else if(c.value == 14) ret = 'A';

  return ret;
}


char suit_letter(card_t c) {
  char ret = '0';
  if(c.suit == SPADES) ret = 's';
  else if(c.suit == HEARTS) ret = 'h';
  else if(c.suit == DIAMONDS) ret = 'd';
  else if(c.suit == CLUBS) ret = 'c';

  return ret;
}

void print_card(card_t c) {
  // printf("hgfdssfgdff\n");
  printf("%c%c ",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp ;
  temp.value = 200;
  temp.suit = 200;
  //  printf("value_let = %c, suit_let = %c\n",value_let,suit_let);
  if(value_let =='0'){ temp.value = 10;}// printf("value = 10\n");}
  else if(value_let =='J'){temp.value = 11;}//printf("value = 11\n");}
  else if(value_let =='Q'){temp.value = 12;}//printf("value = 12\n");}
  else if(value_let =='K'){temp.value = 13;}//printf("value = 13\n");}
  else if(value_let =='A'){ temp.value = 14;}//printf("value = 14\n");}
  else if( value_let > '1' && value_let <= '9' ){
    temp.value = value_let - '0';
    //    printf("value = %d\n",temp.value);
  }
  else{}//printf("value_let = %c",value_let);}

  if(suit_let =='s'){temp.suit = SPADES;}//printf("suit = 0\n");}
  else if(suit_let =='h'){ temp.suit = HEARTS;}//printf("suit = 1\n");}
  else if(suit_let =='d'){ temp.suit = DIAMONDS;}//printf("suit = 2\n");}
  else if(suit_let =='c'){ temp.suit = CLUBS;}//printf("suit = 3\n");}
  else{}//printf("suit wrong\n");}

  if(temp.suit == 200 || temp.value == 200){
      exit(EXIT_FAILURE);
  }
  //  printf("val = %d, suit = %d\n",temp.value,temp.suit);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  unsigned value = c%13 + 2;
  temp.value = value;

  unsigned suit = c/13;
  switch(suit){
  case  0 : {temp.suit =SPADES;  break;}
  case 1 : {  temp.suit =HEARTS;  break;}
  case 2 :{temp.suit = DIAMONDS ;  break;}
  case 3:{temp.suit =CLUBS ; break;}
  default: {temp.suit = NUM_SUITS;  break; }}
    
  return temp;
}
