#include "headers/interface.h"
#include "headers/carte.h"
#include "headers/plateau.h"


// Structure to store cards for the deck, the hand and the discard
struct cardList {
  int length;
  int cards[42];
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
}

int main(int argc, char** argv) {
  // Initialization of game variables
  ensiie players[2];
  int turn;
  int winner;
  gameSetUp(players, &turn, &winner);

  // While the game isn't over an other turn plays out
  while (turn<=30 || winner) {
    turn++;
    gameLoop(turn, players);
    winner = cardIsOver(players);
  }
  
  // When the game is over display the outcome
  interfaceEndGame(winner);

  return 0;
}
