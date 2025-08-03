/*
 * Puzzle: Operator Precedence and Associativity
 * 
 * What will be the output of each printf statement?
 * Think about operator precedence and associativity.
 */

#include <stdio.h>

int main() {
    int a = 5, b = 3, c = 2;
    int result;
    
    // Puzzle 1: Arithmetic operators
    result = a + b * c;
    printf("a + b * c = %d\n", result);
    
    // Puzzle 2: Parentheses override precedence
    result = (a + b) * c;
    printf("(a + b) * c = %d\n", result);
    
    // Puzzle 3: Assignment operator
    int x = 10;
    x += 5 * 2;
    printf("x += 5 * 2 = %d\n", x);
    
    // Puzzle 4: Logical operators
    int p = 1, q = 0, r = 1;
    result = p && q || r;
    printf("p && q || r = %d\n", result);
    
    // Puzzle 5: Bitwise operators
    int m = 5, n = 3;
    result = m & n | 1;
    printf("m & n | 1 = %d\n", result);
    
    // Puzzle 6: Multiple operators
    int i = 2, j = 3, k = 4;
    result = i + j * k / 2;
    printf("i + j * k / 2 = %d\n", result);
    
    // Puzzle 7: Unary operators
    int num = 5;
    result = -num * 2;
    printf("-num * 2 = %d\n", result);
    
    // Puzzle 8: Postfix vs prefix
    int count = 5;
    printf("count++ = %d\n", count++);
    printf("After count++: count = %d\n", count);
    
    count = 5;
    printf("++count = %d\n", ++count);
    printf("After ++count: count = %d\n", count);
    
    return 0;
}

/*
 * Questions:
 * 1. What is the order of precedence for arithmetic operators?
 * 2. How do parentheses affect operator precedence?
 * 3. What is the difference between postfix and prefix increment?
 * 4. How do logical operators short-circuit?
 * 5. What is the precedence between bitwise and logical operators?
 * 
 * Operator Precedence (highest to lowest):
 * 1. () [] -> .
 * 2. ! ~ ++ -- + - * & (type) sizeof
 * 3. * / %
 * 4. + -
 * 5. << >>
 * 6. < <= > >=
 * 7. == !=
 * 8. &
 * 9. ^
 * 10. |
 * 11. &&
 * 12. ||
 * 13. ?:
 * 14. = += -= *= /= %= <<= >>= &= ^= |=
 * 15. ,
 */ 