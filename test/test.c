#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "minic.h"
#include "vml.h"

static float v1[] = {3.0, 7.0, 9.0, 10.0};
static float v2[] = {2.0, 4.0, 8.0, 5.0};

TEST_FUNC(_vec_add) {
    float result[4];
  
    _vec_add(result, v1, v2, 4);

    EXPECT_FLOAT_EQ(result[0], 5.0f);
    EXPECT_FLOAT_EQ(result[1], 11.0f);
    EXPECT_FLOAT_EQ(result[2], 17.0f);
    EXPECT_FLOAT_EQ(result[3], 15.0f);
}

TEST_FUNC(_vec_add_odd) {
    float result[5];
    float v_1[] = {3.0, 7.0, 9.0, 10.0, 12.0};
    float v_2[] = {2.0, 4.0, 8.0, 5.0, 6.0};
    
    _vec_add(result, v_1, v_2, 5);

    EXPECT_FLOAT_EQ(result[0], 5.0f);
    EXPECT_FLOAT_EQ(result[1], 11.0f);
    EXPECT_FLOAT_EQ(result[2], 17.0f);
    EXPECT_FLOAT_EQ(result[3], 15.0f);
    EXPECT_FLOAT_EQ(result[4], 18.0f);
}

TEST_FUNC(_vec_sub) {
    float result[4];
    
    _vec_sub(result, v1, v2, 4);

    EXPECT_FLOAT_EQ(result[0], 1.0f);
    EXPECT_FLOAT_EQ(result[1], 3.0f);
    EXPECT_FLOAT_EQ(result[2], 1.0f);
    EXPECT_FLOAT_EQ(result[3], 5.0f);
}

TEST_FUNC(_vec_mul) {
    float result[4];
    
    _vec_mul(result, v1, v2, 4);

    EXPECT_FLOAT_EQ(result[0], 6.0f);
    EXPECT_FLOAT_EQ(result[1], 28.0f);
    EXPECT_FLOAT_EQ(result[2], 72.0f);
    EXPECT_FLOAT_EQ(result[3], 50.0f);
}

TEST_FUNC(_vec_div) {
    float result[4];
    
    _vec_div(result, v1, v2, 4);

    EXPECT_FLOAT_EQ(result[0], 1.5f);
    EXPECT_FLOAT_EQ(result[1], 1.75f);
    EXPECT_FLOAT_EQ(result[2], 1.125f);
    EXPECT_FLOAT_EQ(result[3], 2.0f);
}

TEST_FUNC(_vec_max) {
    float result[4];
    
    _vec_max(result, v1, v2, 4);

    EXPECT_FLOAT_EQ(result[0], 3.0f);
    EXPECT_FLOAT_EQ(result[1], 7.0f);
    EXPECT_FLOAT_EQ(result[2], 9.0f);
    EXPECT_FLOAT_EQ(result[3], 10.0f);
}

TEST_FUNC(_vec_min) {
    float result[4];
    
    _vec_min(result, v1, v2, 4);

    EXPECT_FLOAT_EQ(result[0], 2.0f);
    EXPECT_FLOAT_EQ(result[1], 4.0f);
    EXPECT_FLOAT_EQ(result[2], 8.0f);
    EXPECT_FLOAT_EQ(result[3], 5.0f);
}

TEST_FUNC(_vec_sadd) {
    float result[4];
    
    _vec_sadd(result, v1, 10.0, 4);

    EXPECT_FLOAT_EQ(result[0], 13.0f);
    EXPECT_FLOAT_EQ(result[1], 17.0f);
    EXPECT_FLOAT_EQ(result[2], 19.0f);
    EXPECT_FLOAT_EQ(result[3], 20.0f);
}

TEST_FUNC(_vec_ssub) {
    float result[4];
    
    _vec_ssub(result, v1, 10.0, 4);

    EXPECT_FLOAT_EQ(result[0], -7.0f);
    EXPECT_FLOAT_EQ(result[1], -3.0f);
    EXPECT_FLOAT_EQ(result[2], -1.0f);
    EXPECT_FLOAT_EQ(result[3], 0.0f);
}

TEST_FUNC(_vec_smul) {
    float result[4];
    
    _vec_smul(result, v1, 10.0, 4);

    EXPECT_FLOAT_EQ(result[0], 30.0f);
    EXPECT_FLOAT_EQ(result[1], 70.0f);
    EXPECT_FLOAT_EQ(result[2], 90.0f);
    EXPECT_FLOAT_EQ(result[3], 100.0f);
}

TEST_FUNC(_vec_sdiv) {
    float result[4];
    
    _vec_sdiv(result, v1, 10.0, 4);

    EXPECT_FLOAT_EQ(result[0], 0.3f);
    EXPECT_FLOAT_EQ(result[1], 0.7f);
    EXPECT_FLOAT_EQ(result[2], 0.9f);
    EXPECT_FLOAT_EQ(result[3], 1.0f);
}

TEST_FUNC(_vec_neg) {
    float result[4];
    
    _vec_neg(result, v1, 4);

    EXPECT_FLOAT_EQ(result[0], -3.0f);
    EXPECT_FLOAT_EQ(result[1], -7.0f);
    EXPECT_FLOAT_EQ(result[2], -9.0f);
    EXPECT_FLOAT_EQ(result[3], -10.0f);
}

TEST_FUNC(_vec_abs) {
    float result[4];
    float v[] = {-3.0, -7.0, -9.0, -10.0};
    
    _vec_abs(result, v, 4);

    EXPECT_FLOAT_EQ(result[0], 3.0f);
    EXPECT_FLOAT_EQ(result[1], 7.0f);
    EXPECT_FLOAT_EQ(result[2], 9.0f);
    EXPECT_FLOAT_EQ(result[3], 10.0f);
}

TEST_FUNC(_vec_norm) {
    float result[4];
    
    _vec_norm(result, v1, 4);

    EXPECT_FLOAT_EQ(result[0], 0.194054f);
    EXPECT_FLOAT_EQ(result[1], 0.452792f);
    EXPECT_FLOAT_EQ(result[2], 0.582162f);
    EXPECT_FLOAT_EQ(result[3], 0.646846f);
}

TEST_FUNC(_vec_len) {
    float result;
    
    result = _vec_len(v1, 4);

    EXPECT_FLOAT_EQ(result, 15.4596f);
}

TEST_FUNC(_vec_dot) {
    float result;
    
    result = _vec_dot(v1, v2, 4);

    EXPECT_FLOAT_EQ(result, 156.0f);
}

int main(int argc, char** argv) {
    minic_init_registry();

    minic_suite* add_suite = minic_add_suite("AddSuite");
    minic_suite* test_suite = minic_add_suite("GeneralTestSuite");
    
    minic_add_test(add_suite, "_vec_add", TEST_FUNC_NAME(_vec_add));
    minic_add_test(add_suite, "_vec_add_odd", TEST_FUNC_NAME(_vec_add_odd));
    minic_add_test(test_suite, "_vec_sub", TEST_FUNC_NAME(_vec_sub));
    minic_add_test(test_suite, "_vec_mul", TEST_FUNC_NAME(_vec_mul));
    minic_add_test(test_suite, "_vec_div", TEST_FUNC_NAME(_vec_div));
    minic_add_test(test_suite, "_vec_max", TEST_FUNC_NAME(_vec_max));
    minic_add_test(test_suite, "_vec_min", TEST_FUNC_NAME(_vec_min));
    minic_add_test(test_suite, "_vec_sadd", TEST_FUNC_NAME(_vec_sadd));
    minic_add_test(test_suite, "_vec_ssub", TEST_FUNC_NAME(_vec_ssub));
    minic_add_test(test_suite, "_vec_smul", TEST_FUNC_NAME(_vec_smul));
    minic_add_test(test_suite, "_vec_sdiv", TEST_FUNC_NAME(_vec_sdiv));
    minic_add_test(test_suite, "_vec_neg", TEST_FUNC_NAME(_vec_neg));
    minic_add_test(test_suite, "_vec_abs", TEST_FUNC_NAME(_vec_abs));
    minic_add_test(test_suite, "_vec_norm", TEST_FUNC_NAME(_vec_norm));
    minic_add_test(test_suite, "_vec_len", TEST_FUNC_NAME(_vec_len));
    minic_add_test(test_suite, "_vec_dot", TEST_FUNC_NAME(_vec_dot));

    printf("Running tests...\n");
    minic_run_all_tests();
    
    minic_cleanup_registry();

    return 0;
}




