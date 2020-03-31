#ifndef CARD_H
#define CARD_H

#include "structure.h"

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the PE that the player has to pay in order to play this card c */
int PE_cost(card c);

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the type of the card */ 
type card_type(card c);

/*
@requires a correctly formated deck 
@assigns nothing
@ensures return the number of cards included in the deck. */ 
int nb_cards_in_deck(cardList deck);

/*
@requires a correctly formated card c, the player who has played it and his opponent
@assigns different according to the played card's effect
@ensures apply the effect of the card. */
void apply_effect(card c, ensiie *player, ensiie *opponent);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISE cards from stack 
@ensures add n more Development points for each FISE cards. */
void add_dev_points_FISE(stack* FISE_s, int n);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISE cards from stack 
@ensures add n more Durability points for each FISE cards. */
void add_dur_points_FISE(stack* FISE_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISA cards from stack 
@ensures add n more Development points for each FISA cards. */
void add_dev_points_FISA(stack* FISA_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISA cards from stack 
@ensures add n more Durability points for each FISA cards. */
void add_dur_points_FISA(stack* FISA_s, int n);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISE cards from stack 
@ensures remove n Development points for each FISE cards. */
void rmv_dev_points_FISE(stack* FISE_s, int n);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISE cards from stack 
@ensures remove n Durability points for each FISE cards. */
void rmv_dur_points_FISE(stack* FISE_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISA cards from stack 
@ensures removen Development points for each FISA cards. */
void rmv_dev_points_FISA(stack* FISA_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISA cards from stack 
@ensures remove n Durability points for each FISA cards. */
void rmv_dur_points_FISA(stack* FISA_s, int n);

/*
@requires a correctly formated player and an integer n equals 1 or 2
@assigns DD
@ensures add n DD points to player. */
void add_dd_points(ensiie *player, int n);

/*
@requires a correctly formated player and an integer n equals 1 or 2
@assigns DD
@ensures remove n DD points to player. */
void rmv_dd_points(ensiie *player, int n);

/*
@requires player and an integer n
@assigns nCard
@ensures add a number n of cards player will have in hand for the next turn. */
void add_card_in_hand(ensiie *player, int n);

/*
@requires player and an integer n
@assigns nStudent
@ensures add a number n of cards player will have in hand for the next turn. */
void add_student_card_on_board(ensiie *player, int n);

#endif

