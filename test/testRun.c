#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "structureTest.c"

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
  
  // Run tests
  CU_basic_run_tests();
  CU_basic_show_failures(CU_get_failure_list());
  CU_cleanup_registry();

  return 0;
}
