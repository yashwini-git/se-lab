#include "arithmetic.h" 
#include <CUnit/Basic.h> 
void test_add(void) { 
CU_ASSERT_EQUAL(add(2, 3), 5); 
CU_ASSERT_EQUAL(add(-1, 1), 0); 
CU_ASSERT_EQUAL(add(-1, -1), -2); 
} 
void test_subtract(void) { 
CU_ASSERT_EQUAL(subtract(5, 3), 2); 
CU_ASSERT_EQUAL(subtract(3, 5), -2); 
CU_ASSERT_EQUAL(subtract(0, 0), 0); 
} 
void test_multiply(void) { 
CU_ASSERT_EQUAL(multiply(2, 3), 6); 
CU_ASSERT_EQUAL(multiply(-2, 3), -6); 
CU_ASSERT_EQUAL(multiply(0, 5), 0); 
} 
void test_divide(void) { 
CU_ASSERT_EQUAL(divide(6, 3), 2); 
CU_ASSERT_EQUAL(divide(10, 2), 5); 
CU_ASSERT_EQUAL(divide(5, 2), 2);  // Integer division 
CU_ASSERT_EQUAL(divide(5, 0), 0);  // Test division by zero 
} 
int main(void) { 
CU_pSuite suite = NULL; 
if (CUE_SUCCESS != CU_initialize_registry()) { 
return CU_get_error(); 
} 
suite = CU_add_suite("Arithmetic Suite", NULL, NULL); 
if (NULL == suite) { 
CU_cleanup_registry(); 
return CU_get_error(); 
} 
if ((NULL == CU_add_test(suite, "test of add()", test_add)) || 
(NULL == CU_add_test(suite, "test of subtract()", test_subtract)) || 
(NULL == CU_add_test(suite, "test of multiply()", test_multiply)) || 
(NULL == CU_add_test(suite, "test of divide()", test_divide))) { 
CU_cleanup_registry(); 
return CU_get_error(); 
} 
CU_basic_set_mode(CU_BRM_VERBOSE);  // Or CU_BRM_NORMAL 
CU_basic_run_tests(); 
CU_cleanup_registry(); 
return CU_get_error();