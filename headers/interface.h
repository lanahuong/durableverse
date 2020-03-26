#ifndef INTERFACE_H
#define INTERFACE_H

#include "board.h"

/*
requires the current turn currturn
assigns 
ensures create a new turn :
		 if turn 6 display fix to 2 the nb of 'personnel' card, if turn 11 fix to 3 the nb of 'personnel' card */
void  interface_newTurn(int currturn);

/*requires 
assigns
ensures display "Nouvelle Phase" and the player associate to the new phase
*/
void interface_newPhase();



/*requires board of both ensiie
assigns
ensures display the board of each player
*/

int interface_board(board player1, board player2);

/*requires 
 * assigns
 * ensures give a FISE or FISA card to the player concerned ( 0 for fise 1 for sisa)
 */
int interface_fiseOrFisa();

/*requires 
 * assigns 
 * ensures The function ask the player what to do : play a card or finish the turn. 
 *         The function only propose the card which cost less than player s PE. If no card
 *         available then the only choice its end the turn
 *         return -1 if the player finish the turn
 *         return the number of the card else
 *         
*/
int interface_choice(board p);


/*requires the winner( player 0 or 1) and players' DD
 * assigns
 * ensures display the winner & the final score 
 * */

void interface_endGame(int winner, int DD1, int DD2);

#endif
