#ifndef STRUCTURE_H
#define STRUCTURE_H



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

/*
@requires nothing
@assigns nothing
@ensures return an 42-sized empty cardList 
*/
cardList structure_emptyCardList();
/*
@requires a correctly formated cardList
@assigns nothing
@ensures return 0 if the cardList is empty else 1
*/
int structure_isEmptyCardList(cardlist cl);
/* 
@requires correctly formatted cardList cl and card number c
@assigns cardList 
@ensures add the card which number is c to the cardList cl
*/
void structure_addCardCardList(cardList cl, int c);

/* 
@requires correctly formatted cardList cl and an int c smaller than cardList.length
@assigns cardList 
@ensures remove the card which index is c from the cardList cl and return the card's number
*/
int structure_removeCardCardList(cardList cl, int c);

/*
@requires a correctly formatted cardList cl
@assigns queue
@ensures free the cardList cl
*/
void structure_freeCardList(cardList cl);

/*
@requires correctly formatted cardList cl and card number c
@assigns nothing
@ensures return the index of the card which number is c in cl or 
                    -1 if that card does not exist in cl
*/
int structure_searchCardList(cardList cl, int c);





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
@ensures remove the first item of the queue and return it */
int structure_dequeue(queue* q);

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

/*
@requires a correctly formatted queue q
@assigns queue
@ensures free the queue q
*/
void structure_freeQueue(queue q);


#endif

