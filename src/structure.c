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
int* structure_getCardListContent(cardList l) {
    return l.content;
}

/*
@requires an unsigned int
@assigns memory space for a capacity-sized queue of int 
@ensures create a queue */
queue* structure_emptyQueue(unsigned capacity) {
    queue q;
    q.capacity = capacity;
    q.size = 0; 
    q.content = (int)malloc(capacity * sizeof(int));
    return &q;
}

/*
@requires a correctly formated cardList
@assigns nothing
@ensures return 0 if the cardList is empty else 1
*/
int structure_isEmptyCardList(cardList cl){
	return (cl.length == 0);
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
@requires a correctly formated non full queue and int n
@assigns content & size
@ensures add n to the queue */
void structure_enqueue(queue* q, int n) {
    if (q->size == 0){
	    q->content[2] = n;
	    q->size +=1;
    }
    else if (q->size == 1){
	    q->content[1] = n;
	    q->size +=1;
    }
    else if (q->size == 2){
	   structure_dequeue(q);
	    q->content[0] = n;
	    
    }
  
    
}

/*
@requires a correctly formated non empty queue
@assigns content & size
@ensures remove the first item of the queue & move the others*/
int structure_dequeue(queue* q) {
    	if (!structure_isEmptyQueue){
    		if(q->size == 1){
			q->content[2] = NULL;
		}
		else if (q->size == 2){
			q->content[2] = q->content[1];
			q->content[1] = NULL;
		}
		else if (q->size ==3){
			q->content[2] = q->content[1];
			q->content[1] = q->content[0];
			q->content[0] = NULL;
		}

		q->size = q->size - 1;
	}
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

/*
@requires nothing
@assigns nothing
@ensures return an 42-sized empty cardList 
*/
cardList structure_emptyCardList(){
	cardList res;
	res.length = 42;
	return res;
}

/* 
@requires correctly formatted cardList cl and card number c
@assigns cardList 
@ensures add the card which number is c to the cardList cl
*/
void structure_addCardCardLIst(cardList cl, int c){
	cl.length = cl.length + 1;
	cl.content[cl.length - 1] = c;
}

/* 
@requires correctly formatted cardList cl and an int c smaller than cardList.length
@assigns cardList 
@ensures remove the card which index is c from the cardList cl and return the card's number
*/
int structure_removeCardCardList(cardList cl, int c){
	int tmp = cl.content[c];
	cl.content[c] = &cl.content[cl.length - 1];
	cl.content[cl.length - 1] = tmp;
	cl.length = cl.length - 1;
	return tmp;
}

