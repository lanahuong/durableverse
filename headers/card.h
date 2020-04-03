#ifndef CARD_H
#define CARD_H

#include "structure.h"

typedef struct card {
  int cout;
  type t;
  int num;
  int AE1;
  int AE2;
  int AA1;
  int AA2;
  int RE1;
  int RE2;
  int RA1;
  int RA2;
  int ADD;
  int RDD;
  int DR;
  int E.
} card;

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the card's cost */
int card_cost(card c);

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the type of the card */ 
type card_type(card c);

/*
@requires a correctly formated deck 
@assigns nothing
@ensures return the number of cards included in the deck */ 
int card_deckCardAmount(cardList deck);

/*
@requires a correctly formated card c, two correctly formated boards
@assigns different according to the played card's effect
@ensures apply the effect of the card */
void card_applyCardEffect(card c, board* player, board* opponent);

/*
@requires an integer FISE_dev and an integer AE1
@assigns FISE_dev
@ensures add AE1 more Development points for each FISE cards to FISE_dev */
void card_addDevFISE(int* FISE_dev, int AE1);

/*
@requires an integer FISE_dur and an integer AE2
@assigns FISE_dur
@ensures add AE2 more Durability points for each FISE cards to FISE_dur */
void card_addDurFISE(int* FISE_dur, int AE2);

/*
@requires an integer FISA_dev and an integer AA1
@assigns FISA_dev
@ensures add AA1 more Development points for each FISA cards to FISA_dev */
void card_addDevFISA(int* FISA_dev, int AA1);

/*
@requires an integer FISA_dur and an integer AA2
@assigns FISA_dur
@ensures add AA2 more Durability points for each FISA cards to FISA_dur */
void card_addDurFISA(int* FISA_dur, int AA2);

/*
@requires an integer FISE_dev and an integer RE1
@assigns FISE_dev
@ensures remove RE1 more Development points for each FISE cards to FISE_dev */
void card_rmvDevFISE(int* FISE_dev, int RE1);

/*
@requires an integer FISE_dur and an integer RE2
@assigns FISE_dur
@ensures remove RE2 more Durability points for each FISE cards to FISE_dur */
void card_rmvDurFISE(int* FISE_dur, int RE2);

/*
@requires an integer FISA_dev and an integer RA1
@assigns FISA_dev
@ensures remove RA1 more Development points for each FISA cards to FISA_dev */
void card_rmvDevFISA(int* FISA_dev, int RA1);

/*
@requires an integer FISA_dur and an integer RA2
@assigns FISA_dur
@ensures remove RA2 more Durability points for each FISA cards to FISA_dur */
void card_rmvDevFISA(int* FISA_dur, int RA2);

/*
@requires an integer DD and an integer ADD
@assigns DD
@ensures add ADD to DD */
void card_addDDPoints(int* DD, int ADD);

/*
@requires an integer DD and an integer RDD
@assigns DD
@ensures remove RDD to DD */
void card_rmvDDPoints(int* DD, int n);

/*
@requires a correctly formated board and an integer DR
@assigns player's hand
@ensures add DR more cards in player's hand  */
void card_addCardInHand(board* player, int DR);

/*
@requires a correctly formated board and an integer E
@assigns FisaCount and/or FiseCount
@ensures play E more student cards */
void card_playMoreStudentCard(board* player, int E);

#endif

