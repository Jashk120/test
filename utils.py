```python
def add(a, b):
    """
    Adds two numbers together.

    Args:
        a: The first number.
        b: The second number.

    Returns:
        The sum of a and b.
    """
    return a + b

def multiply(a, b):
    """
    Multiplies two numbers together.

    Args:
        a: The first number.
        b: The second number.

    Returns:
        The product of a and b.
    """
    return a * b

def divide(a, b):
    """
    Divides the first number by the second number.

    Args:
        a: The numerator.
        b: The denominator.

    Returns:
        The quotient of a divided by b.

    Raises:
        ValueError: If b is zero, division by zero is not allowed.
    """
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b
```