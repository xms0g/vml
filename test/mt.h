#ifndef MT_H
#define MT_H

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
    const char* name;
    test_func* tests;
} MTSuite;

void mtInitRegistry();
void mtRunAllTests();
void mtRunSuiteTests(const char* name);
MTSuite* mtAddSuite(const char* name);
void mtAddTest(MTSuite* suit, test_func fptr);
void mtCleanupRegistry();

#endif