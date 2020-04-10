#include "../headers/card.h"
#include <stdio.h>
#include <stdlib.h>


//We need a list of the different cards and to know their amount so we're gonna create two tables 
//In one of them, we'ra gonna stock the differents cards 
//card deckCards[31];
//and their amount in the second table
//int deckCardsCount[31];
//For instance, card n°1 aka ThomasLim is gonna be stocked in deckCards[0] and its amount which is 1 will be the value of deckCardsCount[0]

/*
@requires number the card will have, its type, its cost and 12 integers each equals to 0, 1 or 2
@assigns memory space for a card
@ensures create a card with all the parameters */
card* card_createCard(int num, type t, int cost, int AE1, int AE2, int AA1, int AA2, int RE1, int RE2, int RA1, int RA2, int ADD, int RDD, int DR, int E) {
  card* c = (card*)malloc(sizeof(card));
  c->num = num;
  c->t = t;
  c->cost = cost;
  c->AE1 = AE1;
  c->AE2 = AE2;
  c->AA1 = AA1;
  c->AA2 = AA2;
  c->RE1 = RE1;
  c->RE2 = RE2;
  c->RA1 = RA1;
  c->RA2 = RA2;
  c->ADD = ADD;
  c->RDD = RDD;
  c->DR = DR;
  c->E = E;
  return c;
}

/*
@requires two empty 31-sized tables, the card and its quantity 
@assigns the two tables
@ensures add the card in one table and card's amount in the second */
void card_addDeckCardsAndCount(card* deckCards[31], int deckCardsCount[31], card* c, int amount) {
  int i = c->num;
  deckCards[i - 1] = c;
  deckCardsCount[i - 1] = amount;
}

/*
@requires two empty 31-sized tables
@assigns the two tables
@ensures add the cards in one table and cards' amount in the second */
void card_setTables(card* deckCards[31], int deckCardsCount[31]) {
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(1, PERSONNEL, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(2, PERSONNEL, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(3, PERSONNEL, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(4, PERSONNEL, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(5, PERSONNEL, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(6, PERSONNEL, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(7, PERSONNEL, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(8, PERSONNEL, 3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(9, PERSONNEL, 5, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(10, PERSONNEL, 5, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(11, PERSONNEL, 5, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(12, PERSONNEL, 5, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(13, PERSONNEL, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(14, PERSONNEL, 8, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(15, PERSONNEL, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(16, PERSONNEL, 10, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(17, PERSONNEL, 10, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(18, PERSONNEL, 15, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(19, PERSONNEL, 15, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(20, PERSONNEL, 20, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(21, ACTION, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 3);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(22, ACTION, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 3);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(23, ACTION, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(24, ACTION, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(25, ACTION, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(26, ACTION, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(27, ACTION, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 4);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(28, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(29, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(30, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(31, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
}

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the card's cost */
int card_getCost(card* c) {
  int n = c->cost;
  return n;
}

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the type of the card */ 
type card_getType(card* c) {
  type type =  c->t;
  return type;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's number */
int card_getNumber(card* c) {
  int n = c->num;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AE1 value */
int card_getAE1(card* c) {
  int n =c->AE1;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AE2 value*/
int card_getAE2(card* c) {
  int n = c->AE2;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AA1 value */
int card_getAA1(card* c) {
  int n = c->AA1;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AA2 value*/
int card_getAA2(card* c) {
  int n = c->AA2;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RE1 value */
int card_getRE1(card* c) {
  int n = c->RE1;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RE2 value*/
int card_getRE2(card* c) {
  int n = c->RE2;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RA1 value */
int card_getRA1(card* c) {
  int n = c->RA1;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RA2 value*/
int card_getRA2(card* c) {
  int n = c->RA2;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's ADD value */
int card_getADD(card* c) {
  int n = c->ADD;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RDD value*/
int card_getRDD(card* c) {
  int n = c->RDD;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's DR value */
int card_getDR(card* c) {
  int n = c->DR;
  return n;
}

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's E value*/
int card_getE(card* c) {
  int n = c->E;
  return n;
}


int main() {
  card* deckCards[31];
  int deckCardsCount[31];
  card_setTables(deckCards, deckCardsCount);
  for (int i = 0; i < 31; i++) {
    printf("carte: %i, type: %i, cout: %i, quantité: %i, AE1: %i, AE2: %i, AA1: %i, AA2: %i, RE1: %i, RE2: %i, RA1: %i, RA2: %i, ADD: %i, RDD: %i, DR: %i, E: %i \n", deckCards[i]->num, deckCards[i]->t, deckCards[i]->cost, deckCardsCount[i], deckCards[i]->AE1, deckCards[i]->AE2, deckCards[i]->AA1, deckCards[i]->AA2, deckCards[i]->RE1, deckCards[i]->RE2, deckCards[i]->RA1, deckCards[i]->RA2, deckCards[i]->ADD, deckCards[i]->RDD, deckCards[i]->DR, deckCards[i]->E);
    printf("============================================================================================================================================================\n");
  }
  card* c1 = deckCards[30];
  card* c2 = deckCards[9];
  printf("carte: %i, type: %i, cout: %i, AE1: %i, AE2: %i, AA1: %i, AA2: %i, RE1: %i, RE2: %i, RA1: %i, RA2: %i, ADD: %i, RDD: %i, DR: %i, E: %i \n", card_getNumber(c1), card_getType(c1), card_getCost(c1), card_getAE1(c1), card_getAE2(c1), card_getAA1(c1), card_getAA2(c1), card_getRE1(c1), card_getRE2(c1), card_getRA1(c1), card_getRA2(c1), card_getADD(c1), card_getRDD(c1), card_getDR(c1), card_getE(c1));
  
  printf("carte: %i, type: %i, cout: %i, AE1: %i, AE2: %i, AA1: %i, AA2: %i, RE1: %i, RE2: %i, RA1: %i, RA2: %i, ADD: %i, RDD: %i, DR: %i, E: %i \n", card_getNumber(c2), card_getType(c2), card_getCost(c2), card_getAE1(c2), card_getAE2(c2), card_getAA1(c2), card_getAA2(c2), card_getRE1(c2), card_getRE2(c2), card_getRA1(c2), card_getRA2(c2), card_getADD(c2), card_getRDD(c2), card_getDR(c2), card_getE(c2));

  return 0;
}