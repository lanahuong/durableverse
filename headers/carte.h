#IFNDEF CARTE_H
#DEFINE CARTE_H

/*
@requires player who will receive its student cards according to its previous turn
@assigns nothing
@ensures return the number of card the player will receive 
*/
int receive_student_card(ensiie player, int turn_nb_prev);

/*
@requires cardboard p and card c
@assigns add a malloc on the cardboard and put c on it 
@ensures add a cad on the cardboard 
*/
void add_student_card(plateau *p, carte c);

/*
@requires current turn and the player
@assigns nothing
@ensures return hte number of PE available forthe player in the current turn 
*/
int nb_energy(ensiie player, int current_turn);

/*
@requires player and the card c he want's to play on the cardboard p
@assigns add a malloc on the cardboard and put c on it
@ensures put the card c on the cardboard 
*/
void play_card(ensiie player, carte c, plateau *p);

/*
@requires cardboard p 
@assigns nothing
@ensures return the number of DD earned by each player "player x : y DD " y could be positive or negative
*/
char DD_earned(plateau p);

/*
@requires cardboard p, player 1, player 2
@assigns nothing
@ensures tells if the game is over and if someone wins 
*/
char is_over(plateau p, ensiie player1, ensiie player2);

#ENDIF

