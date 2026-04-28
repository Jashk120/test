# README.md

## Overview

This repository contains a collection of small, independent utility modules and data structures implemented across multiple programming languages. Each file provides standalone functionality with no interdependencies between them.

## Features

- **Polyglot Micro-Utilities**: Self-contained modules in Java, JavaScript, Python, C, Rust, and Go
- **No Dependencies**: Except for language standard libraries where noted
- **FIFO Queue**: Generic integer queue implementation in Java using LinkedList
- **REST API Client**: JavaScript functions for fetching and creating users
- **Password Hashing**: SHA-256 based password hashing and verification in Python
- **Arithmetic Operations**: Basic math functions in C with error handling for division
- **Math Utilities**: Factorial and prime number checking in Rust
- **String Manipulation**: String reversal and palindrome checking in Go with Unicode support
- **General Math Utilities**: Addition, multiplication, and division with Pythonic error handling

## File Structure

| File | Language | Purpose |
|------|----------|---------|
| `Queue.java` | Java | Generic FIFO integer queue using LinkedList |
| `api.js` | JavaScript | REST API client functions (`fetchUser`, `createUser`) |
| `auth.py` | Python | Password hashing and verification using SHA-256 |
| `calculator.c` | C | Basic arithmetic operations (add, subtract, divide) |
| `math.rs` | Rust | Factorial calculation and prime number checking |
| `strings.go` | Go | String manipulation (reverse, palindrome check) |
| `utils.py` | Python | General math utilities (add, multiply, divide with error handling) |

## Usage

### Queue.java (Java)

```java
import java.util.LinkedList;
import java.util.NoSuchElementException;

public class Queue {
    private LinkedList<Integer> list;

    public Queue() {
        list = new LinkedList<>();
    }

    public void enqueue(int value) {
        list.addLast(value);
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return list.removeFirst();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public static void main(String[] args) {
        Queue queue = new Queue();
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        System.out.println("Dequeued: " + queue.dequeue());
        System.out.println("Is empty? " + queue.isEmpty());
    }
}
```

### api.js (JavaScript)

```javascript
async function fetchUser(userId) {
    const response = await fetch(`/api/users/${userId}`);
    if (!response.ok) {
        throw new Error('Failed to fetch user');
    }
    return response.json();
}

async function createUser(name, email) {
    const response = await fetch('/api/users', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ name, email })
    });
    if (!response.ok) {
        throw new Error('Failed to create user');
    }
    return response.json();
}

// Example usage
async function main() {
    try {
        const user = await fetchUser('123');
        console.log('Fetched user:', user);
        
        const newUser = await createUser('John Doe', 'john@example.com');
        console.log('Created user:', newUser);
    } catch (error) {
        console.error('Error:', error.message);
    }
}

main();
```

### auth.py (Python)

```python
import hashlib

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

def verify_password(password, hashed):
    return hash_password(password) == hashed

# Example usage
if __name__ == "__main__":
    password = "my_secret_password"
    hashed = hash_password(password)
    print("Hashed password:", hashed)
    print("Verification result:", verify_password(password, hashed))
    print("Wrong password check:", verify_password("wrong", hashed))
```

### calculator.c (C)

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

float divide(int a, int b) {
    if (b == 0) {
        return -1.0f;
    }
    return (float)a / b;
}

int main() {
    int x = 10, y = 3;
    printf("add(%d, %d) = %d\n", x, y, add(x, y));
    printf("subtract(%d, %d) = %d\n", x, y, subtract(x, y));
    printf("divide(%d, %d) = %.2f\n", x, y, divide(x, y));
    printf("divide(%d, 0) = %.2f\n", x, divide(x, 0));
    return 0;
}
```

### math.rs (Rust)

```rust
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
    let limit = (n as f64).sqrt() as u64;
    for i in 2..=limit {
        if n % i == 0 {
            return false;
        }
    }
    true
}

fn main() {
    println!("factorial(5) = {}", factorial(5));
    println!("Is 7 prime? {}", is_prime(7));
    println!("Is 10 prime? {}", is_prime(10));
    println!("Is 0 prime? {}", is_prime(0));
    println!("factorial(20) = {}", factorial(20));
}
```

### strings.go (Go)

```go
package main

import (
    "fmt"
    "strings"
)

func reverseString(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}

func isPalindrome(s string) bool {
    lower := strings.ToLower(s)
    return lower == reverseString(lower)
}

func main() {
    original := "hello"
    reversed := reverseString(original)
    fmt.Printf("Reverse of '%s' is '%s'\n", original, reversed)
    fmt.Printf("Is 'racecar' a palindrome? %v\n", isPalindrome("racecar"))
    fmt.Printf("Is 'Hello' a palindrome? %v\n", isPalindrome("Hello"))
    fmt.Printf("Unicode test '日本語': reversed = '%s'\n", reverseString("日本語"))
}
```

### utils.py (Python)

```python
def add(a, b):
    return a + b

def multiply(a, b):
    return a * b

def divide(a, b):
    if b == 0:
        raise ValueError("Division by zero is not allowed")
    return float(a) / b

# Example usage
if __name__ == "__main__":
    print("add(10, 5) =", add(10, 5))
    print("multiply(3, 4) =", multiply(3, 4))
    print("divide(10, 3) =", divide(10, 3))
    
    try:
        divide(10, 0)
    except ValueError as e:
        print("Error:", e)
```

## Setup

### Java
- Requires Java JDK 8+
- Compile: `javac Queue.java`
- Run: `java Queue`

### JavaScript
- Intended for Node.js or browser environments with `fetch` API support
- No additional dependencies required

### Python
- Requires Python 3.x
- `auth.py` and `utils.py` rely only on the standard library (`hashlib` for `auth.py`)
- Run: `python auth.py` or `python utils.py`

### C
- Needs a C compiler (e.g., GCC)
- Compile: `gcc calculator.c -o calculator`
- Run: `./calculator`

### Rust
- Requires Rust toolchain (rustc/Cargo)
- Run with rustc: `rustc math.rs && ./math`
- Or use Cargo in a project

### Go
- Requires Go 1.x
- Run: `go run strings.go`

## Notes

- **Queue.dequeue()**: Throws `NoSuchElementException` (unchecked) on empty queue (Java)
- **calculator.c divide()**: Returns `-1` for zero divisor (non-standard behavior)
- **utils.py divide()**: Raises `ValueError` on zero divisor (Pythonic)
- **math.rs**: No error handling; `factorial` will overflow for values greater than 20
- **strings.go reverseString()**: Handles Unicode correctly via rune conversion
- All modules are standalone with no interdependencies between them
- Only Python (`hashlib`) and Go (`strings`) use standard library imports; all other modules use only built-in language features