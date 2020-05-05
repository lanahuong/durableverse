#ifndef INTERFACE_H
#define INTERFACE_H
#include "board.h"


/*
requires the current turn currturn
assigns 
ensures display new turn and it's number and additionnal informations
*/
void  interface_newTurn(int currturn);

/*requires 
assigns
ensures display "Nouvelle Phase" and the player associated to the new phase
*/
void interface_newPhase(int player);



/*requires 2 correctly formatted board (player1=current player, player2=adversary)
assigns
ensures display the board of each player
*/

void interface_board(board player1, board player2);

/*requires 
 * assigns
 * ensures ask the player which type of card it wants
 * 		   return the chosen type of card (0 for fise 1 for fisa)
 */
int interface_fiseOrFisa();

/*requires 
 * assigns 
 * ensures The function ask the player what to do : play a card or finish the turn. 
 *         The function only propose the card which cost less than player s PE. If no card
 *         available then the only choice is to end the turn
 *         return -1 if the player finish the turn
 *         otherwise return the number of the card
 *         
*/
int interface_choice(board p, int PE);


/*requires the winner( player 0 or 1) and players' DD
 * assigns
 * ensures display the winner & the final score 
 * */

void interface_endGame(int winner, int DD1, int DD2);

#endif
