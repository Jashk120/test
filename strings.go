```go
package main

import "strings"

// reverseString reverses the input string, handling Unicode characters correctly.
func reverseString(s string) string {
    runes := []rune(s)
    for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
        runes[i], runes[j] = runes[j], runes[i]
    }
    return string(runes)
}

// isPalindrome checks whether the given string is a palindrome, ignoring case.
func isPalindrome(s string) bool {
    s = strings.ToLower(s)
    return s == reverseString(s)
}
```