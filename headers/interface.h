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

/*Let s define the cardboard as a structure with 2 categories : Leleves, Lpersonnel which represent the card present 
on 1 player s board. each composante is a list with the diffent cards on the board
*/

typedef struct cardsonboard cob;
struct cardsonboard
{
	char* Leleves;
	char* Lpersonnel;
	
};

/*requires matrix of player1's cards idem for player2,
assigns
ensures display the board of each player
*/

void interfaceBoard(cob* p1card, cob* p2cards);

/*requires 
 * assigns
 * ensures give a FISE or FISA card to the player concerned
 */
void interfaceFiseOrFisa();

/*requires 
 * assigns 
 * ensures The function ask the player what to do : play a card or finish the turn. 
 *         The function only propose the card which cost less than player s PE. If no card
 *         available then the only choice its end the turn
*/
void interfaceChoice();


/*requires 
 * assigns
 * ensures display the winner & the final score 
 * */

void interfaceEndGame();

#endif
