# Monty - A Monty ByteCode Interpreter

This is a README file for the Monty project, which is an interpreter for Monty ByteCode files. The project involves implementing a set of opcodes and data structures to manipulate a stack and queue. Below, you'll find information about the project, its requirements, and the tasks you need to complete.

## Project Overview

Monty is a scripting language that uses a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCode files. These files have a .m extension and contain a series of opcodes that you need to execute. The project is to be done in teams of two people.

## Learning Objectives

By the end of this project, you should be able to explain:

- What LIFO and FIFO mean.
- What a stack is and when to use it.
- What a queue is and when to use it.
- Common implementations of stacks and queues.
- Common use cases of stacks and queues.
- The proper way to use global variables.

## Requirements

### General

- Allowed editors: vi, vim, emacs.
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, with specific compiler flags.
- All your files should end with a new line.
- A README.md file at the root of the project folder is mandatory.
- Your code should use the Betty style, and it will be checked using betty-style.pl and betty-doc.pl.
- You are allowed to use a maximum of one global variable.
- No more than 5 functions per file.
- You are allowed to use the C standard library.
- The prototypes of all your functions should be included in your header file called `monty.h`.
- All your header files should be include guarded.
- You are expected to complete the tasks in the order shown in the project.

### Data Structures

Please use the following data structures for this project. These data structures should be included in your `monty.h` header file:

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

### Compilation & Output

Your code will be compiled with the following command:

```sh
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

- Any output must be printed on stdout.
- Any error message must be printed on stderr.

### Task List

Here is a list of the tasks you need to complete for this project:

1. **push, pall**
   - Implement the push and pall opcodes.

2. **pint**
   - Implement the pint opcode.

3. **pop**
   - Implement the pop opcode.

4. **swap**
   - Implement the swap opcode.

5. **add**
   - Implement the add opcode.

6. **nop**
   - Implement the nop opcode.

7. **sub (Advanced)**
   - Implement the sub opcode.

8. **div (Advanced)**
   - Implement the div opcode.

9. **mul (Advanced)**
   - Implement the mul opcode.

10. **mod (Advanced)**
    - Implement the mod opcode.

11. **comments (Advanced)**
    - Implement commenting functionality.

12. **pchar (Advanced)**
    - Implement the pchar opcode.

13. **pstr (Advanced)**
    - Implement the pstr opcode.

14. **rotl (Advanced)**
    - Implement the rotl opcode.

15. **rotr (Advanced)**
    - Implement the rotr opcode.

16. **stack, queue (Advanced)**
    - Implement the stack and queue opcodes.

17. **Brainf*ck (Advanced)**
    - Write a Brainf*ck script that prints "School," followed by a new line.

18. **Add two digits (Advanced)**
    - Add two digits given by the user.

19. **Multiplication (Advanced)**
    - Multiply two digits given by the user.

20. **Multiplication level up (Advanced)**
    - Multiply two digits given by the user.

## AUTHOR
* Name: Martin Magonagona
* Email: <martinmagonazz@outlook.com>
