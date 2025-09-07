# SIMD-Accelerated Vector Math Library
## Overview
This library provides a set of SIMD-accelerated routines for performing vector mathematics on x86 architectures. It is implemented in x86 assembly to leverage the power of SIMD (Single Instruction, Multiple Data) instructions, offering significant performance improvements for vector operations.

## Features
- **High Performance:** Leverages SIMD instructions(SSE) to perform vector math operations efficiently.
- **Assembly Optimization:** Written in x86 assembly for maximum control over instruction usage and performance.
- **Wide Range of Operations:** Includes basic operations like addition, subtraction, multiplication, and dot product, as well as more complex functions like vector normalization.
- **Supports Various Data Types:** Handles vectors with different data types, including 32-bit and 64-bit floating-point numbers.

## Building
```bash
make
```
## Usage
```C
#include <stdio.h>
#include <stdlib.h>
#include "vml.h"

int main(int argc, char** argv) {
    float v1[] = {1, 3, 5, 7, 9};
    float v2[] = {2, 4, 6, 8, 10};
    float result[5];

    unsigned int size = sizeof(v1)/sizeof(float);
    
    _vec_add(result, v1, v2, size);
 
    for (int i = 0; i < size; i++) {
        printf("%f\n", result[i]);
    }

    return 0;
}
```
## Benchmark
```bash
➜  bin git:(main) ✗ ./benchmark
No SIMD: 0.000004s
SIMD: 0.000002s
```

## Contributing
Contributions are welcome! Please submit a pull request or open an issue to discuss changes.

## License
This project is licensed under the LGPL-3.0 License. See the LICENSE file for details.


