# Arbitrary Precision Calculator (APC) Using Double Linked List in C

## Overview

The Arbitrary Precision Calculator (APC) is a command-line application developed in C that performs arithmetic operations on integers of virtually unlimited length.

Unlike built-in data types, which are restricted by memory size and compiler limits, this calculator uses a Doubly Linked List to store each digit separately, enabling operations on extremely large numbers.

This project demonstrates:

* Data Structures and Algorithms
* Doubly Linked Lists
* Dynamic Memory Management
* Big Integer Arithmetic
* Modular Programming
* Command Line Processing

---

## Features

* Addition of Large Numbers
* Subtraction of Large Numbers
* Multiplication of Large Numbers
* Division of Large Numbers
* Positive and Negative Number Support
* Dynamic Memory Allocation
* Doubly Linked List Implementation
* Command Line Interface
* Large Integer Computation

---

## Technologies Used

| Technology                | Purpose                 |
| ------------------------- | ----------------------- |
| C Programming             | Core Implementation     |
| GCC Compiler              | Compilation             |
| Doubly Linked List        | Number Storage          |
| Dynamic Memory Allocation | Runtime Data Management |
| Linux                     | Development Environment |

---

## Project Structure

```text
.
├── main.c
├── DLL.c
├── Operations.c
├── require.h
├── Makefile
├── Test_apc.sh
└── README.md
```

---

## Problem Statement

Built-in C data types have limitations:

```text
int        -> ~2 Billion
long long  -> ~9 Quintillion
```

Operations involving numbers larger than these limits cannot be processed accurately.

This project overcomes that limitation by storing each digit as a separate node in a Doubly Linked List.

Example:

```text
98765432101234567890
```

Stored as:

```text
9 <-> 8 <-> 7 <-> 6 <-> 5 <-> 4 <-> 3 <-> 2 <-> 1
<-> 0 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <-> 9 <-> 0
```

---

## Architecture

```text
             User Input
                  |
                  v
      +-----------------------+
      | Command Line Parser   |
      +-----------------------+
                  |
                  v
      +-----------------------+
      | Linked List Creation  |
      +-----------------------+
                  |
                  v
      +-----------------------+
      | Arithmetic Engine     |
      +-----------------------+
          |     |     |     |
          |     |     |     |
          v     v     v     v

        Add   Sub   Mul   Div

                  |
                  v
      +-----------------------+
      | Result Linked List    |
      +-----------------------+
                  |
                  v
             Display Output
```

---

## Data Structure Used

```c
typedef struct node
{
    int8_t data;
    struct node *prev;
    struct node *next;
} Dlist;
```

Each node stores a single digit.

---

## Supported Operations

### Addition

```bash
./apc 123456789123456789 + 987654321987654321
```

Output:

```text
1111111111111111110
```

---

### Subtraction

```bash
./apc 999999999999999999 - 111111111111111111
```

Output:

```text
888888888888888888
```

---

### Multiplication

```bash
./apc 123456789 x 987654321
```

Output:

```text
121932631112635269
```

---

### Division

```bash
./apc 1000000000 / 10
```

Output:

```text
100000000
```

---

## Function Descriptions

### Doubly Linked List Module

#### insert_last()

* Inserts a digit at the end of the list.
* Used while creating large numbers.

#### insert_at_first()

* Inserts a digit at the beginning.
* Used during arithmetic operations.

#### create_list()

* Converts user input string into linked list format.

#### get_tail()

* Returns last node of the list.

#### remove_leading_zeros()

* Removes unnecessary leading zeros.

#### print_list()

* Displays the stored number.

#### free_list()

* Releases dynamically allocated memory.

#### copy_list()

* Creates duplicate linked list.

---

## Arithmetic Operations Module

### add()

* Performs digit-by-digit addition.
* Handles carry propagation.

### subtract()

* Performs subtraction using borrow logic.
* Assumes larger number is first operand.

### multiplication()

* Performs multiplication similar to manual multiplication.
* Handles place-value shifting.

### division()

* Implements long division using repeated subtraction.
* Produces quotient for large numbers.

### compare()

* Compares two large numbers.
* Returns:

  * GREATER
  * SMALLER
  * EQUAL

---

## Program Flow

```text
1. Read Command Line Arguments
2. Validate Inputs
3. Create Linked Lists
4. Select Operation
5. Perform Arithmetic
6. Remove Leading Zeros
7. Display Result
8. Free Allocated Memory
```

---

## Build Instructions

### Using GCC

```bash
gcc main.c DLL.c Operations.c -o apc
```

### Using Makefile

```bash
make
```

---

## Usage

```bash
./apc <Number1> <Operator> <Number2>
```

Example:

```bash
./apc 123456789123456789 + 987654321987654321
```

Operators:

```text
+  Addition
-  Subtraction
x  Multiplication
/  Division
```

---

## Sample Execution

```bash
./apc 999999999999999999 + 1
```

Output:

```text
Result: 1000000000000000000
```

---

## Concepts Demonstrated

* Doubly Linked Lists
* Dynamic Memory Allocation
* Big Integer Arithmetic
* Command Line Arguments
* Data Structures
* Algorithms
* Memory Management
* Modular Programming
* Software Design

---

## Applications

* Cryptography
* Scientific Calculations
* Financial Software
* Large Number Computation
* Mathematical Research
* Arbitrary Precision Arithmetic Libraries

---

## Future Improvements

* Modulus Operation
* Exponentiation
* Factorial Calculation
* Floating Point Support
* Expression Evaluation
* GUI Version
* Optimized Division Algorithm

---

## Learning Outcomes

Through this project, I gained practical experience in:

* Advanced Data Structures
* Linked List Manipulation
* Memory Management
* Arithmetic Algorithms
* Debugging Large Programs
* Software Architecture
* Linux Development Environment

---

## Author

**Darsh Patel**

Electronics & Communication Engineer

Firmware Engineer | Embedded Systems | IoT Developer

GitHub: https://github.com/darshpatel001

---

## License

This project is licensed under the MIT License.
