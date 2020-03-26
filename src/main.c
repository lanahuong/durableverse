#include "headers/interface.h"
#include "headers/card.h"
#include "headers/board.h"


// Structure to store all the informations of a player
struct ensiie {
  int DD;
  int PE;
  board cb;
};
typedef struct ensiie ensiie;

/* 
 * Handle the playing phase of one player
 * @require nothing
 * @assigns players' board, deck, hand and discard
 * @ensures nothing
 */
void phase(ensiie player, board adv, int turn){
  // Count student cards to be received
  int studentCardsNbr = board_studentCardCount(player.cb);

  // Display the cardboards
  interface_board(player.cb, adv);

  // Play the student cards
  for (int i = 0; i<studentCardsNbr; i++) {
    int card = interface_fiseOrFisa();
    board_playStudentCard(player.cb, card);
  }

  // Count PE
  player.PE = (player.cb, turn);

  // Display the cardboards
  interface_board(player.cb, adv);

  // Play cards
  int choice = 0;
  while (choice !=-1) {
    choice = interface_choice(player.cb);
    if (choice != 0) {
      board_playCard(player.cb, choice, &(player.PE));
    }
  }
}

/* Handle one turn off the game
 * @require nothing
 * @assigns players' DD
 * @ensures nothing
 */
void gameLoop(int *turn, ensiie players[2]){
  // Start a new turn
  board_newTurn(turn);

  // Display the new turn
  interface_newTurn(*turn);

  // Play the 2 phases
  interface_newPhase(0);
  phase(players[0], players[1].cb,*turn);
  interface_newPhase(1);
  phase(players[1], players[0].cb, *turn);

  // Finish the turn by counting the players DD
  int DDEarned[2] = board_DDEarned(players[0].cb,players[1].cb);
  players[0].DD += max(DDEarned[0],0);
  players[1].DD += max(DDEarned[1],0);

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
    players[i].cb = board_newBoard();
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
    gameLoop(&turn, players);
    winner = cardIsOver(players);
  }
  
  // When the game is over display the outcome
  interfaceEndGame(winner);

  return 0;
}
