/*
 * Exercise: String Manipulation
 * 
 * Write a program that implements various string manipulation functions
 * without using the standard string library functions (except strlen):
 * 
 * 1. String length (strlen)
 * 2. String copy (strcpy)
 * 3. String concatenation (strcat)
 * 4. String comparison (strcmp)
 * 5. String reverse
 * 6. Check if string is palindrome
 * 7. Convert string to uppercase
 * 8. Convert string to lowercase
 * 9. Count vowels and consonants
 * 10. Remove spaces from string
 * 
 * Requirements:
 * - Implement all functions from scratch
 * - Handle edge cases (null strings, empty strings)
 * - Use proper memory management
 * - Test with various input strings
 * 
 * Example Output:
 * Original string: "Hello World"
 * Length: 11
 * Reversed: "dlroW olleH"
 * Uppercase: "HELLO WORLD"
 * Lowercase: "hello world"
 * Vowels: 3, Consonants: 7
 * Without spaces: "HelloWorld"
 * Is palindrome: No
 */

#include <stdio.h>

// Function prototypes
int myStrlen(const char *str);
void myStrcpy(char *dest, const char *src);
void myStrcat(char *dest, const char *src);
int myStrcmp(const char *str1, const char *str2);
void reverseString(char *str);
int isPalindrome(const char *str);
void toUppercase(char *str);
void toLowercase(char *str);
void countVowelsConsonants(const char *str, int *vowels, int *consonants);
void removeSpaces(char *str);

int main() {
    // TODO: Implement your solution here
    
    return 0;
}

// TODO: Implement all the functions above

/*
 * Hints:
 * 1. Use pointer arithmetic for string operations
 * 2. Remember to handle null terminators
 * 3. For case conversion, use ASCII values
 * 4. For palindrome check, compare characters from both ends
 * 5. For space removal, shift characters to fill gaps
 * 
 * Important Notes:
 * - Always check for null pointers
 * - Ensure destination strings have enough space
 * - Handle edge cases like empty strings
 * - Consider memory safety and buffer overflows
 * 
 * Extension Challenges:
 * 1. Implement substring function
 * 2. Add support for word count
 * 3. Implement string tokenization
 * 4. Add support for string replacement
 * 5. Implement pattern matching
 */ 