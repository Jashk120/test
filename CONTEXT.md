```markdown
# CONTEXT.md

## Repository Overview

This repository contains a collection of small, independent utility modules and data structures implemented across multiple programming languages. Each file provides standalone functionality with no interdependencies between them.

## Architecture

The codebase follows a **polyglot micro-utility** pattern—each file is a self-contained module that solves a specific problem. There is no overarching application framework or shared infrastructure. The modules are organized by programming language (Java, JavaScript, Python, C, Rust, Go).

## Module Breakdown

| File | Language | Purpose |
|------|----------|---------|
| `Queue.java` | Java | Generic FIFO integer queue using LinkedList |
| `api.js` | JavaScript | REST API client functions (`fetchUser`, `createUser`) |
| `auth.py` | Python | Password hashing and verification using SHA-256 |
| `calculator.c` | C | Basic arithmetic operations (add, subtract, divide) |
| `math.rs` | Rust | Factorial calculation and prime number checking |
| `strings.go` | Go | String manipulation (reverse, palindrome check) |
| `utils.py` | Python | General math utilities (add, multiply, divide with error handling) |

## Setup Assumptions

- **Java**: Requires Java JDK 8+ and a standard compiler (`javac Queue.java`).
- **JavaScript**: Intended for Node.js or browser environments with `fetch` API support.
- **Python**: Python 3.x required. `auth.py` and `utils.py` rely only on the standard library (`hashlib`).
- **C**: Needs a C compiler (e.g., GCC). Functions are standalone and can be compiled into a library.
- **Rust**: Requires Rust toolchain (rustc/Cargo). File is likely part of a larger crate; no external dependencies.
- **Go**: Requires Go 1.x. The `strings.go` file assumes a `main` package. Run with `go run strings.go`.

## Key Flows

### 1. Queue Operations (Java)
- **Enqueue**: `list.addLast(value)` — Adds to tail.
- **Dequeue**: `list.removeFirst()` — Removes from head. Throws `NoSuchElementException` if empty.
- **isEmpty**: Checks `list.isEmpty()`.

### 2. API Interactions (JavaScript)
- **Fetch User**: GET `/api/users/{userId}` → returns JSON.
- **Create User**: POST `/api/users` with `name` and `email` in body → returns created user JSON.

### 3. Password Authentication (Python)
- **Hash**: Uses `hashlib.sha256` to produce a hex digest.
- **Verify**: Compares hash of input password against stored hash.

### 4. Arithmetic (C)
- **add/subtract**: Standard integer operations.
- **divide**: Integer division returning float; returns `-1` if divisor is zero.

### 5. Math Utilities (Rust)
- **factorial**: Recursive computation (n \* factorial(n-1)), returns 1 for n=0.
- **is_prime**: Checks divisibility up to `sqrt(n)`. Returns `false` for n < 2.

### 6. String Utilities (Go)
- **reverseString**: Reverses string using rune slicing for Unicode support.
- **isPalindrome**: Case-insensitive check using `strings.ToLower` and reversal.

### 7. General Math (Python)
- **add/multiply**: Standard numeric operations.
- **divide**: Returns float; raises `ValueError` for division by zero.

## Notable Interfaces

### Public API Signatures

| Module | Function | Input | Output |
|--------|----------|-------|--------|
| `Queue` | `enqueue(int)` | Integer | void |
| `Queue` | `dequeue()` | None | Integer (throws if empty) |
| `Queue` | `isEmpty()` | None | boolean |
| `api.js` | `fetchUser(userId)` | string/number | Promise<Object> |
| `api.js` | `createUser(name, email)` | string, string | Promise<Object> |
| `auth.py` | `hash_password(password)` | string | string (hex) |
| `auth.py` | `verify_password(password, hashed)` | string, string | bool |
| `calculator.c` | `add(int, int)` | int, int | int |
| `calculator.c` | `subtract(int, int)` | int, int | int |
| `calculator.c` | `divide(int, int)` | int, int | float |
| `math.rs` | `factorial(u64)` | u64 | u64 |
| `math.rs` | `is_prime(u64)` | u64 | bool |
| `strings.go` | `reverseString(string)` | string | string |
| `strings.go` | `isPalindrome(string)` | string | bool |
| `utils.py` | `add(a, b)` | int/float, int/float | int/float |
| `utils.py` | `multiply(a, b)` | int/float, int/float | int/float |
| `utils.py` | `divide(a, b)` | int/float, int/float | float (raises ValueError) |

## Error Handling Notes

- **Queue.dequeue()**: Unchecked exception on empty queue (Java).
- **calculator.c divide()**: Returns `-1` for zero divisor (non-standard behavior).
- **utils.py divide()**: Raises `ValueError` on zero divisor (Pythonic).
- **math.rs**: No error handling; `factorial` will overflow for large n (>20).
- **strings.go**: Reverse function handles Unicode correctly via rune conversion.

## Dependencies

- **Python**: `hashlib` (standard library)
- **Go**: `strings` (standard library)
- **All other modules**: Zero external dependencies; only language standard library/features.
```