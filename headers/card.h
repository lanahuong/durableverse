#ifndef CARD_H
#define CARD_H

/**
* \file card.h
*
* Ce fichier décrit un ensemble de fonctions utiles dans l'exploitation des cartes. Il contient un nouveau type \a card avec tous les getters 
* des différents paramètres de \a card ainsi que 3 fonctions et 3 enumérations : 
* - le type \a card définit une carte dans le jeu
* - enum type pour las différents types de cartes
* - enum staff pour les différtentes cartes PERSONNEL
* - enum action pour les différentes cartes ACTION
* - card_createCard(int num, type t, int cost, int AE1, int AE2, int AA1, int AA2, int RE1, int RE2, int RA1, int RA2, int ADD, int RDD, int DR,
* int E) pour créer une carte avec les caractéristiques qu'on veut lui donner.
* - card_addDeckCardsAndCount(card deckCards[31], int deckCardsCount[31], card c, int amount) pour ajouter les différentes cartes dans un premier 
* tableau en fonction de leur numéro et dans un second tableau, ajoute leur quantité au même index que la carte dans son tableau
* - void card_setTables(card deckCards[31], int deckCardsCount[31]) pour créer les 2 tableau avec les cartes qu'on a dans le jeu
*/


// In order to make the code easily understandable :
typedef enum {ELEVE, PERSONNEL, ACTION} type;
typedef enum {ThomasLim = 1, MarieSzafranski, AlainFaye, ChristopheMouilleron, StefaniaDumbrava, JulienForest, NicolasBrunel, LaurenceBourard, DimitriWatel, ViteraY, 
KevinGoilard, VincentJeannas, MassinissaMerabet, Anne_LaureLigozat, CatherineDubois, EricLejeune, ChristineMathias, KatrinSalhab, AbassSagna, LaurentPrevel} staff;
typedef enum {CoursDeveloppementDurable = 21, Recrutement, RentreeFISE, RentreeFISA, EnergieVerte, Diplomation, Decharge, Recyclage, ZeroPapier, RepasVegetarien, 
FermetureAnnuelle} action;


typedef struct card* card;

card DECKCARDS[31];
int DECKCARDSCOUNT[31];

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
card card_createCard(int num, type t, int cost, int AE1, int AE2, int AA1, int AA2, int RE1, int RE2, int RA1, int RA2, int ADD, int RDD, int DR, int E);

/**
* \brief add the \a card in one table and card's amount in the second
* \param deckCard empty corretly formated 31-sized table to stock the cards
* \param deckCardCount empty corretly formated 31-sized table to stock the amount of the card 
* \param c the \a card we want to add
* \param amount the amount of the card \a c
* \return nothing 
*/
void card_addDeckCardsAndCount(card deckCards[31], int deckCardsCount[31], card c, int amount);

/**
* \brief create the initial deck with the amount of each card
* \param deckCard empty corretly formated 31-sized table to stock the cards
* \param deckCardCount empty corretly formated 31-sized table to stock the amount of the card 
* \return nothing
 */
void card_setTables(card deckCards[31], int deckCardsCount[31]);

/**
* \brief get the \a cost of the card
* \param c the correctly formated card we want to get the cost
* \return \a cost, the cost of the card \a c
*/
int card_getCost(card c);

/**
* \brief get the \a type of the card
* \param c the correctly formated card we want to get the type
* \return \a type, the type of the card \a c
*/
type card_getType(card c);

/**
* \brief get the \a number of the card
* \param c the correctly formated card we want to get the number
* \return \a number, the number of the card \a c
*/
int card_getNumber(card c);

/**
* \brief get the \a AE1 value of the card
* \param c the correctly formated card we want to get the AE1 value
* \return \a AE1 value of the card \a c
*/
int card_getAE1(card c);

/**
* \brief get the \a AE2 value of the card
* \param c the correctly formated card we want to get the AE2 value
* \return \a AE2 value of the card \a c
*/
int card_getAE2(card c);

/**
* \brief get the \a AA1 value of the card
* \param c the correctly formated card we want to get the AA1 value
* \return \a AA1 value of the card \a c
*/
int card_getAA1(card c);

/**
* \brief get the \a AA2 value of the card
* \param c the correctly formated card we want to get the AA2 value
* \return \a AA2 value of the card \a c
*/
int card_getAA2(card c);

/**
* \brief get the \a RE1 value of the card
* \param c the correctly formated card we want to get the RE1 value
* \return \a RE1 value of the card \a c
*/
int card_getRE1(card c);

/**
* \brief get the \a RE2 value of the card
* \param c the correctly formated card we want to get the RE2 value
* \return \a RE2 value of the card \a c
*/
int card_getRE2(card c);

/**
* \brief get the \a RA1 value of the card
* \param c the correctly formated card we want to get the RA1 value
* \return \a RA1 value of the card \a c
*/
int card_getRA1(card c);

/**
* \brief get the \a RA2 value of the card
* \param c the correctly formated card we want to get the RA2 value
* \return \a RA2 value of the card \a c
*/
int card_getRA2(card c);

/**
* \brief get the \a ADD value of the card
* \param c the correctly formated card we want to get the ADD value
* \return \a ADD value of the card \a c
*/
int card_getADD(card c);

/**
* \brief get the \a RDD value of the card
* \param c the correctly formated card we want to get the RDD value
* \return \a RDD value of the card \a c
*/
int card_getRDD(card c);

/**
* \brief get the \a DR value of the card
* \param c the correctly formated card we want to get the DR value
* \return \a DR value of the card \a c
*/
int card_getDR(card c);

/**
* \brief get the \a E value of the card
* \param c the correctly formated card we want to get the E value
* \return \a E value of the card \a c
*/
int card_getE(card c);

#endif

