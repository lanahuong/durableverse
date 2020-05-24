#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include <stdlib.h>
#include <stdio.h>
#include "utils.c"
#include "../headers/structure.h"

/*
 * \brief Test creation of a cardList
 */
void test_emptyCardList(void) {
  // Mocks
  
  // Call function and test
  cardList* list = structure_emptyCardList();
  
  CU_ASSERT(list->length == 0);
  
  // Free everything
  free(list->content);
  free(list);
}


/*
 * @brief Test the length getter of a cardList
 */
void test_getCardListLength(void) {
  // Mocks
  cardList* mockCardList = structure_emptyCardList();
  mockCardList->length = 12;
  
  // Call function and test
  int length = structure_getCardListLength(mockCardList);
  
  CU_ASSERT(length == 12);
  
  // Free everything
  free(mockCardList->content);
  free(mockCardList);
}

/*
 * \brief Test addition of a card to a cardList provided it's not full
 */
void test_addCardCardList(void) {
  // Mocks
  int mockCard = 24;
  
  // Call function and test
  cardList* list = structure_emptyCardList();
  int oldLength = structure_getCardListLength(list);
  structure_addCardCardList(list, mockCard);
  int newLength = structure_getCardListLength(list);

  CU_ASSERT(newLength == oldLength+1);
  CU_ASSERT(list->content[oldLength] == mockCard);
  
  // Free everything
  free(list->content);
  free(list);
}

/*
 * @brief Test the content getter of a cardList
 */
void test_getCardListContent(void) {
  // Mocks
  cardList* mockCardList = structure_emptyCardList();
  int mockContent[] = {23,1,12,4};
  structure_addCardCardList(mockCardList,23);
  structure_addCardCardList(mockCardList,1);
  structure_addCardCardList(mockCardList,12);
  structure_addCardCardList(mockCardList,4);
  
  // Call function and test
  int* content = structure_getCardListContent(mockCardList);
  
  CU_ASSERT(arraysEqual(mockContent, content, 4, 4));
  
  // Free everything
  free(mockCardList->content);
  free(mockCardList);
}

/*
 * @brief Test the removal of the last card from a cardList
 */
void test_removeCardCardList_lastCard(void) {
  // Mocks
  cardList* mockCardList = structure_emptyCardList();
  structure_addCardCardList(mockCardList,23);
  structure_addCardCardList(mockCardList,1);
  structure_addCardCardList(mockCardList,12);
  structure_addCardCardList(mockCardList,4);
  
  // Call function and test
  int oldLength = structure_getCardListLength(mockCardList);
  int* oldContent = deepCopy(structure_getCardListContent(mockCardList),oldLength);
  int removed = structure_removeCardCardList(mockCardList,3);
  int newLength = structure_getCardListLength(mockCardList);
  int* newContent = structure_getCardListContent(mockCardList);
  
  CU_ASSERT(newLength == oldLength-1);
  CU_ASSERT(removed == 4);
  CU_ASSERT(arraysEqual(newContent,oldContent,newLength,newLength));
  

  // Free everything
  free(mockCardList->content);
  free(mockCardList);
  free(oldContent);
}

/*
 * @brief Test the removal of a card (not last) from a cardList
 */
void test_removeCardCardList_notLastCard(void) {
  // Mocks
  cardList* mockCardList = structure_emptyCardList();
  structure_addCardCardList(mockCardList,23);
  structure_addCardCardList(mockCardList,1);
  structure_addCardCardList(mockCardList,12);
  structure_addCardCardList(mockCardList,4);
  
  // Call function and test
  int oldLength = structure_getCardListLength(mockCardList);
  int* content = deepCopy(structure_getCardListContent(mockCardList),oldLength);
  int tmp = content[oldLength-1];
  content[oldLength-1] = content[1];
  content[1] = tmp;
  structure_removeCardCardList(mockCardList,1);
  int newLength = structure_getCardListLength(mockCardList);
  int* newContent = structure_getCardListContent(mockCardList);
  
  CU_ASSERT(newLength == oldLength-1);
  CU_ASSERT(arraysEqual(content,newContent,newLength,newLength));

  // Free everything
  free(mockCardList->content);
  free(mockCardList);
  free(content);
}

/*
 * @brief Test the research of a card in a cardList when it is in the cardList
 */
void test_searchCardList_cardInList(void) {
  // Mocks
  cardList* mockCardList = structure_emptyCardList();
  structure_addCardCardList(mockCardList,23);
  structure_addCardCardList(mockCardList,1);
  structure_addCardCardList(mockCardList,12);
  structure_addCardCardList(mockCardList,4);
  
  // Call function and test
  CU_ASSERT(structure_searchCardList(mockCardList,1) == 1);
  CU_ASSERT(structure_searchCardList(mockCardList,12) == 2);

  // Free everything
  free(mockCardList->content);
  free(mockCardList);
}

/*
 * @brief Test the research of a card in a cardList when it is not in the cardList
 */
void test_searchCardList_cardNotInList(void) {
  // Mocks
  cardList* mockCardList = structure_emptyCardList();
  structure_addCardCardList(mockCardList,23);
  structure_addCardCardList(mockCardList,1);
  structure_addCardCardList(mockCardList,12);
  structure_addCardCardList(mockCardList,4);
  
  // Call function and test
  CU_ASSERT(structure_searchCardList(mockCardList, 5) == -1);

  // Free everything
  free(mockCardList->content);
  free(mockCardList);
}

/*
 * \brief Test the creation of an empty queue
 */
void test_emptyQueue(void) {
  // Mocks
  
  // Call function and test
  queue* q = structure_emptyQueue();
  CU_ASSERT(q->size == 0);
  CU_ASSERT(q->capacity == 1);

  // Free everything
  free(q->content);
  free(q);
}

/*
 * \brief Test if an empty queue is empty
 */
void test_isEmptyQueue_empty(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();

  // Call function and test
  CU_ASSERT(structure_isEmptyQueue(mockQ));
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test if an non-empty queue is empty
 */
void test_isEmptyQueue_notEmpty(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  mockQ->size = mockQ->capacity;

  // Call function and test
  CU_ASSERT(structure_isEmptyQueue(mockQ) == 0);
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test if a full queue is full
 */
void test_isFullQueue_full(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  mockQ->size++;

  // Call function and test
  CU_ASSERT(structure_isFullQueue(mockQ));
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test if a non-full queue is full
 */
void test_isFullQueue_notFull(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();

  // Call function and test
  CU_ASSERT(structure_isFullQueue(mockQ) == 0);
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test adding an element to the queue 1
 */
void test_enqueue1(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  int mockContent[] = {22};

  // Call function and test
  int oldLength = structure_getQueueSize(mockQ);
  int oldCapacity = mockQ->capacity;
  structure_enqueue(mockQ, 22);
  int newLength = structure_getQueueSize(mockQ);
  int newCapacity = mockQ->capacity;
  int* newContent = structure_getQueueContent(mockQ);

  CU_ASSERT(newLength == oldLength+1);
  CU_ASSERT(newCapacity == oldCapacity);
  CU_ASSERT(arraysEqual(mockContent,newContent,1,1));
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test adding an element to the queue 2
 */
void test_enqueue2(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  mockQ->capacity = 2;
  int mockContent[] = {4,22};

  // Call function and test
  int oldLength = structure_getQueueSize(mockQ);
  int oldCapacity = mockQ->capacity;
  structure_enqueue(mockQ, 22);
  structure_enqueue(mockQ, 4);
  int newLength = structure_getQueueSize(mockQ);
  int newCapacity = mockQ->capacity;
  int* newContent = structure_getQueueContent(mockQ);

  CU_ASSERT(newLength == oldLength+2);
  CU_ASSERT(newCapacity == oldCapacity);
  CU_ASSERT(arraysEqual(mockContent,newContent,2,2));
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test adding an element to the queue 3
 */
void test_enqueue3(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  mockQ->capacity = 3;
  int mockContent[] = {12,4,22};

  // Call function and test
  int oldLength = structure_getQueueSize(mockQ);
  int oldCapacity = mockQ->capacity;
  structure_enqueue(mockQ, 22);
  structure_enqueue(mockQ, 4);
  structure_enqueue(mockQ, 12);
  int newLength = structure_getQueueSize(mockQ);
  int newCapacity = mockQ->capacity;
  int* newContent = structure_getQueueContent(mockQ);

  CU_ASSERT(newLength == oldLength+3);
  CU_ASSERT(newCapacity == oldCapacity);
  CU_ASSERT(arraysEqual(mockContent,newContent,2,2));
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test removing an element to the queue
 */
void test_dequeue(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  mockQ->capacity = 3;
  structure_enqueue(mockQ, 22);
  structure_enqueue(mockQ, 4);
  structure_enqueue(mockQ, 12);
  int mockContent[] = {12,4};

  // Call function and test
  int oldLength = structure_getQueueSize(mockQ);
  int oldCapacity = mockQ->capacity;
  int elem = structure_dequeue(mockQ);
  int newLength = structure_getQueueSize(mockQ);
  int newCapacity = mockQ->capacity;
  int* newContent = structure_getQueueContent(mockQ);

  CU_ASSERT(newLength == oldLength-1);
  CU_ASSERT(newCapacity == oldCapacity);
  CU_ASSERT(elem == 22);
  CU_ASSERT(arraysEqual(mockContent,newContent,newLength,newLength));
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test the size getter of the queue
 */
void test_getQueueSize(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  mockQ->size = 2;

  // Call function and test
  CU_ASSERT(structure_getQueueSize(mockQ) == 2);
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}

/*
 * \brief Test the content getter of the queue
 */
void test_getQueueContent(void) {
  // Mocks
  queue* mockQ = structure_emptyQueue();
  mockQ->content[0] = 4;
  mockQ->content[1] = 12;
  int mockContent[] = {4,12};

  // Call function and test
  CU_ASSERT(arraysEqual(structure_getQueueContent(mockQ),mockContent,2,2));
  
  // Free everything
  free(mockQ->content);
  free(mockQ);
}
