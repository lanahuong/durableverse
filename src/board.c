#include "../headers/board.h"
struct board {
    int DD;
    int PE;
    int FiseCount;
    int FisaCount; 
    int duraBonus;
    int devBonus;
    queue personnel;
    cardList deck;
    cardList hand;
    cardList discard;
};


/*
 @requires nothing
 @assigns  nothing
 @ensures  return a new correctly initialized board
 */

board board_newBoard() {
    board b = (board) malloc(sizeof(board));
    b->DD = 0;
    b->PE = 0;
    b->FiseCount = 0;
    b->FisaCount = 0;
    b->duraBonus = 0;
    b->devBonus = 0;
    queue *personnelq = structure_emptyQueue(3);
    b->personnel = *personnelq;
    b->deck = structure_emptyCardList();
    // Create a complete deck
    int i=0;
    int k=0;
    while (i<31) {
        k+=1;
        if (k<=DECKCARDSCOUNT[i]) {
            structure_addCardCardList(b->deck, i);
        } else {
            i++;
            k=0;
        }
    }

    b->hand = structure_emptyCardList();
    b->discard = structure_emptyCardList();
}


/*
 @requires a correctly fomatted board
 @assigns  nothing
 @ensures  free the memory espace 
 */

void board_freeBoard(board p) {
    structure_freeCardList(p->deck);
    structure_freeCardList(p->hand);
    structure_freeCardList(p->discard);
    structure_freeQueue(p->personnel);
}

/*
 @requires 2 correctly formatted boards
 @assigns  *turn 
 @ensures  add 1 to the number of the turn
           if turn is 6 or 11 , add 1 to the number of personnel cards boards can hold
 */

void board_newTurn(board b1, board b2, int *turn) {
    *turn = *turn+1;
    if (*turn==6 || *turn==11) {
        b1->personnel.capacity+=1;
    }
}

/*
 @requires a correctly formatted board
 @assigns  nothing
 @ensures  calcule how many card should ensiie draw at the beginning the phase
 */

int board_drawCount(board p) {
    int c = 1;
    queue personnel = card_getPersonnel(p);
    if (!isEmptyQueue(personnel)) {
        int* content = structure_getQueueContent(personnel);
        for (int i=0; i<structure_getQueueSize(personnel); i++){
            c+=card_getDR(content[i]);
        }
    }
}

/*
 @requires a correctly formatted board
 @assigns  the hand and deck of the board
 @ensures  remove a card from the deck and put's it in the hand
 */

void board_draw(board p) {
    int c = structure_removeCardCardList(card_getHand(p));
    structure_addCardCardList(card_getHand(p), c);
}

/*
@requires a correctly formatted board
@assigns nothing
@ensures return the number of student cards the player will receive
*/
 // TODO int board_studentCardCount(board p);

/*
@requires a correctly formatted board and c is 0 for fise and 1 for fisa
@assigns the play area of the board
@ensures add the student card to the board's play area
*/
 // TODO void board_playStudentCard(board p, int c);

/*
@requires a correctly formatted card board
@assigns nothing
@ensures return the number of PE available to the player in the current turn 
*/
 // TODO int board_initialPECount(board p, int curturn);

/*
@requires a correctly formatted board, c is a number from 1 to 30
@assigns the hand and the play area of the board, *PE
@ensures put the card c on the cardboard's play area 
*/
 // TODO void board_playCard(board p, int c);

/*
@requires 2 correctly formatted boards
@assigns DD
@ensures DD comtains the number of DD earned by the 2 players (can be negative)
*/
void board_DDEarned(board p1, board p2, int DD[2], int turn) {
    int devMultFISE1 = 1 + p1->devBonus;
    int devMultFISE2 = 1 + p1->devBonus;
    int durMultFISE1 = 1 + p1->duraBonus;
    int durMultFISE2 = 1 + p1->duraBonus;
    int devMultFISA1 = 1 + p2->devBonus;
    int devMultFISA2 = 1 + p2->devBonus;
    int durMultFISA1 = 1 + p2->duraBonus;
    int durMultFISA2 = 1 + p2->duraBonus;
    int DDbonus1 = 0;
    int DDbonus2 = 0;
    queue personnel = card_getPersonnel(p1);
    if (!isEmptyQueue(personnel)) {
        int* content = structure_getQueueContent(personnel);
        for (int i=0; i<structure_getQueueSize(personnel); i++){
            devMultFISE1+=card_getAE1(content[i]);
            durMultFISE1+=card_getAE2(content[i]);
            devMultFISA1+=card_getAA1(content[i]);
            durMultFISA1+=card_getAA2(content[i]);
            devMultFISE2-=card_getRE1(content[i]);
            durMultFISE2-=card_getRE2(content[i]);
            devMultFISA2-=card_getRA1(content[i]);
            durMultFISA2-=card_getRA2(content[i]);
            DDbonus1+=card_getDR(content[i]);
            DDbonus2-=card_getRDD(content[i]);
        }
    }
    personnel = card_getPersonnel(p2);
    if (!isEmptyQueue(personnel)) {
        int* content = structure_getQueueContent(personnel);
        for (int i=0; i<structure_getQueueSize(personnel); i++){
            devMultFISE2+=(card_getAE1(content[i]));
            durMultFISE2+=(card_getAE2(content[i]));
            devMultFISA2+=(card_getAA1(content[i]));
            durMultFISA2+=(card_getAA2(content[i]));
            devMultFISE1-=(card_getRE1(content[i]));
            durMultFISE1-=(card_getRE2(content[i]));
            devMultFISA1-=(card_getRA1(content[i]));
            durMultFISA1-=(card_getRA2(content[i]));
            DDbonus2+=card_getDR(content[i]);
            DDbonus1-=card_getRDD(content[i]);
        }
    }
    int FISE1 = card_getFiseCount(p1);
    int FISE2 = card_getFiseCount(p2);
    int dev1 = devMultFISE1*FISE1;
    int dur1 = durMultFISE1*FISE1;
    int dev2 = devMultFISE2*FISE2;
    int dur2 = durMultFISE2*FISE2;
    if (turn%2) {
        int FISA1 = card_getFisaCount(p1);
        int FISA2 = card_getFisaCount(p2);
        dev1 += devMultFISA1*FISA1;
        dur1 += durMultFISA1*FISA1;
        dev2 += devMultFISA2*FISA2;
        dur2 += durMultFISA2*FISA2;
    }
    DD[0] = dev1-dur2+DDbonus1;
    DD[1] = dev2-dur1+DDbonus2;
}

/*
@requires 
@assigns nothing
@ensures return -1 if the game is not over, 0 (resp. 1) if player 0 (resp.1) wins
         2 if it is a tie

*/
int board_gameIsOver(int DDp1,int DDp2, int curturn) {
    if (DDp1>=20 && DDp1>DDp2) {
        return 0;
    }
    if (DDp2>=20 && DDp2>DDp1) {
        return 1;
    }
    if (DDp1>=20 && DDp1==DDp2) {
        return 2;
    }
    if (curturn==30) {
        return 2;
    }
    return -1;
}

/*
@requires newPE>=0, b a correctly formatted board
@assigns b->PE
@ensures b->PE holds the value newPE
*/
void board_setPE(board b, int newPE) {
    b->PE = newPE;
}

/*
@requires b a correctly formatted board
@assigns nothing
@ensures return b->PE
*/
int board_getPE(board b) {
    return b->PE;
}

/*
@requires newDD>=0, b a correctly formatted board
@assigns b->DD
@ensures b->DD holds the value newPE+b->DD
*/
void board_earnDD(board b, int newDD) {
    b->DD = b->DD + newDD;
}

/*
@requires b a correctly formatted board
@assigns nothing
@ensures return b->DD
*/
int board_getDD(board b) {
    return b->DD;
}

/*
@requires a correctly formated deck 
@assigns nothing
@ensures return the number of cards included in the deck */ 
 // TODO int card_deckCardAmount(cardList deck);

/*
@requires a correctly formated card c, two correctly formated boards
@assigns different according to the played card's effect
@ensures apply the effect of the card */
 // TODO void card_applyCardEffect(card c, board* player, board* opponent);


/*
@requires a correctly formated board)
@assigns
@ensures return the FiseCount
*/
int card_getFiseCount(board player) {
    return player->FiseCount;
}

/*
@requires a correctly formated board)
@assigns
@ensures return the FisaCount
*/
int card_getFisaCount(board player) {
    return player->FisaCount;
}

/*
@requires a correctly formated board)
@assigns
@ensures return the devbonus
*/
 // TODO int card_getDevBonus(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the queue personnel
*/
 // TODO queue card_getPersonnel(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the deck
*/
 // TODO cardList card_getDeck(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the hand
*/
 // TODO cardList card_getHand(board* player);

/*
@requires a correctly formated board)
@assigns
@ensures return the discard
*/
 // TODO cardList card_getDiscard(board* player);