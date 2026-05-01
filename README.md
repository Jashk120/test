# Multi-Language Utility Monorepo

## Overview

This repository contains a collection of independent, self-contained utility modules and data structures. Each module is implemented in a different programming language (Java, JavaScript, Python, C, Rust, Go) and follows that language’s idiomatic conventions. There are no cross-module dependencies, making each reusable individually or as a language-specific reference.

## Features

| Module (File) | Language | Description |
|---|---|---|
| `Queue.java` | Java | FIFO integer queue backed by `LinkedList`. |
| `api.js` | JavaScript | Async HTTP client for fetching/creating user records. |
| `auth.py` | Python | SHA-256 password hashing and verification. |
| `calculator.c` | C | Basic integer arithmetic (add, subtract, divide). |
| `math.rs` | Rust | Factorial and primality testing. |
| `strings.go` | Go | Unicode-safe string reversal and palindrome check. |
| `utils.py` | Python | Numeric helpers (add, multiply, divide with zero‑division check). |

## File Structure

```
Queue.java
api.js
auth.py
calculator.c
math.rs
strings.go
utils.py
```

## Usage

Below are complete, runnable examples for each module. Each example assumes the corresponding source file is in the same directory.

### Java (Queue.java)

`TestQueue.java` – a small driver that demonstrates the Queue class.

```java
// TestQueue.java
import java.util.NoSuchElementException;

public class TestQueue {
    public static void main(String[] args) {
        Queue q = new Queue();
        System.out.println("Empty? " + q.isEmpty());   // true

        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);

        System.out.println("Dequeued: " + q.dequeue()); // 10
        System.out.println("Dequeued: " + q.dequeue()); // 20
        System.out.println("Empty? " + q.isEmpty());   // false
        System.out.println("Dequeued: " + q.dequeue()); // 30
        System.out.println("Empty? " + q.isEmpty());   // true

        // Uncommenting the next line would throw NoSuchElementException
        // q.dequeue();
    }
}
```

Compile and run:

```bash
javac Queue.java TestQueue.java
java TestQueue
```

### JavaScript (api.js)

A Node.js script that uses the exported functions.

```javascript
// test-api.js (requires Node.js 18+ for fetch)
import { fetchUser, createUser } from './api.js';

async function main() {
    // Fetch a user (replace with actual endpoint)
    try {
        const user = await fetchUser(1);
        console.log('Fetched user:', user);
    } catch (err) {
        console.error('Fetch error:', err.message);
    }

    // Create a new user
    try {
        const newUser = await createUser('Alice', 'alice@example.com');
        console.log('Created user:', newUser);
    } catch (err) {
        console.error('Create error:', err.message);
    }
}

main();
```

Run:

```bash
node test-api.js
```

### Python – auth.py

A script that demonstrates password hashing and verification.

```python
# test_auth.py
from auth import hash_password, verify_password

password = "mySecureP@ssw0rd"
hashed = hash_password(password)
print("Hash:", hashed)

# Correct password
print("Verified:", verify_password(password, hashed))   # True

# Wrong password
print("Wrong:", verify_password("wrong", hashed))       # False
```

Run:

```bash
python test_auth.py
```

### Python – utils.py

A script that exercises the numeric utilities.

```python
# test_utils.py
from utils import add, multiply, divide

print("add(5, 3):", add(5, 3))               # 8
print("multiply(4, 7):", multiply(4, 7))     # 28
print("divide(10, 3):", divide(10, 3))       # 3.333...
try:
    divide(10, 0)
except ValueError as e:
    print("Error:", e)                        # Error: Cannot divide by zero
```

Run:

```bash
python test_utils.py
```

### C (calculator.c)

A complete C program that uses the calculator functions.

```c
// test_calculator.c
#include <stdio.h>
#include "calculator.c"   // or compile separately and link

int main() {
    int a = 10, b = 3;
    printf("add(%d, %d) = %d\n", a, b, add(a, b));
    printf("subtract(%d, %d) = %d\n", a, b, subtract(a, b));
    printf("divide(%d, %d) = %.2f\n", a, b, divide(a, b));

    // division by zero
    float result = divide(a, 0);
    printf("divide(%d, 0) = %.2f (error sentinel)\n", a, result);
    return 0;
}
```

Compile and run:

```bash
gcc test_calculator.c -o test_calculator
./test_calculator
```

### Rust (math.rs)

A standalone Rust program that tests the `factorial` and `is_prime` functions.

```rust
// main.rs
mod math;  // assumes math.rs exists

fn main() {
    let n = 7;
    println!("factorial({}) = {}", n, math::factorial(n));
    println!("is_prime({}) = {}", n, math::is_prime(n));

    let m = 10;
    println!("factorial({}) = {}", m, math::factorial(m));
    println!("is_prime({}) = {}", m, math::is_prime(m));
}
```

Run (assuming `rustc` is used):

```bash
rustc math.rs main.rs   # or compile together
./main
```

Alternatively, if you use Cargo, place `math.rs` in `src/` and add `mod math;` in `main.rs`.

### Go (strings.go)

A Go program that illustrates string reversal and palindrome checking.  
Since `strings.go` has `package main` but no `main` function, we add one in a separate file or modify the original. Here we present a complete example using a single file that includes the utility functions and a `main` function.

Create a file `main.go`:

```go
package main

import (
    "fmt"
    "strings"
)

// reverseString reverses a Unicode string.
func reverseString(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}

// isPalindrome checks case-insensitively if s is a palindrome.
func isPalindrome(s string) bool {
    lower := strings.ToLower(s)
    return lower == reverseString(lower)
}

func main() {
    str := "A man, a plan, a canal, Panama"
    fmt.Printf("Original: %q\n", str)
    fmt.Printf("Reversed: %q\n", reverseString(str))
    fmt.Printf("Is palindrome? %v\n", isPalindrome(str))

    str2 := "Hello"
    fmt.Printf("\nOriginal: %q\n", str2)
    fmt.Printf("Reversed: %q\n", reverseString(str2))
    fmt.Printf("Is palindrome? %v\n", isPalindrome(str2))
}
```

If you prefer to keep `strings.go` as the original (without `main`), you can compile both files together:

```bash
go run strings.go main.go
```

Or build:

```bash
go build -o test_strings strings.go main.go
./test_strings
```

## Setup

Each module requires its respective language runtime or compiler. No external dependencies beyond the standard library are needed (exception: `api.js` requires Node.js 18+ for the built-in `fetch`).

- **Java**: JDK 8 or later
- **JavaScript**: Node.js 18+ (for `fetch`) or any modern browser
- **Python**: Python 3.x
- **C**: C99 or later compiler (e.g., GCC, Clang)
- **Rust**: Rust 2018 edition or later (use `rustc` or Cargo)
- **Go**: Go 1.x

## Notes

- All modules are designed to be used as libraries. The Java, C, Rust, and Go examples provided above include driver code to demonstrate usage.
- The C `divide` function returns `-1.0` when the divisor is zero as an error sentinel.
- The Python `utils.py` `divide` function raises a `ValueError` on zero division.
- The Rust `factorial` function returns `u64` and will panic on overflow (for `n > 20`).
- The Go `strings.go` file as provided in the repository does not contain a `main` function. To run it standalone, either add a `main` function or compile it together with a driver as shown in the usage example.