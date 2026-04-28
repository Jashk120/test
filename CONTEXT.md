# CONTEXT.md

## Repository Overview

This repository (`Jashk120/test`) contains a collection of utility functions and data structures implemented across multiple programming languages. The codebase serves as a learning/reference repository demonstrating basic algorithms, data structures, and API patterns.

## Architecture

The repository is organized by language and functionality, with no overarching framework or runtime dependency. Each file is self-contained and can be used independently.

### Language Breakdown
- **Java**: Data structures (Queue)
- **JavaScript**: API client functions
- **Python**: Authentication utilities and math operations
- **C**: Basic arithmetic operations
- **Rust**: Mathematical functions (factorial, prime checking)

## Modules

### 1. Java Queue (`Queue.java`)
- **Purpose**: FIFO integer queue implementation
- **Dependencies**: None external (uses `java.util.LinkedList`)
- **Interface**:
  - `enqueue(int value)` – Adds element to end
  - `dequeue()` – Removes and returns front element (throws `NoSuchElementException` if empty)
  - `isEmpty()` – Returns queue emptiness status

### 2. JavaScript API Client (`api.js`)
- **Purpose**: User management API interaction
- **Dependencies**: Browser `fetch` API (assumes modern JavaScript runtime)
- **Functions**:
  - `fetchUser(userId)` – GET request to `/api/users/{userId}`
  - `createUser(name, email)` – POST request to `/api/users`
- **Assumptions**: API server running on same origin; responses are JSON

### 3. Python Authentication (`auth.py`)
- **Purpose**: Password hashing and verification
- **Dependencies**: `hashlib` (standard library)
- **Key Functions**:
  - `hash_password(password)` – Returns SHA-256 hex digest
  - `verify_password(password, hash)` – Returns boolean comparison result
- **Security Note**: Uses basic SHA-256 without salting (not production-ready)

### 4. C Calculator (`calculator.c`)
- **Purpose**: Basic integer arithmetic
- **Functions**:
  - `int add(int a, int b)` – Sum of two integers
  - `int subtract(int a, int b)` – Difference of two integers
  - `float divide(int a, int b)` – Returns `-1` on division by zero

### 5. Rust Math Utilities (`math.rs`)
- **Purpose**: Number theory functions
- **Functions**:
  - `factorial(n: u64) -> u64` – Recursive factorial (returns 1 for n=0)
  - `is_prime(n: u64) -> bool` – Primality test with sqrt optimization

### 6. Python Utility Functions (`utils.py`)
- **Purpose**: General math operations with error handling
- **Functions**:
  - `add(a, b)` – Addition (int/float)
  - `multiply(a, b)` – Multiplication (int/float)
  - `divide(a, b)` –