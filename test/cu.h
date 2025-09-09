#ifndef CU_H
#define CU_H

#include <stddef.h>

#define EPSILON 0.0001

#define ASSERT_EQUAL(result, expected, func_name) \
    do { \
        if (fabs((result) - (expected)) >= EPSILON) { \
            fprintf(stderr, "%s failed: expected %f, got %f\n", func_name, expected, result); \
            exit(EXIT_FAILURE); \
        } else { \
            printf("%s passed.\n", func_name); \
        } \
    } while (0)

#define TEST_FUNC_NAME(name) test_##name
#define TEST_FUNC(name) void TEST_FUNC_NAME(name)()

typedef void (*test_func)(); 

typedef struct {
    size_t count;
    size_t capacity;
    test_func* tests;
} CUSuite;

void cuRunTests();
CUSuite* cuAddSuite();
void cuAddTest(CUSuite* suit, test_func fptr);
void cuCleanupRegistry();

#endif