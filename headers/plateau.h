#ifndef PLATEAU_H
#define PLATEAU_H

typedef struct Plateau  Plateau;

/*
 @requires rien
 @assigns  rien
 @ensures  return a new plateau
 */

Plateau plateauNew();


/*
 @requires a plateau exist
 @assigns  rien
 @ensures  free the memory espace 
 */

void free_plateau(Plateau *p);

/*
 @requires a plateau (tour number)
 @assigns  
 @ensures  add the number of the "tour";if "tour" is pair , FISA doesnt work
           if "tour" is 6 or 11 , add a new place
 */

void tourNew(Plateau *p);

/*
 @requires plateau(not a pointure)
 @assigns  rien
 @ensures  calcule how many card should ensiie pioche at the beginning of each phase
 */

int nbr_cd_phaseNew(Plateau p);

/*
 @requires Plateau 
 @assigns  le main et le deck du plateau
 @ensures  catch a card from "deck" to hands (main)
 */

void pioche(Plateau *p);

#endif
