#ifndef CARTE_H
#define CARTE_H

typedef struct Carte Carte;

enum type {ELEVE, PERSONNEL, ACTION};

struct Carte
{
  int cout;
  enum type t;
  int num;
};


#endif

