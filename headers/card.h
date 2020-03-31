#ifndef CARD_H
#define CARD_H

typedef struct card card;

enum type {ELEVE, PERSONNEL, ACTION};

struct card {
  int cost;
  enum type t;
  int num;
};

typedef struct studentCard studentCard;
typedef enum type {PERSONNEL, ACTION} type;
typedef enum student {FISE, FISA} student;

typedef struct cardList {
  int length;
  card* cards;
} cardList; 


enum staff {ThomasLim = 1, MarieSzafranski, AlainFaye, ChristopheMouilleron, StefaniaDumbrava, JulienForest, NicolasBrunel, LaurenceBourard, DimitriWatel, ViteraY, KevinGoilard, VincentJeannas, MassinissaMerabet, Anne_LaureLigozat, CatherineDubois, EricLejeune, ChristineMathias, KatrinSalhab, AbassSagna, LaurentPrevel};
enum action {CoursDeveloppementDurable = 21, Recrutement, RentreeFISE, RentreeFISA, EnergieVerte, Diplomation, Decharge, Recyclage, ZeroPapier, RepasVegetarien, FermetureAnuelle};

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the PE that the player has to pay in order to play this card c */
int PE_cost(card c);

/*
@requires a correctly formated card c
@assigns nothing
@ensures return the type of the card */ 
Type card_type(card c);

/*
@requires a correctly formated deck 
@assigns nothing
@ensures return the number of cards included in the deck. */ 
int nb_cards_in_deck(cardList deck);

/*
@requires a correctly formated card c, the player who has played it and his opponent
@assigns different according to the played card's effect
@ensures apply the effect of the card. */
void apply_effect(card c, ensiie player, ensiie opponent);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISE cards from Stack 
@ensures add n more Development points for each FISE cards. */
void add_dev_points_FISE(Stack* FISE_s, int n);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISE cards from Stack 
@ensures add n more Durability points for each FISE cards. */
void add_dur_points_FISE(Stack* FISE_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISA cards from Stack 
@ensures add n more Development points for each FISA cards. */
void add_dev_points_FISA(Stack* FISA_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISA cards from Stack 
@ensures add n more Durability points for each FISA cards. */
void add_dur_points_FISA(Stack* FISA_s, int n);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISE cards from Stack 
@ensures remove n Development points for each FISE cards. */
void rmv_dev_points_FISE(Stack* FISE_s, int n);

/*
@requires a correctly formated stack FISE_s used for FISE cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISE cards from Stack 
@ensures remove n Durability points for each FISE cards. */
void rmv_dur_points_FISE(Stack* FISE_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dev_pts of each FISA cards from Stack 
@ensures removen Development points for each FISA cards. */
void rmv_dev_points_FISA(stack* FISA_s, int n);

/*
@requires a correctly formated stack FISA_s used for FISA cards and an integer n equals 1 or 2
@assigns Dur_pts of each FISA cards from Stack 
@ensures remove n Durability points for each FISA cards. */
void rmv_dur_points_FISA(stack* FISA_s, int n);

/*
@requires a correctly formated player and an integer n equals 1 or 2
@assigns DD
@ensures add n DD points to player. */
void add_dd_points(ensiie player, int n);

/*
@requires a correctly formated player and an integer n equals 1 or 2
@assigns DD
@ensures remove n DD points to player. */
void rmv_dd_points(ensiie *player, int n);


#endif

