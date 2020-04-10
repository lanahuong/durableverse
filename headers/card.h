#ifndef CARD_H
#define CARD_H

// In order to make the code easily understandable :
typedef enum {ELEVE, PERSONNEL, ACTION} type;
typedef enum {ThomasLim = 1, MarieSzafranski, AlainFaye, ChristopheMouilleron, StefaniaDumbrava, JulienForest, NicolasBrunel, LaurenceBourard, DimitriWatel, ViteraY, KevinGoilard, VincentJeannas, MassinissaMerabet, Anne_LaureLigozat, CatherineDubois, EricLejeune, ChristineMathias, KatrinSalhab, AbassSagna, LaurentPrevel} staff;
typedef enum {CoursDeveloppementDurable = 21, Recrutement, RentreeFISE, RentreeFISA, EnergieVerte, Diplomation, Decharge, Recyclage, ZeroPapier, RepasVegetarien, FermetureAnuelle} action;


typedef struct car {
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
}card;

//We need a list of the different cards and to know their amount so we're gonna create two tables 
//In one of them, we'ra gonna stock the differents cards 
//card deckCards[31];
//and their amount in the second table
//int deckCardsCount[31];
//For instance, card n°1 aka ThomasLim is gonna be stocked in deckCards[0] and its amount which is 1 will be the value of deckCardsCount[0]

/*
@requires number the card will have, its type, its cost, its amount and 12 integers each equals to 0, 1 or 2
@assigns memory space for a card
@ensures create a card with all the parameters */
card* card_createCard(int num, type t, int cost, int AE1, int AE2, int AA1, int AA2, int RE1, int RE2, int RA1, int RA2, int ADD, int RDD, int DR, int E);

/*
@requires two empty 31-sized tables, the card and its quantity 
@assigns the two tables
@ensures add the card in one table and card's amount in the second */
void card_addDeckCardsAndCount(card* deckCards[31], int deckCardsCount[31], card* c, int amount);

/*
@requires two empty 31-sized tables
@assigns the two tables
@ensures add the cards in one table and cards' amount in the second */
void card_setTables(card* deckCards[31], int deckCardsCount[31]);

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the card's cost */
int card_getCost(card* c);

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the type of the card */ 
type card_getType(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's number */
int card_getNumber(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AE1 value */
int card_getAE1(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AE2 value*/
int card_getAE2(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AA1 value */
int card_getAA1(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's AA2 value*/
int card_getAA2(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RE1 value */
int card_getRE1(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RE2 value*/
int card_getRE2(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RA1 value */
int card_getRA1(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RA2 value*/
int card_getRA2(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's ADD value */
int card_getADD(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's RDD value*/
int card_getRDD(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's DR value */
int card_getDR(card* c);

/*
@requires a correctly formatted card c
@assigns nothing
@ensures return the card's E value*/
int card_getE(card* c);

#endif

