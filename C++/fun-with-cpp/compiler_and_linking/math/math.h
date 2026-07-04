/*
 * [ Learn Header Guard ]:
 *                       Including header into a C++ file, means copying the contents of the header file into the source file. But if we include the same header twice,
 *                       Means, the contents will be copied twice, leading to duplicate definitions, which can cause compilation errors.
 *
 * 🔶 That's why we use header guards to prevent this, there are two ways to do it:
 *      1. Using older C++ style header guards (using `#ifndef`, `#define`, and `#endif`)
 *      2. Using newer C++ style header guards (using `#pragma once`)
 */
#pragma once

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
