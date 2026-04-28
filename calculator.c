/**
 * @brief Adds two integers.
 * @param a First integer to add.
 * @param b Second integer to add.
 * @return The sum of a and b.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * @brief Subtracts two integers.
 * @param a Integer to subtract from.
 * @param b Integer to subtract.
 * @return The result of a minus b.
 */
int subtract(int a, int b) {
    return a - b;
}

/**
 * @brief Divides two integers, returning a float. Returns -1 if divisor is zero.
 * @param a Dividend (numerator).
 * @param b Divisor (denominator).
 * @return The quotient as a float, or -1 if b is zero.
 */
float divide(int a, int b) {
    if (b == 0) return -1;
    return (float)a / b;
}