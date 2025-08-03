/*
 * Exercise: String Functions Implementation
 * 
 * Implement the following string functions from scratch without using
 * the standard string library functions:
 * 
 * 1. strlen() - Calculate string length
 * 2. strcpy() - Copy string
 * 3. strcat() - Concatenate strings
 * 4. strcmp() - Compare strings
 * 5. strrev() - Reverse string
 * 6. isPalindrome() - Check if string is palindrome
 * 
 * Requirements:
 * - Implement all functions from scratch
 * - Handle edge cases (null pointers, empty strings)
 * - Use proper memory management
 * - Test with various input strings
 * 
 * Example Output:
 * Original string: "Hello"
 * Length: 5
 * Copied string: "Hello"
 * Concatenated: "Hello World"
 * Comparison result: -1 (str1 < str2)
 * Reversed: "olleH"
 * Is palindrome: No
 */

#include <stdio.h>

// Function prototypes
int myStrlen(const char *str);
void myStrcpy(char *dest, const char *src);
void myStrcat(char *dest, const char *src);
int myStrcmp(const char *str1, const char *str2);
void myStrrev(char *str);
int isPalindrome(const char *str);

int main() {
    // TODO: Implement your solution here
    
    return 0;
}

// TODO: Implement all the functions above

/*
 * Hints:
 * 1. Use pointer arithmetic for string operations
 * 2. Remember to handle null terminators
 * 3. Always check for null pointers
 * 4. For palindrome check, compare characters from both ends
 * 5. For string reverse, swap characters from both ends
 * 
 * Important Notes:
 * - Always check for null pointers before dereferencing
 * - Ensure destination strings have enough space
 * - Handle edge cases like empty strings
 * - Consider memory safety and buffer overflows
 * 
 * Extension Challenges:
 * 1. Implement strncpy() with length limit
 * 2. Add support for case-insensitive comparison
 * 3. Implement substring function
 * 4. Add support for string tokenization
 * 5. Implement pattern matching
 */ 