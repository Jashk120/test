```c
/**
 * @brief Adds two integers.
 * @param a First integer.
 * @param b Second integer.
 * @return The sum of a and b.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * @brief Subtracts two integers.
 * @param a Minuend.
 * @param b Subtrahend.
 * @return The difference a - b.
 */
int subtract(int a, int b) {
    return a - b;
}

/**
 * @brief Divides two integers. Returns -1 if divisor is zero.
 * @param a Dividend.
 * @param b Divisor.
 * @return The floating-point result of a divided by b, or -1 if b is 0.
 */
float divide(int a, int b) {
    if (b == 0) return -1;
    return (float)a / b;
}
```