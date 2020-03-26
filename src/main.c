#include "../headers/interface.h"
#include "../headers/card.h"
#include "../headers/board.h"


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
  int studentCardNbr = board_studentCardCount(player.cb);

  // Display the cardboards
  interface_board(player.cb, adv);

  // Play the student cards
  for (int i = 0; i<studentCardNbr; i++) {
    int card = interface_fiseOrFisa();
    board_playStudentCard(player.cb, card);
  }

  // Count the cards to draw
  int cardNbr = board_drawCount(player.cb);

  // Draw the cards
  for (int i = 0; i<cardNbr; i++) {
    board_draw(player.cb);
  }

  // Count PE
  player.PE = board_initialPECount(player.cb, turn);

  // Display the cardboards
  interface_board(player.cb, adv);

  // Play cards
  int choice = 0;
  while (choice !=-1) {
    choice = interface_choice(player.cb, player.PE);
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
  board_newTurn(players[0].cb, players[1].cb, turn);

  // Display the new turn
  interface_newTurn(*turn);

  // Play the 2 phases
  interface_newPhase(0);
  phase(players[0], players[1].cb,*turn);
  interface_newPhase(1);
  phase(players[1], players[0].cb, *turn);

  // Finish the turn by counting the players DD
  int DDEarned[2] = {0,0};
  board_DDEarned(players[0].cb,players[1].cb, DDEarned);
  players[0].DD += (DDEarned[0] > 0) ? DDEarned[0] : 0;
  players[1].DD += (DDEarned[1] > 0) ? DDEarned[1] : 1;

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

int main() {
  // Initialization of game variables
  ensiie players[2];
  int turn;
  int winner;
  gameSetUp(players, &turn, &winner);

  // While the game isn't over an other turn plays out
  while (winner==-1) {
    turn++;
    gameLoop(&turn, players);
    winner = board_gameIsOver(players[0].DD,players[1].DD, turn);
  }
  
  // When the game is over display the outcome
  interface_endGame(winner,players[0].DD,players[1].DD);

  //Free the boards
  board_freeBoard(players[0].cb);
  board_freeBoard(players[1].cb);

  return 0;
}
