#ifndef BOARD_H
#define BOARD_H

#include "card.h"

typedef struct board* board;

// à ajouter dans le board.c
struct board* {
    int FISE;
    int FISA; 
    int bonusDur;
    fifo personnel;
    cardList deck;
    cardList hand;
    cardList discard;
};

/*
 @requires nothing
 @assigns  nothing
 @ensures  return a new correctly initialized board
 */

board board_newBoard();


/*
 @requires a correctly fomatted board
 @assigns  nothing
 @ensures  free the memory espace 
 */

void board_freeBoard(board p);

/*
 @requires 2 correctly formatted boards
 @assigns  *turn
 @ensures  add 1 to the number of the turn
           if turn is 6 or 11 , add 1 to the number of personnel cards boards can hold
 */

void board_newTurn(board b1, board b2, int *turn);

/*
 @requires a correctly formatted board
 @assigns  nothing
 @ensures  calcule how many card should ensiie draw at the beginning the phase
 */

int board_drawCount(board p);

/*
 @requires a correctly formatted board
 @assigns  the hand and deck of the board
 @ensures  remove a card from the deck and put's it in the hand
 */

void board_draw(board p);

/*
@requires a correctly formatted board
@assigns nothing
@ensures return the number of student cards the player will receive
*/
int board_studentCardCount(board p);

/*
@requires a correctly formatted board and c is 0 for fise and 1 for fisa
@assigns the play area of the board
@ensures add the student card to the board's play area
*/
void board_playStudentCard(board p, int c);

/*
@requires a correctly formatted card board
@assigns nothing
@ensures return the number of PE available to the player in the current turn 
*/
int board_initialPECount(board p, int curturn);

/*
@requires a correctly formatted board, c is a number from 1 to 30
@assigns the hand and the play area of the board, *PE
@ensures put the card c on the cardboard's play area 
*/
void board_playCard(board p, int c, int *PE);

/*
@requires 2 correctly formatted boards
@assigns DD
@ensures DD comtains the number of DD earned by the 2 players (can be negative)
*/
void board_DDEarned(board p1, board p2, int DD[2]);

/*
@requires 
@assigns nothing
@ensures return -1 if the game is not over, 0 (resp. 1) if player 0 (resp.1) wins
         2 if it is a tie

*/
int board_gameIsOver(int DDp1,int DDp2, int curturn);


#endif
