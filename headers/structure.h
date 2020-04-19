#ifndef STRUCTURE_H
#define STRUCTURE_H

#include "card.h"


// To set a structure for the deck
typedef struct cardList {
  int length;
  int* content;
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
int* structure_getCardListContent(cardList l);

// To set a structure for the board where Staff cards would be played
typedef struct queue {
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
void structure_dequeue(queue* q);

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

#endif

