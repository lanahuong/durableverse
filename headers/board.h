#ifndef BOARD_H
#define BOARD_H

#include "card.h"

typedef struct board* board;

/*
 @requires rien
 @assigns  rien
 @ensures  return a new plateau
 */

board board_newBoard();


/*
 @requires a plateau exist
 @assigns  rien
 @ensures  free the memory espace 
 */

void board_freeBoard(board p);

/*
 @requires a plateau (tour number)
 @assigns  
 @ensures  add the number of the "tour";if "tour" is pair , FISA doesnt work
           if "tour" is 6 or 11 , add a new place
 */

void board_newTurn(board b1, board b2, int *turn);

/*
 @requires plateau(not a pointure)
 @assigns  rien
 @ensures  calcule how many card should ensiie pioche at the beginning of each phase
 */

int board_drawCount(board p);

/*
 @requires board 
 @assigns  le main et le deck du plateau
 @ensures  catch a card from "deck" to hands (main)
 */

void board_draw(board p);

/*
@requires player's cardboard who will receive its student cards
@assigns nothing
@ensures return the number of card the player will receive according to its cardboard
*/
int board_studentCardCount(board p);

/*
@requires player's cardboard and student card c one wants to play on its cardboard
@assigns add a malloc on player's cardboard on FILO side and put c on it 
@ensures add the student card c on one of the FILO from the player's cardboard  
*/
void board_playStudentCard(board p, int c);

/*
@requires player's cardboard and the current turn
@assigns nothing
@ensures return the number of PE available for the player in the current turn 
*/
int board_initialPECount(board p, int curturn);

/*
@requires player's cardboard and the card c one wants to play on its cardboard 
@assigns add a malloc on player's cardboard and put c on it, *PE
@ensures put the card c on the cardboard 
*/
void board_playCard(board p, int c, int *PE);

/*
@requires players' cardboards 
@assigns nothing
@ensures return the number of DD earned by each player "player x : y DD " y could be positive or negative
*/
void board_DDEarned(board p1, board p2, int DD[2]);

/*
@requires DD from player 1 and player 2 and the current turn
@assigns nothing
@ensures tells if the game is over and if someone wins 
*/
char board_gameIsOver(int DDp1,int DDp2, int curturn);


#endif
