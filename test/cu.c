#include "cu.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    CUSuite* pSuite;
} CURegistry;

static CURegistry registry;

void cuRunTests() {
    for (size_t i = 0; i < registry.pSuite->count; i++) {
        registry.pSuite->tests[i]();
    }

    printf("All tests passed!\n");
}

CUSuite* cuAddSuite() {
    registry.pSuite = malloc(sizeof(CUSuite));
    registry.pSuite->count = 0;
    registry.pSuite->capacity = 2;

    registry.pSuite->tests = malloc(registry.pSuite->capacity * sizeof(test_func));
    if (!registry.pSuite->tests) {
        fprintf(stderr, "malloc failed");
        return NULL;
    }

    return registry.pSuite;
}

void cuAddTest(CUSuite* suite, test_func fptr) {
    if (suite->count == suite->capacity) {
        suite->capacity *= 2;
        suite->tests = realloc(suite->tests, suite->capacity * sizeof(test_func));
        
        if (!suite->tests) {
            fprintf(stderr, "realloc failed");
            return;
        }
    }

    suite->tests[suite->count++] = fptr;
}

void cuCleanupRegistry() {
    free (registry.pSuite->tests);
    free (registry.pSuite);
}