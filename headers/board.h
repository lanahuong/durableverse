#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include "structure.h"
#include "card.h"

/**
 * \file board.h
 * This file describes all the functions to manipulate and modify the board
 * according the rules of the game.
 */

typedef struct board* board;

/**
 * \brief Create a new board and return it
 * \internal Initialize all attributes
 */
board board_newBoard();

/**
 * \brief Free memory space used by a board
 * \param p the board to destroy and free it's memory space
 * \internal free all cardLists (hand, deck and discard), the queue (personnel)
 *           and finally free itself
 * \attention not testable
 */
void board_freeBoard(board p);

/**
 * \brief Make all updates related to the begining of a new turn
 * \param b1 the board of player 1
 * \param b2 the board of player 2
 * \param turn a pointer to the turn number
 * \internal increment the turn number through \a turn and update the number of
 *           personnel cards allowed on board when necessary
 */
void board_newTurn(board b1, board b2, int *turn);

/**
 * \brief Count the number of cards the player should draw at the begining of
 *        its phase
 * \param p the board of the current player
 * \internal 1 + bonus from cards on the board
 * \return the number of cards to draw
 */
int board_drawCount(board p);

/**
 * \brief Draw a card for a player
 * \param p the board of the current player
 * \internal remove a random card from the deck and add it to the hand
 */
void board_draw(board p);

/**
 * \brief Count the number of student card a player receives at the begining of
 *        their phase
 * \param p the board of the current player
 * \internal 1 + bonus from cards on the board
 */
int board_studentCardCount(board p);

/**
 * \brief Make a player play a card a student card
 * \param b the board of the current player
 * \param c the number of the card to play
 * \internal if c is 0 it a FISE card is added to the board, if it's 1, a FISA
 *           card id added
 */
void board_playStudentCard(board p, int c);

/**
 * \brief Count the number of PE a player has at the begining of their turn
 * \param p the board of the current player
 * \param curturn the number of the current turn
 * \internal number of FISE + 2 * number of FISA (on odd turns) + bonus from the
 *           cards on the board
 * \return the number of PE the player has when starting their turn
 */
int board_initialPECount(board p, int curturn);

/**
 * \brief Make a player play a card
 * \param p the board of the current player
 * \param o the borad of the opponent
 * \param c the number of the card to play
 * \internal if it's personnel card add it to the board and apply the necessary
 *           border effects, if it's an action card apply it's effect and put it
 *           in the discard, in all cases the card is removed from the hand
 */
void board_playCard(board p, board o, int c);

/**
 * \brief Counts the DD earned by each player
 * \param p1 the board of player 1
 * \param p2 the corad of player 2
 * \param DD the array of DD to modify with correct values
 * \param turn the number of the current turn
 * \internal for each player : number of FISE + 2* number of FISA + bonus/malus
 * from cards of the boards + eventuallay bonus from action card
 */
void board_DDEarned(board p1, board p2, int DD[2], int turn);

/**
 * \brief Determines if the game is over and who is the winner
 * \param DDp1 DD of player 1
 * \param DDp2 DD of player 2
 * \param curturn the number of the current turn
 * \return -1 if the game is not over, 0 if player 1 wins, 1 if player 2 wins
 */
int board_gameIsOver(int DDp1,int DDp2, int curturn);

/**
 * \brief PE setter
 * \param b a board
 * \param newPE the new PE value to set in the board
 */
void board_setPE(board b, int newPE);

/**
 * \brief PE getter
 * \param b a board
 * \return the PE value of the board
 */
int board_getPE(board b);

/**
 * \brief DD adder
 * \param b a board
 * \param newDD newly earned DD
 * \internal add \a newDD to the current DD value of \a b
 */
void board_earnDD(board b, int newDD);

/**
 * \brief DD getter
 * \param b a board
 * \return the DD value of the board
 */
int board_getDD(board b);

/**
 * \brief Apply the effect of an action card
 * \param c the number of the card played
 * \param player the board of the current player
 * \param opponenent the board of the other player
 */
void card_applyCardEffect(int c, board player, board opponent);

/**
 * \brief FISEcount getter
 * \param player a board
 * \return the number of FISE cards on the board
 */
int card_getFiseCount(board player);

/**
 * \brief FISAcount getter
 * \param player a board
 * \return the number of FISA cards on the board
 */
int card_getFisaCount(board player);

/**
 * \brief Personnel getter
 * \param player a board
 * \return the personnel queue of \a player
 */
queue* card_getPersonnel(board player);

/**
 * \brief Deck getter
 * \param player a board
 * \return the deck cardList of \a player
 */
cardList* card_getDeck(board player);

/**
 * \brief Hand getter
 * \param player a board
 * \return the hand cardList of \a player
 */
cardList* card_getHand(board player);

/**
 * \brief Discard getter
 * \param player a board
 * \return the discard cardList of \a player
 */
cardList* card_getDiscard(board player);

#endif
