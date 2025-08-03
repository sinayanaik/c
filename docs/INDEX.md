# C Programming Documentation Index

## 📚 Quick Navigation

### [01. Basics](./01-basics/)
- [History and Overview](./01-basics/01-history-overview.md) - C language history and fundamentals
- [Data Types](./01-basics/02-data-types.md) - Complete guide to C data types
- [Identifiers](./01-basics/03-identifiers.md) - Rules and best practices for naming
- [Keywords](./01-basics/04-keywords.md) - All 32 C keywords explained
- [Header Files](./01-basics/05-header-files.md) - Understanding header files

### [02. Operators](./02-operators/)
- [Logical Operators](./02-operators/01-logical-operators.md) - AND, OR, NOT operators
- [Bitwise Operators](./02-operators/02-bitwise-operators.md) - Bit manipulation operators
- [Ternary Operators](./02-operators/03-ternary-operators.md) - Conditional operator

### [03. Control Flow](./03-control-flow/)
- [Break Statement](./03-control-flow/01-break-statement.md) - Exiting loops and switches
- [Continue Statement](./03-control-flow/02-continue-statement.md) - Skipping iterations

### [04. Arrays](./04-arrays/)
- [Array Basics](./04-arrays/01-array-basics.md) - Fundamental array concepts
- [Arrays as Pointers](./04-arrays/02-arrays-as-pointers.md) - Array-pointer relationship
- [Array of Pointers](./04-arrays/03-array-of-pointers.md) - Advanced pointer arrays

### [05. Strings](./05-strings/)
- [String Handling](./05-strings/01-string-handling.md) - String manipulation in C

### [06. Structures](./06-structures/)
- [Structure Basics](./06-structures/01-structure-basics.md) - User-defined data types

### [07. Pointers](./07-pointers/)
- [Pointer Basics](./07-pointers/01-pointer-basics.md) - Understanding pointers
- [Double Pointers](./07-pointers/02-double-pointers.md) - Pointers to pointers
- [Pointer to Functions](./07-pointers/03-pointer-to-functions.md) - Function pointers
- [Pointer to Array of Structures](./07-pointers/04-pointer-to-array-of-structures.md) - Complex pointer usage

### [08. Storage Classes](./08-storage-classes/)
- [Storage Class Overview](./08-storage-classes/01-storage-class-overview.md) - Variable storage concepts
- [Variable Scope](./08-storage-classes/02-variable-scope.md) - Scope, lifetime, and visibility

### [09. File I/O](./09-file-io/)
- [File Handling](./09-file-io/01-file-handling.md) - Reading and writing files

### [10. Examples](./10-examples/)
- [Code Examples](./10-examples/) - Practical C programming examples

## 🎯 Learning Path

### Beginner Level
1. **Start with Basics**
   - [History and Overview](./01-basics/01-history-overview.md)
   - [Data Types](./01-basics/02-data-types.md)
   - [Identifiers](./01-basics/03-identifiers.md)
   - [Keywords](./01-basics/04-keywords.md)

2. **Learn Operators**
   - [Logical Operators](./02-operators/01-logical-operators.md)
   - [Bitwise Operators](./02-operators/02-bitwise-operators.md)

3. **Control Flow**
   - [Break Statement](./03-control-flow/01-break-statement.md)
   - [Continue Statement](./03-control-flow/02-continue-statement.md)

### Intermediate Level
4. **Data Structures**
   - [Array Basics](./04-arrays/01-array-basics.md)
   - [String Handling](./05-strings/01-string-handling.md)
   - [Structure Basics](./06-structures/01-structure-basics.md)

5. **Pointers**
   - [Pointer Basics](./07-pointers/01-pointer-basics.md)
   - [Arrays as Pointers](./04-arrays/02-arrays-as-pointers.md)

### Advanced Level
6. **Advanced Concepts**
   - [Storage Classes](./08-storage-classes/02-variable-scope.md)
   - [Double Pointers](./07-pointers/02-double-pointers.md)
   - [Pointer to Functions](./07-pointers/03-pointer-to-functions.md)
   - [File I/O](./09-file-io/01-file-handling.md)

## 🔧 Code Examples

All source code examples are organized in the `src/` directory:

```
src/
├── basics/           # Basic concepts examples
├── operators/        # Operator examples
├── control-flow/     # Control structure examples
├── arrays/          # Array examples
├── strings/         # String handling examples
├── structures/      # Structure examples
├── pointers/        # Pointer examples
├── storage-classes/ # Storage class examples
└── file-io/         # File I/O examples
```

## 📖 How to Use This Documentation

### For Beginners
1. Follow the learning path from top to bottom
2. Read each section thoroughly
3. Practice with the provided code examples
4. Compile and run examples to understand concepts

### For Reference
1. Use the quick navigation to find specific topics
2. Search for keywords in the documentation
3. Check code examples for practical implementation

### For Practice
1. Modify existing code examples
2. Create your own programs based on concepts
3. Experiment with different approaches
4. Test edge cases and error conditions

## 🚀 Getting Started

### Prerequisites
- Basic understanding of programming concepts
- C compiler installed (gcc recommended)
- Text editor or IDE

### First Steps
1. Read [History and Overview](./01-basics/01-history-overview.md)
2. Set up your development environment
3. Start with simple programs
4. Gradually move to complex concepts

### Compilation Commands
```bash
# Compile a C program
gcc -o program_name source_file.c

# Run the program
./program_name

# Compile with warnings
gcc -Wall -o program_name source_file.c

# Compile with optimization
gcc -O2 -o program_name source_file.c
```

## 📝 Contributing

This documentation is designed to be:
- **Comprehensive**: Covering all major C concepts
- **Progressive**: Building from basics to advanced topics
- **Practical**: Including real code examples
- **Clear**: Using simple explanations and examples

### Suggestions for Improvement
- Add more code examples
- Include exercises and practice problems
- Add debugging tips and common pitfalls
- Include performance optimization techniques

## 🔗 Related Resources

- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [GCC Compiler Documentation](https://gcc.gnu.org/onlinedocs/)
- [C Programming Best Practices](https://en.wikipedia.org/wiki/C_programming_language)

---

**Note**: This documentation is designed to be a comprehensive guide for learning C programming. Each section builds upon previous knowledge, so it's recommended to follow the learning path in order. 