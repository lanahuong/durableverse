#ifndef CARD_H
#define CARD_H

typedef struct card card;

enum type {ELEVE, PERSONNEL, ACTION};

struct card
{
  int cost;
  enum type t;
  int num;
};


#endif

