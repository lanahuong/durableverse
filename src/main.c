#include "headers/interface.h"
#include "headers/carte.h"
#include "headers/plateau.h"


// Structure to store cards for the deck, the hand and the discard
struct cardList {
  int length;
  int *cards;
};
typedef struct cardList cardList;

// Structure to store all the informations of a player
struct ensiie {
  int DD;
  int PE;
  board cb;
  cardList deck;
  cardList hand;
  cardList discard;
};
typedef struct ensiie ensiie;

int const NB_CARDS = 42;
int const DEFAULT_DECK[NB_CARDS] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,21,21,22,22,22,23,23,24,24,25,25,26,26,27,27,27,27,28,29,30,31};

/* 
 * Handle the playing phase of one player
 * @require nothing
 * @assigns players' board, deck, hand and discard
 * @ensures nothing
 */
void phase(ensiie player){
}

/* Handle one turn off the game
 * @require nothing
 * @assigns players' DD
 * @ensures nothing
 */
void gameLoop(int turn, ensiie players[2]){
}

/* Initialize the whole game
 * @require nothing
 * @assigns turn=0, winner=-1, players have a full deck, empty hand, discard and
 *          board, 0 PE and 0 DD
 * @ensures nothing
 */
void gameSetUp(ensiie players[2], int* turn, int* winner){
  *winner = -1;
  *turn = 0;
  
  for (int i=0; i<2 ; i++){
    players[i].DD = 0;
    players[i].PE = 0;
    players[i].hand.length = 0;
    players[i].discard.length = 0;
    players[i].deck.length = NB_CARDS;
    players[i].deck.cards = malloc(NB_CARDS*sizeof(int));
    for (int k=0; k<NB_CARDS; k++) {
      players[i].deck.cards[k] = DEFAULT_DECK[k];
    }
  }
}

int main(int argc, char** argv) {
  // Initialization of game variables
  ensiie players[2];
  int turn;
  int winner;
  gameSetUp(players, &turn, &winner);

  // While the game isn't over an other turn plays out
  while (turn<=30 && winner==-1) {
    turn++;
    gameLoop(turn, players);
    winner = cardIsOver(players);
  }
  
  // When the game is over display the outcome
  interfaceEndGame(winner);

  return 0;
}
