/**
 * @file test_public_api.c
 * @brief Example Unity test for the public API.
 * @date 2025-11-09
 * @version 1.0
 */

#include "unity.h"
#include "public_api.h"
#include "example.h"

void setUp(void) {}
void tearDown(void) {}

void test_public_function() {
    int result = public_function(2);
    TEST_ASSERT_EQUAL_INT(2, result);
}

void test_internal_process() {
    int result = internal_process(3);
    TEST_ASSERT_EQUAL_INT(3, result);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_public_function);
    RUN_TEST(test_internal_process);

    return UNITY_END();
}
