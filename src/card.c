#include "../headers/card.h"
#include <stdio.h>
#include <stdlib.h>

struct card {
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
};

//We need a list of the different cards and to know their amount so we're gonna create two tables. In one of them, we'ra gonna stock the differents cards 
//card deckCards[31];
//and their amount in the second table
//int deckCardsCount[31];
//For instance, card n°1 aka ThomasLim is gonna be stocked in deckCards[0] and its amount which is 1 will be the value of deckCardsCount[0]

/**
* \brief create a \a card with all the parameters
* \param number the card will have, \attention should be unique for each card
* \param t type of the card 
* \param cost cost of the card
* \param amount amount of the card
* \param integers x 12, each equals to 0, 1 or 2
* \return the \a card created 
*/
card card_createCard(int num, type t, int cost, int AE1, int AE2, int AA1, int AA2, int RE1, int RE2, int RA1, int RA2, int ADD, int RDD, int DR, int E) {
  card c = (card)malloc(sizeof (*c));
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

/**
* \brief add the \a card in one table and card's amount in the second
* \param deckCard empty corretly formated 31-sized table to stock the cards
* \param deckCardCount empty corretly formated 31-sized table to stock the amount of the card 
* \param c the \a card we want to add
* \param amount the amount of the card \a c
* \return nothing 
*/
void card_addDeckCardsAndCount(card deckCards[31], int deckCardsCount[31], card c, int amount) {
  int i = c->num;
  deckCards[i - 1] = c;
  deckCardsCount[i - 1] = amount;
}

/**
* \brief create the initial deck with the amount of each card
* \param deckCard empty corretly formated 31-sized table to stock the cards
* \param deckCardCount empty corretly formated 31-sized table to stock the amount of the card 
* \return nothing
 */
void card_setTables(card deckCards[31], int deckCardsCount[31]) {
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(ThomasLim, PERSONNEL, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(MarieSzafranski, PERSONNEL, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(AlainFaye, PERSONNEL, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(ChristopheMouilleron, PERSONNEL, 3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(StefaniaDumbrava, PERSONNEL, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(JulienForest, PERSONNEL, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(NicolasBrunel, PERSONNEL, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(LaurenceBourard, PERSONNEL, 3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(DimitriWatel, PERSONNEL, 5, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(ViteraY, PERSONNEL, 5, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(KevinGoilard, PERSONNEL, 5, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(VincentJeannas, PERSONNEL, 5, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(MassinissaMerabet, PERSONNEL, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(Anne_LaureLigozat, PERSONNEL, 8, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(CatherineDubois, PERSONNEL, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(EricLejeune, PERSONNEL, 10, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(ChristineMathias, PERSONNEL, 10, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(KatrinSalhab, PERSONNEL, 15, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(AbassSagna, PERSONNEL, 15, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 1), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(LaurentPrevel, PERSONNEL, 20, 2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(CoursDeveloppementDurable, ACTION, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 3);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(Recrutement, ACTION, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 3);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(RentreeFISE, ACTION, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(RentreeFISA, ACTION, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(EnergieVerte, ACTION, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(Diplomation, ACTION, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 2);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(Decharge, ACTION, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 4);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(Recyclage, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(ZeroPapier, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(RepasVegetarien, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
  card_addDeckCardsAndCount(deckCards, deckCardsCount, card_createCard(FermetureAnnuelle, ACTION, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), 1);
}

/**
* \brief get the \a cost of the card
* \param c the correctly formated card we want to get the cost
* \return \a cost, the cost of the card \a c
*/
int card_getCost(int c) {
  int n = DECKCARDS[c]->cost;
  return n;
}

/**
* \brief get the \a type of the card
* \param c the correctly formated card we want to get the tyoe
* \return \a type, the type of the card \a c
*/
type card_getType(int c) {
  type type =  DECKCARDS[c]->t;
  return type;
}

/**
* \brief get the \a AE1 value of the card
* \param c the correctly formated card we want to get the AE1 value
* \return \a AE1 value of the card \a c
*/
int card_getAE1(int c) {
  int n = DECKCARDS[c]->AE1;
  return n;
}

/**
* \brief get the \a AE2 value of the card
* \param c the correctly formated card we want to get the AE2 value
* \return \a AE2 value of the card \a c
*/
int card_getAE2(int c) {
  int n = DECKCARDS[c]->AE2;
  return n;
}

/**
* \brief get the \a AA1 value of the card
* \param c the correctly formated card we want to get the AA1 value
* \return \a AA1 value of the card \a c
*/
int card_getAA1(int c) {
  int n = DECKCARDS[c]->AA1;
  return n;
}

/**
* \brief get the \a AA2 value of the card
* \param c the correctly formated card we want to get the AA2 value
* \return \a AA2 value of the card \a c
*/
int card_getAA2(int c) {
  int n = DECKCARDS[c]->AA2;
  return n;
}

/**
* \brief get the \a RE1 value of the card
* \param c the correctly formated card we want to get the RE1 value
* \return \a RE1 value of the card \a c
*/
int card_getRE1(int c) {
  int n = DECKCARDS[c]->RE1;
  return n;
}

/**
* \brief get the \a RE2 value of the card
* \param c the correctly formated card we want to get the RE2 value
* \return \a RE2 value of the card \a c
*/
int card_getRE2(int c) {
  int n = DECKCARDS[c]->RE2;
  return n;
}

/**
* \brief get the \a RA1 value of the card
* \param c the correctly formated card we want to get the RA1 value
* \return \a RA1 value of the card \a c
*/
int card_getRA1(int c) {
  int n = DECKCARDS[c]->RA1;
  return n;
}

/**
* \brief get the \a RA2 value of the card
* \param c the correctly formated card we want to get the RA2 value
* \return \a RA2 value of the card \a c
*/
int card_getRA2(int c) {
  int n = DECKCARDS[c]->RA2;
  return n;
}

/**
* \brief get the \a ADD value of the card
* \param c the correctly formated card we want to get the ADD value
* \return \a ADD value of the card \a c
*/
int card_getADD(int c) {
  int n = DECKCARDS[c]->ADD;
  return n;
}

/**
* \brief get the \a RDD value of the card
* \param c the correctly formated card we want to get the RDD value
* \return \a RDD value of the card \a c
*/
int card_getRDD(int c) {
  int n = DECKCARDS[c]->RDD;
  return n;
}

/**
* \brief get the \a DR value of the card
* \param c the correctly formated card we want to get the DR value
* \return \a DR value of the card \a c
*/
int card_getDR(int c) {
  int n = DECKCARDS[c]->DR;
  return n;
}

/**
* \brief get the \a E value of the card
* \param c the correctly formated card we want to get the E value
* \return \a E value of the card \a c
*/
int card_getE(int c) {
  int n = DECKCARDS[c]->E;
  return n;
}


int main() {
  card deckCards[31];
  int deckCardsCount[31];
  card_setTables(deckCards, deckCardsCount);
  for (int i = 0; i < 31; i++) {
    printf("carte: %i, type: %i, cout: %i, quantité: %i, AE1: %i, AE2: %i, AA1: %i, AA2: %i, RE1: %i, RE2: %i, RA1: %i, RA2: %i, ADD: %i, RDD: %i, DR: %i, E: %i \n", deckCards[i]->num, deckCards[i]->t, deckCards[i]->cost, deckCardsCount[i], deckCards[i]->AE1, deckCards[i]->AE2, deckCards[i]->AA1, deckCards[i]->AA2, deckCards[i]->RE1, deckCards[i]->RE2, deckCards[i]->RA1, deckCards[i]->RA2, deckCards[i]->ADD, deckCards[i]->RDD, deckCards[i]->DR, deckCards[i]->E);
    printf("============================================================================================================================================================\n");
  }
  card c1 = deckCards[30];
  card c2 = deckCards[9];
  printf("carte: %i, type: %i, cout: %i, AE1: %i, AE2: %i, AA1: %i, AA2: %i, RE1: %i, RE2: %i, RA1: %i, RA2: %i, ADD: %i, RDD: %i, DR: %i, E: %i \n", card_getNumber(c1), card_getType(c1), card_getCost(c1), card_getAE1(c1), card_getAE2(c1), card_getAA1(c1), card_getAA2(c1), card_getRE1(c1), card_getRE2(c1), card_getRA1(c1), card_getRA2(c1), card_getADD(c1), card_getRDD(c1), card_getDR(c1), card_getE(c1));
  
  printf("carte: %i, type: %i, cout: %i, AE1: %i, AE2: %i, AA1: %i, AA2: %i, RE1: %i, RE2: %i, RA1: %i, RA2: %i, ADD: %i, RDD: %i, DR: %i, E: %i \n", card_getNumber(c2), card_getType(c2), card_getCost(c2), card_getAE1(c2), card_getAE2(c2), card_getAA1(c2), card_getAA2(c2), card_getRE1(c2), card_getRE2(c2), card_getRA1(c2), card_getRA2(c2), card_getADD(c2), card_getRDD(c2), card_getDR(c2), card_getE(c2));

  return 0;
}