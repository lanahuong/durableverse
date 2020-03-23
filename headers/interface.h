#ifndef INTERFACE_H
#define INTERFACE_H


/*
requires the current turn currturn
assigns 
ensures create a new turn :
		 if turn 6 display fix to 2 the nb of 'personnel' card, if turn 11 fix to 3 the nb of 'personnel' card */
void  interfaceNewTurn(int currturn);

/*requires 
assigns
ensures display "Nouvelle Phase" and the player associate to the new phase
*/
void interfaceNewPhase();



/*requires plateau of both ensiie
assigns
ensures display the board of each player
*/

int interfaceBoard(plateau player1, plateau player2);

/*requires 
 * assigns
 * ensures give a FISE or FISA card to the player concerned ( 0 for fise 1 for sisa)
 */
int interfaceFiseOrFisa();

/*requires 
 * assigns 
 * ensures The function ask the player what to do : play a card or finish the turn. 
 *         The function only propose the card which cost less than player s PE. If no card
 *         available then the only choice its end the turn
 *         return -1 if the player finish the turn
 *         return the number of the card else
 *         
*/
void interfaceChoice();


/*requires 
 * assigns
 * ensures display the winner & the final score 
 * */

void interfaceEndGame();

#endif
