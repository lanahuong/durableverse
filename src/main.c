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
 * @require
 * @assigns
 * @ensures
 */
void phase(){
}

/* Handle on turn off the game
 * @require
 * @assigns
 * @ensures
 */
void gameLoop(){
}

/* Initialize the whole game
 * @require
 * @assigns
 * @ensures
 */
void gameSetUp(){
}

int main(int argc, char** argv) {
  return 0;
}
