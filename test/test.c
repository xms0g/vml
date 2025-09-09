#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "cu.h"
#include "../include/vml.h"

static float v1[] = {3.0, 7.0, 9.0, 10.0};
static float v2[] = {2.0, 4.0, 8.0, 5.0};

TEST_FUNC(_vec_add) {
    float result[4];
    
    _vec_add(result, v1, v2, 4);

    ASSERT_EQUAL(result[0], 5.0, "_vec_add");
    ASSERT_EQUAL(result[1], 11.0, "_vec_add");
    ASSERT_EQUAL(result[2], 17.0, "_vec_add");
    ASSERT_EQUAL(result[3], 15.0, "_vec_add");
}

TEST_FUNC(_vec_sub) {
    float result[4];
    
    _vec_sub(result, v1, v2, 4);

    ASSERT_EQUAL(result[0], 1.0, "_vec_sub");
    ASSERT_EQUAL(result[1], 3.0, "_vec_sub");
    ASSERT_EQUAL(result[2], 1.0, "_vec_sub");
    ASSERT_EQUAL(result[3], 5.0, "_vec_sub");

}

TEST_FUNC(_vec_mul) {
    float result[4];
    
    _vec_mul(result, v1, v2, 4);

    ASSERT_EQUAL(result[0], 6.0, "_vec_mul");
    ASSERT_EQUAL(result[1], 28.0, "_vec_mul");
    ASSERT_EQUAL(result[2], 72.0, "_vec_mul");
    ASSERT_EQUAL(result[3], 50.0, "_vec_mul");
}

TEST_FUNC(_vec_div) {
    float result[4];
    
    _vec_div(result, v1, v2, 4);

    ASSERT_EQUAL(result[0], 1.5, "_vec_div");
    ASSERT_EQUAL(result[1], 1.75, "_vec_div");
    ASSERT_EQUAL(result[2], 1.125, "_vec_div");
    ASSERT_EQUAL(result[3], 2.0, "_vec_div");
}

TEST_FUNC(_vec_max) {
    float result[4];
    
    _vec_max(result, v1, v2, 4);

    ASSERT_EQUAL(result[0], 3.0, "_vec_max");
    ASSERT_EQUAL(result[1], 7.0, "_vec_max");
    ASSERT_EQUAL(result[2], 9.0, "_vec_max");
    ASSERT_EQUAL(result[3], 10.0, "_vec_max");
}

TEST_FUNC(_vec_min) {
    float result[4];
    
    _vec_min(result, v1, v2, 4);

    ASSERT_EQUAL(result[0], 2.0, "_vec_min");
    ASSERT_EQUAL(result[1], 4.0, "_vec_min");
    ASSERT_EQUAL(result[2], 8.0, "_vec_min");
    ASSERT_EQUAL(result[3], 5.0, "_vec_min");
}

TEST_FUNC(_vec_sadd) {
    float result[4];
    
    _vec_sadd(result, v1, 10.0, 4);

    ASSERT_EQUAL(result[0], 13.0, "_vec_sadd");
    ASSERT_EQUAL(result[1], 17.0, "_vec_sadd");
    ASSERT_EQUAL(result[2], 19.0, "_vec_sadd");
    ASSERT_EQUAL(result[3], 20.0, "_vec_sadd");
}

TEST_FUNC(_vec_ssub) {
    float result[4];
    
    _vec_ssub(result, v1, 10.0, 4);

    ASSERT_EQUAL(result[0], -7.0, "_vec_ssub");
    ASSERT_EQUAL(result[1], -3.0, "_vec_ssub");
    ASSERT_EQUAL(result[2], -1.0, "_vec_ssub");
    ASSERT_EQUAL(result[3], 0.0, "_vec_ssub");
}

TEST_FUNC(_vec_smul) {
    float result[4];
    
    _vec_smul(result, v1, 10.0, 4);

    ASSERT_EQUAL(result[0], 30.0, "_vec_smul");
    ASSERT_EQUAL(result[1], 70.0, "_vec_smul");
    ASSERT_EQUAL(result[2], 90.0, "_vec_smul");
    ASSERT_EQUAL(result[3], 100.0, "_vec_smul");
}

TEST_FUNC(_vec_sdiv) {
    float result[4];
    
    _vec_sdiv(result, v1, 10.0, 4);

    ASSERT_EQUAL(result[0], 0.3, "_vec_sdiv");
    ASSERT_EQUAL(result[1], 0.7, "_vec_sdiv");
    ASSERT_EQUAL(result[2], 0.9, "_vec_sdiv");
    ASSERT_EQUAL(result[3], 1.0, "_vec_sdiv");
}

TEST_FUNC(_vec_neg) {
    float result[4];
    
    _vec_neg(result, v1, 4);

    ASSERT_EQUAL(result[0], -3.0, "_vec_neg");
    ASSERT_EQUAL(result[1], -7.0, "_vec_neg");
    ASSERT_EQUAL(result[2], -9.0, "_vec_neg");
    ASSERT_EQUAL(result[3], -10.0, "_vec_neg");
}

TEST_FUNC(_vec_abs) {
    float result[5];
    
    _vec_abs(result, v1, 4);

    ASSERT_EQUAL(result[0], 3.0, "_vec_abs");
    ASSERT_EQUAL(result[1], 7.0, "_vec_abs");
    ASSERT_EQUAL(result[2], 9.0, "_vec_abs");
    ASSERT_EQUAL(result[3], 10.0, "_vec_abs");
}

TEST_FUNC(_vec_norm) {
    float result[4];
    
    _vec_norm(result, v1, 4);

    ASSERT_EQUAL(result[0], 0.194054, "_vec_norm");
    ASSERT_EQUAL(result[1], 0.452792, "_vec_norm");
    ASSERT_EQUAL(result[2], 0.582162, "_vec_norm");
    ASSERT_EQUAL(result[3], 0.646846, "_vec_norm");
}

TEST_FUNC(_vec_len) {
    float result;
    
    result = _vec_len(v1, 4);

    ASSERT_EQUAL(result, 15.4596, "_vec_len");
}

TEST_FUNC(_vec_dot) {
    float result;
    
    result = _vec_dot(v1, v2, 4);

    ASSERT_EQUAL(result, 156.0, "_vec_dot");
}

int main(int argc, char** argv) {
    CUSuite* testSuite = cuAddSuite();
    
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_add));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_sub));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_mul));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_div));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_max));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_min));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_sadd));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_ssub));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_smul));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_sdiv));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_neg));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_abs));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_norm));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_len));
    cuAddTest(testSuite, TEST_FUNC_NAME(_vec_dot));

    
    printf("Running tests...\n");
    cuRunTests();
    
    cuCleanupRegistry();

    return 0;
}




