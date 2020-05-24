#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "structureTest.c"
#include "cardTest.c"

int main() {
  // Create registery
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  
  CU_pSuite psuite = NULL;
  // Create the test suit for structure module
  psuite = CU_add_suite("structure_tests", NULL, NULL);
  if (NULL == psuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  // Add tests to the structure_tests suite
  if ((NULL == CU_add_test(psuite, "emptyCardList", test_emptyCardList)) ||
      (NULL == CU_add_test(psuite, "getCardListLength", test_getCardListLength)) ||
      (NULL == CU_add_test(psuite, "addCardCardList", test_addCardCardList)) ||
      (NULL == CU_add_test(psuite, "getCardListContent", test_getCardListContent)) ||
      (NULL == CU_add_test(psuite, "removeLastCardCardList", test_removeCardCardList_lastCard)) ||
      (NULL == CU_add_test(psuite, "removeMiddleCardCardList", test_removeCardCardList_notLastCard)) ||
      (NULL == CU_add_test(psuite, "searchCardInList", test_searchCardList_cardInList)) ||
      (NULL == CU_add_test(psuite, "emptyQueue", test_emptyQueue)) ||
      (NULL == CU_add_test(psuite, "getQueueContent", test_getQueueContent)) ||
      (NULL == CU_add_test(psuite, "getQueueSize", test_getQueueSize)) ||
      (NULL == CU_add_test(psuite, "enqueue1", test_enqueue1)) ||
      (NULL == CU_add_test(psuite, "enqueue2", test_enqueue2)) ||
      (NULL == CU_add_test(psuite, "enqueue3", test_enqueue3)) ||
      (NULL == CU_add_test(psuite, "dequeue", test_dequeue)) ||
      (NULL == CU_add_test(psuite, "isEmptyQueueEmpty", test_isEmptyQueue_empty)) ||
      (NULL == CU_add_test(psuite, "isEmptyQueueNotEmpty", test_isEmptyQueue_notEmpty)) ||
      (NULL == CU_add_test(psuite, "isFullQueueFull", test_isFullQueue_full)) ||
      (NULL == CU_add_test(psuite, "isFullQueueNotFull", test_isFullQueue_notFull)) )
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  
  psuite = NULL;
  // Create the test suit for card module
  psuite = CU_add_suite("card_tests", cardtest_setup, cardtest_teardown);
  if (NULL == psuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }
  // Add tests to the structure_tests suite
  if ((NULL == CU_add_test(psuite, "getCost", test_getCost)) ||
      (NULL == CU_add_test(psuite, "getType", test_getType)) ||
      (NULL == CU_add_test(psuite, "getAA1", test_getAA1)) ||
      (NULL == CU_add_test(psuite, "getAA2", test_getAA2)) ||
      (NULL == CU_add_test(psuite, "getAE1", test_getAE1)) ||
      (NULL == CU_add_test(psuite, "getAE2", test_getAE2)) ||
      (NULL == CU_add_test(psuite, "getRA1", test_getRA1)) ||
      (NULL == CU_add_test(psuite, "getRA2", test_getRA2)) ||
      (NULL == CU_add_test(psuite, "getRE1", test_getRE1)) ||
      (NULL == CU_add_test(psuite, "getRE2", test_getRE2)) ||
      (NULL == CU_add_test(psuite, "getADD", test_getADD)) ||
      (NULL == CU_add_test(psuite, "getRDD", test_getRDD)) ||
      (NULL == CU_add_test(psuite, "getDR)", test_getDR)) ||
      (NULL == CU_add_test(psuite, "getE", test_getE)) )
  {
    CU_cleanup_registry();
    return CU_get_error();
  }
  
  // Run tests
  CU_basic_run_tests();
  CU_basic_show_failures(CU_get_failure_list());
  CU_cleanup_registry();

  return 0;
}
