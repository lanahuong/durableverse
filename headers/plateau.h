#ifndef PLATEAU_H
#define PLATEAU_H

typedef struct Plateau  Plateau;

/*
 @requires rien
 @assigns  rien
 @ensures  return a new plateau
 */

Plateau plateauNew();


/*
 @requires a plateau exist
 @assigns  rien
 @ensures  free the memory espace 
 */

void free_plateau(Plateau *p);

/*
 @requires a plateau (tour number)
 @assigns  
 @ensures  add the number of the "tour";if "tour" is pair , FISA doesnt work
           if "tour" is 6 or 11 , add a new place
 */

void tourNew(Plateau *p);

/*
 @requires plateau(not a pointure)
 @assigns  rien
 @ensures  calcule how many card should ensiie pioche at the beginning of each phase
 */

int nbr_cd_phaseNew(Plateau p);

/*
 @requires Plateau 
 @assigns  le main et le deck du plateau
 @ensures  catch a card from "deck" to hands (main)
 */

void pioche(Plateau *p);

/*
@requires player's cardboard who will receive its student cards
@assigns nothing
@ensures return the number of card the player will receive according to its cardboard
*/
int receive_student_card(Plateau p);

/*
@requires player's cardboard and student card c one wants to play on its cardboard
@assigns add a malloc on player's cardboard on FILO side and put c on it 
@ensures add the student card c on one of the FILO from the player's cardboard  
*/
void play_student_card(Plateau p, Carte c);

/*
@requires player's cardboard and the current turn
@assigns nothing
@ensures return the number of PE available for the player in the current turn 
*/
int available_PE(Plateau p, int curturn);

/*
@requires player's cardboard and the card c one wants to play on its cardboard 
@assigns add a malloc on player's cardboard and put c on it
@ensures put the card c on the cardboard 
*/
void play_card(Plateau p, Carte c);

/*
@requires players' cardboards 
@assigns nothing
@ensures return the number of DD earned by each player "player x : y DD " y could be positive or negative
*/
char DD_earned(Plateau p1, Plateau p2);

/*
@requires DD from player 1 and player 2 and the current turn
@assigns nothing
@ensures tells if the game is over and if someone wins 
*/
char is_over(int DDp1,int DDp2, int curturn);


#endif
