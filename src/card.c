#include "../headers/card.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct card {
  int cost;
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
  int E;
} card;

//We need a list of the different cards and to know their amount so we're gonna create two tables 
//In one of them, we'ra gonna stock the differents cards 
card deckCards[31];
//and their amount in the second table
int deckCardsCount[31];
//For instance, card n°1 aka ThomasLim is gonna be stocked in deckCards[0] and its amount which is 1 will be the value of deckCardsCount[0]

/*
@requires number the card will have, its type, its cost and 12 integers each equals to 0, 1 or 2
@assigns memory space for a card
@ensures create a card with all the parameters */
card* card_createCard(
  int num, type t, int cost, int AE1; int AE2, int AA1, int AA2, 
  int RE1, int RE2, int RA1, int RA2, int ADD, int RDD, int DR, int E) {
      card* card = (card*)malloc(sizeof(card));
      card->num = num;
      card->t = t;
      card->cost = cost;
      card->AE1 = AE1;
      card->AE2 = AE2;
      card->AA1 = AA1;
      card->AA2 = AA2;
      card->RE1 = RE1;
      card->RE2 = RE2;
      card->RA1 = RA1;
      card->RA2 = RA2;
      card->ADD = ADD;
      card->RDD = RDD;
      card->DR = DR;
      card->E = E;
  }

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
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's number */
int card_number(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AE1 value */
int card_getAE1(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AE2 value*/
int card_getAE2(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AA1 value */
int card_getAA1(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AA2 value*/
int card_getAA2(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RE1 value */
int card_getRE1(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RE2 value*/
int card_getRE2(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RA1 value */
int card_getRA1(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RA2 value*/
int card_getRA2(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's ADD value */
int card_getADD(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RDD value*/
int card_getRDD(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's DR value */
int card_getDR(card c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's E value*/
int card_getE(card c);