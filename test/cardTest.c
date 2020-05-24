#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include <stdlib.h>
#include <stdio.h>
#include "utils.c"
#include "../headers/card.h"

int cardtest_setup(void) {
  card_setTables(DECKCARDS, DECKCARDSCOUNT);
  return 0;
}

int cardtest_teardown(void) {
  //Free the cards list
  for (int i=0; i<31; i++)
    free(DECKCARDS[i]);
  return 0;
}
/* 
 * \brief Test the cost getter of a card
 */
void test_getCost(void){
  // Mocks
  int mockVal = 15;

  // Call function and test
  CU_ASSERT(card_getCost(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the type getter of a card
 */
void test_getType(void){
  // Mocks
  type mockVal = PERSONNEL;

  // Call function and test
  CU_ASSERT(card_getType(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the AE1 getter of a card
 */
void test_getAE1(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getAE1(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the AE2 getter of a card
 */
void test_getAE2(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getAE2(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the AA1 getter of a card
 */
void test_getAA1(void){
  // Mocks
  int mockVal = 2;

  // Call function and test
  CU_ASSERT(card_getAA1(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the AA2 getter of a card
 */
void test_getAA2(void){
  // Mocks
  int mockVal = 2;

  // Call function and test
  CU_ASSERT(card_getAA2(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the RE1 getter of a card
 */
void test_getRE1(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getRE1(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the RE2 getter of a card
 */
void test_getRE2(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getRE2(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the RA1 getter of a card
 */
void test_getRA1(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getRA1(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the RA2 getter of a card
 */
void test_getRA2(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getRA2(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the ADD getter of a card
 */
void test_getADD(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getADD(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the RDD getter of a card
 */
void test_getRDD(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getRDD(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the DR getter of a card
 */
void test_getDR(void){
  // Mocks
  int mockVal = 0;

  // Call function and test
  CU_ASSERT(card_getDR(18) == mockVal);
  
  // Free everything
}

/* 
 * \brief Test the E getter of a card
 */
void test_getE(void){
  // Mocks
  int mockVal = 1;

  // Call function and test
  CU_ASSERT(card_getE(18) == mockVal);
  
  // Free everything
}

