```c
/**
 * @brief Adds two integers.
 *
 * This function takes two integer arguments and returns their sum.
 *
 * @param a The first integer to add.
 * @param b The second integer to add.
 * @return The sum of a and b.
 */
int add(int a, int b) {
    return a + b;
}

/**
 * @brief Subtracts two integers.
 *
 * This function subtracts the second integer from the first and returns the result.
 *
 * @param a The integer to subtract from.
 * @param b The integer to subtract.
 * @return The result of a minus b.
 */
int subtract(int a, int b) {
    return a - b;
}

/**
 * @brief Divides two integers.
 *
 * This function divides the first integer by the second and returns a float result.
 * If the divisor is zero, the function returns -1 to indicate an error.
 *
 * @param a The dividend.
 * @param b The divisor.
 * @return The float result of a divided by b, or -1 if b is zero.
 */
float divide(int a, int b) {
    if (b == 0) return -1;
    return (float)a / b;
}
```