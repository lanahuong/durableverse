#ifndef INTERFACE_H
#define INTERFACE_H
#include "board.h"

/**
 * \file interface.h
 * This file describes the functions used to display the game to the user and to
 * prompt them to play.
 */

/** 
 * \brief Gives the name of a card
 * \param n the number of the card
 * \internal switch on the value \a n
 * \return the name of the card as a char*
 */
char* interface_getName(int n);

/**
 * \brief Display new turn informations
 * \param currturn the turn number
 * \internal Display the number and gives additionnal informations : if FISA are
 *           on the board, the maximum number of personnel cards that can be
 *           placed on the board
 */
void  interface_newTurn(int currturn);

/**
 * \brief Display begining of a new phase message including which player can
 *        play
 * \param player the player number
 */
void interface_newPhase(int player);

/**
 * \brief Display the board of the 2 players
 * \param player1 the board of the current player
 * \param player2 the board of the other player
 * \internal Display a grid with the number of FISE and FISA cards (even when
 *           they don't count) and the list of personnel cards for the adversary
 *           (player2) and the current player (player1), also show the DD and PE
 *           of each player befor their grid
 */
void interface_board(board player1, board player2);

/**
 * \brief Prompt the user to chose a student card between FISE and FISA
 * \internal Ask the user until the oput is 0 for FISE or 1 for FISA
 * \return the number entered by the user
 */
int interface_fiseOrFisa();

/**
 * \brief Prompt the user to chose a card to play or finish the turn
 * \param p the board of the player
 * \param PE current number of PE of the current player
 * \internal Display the hand of the player and the cards they can play with
 *           their current PE, also show DD and PE
 *           0 or -1 means end of turn
 * \return the number entered by the user
 */
int interface_choice(board p, int PE);

/**
 * \brief Show the results when the game is over
 * \param winner the number of the winner (0 for player1 and 1 for player2)
 * \param DD1 DD of player 1
 * \param DD2 DD of player 2
 * \internal print the winner and the scores
 */
void interface_endGame(int winner, int DD1, int DD2);

#endif
