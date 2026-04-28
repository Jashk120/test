```rust
/// Computes the factorial of a non-negative integer.
///
/// # Arguments
/// * `n` - The non-negative integer to compute the factorial of.
///
/// # Returns
/// * `u64` - The factorial result. Returns 1 if `n` is 0.
fn factorial(n: u64) -> u64 {
    if n == 0 {
        return 1;
    }
    n * factorial(n - 1)
}

/// Determines whether a given number is prime.
///
/// # Arguments
/// * `n` - The number to check for primality.
///
/// # Returns
/// * `bool` - `true` if the number is prime, `false` otherwise.
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