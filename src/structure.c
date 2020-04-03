#include <stdio.h>
#include <stdlib.h>
#include "../headers/structure.h"

/* 
@requires a correctly formated cardList
@assigns nothing
@ensures return the length */
int structure_getCardListLength(cardList l) {
    return l.length;
}

/* 
@requires a correctly formated cardList
@assigns nothing
@ensures return the content */
card* structure_getCardListContent(cardList l) {
    return l.content;
}

/*
@requires an unsigned int
@assigns memory space for a capacity-sized queue of int 
@ensures create a queue */
queue* structure_emptyQueue(unsigned capacity) {
    queue* queue = (queue*)malloc(sizeof(queue));
    queue->capacity = capacity;
    queue->first = 0;
    queue->size = 0;
    queue->last = capacity - 1; 
    // quand on ajoutera le premier élément, first et last seront égaux 
    queue->content = (card*)malloc(capacity * sizeof(card));
    return queue;
}

/*
@requires a correctly formated queue
@assigns nothing
@ensures return 1 if the queue is empty else 0 */
int structure_isEmptyQueue(queue q) {
    return (q.size == 0);
}

/*
@requires a correctly formated queue
@assigns nothing
@ensures return 1 if the queue is full else 0 */
int structure_isFullQueue(queue q) {
    return (q.size == q.capacity);;
}

/*
@requires a correctly formated non full queue and a card c
@assigns content, size and last
@ensures add n to the queue */
void structure_enqueue(queue* q, card c) {
    q->last = (q->last + 1) % (q->capacity); // il faut un modulo
    q->content[q->last] = c;
    q->size += 1;
}

/*
@requires a correctly formated non empty queue
@assigns content, size and first
@ensures remove the first item of the queue */
card structure_dequeue(queue* q) {
    card firstCard = q->content[q->first];
    q->first = (q->first + 1) % (q->capacity); // il faut un modulo 
    q->size = q->size - 1;
    return firstCard;
}

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the first item's index */
int structure_getQueueFirst(queue q) {
    return q.first;
}

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the last item's index */
int structure_getQueueLast(queue q) {
    return q.last;
}

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the size */
int structure_getQueueSize(queue q) {
    return q.size;
}

/* 
@requires a correctly formated queue
@assigns nothing
@ensures return the content */
int* structure_getQueueContent(queue q) {
    return q.content;
}
