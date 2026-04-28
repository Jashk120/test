```rust
/// Computes the factorial of a non-negative integer.
///
/// The factorial of a number n is the product of all positive integers less than or equal to n.
/// This function uses recursion to compute the result.
///
/// # Arguments
/// * `n` - The non-negative integer to compute the factorial of.
///
/// # Returns
/// * `u64` - The factorial of n. For n = 0, returns 1.
fn factorial(n: u64) -> u64 {
    if n == 0 {
        return 1;
    }
    n * factorial(n - 1)
}

/// Determines whether a given number is a prime number.
///
/// A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.
/// This function checks divisibility from 2 up to the square root of n.
///
/// # Arguments
/// * `n` - The number to check for primality.
///
/// # Returns
/// * `bool` - `true` if n is prime, `false` otherwise.
fn is_prime(n: u64) -> bool {
    if n < 2 {
        return false;
    }
    for i in 2..=(n as f64).sqrt() as u64 {
        if n % i == 0 {
            return false;
        }
    }
    true
}
```