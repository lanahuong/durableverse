#ifndef STRUCTURE_H
#define STRUCTURE_H

/**
 * \file structure.h
 *
 * This file describes all the function used to create and manipulate cardList
 * and queue data structures.
 */

// To set a structure for the deck
typedef struct cardList {
  int length;
  int* content;
} cardList; 

/**
 * \brief length getter
 * \param l a cardList
 * \return the length of l
 */
int structure_getCardListLength(cardList* l);

/**
 * \brief content getter
 * \param l a cardList
 * \return the content array of l
 */
int* structure_getCardListContent(cardList* l);

/**
 * \brief Create an empty cardList of maximum size 42
 */
cardList* structure_emptyCardList();

/**
 * \brief Test if a cardList is empty
 * \param cl a cardList
 * \return 1 if the list is empty else 0
 */
int structure_isEmptyCardList(cardList* cl);

/**
 * \brief Add a card to a cardList
 * \param cl a calrdList
 * \param c the number of the card to add
 * \internal increament the length of the list and set the length-1 th
 *           element content array to \a c
 */
void structure_addCardCardList(cardList* cl, int c);

/**
 * \brief Remove the card at the given index from a cardList
 * \param cL a cardList
 * \param c the index of the card to remove
 * \internal swap the last card (of index length-1) and the one to remove and
 *           decrease the length
 * \return the number of the card removed
 */
int structure_removeCardCardList(cardList* cl, int c);

/**
 * \brief Free the memory space used by a cardList
 * \param cl a cardList
 * \internal free the content and free itself
 */
void structure_freeCardList(cardList* cl);

/**
 * \brief Search a card in a cardList given its number
 * \param cl the cardList to search
 * \param c the number of the card to search for
 * \return the index of the card if it's found else -1
 */
int structure_searchCardList(cardList* cl, int c);





// To set a structure for the board where Staff cards would be played
typedef struct queue {
    int size;
    int capacity;
    int* content;
} queue;

/**
 * \brief Create an empty queue
 * \return the newly created empty queue
 */
queue* structure_emptyQueue();

/**
 * \brief Test if a queue is empty
 * \return 1 if the queue is empty else 0
 */
int structure_isEmptyQueue(queue* q);

/**
 * \brief Test if a queue is full
 * \return 1 if the queue is full else 0
 */
int structure_isFullQueue(queue* q);

/**
 * \brief Add an element to a non full queue
 */
void structure_enqueue(queue* q, int n);

/**
 * \brief Remove an element from a non empty queue
 */
int structure_dequeue(queue* q);

/**
 * \brief size getter
 * \return the size of the queue (numbr of elements it contains)
 */
int structure_getQueueSize(queue* l);

/**
 * \brief content getter
 * \return the content of the queue
 */
int* structure_getQueueContent(queue* l);

/**
 * \brief Free the memory space used by a queue
 */
/*
@requires a correctly formatted queue q
@assigns queue
@ensures free the queue q
*/
void structure_freeQueue(queue* q);


#endif

