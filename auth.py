```python
def hash_password(password):
    """
    Hashes a password using SHA-256.

    Args:
        password (str): The plaintext password to hash.

    Returns:
        str: The hexadecimal digest of the SHA-256 hash.
    """
    import hashlib
    return hashlib.sha256(password.encode()).hexdigest()

def verify_password(password, hashed):
    """
    Verifies a password against a stored hash by comparing their SHA-256 digests.

    Args:
        password (str): The plaintext password to verify.
        hashed (str): The stored hash to compare against.

    Returns:
        bool: True if the password's hash matches the stored hash, False otherwise.
    """
    return hash_password(password) == hashed
```