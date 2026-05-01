```python
def hash_password(password):
    """
    Hashes a plaintext password using SHA-256.

    Args:
        password (str): The plaintext password to hash.

    Returns:
        str: The SHA-256 hexadecimal digest of the encoded password.
    """
    import hashlib
    return hashlib.sha256(password.encode()).hexdigest()


def verify_password(password, hashed):
    """
    Verifies a plaintext password against a stored SHA-256 hash.

    Args:
        password (str): The plaintext password to check.
        hashed (str): The stored hash to compare against.

    Returns:
        bool: True if the password matches the hash, False otherwise.
    """
    return hash_password(password) == hashed
```