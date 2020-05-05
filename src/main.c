#include "../headers/interface.h"
#include "../headers/card.h"
#include "../headers/board.h"


/* 
 * Handle the playing phase of one player
 * @require nothing
 * @assigns players' board, deck, hand and discard
 * @ensures nothing
 */
void phase(board player, board adv, int turn){
  // Count student cards to be received
  int studentCardNbr = board_studentCardCount(player);

  // Display the cardboards
  interface_board(player, adv);

  // Play the student cards
  for (int i = 0; i<studentCardNbr; i++) {
    int card = interface_fiseOrFisa();
    board_playStudentCard(player, card);
  }

  // Count the cards to draw
  int cardNbr = board_drawCount(player);

  // Draw the cards
  for (int i = 0; i<cardNbr; i++) {
    board_draw(player);
  }

  // Count PE
  board_setPE(player, board_initialPECount(player, turn));

  // Display the cardboards
  interface_board(player, adv);

  // Play cards
  int choice = 0;
  while (choice !=-1) {
    choice = interface_choice(player, board_getPE(player));
    if (choice != 0) {
      board_playCard(player, choice);
    }
  }
}

/* Handle one turn off the game
 * @require nothing
 * @assigns players' DD
 * @ensures nothing
 */
void gameLoop(int *turn, board players[2]){
  // Start a new turn
  board_newTurn(players[0], players[1], turn);

  // Display the new turn
  interface_newTurn(*turn);

  // Play the 2 phases
  interface_newPhase(0);
  phase(players[0], players[1],*turn);
  interface_newPhase(1);
  phase(players[1], players[0], *turn);

  // Finish the turn by counting the players DD
  int DDEarned[2] = {0,0};
  board_DDEarned(players[0],players[1], DDEarned);
  board_earnDD(players[0],((DDEarned[0] > 0) ? DDEarned[0] : 0));
  board_earnDD(players[1],((DDEarned[1] > 0) ? DDEarned[1] : 1));

}

/* Initialize the whole game
 * @require nothing
 * @assigns turn=0, winner=-1, players have a full deck, empty hand, discard and
 *          board, 0 PE and 0 DD
 * @ensures nothing
 */
void gameSetUp(board players[2], int* turn, int* winner){
  *winner = -1;
  *turn = 0;
  
  for (int i=0; i<2 ; i++){
    players[i] = board_newBoard();
  }
}

int main() {
  // Initialization of game variables
  card_setTables(DECKCARDS, DECKCARDSCOUNT);
  board players[2];
  int turn;
  int winner;
  gameSetUp(players, &turn, &winner);

  // While the game isn't over an other turn plays out
  while (winner==-1) {
    turn++;
    gameLoop(&turn, players);
    winner = board_gameIsOver(board_getDD(players[0]),board_getDD(players[1]), turn);
  }
  
  // When the game is over display the outcome
  interface_endGame(winner,board_getDD(players[0]),board_getDD(players[1]));

  //Free the boards
  board_freeBoard(players[0]);
  board_freeBoard(players[1]);

  return 0;
}
