#include <stdio.h>
#include <time.h>
#include "vml.h"

static double now() {
    return (double)clock() / CLOCKS_PER_SEC * 1e6;
}

int main(int argc, char** argv) {
    double start;

    float v1[] = {3.0, 7.0, 9.0, 10.0, 13.0};
    float v2[] = {2.0, 4.0, 8.0, 5.0, 6.0};
    float result[5];
    
    unsigned int size = sizeof(v1)/sizeof(float);
    
    start = now();
    for (unsigned i = 0; i < size; ++i) {
        result[i] = v1[i] + v2[i];
    }

    printf("No SIMD: %fs\n", now() - start);

    start = clock();
    _vec_add(result, v1, v2, size);

    printf("SIMD: %fs\n", now() - start);
    return 0;
}