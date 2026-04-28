fn factorial(n: u64) -> u64 {
    if n == 0 {
        return 1;
    }
    n * factorial(n - 1)
}

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
