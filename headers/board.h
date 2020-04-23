#ifndef BOARD_H
#define BOARD_H

#include "structure.h"
#include "card.h"

typedef struct board* board;


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

/*
@requires a correctly formated deck 
@assigns nothing
@ensures return the number of cards included in the deck */ 
int card_deckCardAmount(cardList deck);

/*
@requires a correctly formated card c, two correctly formated boards
@assigns different according to the played card's effect
@ensures apply the effect of the card */
void card_applyCardEffect(card c, board* player, board* opponent);

/*
@requires an integer FISE_dev and an integer AE1
@assigns FISE_dev
@ensures add AE1 more Development points for each FISE cards to FISE_dev */
void card_addDevFISE(int* FISE_dev, int AE1);

/*
@requires an integer FISE_dur and an integer AE2
@assigns FISE_dur
@ensures add AE2 more Durability points for each FISE cards to FISE_dur */
void card_addDurFISE(int* FISE_dur, int AE2);

/*
@requires an integer FISA_dev and an integer AA1
@assigns FISA_dev
@ensures add AA1 more Development points for each FISA cards to FISA_dev */
void card_addDevFISA(int* FISA_dev, int AA1);

/*
@requires an integer FISA_dur and an integer AA2
@assigns FISA_dur
@ensures add AA2 more Durability points for each FISA cards to FISA_dur */
void card_addDurFISA(int* FISA_dur, int AA2);

/*
@requires an integer FISE_dev and an integer RE1
@assigns FISE_dev
@ensures remove RE1 more Development points for each FISE cards to FISE_dev */
void card_rmvDevFISE(int* FISE_dev, int RE1);

/*
@requires an integer FISE_dur and an integer RE2
@assigns FISE_dur
@ensures remove RE2 more Durability points for each FISE cards to FISE_dur */
void card_rmvDurFISE(int* FISE_dur, int RE2);

/*
@requires an integer FISA_dev and an integer RA1
@assigns FISA_dev
@ensures remove RA1 more Development points for each FISA cards to FISA_dev */
void card_rmvDevFISA(int* FISA_dev, int RA1);

/*
@requires an integer FISA_dur and an integer RA2
@assigns FISA_dur
@ensures remove RA2 more Durability points for each FISA cards to FISA_dur */
void card_rmvDevFISA(int* FISA_dur, int RA2);

/*
@requires an integer DD and an integer ADD
@assigns DD
@ensures add ADD to DD */
void card_addDDPoints(int* DD, int ADD);

/*
@requires an integer DD and an integer RDD
@assigns DD
@ensures remove RDD to DD */
void card_rmvDDPoints(int* DD, int n);

/*
@requires a correctly formated board and an integer DR
@assigns player's hand
@ensures add DR more cards in player's hand  */
void card_addCardInHand(board* player, int DR);

/*
@requires a correctly formated board and an integer E
@assigns FisaCount and/or FiseCount
@ensures play E more student cards */
void card_playMoreStudentCard(board* player, int E);

/*
@requires a correctly formated board)
@assigns
@ensures return the DD
*/
 int card_getDD(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the PE
*/
int card_getPE(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the FiseCount
*/
int card_getFiseCount(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the FisaCount
*/
int card_getFisaCount(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the devbonus
*/
int card_getDevBonus(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the queue personnel
*/
queue card_getPersonnel(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the deck
*/
cardList card_getDeck(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the hand
*/
cardList card_getHand(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the discard
*/
cardList card_getDiscard(board* player);

#endif
