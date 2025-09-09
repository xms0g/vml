#include "mt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t count;
    size_t capacity;
    MTSuite* suites;
} MTRegistry;

static MTRegistry registry;

void mtInitRegistry() {
    registry.count = 0;
    registry.capacity = 2;
    registry.suites = malloc(registry.capacity * sizeof(MTSuite));
}

void mtRunAllTests() {
    for (size_t i = 0; i < registry.count; i++) {
        MTSuite currentSuite = registry.suites[i];
        
        for (size_t j = 0; j < currentSuite.count; j++) {
            currentSuite.tests[j]();
        }
        
    }

    printf("All tests passed!\n");
}

void mtRunSuiteTests(const char* name) {
   for (size_t i = 0; i < registry.count; i++) {
        if (strcmp(registry.suites[i].name, name))
            continue;
        
        for (size_t j = 0; j < registry.suites[i].count; j++) {
            registry.suites[i].tests[j]();
        }

        break;
        
    }
}

MTSuite* mtAddSuite(const char* name) {
    if (registry.count == registry.capacity) {
        registry.capacity *= 2;
        registry.suites = realloc(registry.suites, registry.capacity * sizeof(MTSuite));
        
        if (!registry.suites) {
            fprintf(stderr, "realloc failed");
            return NULL;
        }
    }

    MTSuite suite;
    suite.name = name;
    suite.count = 0;
    suite.capacity = 2;
    
    suite.tests = malloc(suite.capacity * sizeof(test_func));
    if (!suite.tests) {
        fprintf(stderr, "malloc failed");
        return NULL;
    }
    
    size_t idx = registry.count++;
    registry.suites[idx] = suite;

    return &registry.suites[idx];
}

void mtAddTest(MTSuite* suite, test_func fptr) {
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

void mtCleanupRegistry() {
    free (registry.suites->tests);
    free (registry.suites);
}