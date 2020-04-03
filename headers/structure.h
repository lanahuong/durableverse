#ifndef STRUCTURE_H
#define STRUCTURE_H

// In order to make the code easily understandable :
typedef enum {ELEVE, PERSONNEL, ACTION} type;
typedef enum {ThomasLim = 1, MarieSzafranski, AlainFaye, ChristopheMouilleron, StefaniaDumbrava, JulienForest, NicolasBrunel, LaurenceBourard, DimitriWatel, ViteraY, KevinGoilard, VincentJeannas, MassinissaMerabet, Anne_LaureLigozat, CatherineDubois, EricLejeune, ChristineMathias, KatrinSalhab, AbassSagna, LaurentPrevel} staff;
typedef enum {CoursDeveloppementDurable = 21, Recrutement, RentreeFISE, RentreeFISA, EnergieVerte, Diplomation, Decharge, Recyclage, ZeroPapier, RepasVegetarien, FermetureAnuelle} action;

// To set a structure for the deck
typedef struct cardList {
  int length;
  card* content;
} cardList; 

/* 
@requires a correctly formated cardList
@assigns nothing
@ensures return the length */
int structure_getCardListLength(cardList l);

/* 
@requires a correctly formated cardList
@assigns nothing
@ensures return the content */
card* structure_getCardListContent(cardList l);

// To set a structure for the board where Staff cards would be played
typedef struct queue {
    int first;
    int last;
    int size;
    unsigned capacity;
    int* content;
} queue;

/*
@requires an unsigned int
@assigns memory space for a capacity-sized queue of int 
@ensures create a queue */
queue* structure_emptyQueue(unsigned capacity);

/*
@requires a correctly formated queue
@assigns nothing
@ensures return 1 if the queue is empty else 0 */
int structure_isEmptyQueue(queue q);

/*
@requires a correctly formated queue
@assigns nothing
@ensures return 1 if the queue is full else 0 */
int structure_isFullQueue(queue q);

/*
@requires a correctly formated non full queue and an integer n
@assigns content, size and last
@ensures add n to the queue */
void structure_enqueue(queue* q, int n);

/*
@requires a correctly formated non empty queue
@assigns content, size and first
@ensures remove the first item of the queue */
card structure_dequeue(queue* q);

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the first item's index */
int structure_getQueueFirst(queue l);

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the last item's index */
int structure_getQueueLast(queue l);

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the size */
int structure_getQueueSize(queue l);

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the content */
int* structure_getQueueContent(queue l);
