```markdown
# Repository Context: Jashk120/test

## Architecture Overview

This repository is a **multi-language monorepo** containing a collection of independent utility modules and data structures. Each module is self-contained and implemented in a different programming language (Java, JavaScript, Python, C, Rust, Go). There are no cross-module dependencies; the modules are designed to be reusable individually or as examples of language-specific idioms.

## Modules

| Module (File)         | Language   | Description                                                                 |
|-----------------------|------------|-----------------------------------------------------------------------------|
| `Queue.java`          | Java       | A simple integer queue (FIFO) backed by `LinkedList`.                       |
| `api.js`              | JavaScript | Async API client for fetching/creating user records via HTTP.               |
| `auth.py`             | Python     | SHA-256 password hashing and verification utilities.                        |
| `calculator.c`        | C          | Basic integer arithmetic functions (add, subtract, divide).                |
| `math.rs`             | Rust       | Number theory utilities: factorial and primality testing.                   |
| `strings.go`          | Go         | String manipulation: Unicode-safe reversal and palindrome checking.         |
| `utils.py`            | Python     | General numeric operations: add, multiply, divide (with zero-division check). |

## Setup Assumptions

- **Language Runtimes**: Each module requires its respective runtime/compiler:
  - Java: JDK 8 or later (run with `javac Queue.java && java Queue` – note no main method, used as a library).
  - JavaScript: Node.js (ES6+ module support) – the file exports `fetchUser` and `createUser`.
  - Python: Python 3.x – both `auth.py` and `utils.py` are importable modules.
  - C: A C99 or later compiler (e.g., `gcc -c calculator.c`).
  - Rust: Rust 2018 edition or later (`rustc math.rs` or include in a Cargo project).
  - Go: Go 1.x (`go build strings.go` – note the package is `main` but no `main()` function; for reuse, change package or compile as library).
- **No external dependencies** are required beyond the standard library of each language. (Exception: `api.js` uses the Fetch API, available in modern Node.js 18+ or browsers.)
- **No build system** is assumed; each module can be compiled/run independently.

## Key Flows

### Queue (Java)
- `enqueue(int)` adds an element to the tail.
- `dequeue()` removes and returns the head element. Throws `NoSuchElementException` if empty.
- `isEmpty()` checks emptiness.
- Typical flow: create `Queue`, enqueue a sequence, dequeue and process.

### API Client (JavaScript)
- `fetchUser(userId)`: sends a `GET` request to `/api/users/{userId}` and parses JSON response.
- `createUser(name, email)`: sends a `POST` to `/api/users` with JSON body `{name, email}`.
- Both return Promises that resolve to the user object.

### Password Hashing (Python)
- `hash_password(password)`: returns SHA-256 hex digest of input string.
- `verify_password(password, hashed)`: compares hash of `password` against stored `hashed` string.

### Calculator (C)
- `add(a, b)`: returns `a + b`.
- `subtract(a, b)`: returns `a - b`.
- `divide(a, b)`: returns float division if `b != 0`, else returns `-1` (error sentinel).

### Math (Rust)
- `factorial(n)`: recursive computation of `n!` for `n >= 0`. Returns `u64`.
- `is_prime(n)`: checks primality by trial division up to sqrt(n). Returns `bool`.

### Strings (Go)
- `reverseString(s)`: reverses Unicode string by converting to runes and swapping.
- `isPalindrome(s)`: case-insensitive palindrome check using `reverseString`.

### Utils (Python)
- `add(a, b)`, `multiply(a, b)`: simple arithmetic.
- `divide(a, b)`: float division; raises `ValueError` if `b == 0`.

## Notable Interfaces

| File        | Exposed Interface                                                                 |
|-------------|-----------------------------------------------------------------------------------|
| Queue.java  | `public void enqueue(int)`, `public int dequeue()`, `public boolean isEmpty()`    |
| api.js      | `fetchUser(userId)`, `createUser(name, email)` (both async)                       |
| auth.py     | `hash_password(password) -> str`, `verify_password(password, hashed) -> bool`    |
| calculator.c| `int add(int, int)`, `int subtract(int, int)`, `float divide(int, int)`           |
| math.rs     | `fn factorial(n: u64) -> u64`, `fn is_prime(n: u64) -> bool`                      |
| strings.go  | `func reverseString(s string) string`, `func isPalindrome(s string) bool`          |
| utils.py    | `add(a, b)`, `multiply(a, b)`, `divide(a, b)` (raises ValueError on zero)        |

All interfaces are intentionally minimal and focused, following each language’s conventions (e.g., exceptions, result codes, or type safety).
```