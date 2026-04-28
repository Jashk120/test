```javascript
/**
 * Fetches a user record from the API by their unique identifier.
 *
 * @param userId - The unique identifier of the user.
 * @returns A promise resolving to the user object.
 */
async function fetchUser(userId) {
    const response = await fetch(`/api/users/${userId}`);
    return response.json();
}

/**
 * Creates a new user with the provided name and email.
 *
 * @param name - The name of the new user.
 * @param email - The email address of the new user.
 * @returns A promise resolving to the created user object.
 */
async function createUser(name, email) {
    const response = await fetch('/api/users', {
        method: 'POST',
        body: JSON.stringify({ name, email })
    });
    return response.json();
}
```