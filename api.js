async function fetchUser(userId) {
    const response = await fetch(`/api/users/${userId}`);
    return response.json();
}
//yo ho ho ho ho ho ho ho ho ho ho ho ho 
async function createUser(name, email) {
    const response = await fetch('/api/users', {
        method: 'POST',
        body: JSON.stringify({ name, email })
    });
    return response.json();
}
