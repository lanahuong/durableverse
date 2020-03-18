#IFNDEF CARTE_H
#DEFINE CARTE_H

/*
@requires player who will receive its student cards according to its previous turn
@assigns nothing
@ensures return the number of card the player will receive 
*/
int receive_student_card(ensiie player, int turn_nb_prev);

/*
@requires player and card c
@assigns add a malloc on player's cardboard and put c on it 
@ensures add a card on the cardboard of player 
*/
void add_student_card(ensiie *player, carte c);

/*
@requires current turn and the player
@assigns nothing
@ensures return the number of PE available for the player in the current turn 
*/
int available_PE(ensiie player, int current_turn);

/*
@requires player and the card c one wants to play on its cardboard 
@assigns add a malloc on player's cardboard and put c on it
@ensures put the card c on the cardboard 
*/
void play_card(ensiie player, carte c);

/*
@requires player's cardboard 
@assigns nothing
@ensures return the number of DD earned by each player "player x : y DD " y could be positive or negative
*/
char DD_earned(ensiie player);

/*
@requires player 1 and player 2 
@assigns nothing
@ensures tells if the game is over and if someone wins 
*/
char is_over(ensiie player1, ensiie player2);

#ENDIF

