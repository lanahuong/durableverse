#include "../headers/board.h"
#include "../headers/interface.h"
#include <stdio.h>
#include <stdlib.h>

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the PE that the player has to pay in order to play this card c */
int PE_cost(card c) {
    return c.cout;
}

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the type of the card */ 
type card_type(card c) {
    return c.t;
}

/*
@requires a correctly formated deck 
@assigns nothing
@ensures return the number of cards included in the deck. */ 
int nb_cards_in_deck(cardList deck) {
    return deck.length;
}

/*
@requires a correctly formated card c, a correctly formated player who has played it and his opponent
@assigns different according to the played card's effect
@ensures apply the effect of the card. */
void apply_effect(card c, ensiie *player, ensiie *opponent) {
    switch (c.num) {
        case 1 : {
            add_dev_points_FISE(player->cb->FISE, 1); 
            break; 
        }
        case 2 : {
            add_dur_points_FISE(player->cb->FISE, 1);
            break;
        }
        case 3 : {
            add_dev_points_FISA(player->cb->FISA, 1); 
            break;
            }
        case 4 : {
            add_dur_points_FISA(player->cb->FISA, 1); 
            break;
            }
        case 5 : {
            rmv_dev_points_FISE(opponent->cb->FISE, 1); 
            break;
            }
        case 6 : {
            rmv_dur_points_FISE(opponent->cb->FISE, 1); 
            break;
            }
        case 7 : {
            rmv_dev_points_FISA(opponent->cb->FISA, 1); 
            break;
        }
        case 8 : {
            rmv_dur_points_FISA(opponent->cb->FISA, 1); 
            break;
            }
        case 9 : {
            add_dev_points_FISE(player->cb->FISE, 1); 
            add_dev_points_FISA(player->cb->FISA), 1; 
            break; 
        }
        case 10 : {
            add_dur_points_FISE(player->cb->FISE, 1);
            add_dur_points_FISA(player->cb->FISA, 1);
            break;
        }
        case 11 : {
            rmv_dev_points_FISE(opponent->cb->FISE, 1);
            rmv_dev_points_FISA(opponent->cb->FISA, 1); 
            break;
        }
        case 12 : {
            rmv_dur_points_FISE(opponent->cb->FISE, 1);
            rmv_dur_points_FISA(opponent->cb->FISA, 1); 
            break;
        }
        case 13 : {
            add_card_in_hand(player, 2);
            break;
        }
        case 14 : {
            add_dd_points(player, 2);
            add_card_in_hand(player, 1);
            add_student_card_on_board(player, 1);
            break;
        }
        case 15 : {
            rmv_dd_points(opponent, 2);
            add_card_in_hand(player, 1);
            add_student_card_on_board(player, 1);
            break;
        }
        case 16 : {
            add_dev_points_FISE(player->cb->FISE, 1);
            add_dur_points_FISE(player->cb->FISE, 1);
            rmv_dur_points_FISE(opponent->cb->FISE, 1);
            rmv_dd_points(opponent, 1);
            break;
        }
        case 17 : {
            add_dev_points_FISA(player->cb->FISA, 1);
            add_dur_points_FISA(player->cb->FISA, 1);
            rmv_dur_points_FISA(opponent->cb->FOSA, 1);
            rmv_dd_points(opponent, 1);
            break;
        }
        case 18 : {
            add_dev_points_FISE(player->cb->FISE, 2);
            add_dur_points_FISE(player->cb->FISE, 2);
            add_student_card_on_board(player, 1);
            break;
        }
        case 19 : {
            add_dev_points_FISA(player->cb->FISA, 2);
            add_dur_points_FISA(player->cb->FISA, 2);
            add_student_card_on_board(player, 1);
            break;
        }
        case 20 : {
            add_dev_points_FISE(player->cb->FISE, 2);
            add_dur_points_FISE(player->cb->FISE, 2);
            add_dev_points_FISA(player->cb->FISA, 2);
            add_dur_points_FISA(player->cb->FISA, 2);
            add_dd_points(player, 1);
            rmv_dd_points(opponent, 1);
            add_card_in_hand(player, 1);
            add_student_card_on_board(player, 2);
            break;
        }
    }
}

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISE cards from stack 
@ensures add n more Development points for each FISE cards. */
void add_dev_points_FISE(stack* FISE_s, int n) {
    if (FISE_s->top != -1) {
        for (int i=0; i<FISE_s->top; i++) {
            (FISE_s->contain[i])->Dev_pts += n;
        }
    }
}

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISE cards from stack 
@ensures add n more Durability points for each FISE cards. */
void add_dur_points_FISE(stack* FISE_s, int n) {
    if (FISE_s->top != -1) {
        for (int i=0; i<FISE_s->top; i++) {
            (FISE_s->contain[i])->Dur_pts += n;
        }
    }
}

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISA cards from stack 
@ensures add n more Development points for each FISA cards. */
void add_dev_points_FISA(stack* FISA_s, int n) {
    if (FISA_s->top != -1) {
        for (int i=0; i<FISA_s->top; i++) {
            (FISA_s->contain[i])->Dev_pts += n;
        }
    }
}

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISA cards from stack 
@ensures add n more Durability points for each FISA cards. */
void add_dur_points_FISA(stack* FISA_s, int n) {
    if (FISA_s->top != -1) {
        for (int i=0; i<FISA_s->top; i++) {
            (FISA_s->contain[i])->Dur_pts += n;
        }
    }
}

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISE cards from stack 
@ensures remove n Development points for each FISE cards. */
void rmv_dev_points_FISE(stack* FISE_s, int n) {
    if (FISE_s->top != -1) {
        for (int i=0; i<FISE_s->top; i++) {
            (FISE_s->contain[i])->Dev_pts = (FISE_s->contain[i])->Dev_pts - n;
        }
    }
}

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISE cards from stack 
@ensures remove n Durability points for each FISE cards. */
void rmv_dur_points_FISE(stack* FISE_s, int n) {
    if (FISE_s->top != -1) {
        for (int i=0; i<FISE_s->top; i++) {
            (FISE_s->contain[i])->Dur_pts = (FISE_s->contain[i])->Dur_pts - n;
        }
    }
}

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISA cards from stack 
@ensures remove n Development points for each FISA cards. */
void rmv_dev_points_FISA(stack* FISA_s, int n) {
    if (FISA_s->top != -1) {
        for (int i=0; i<FISA_s->top; i++) {
            (FISA_s->contain[i])->Dev_pts = (FISA_s->contain[i])->Dev_pts - n;
        }
    }
}

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISA cards from stack 
@ensures remove n Durability points for each FISA cards. */
void rmv_dur_points_FISA(stack* FISA_s, int n) {
    if (FISA_s->top != -1) {
        for (int i=0; i<FISA_s->top; i++) {
            (FISA_s->contain[i])->Dur_pts = (FISA_s->contain[i])->Dur_pts - n;
        }
    }
}

/*
@requires a correctly formated player and an integer n equals 1 or 2
@assigns DD
@ensures add n DD points to player. */
void add_dd_points(ensiie *player, int n) {
    player->DD += n;
}

/*
@requires a correctly formated player and an integer n equals 1 or 2
@assigns DD
@ensures remove n DD points to player. */
void rmv_dd_points(ensiie *player, int n) {
    player->DD = player->DD - n;
}


/*
@requires player and an integer n
@assigns nCard
@ensures add a number n of cards player will have in hand for the next turn. */
void add_card_in_hand(ensiie *player, int n) {
    player->nCard += n;

}

/*
@requires player and an integer n
@assigns nStudent
@ensures add a number n of cards player will have in hand for the next turn. */
void add_student_card_on_board(ensiie *player, int n) {
    player->nStudent += n;
}
