<p align="center">
  <img src="https://i.ibb.co/qCHmRsb/Monty-Python-title.jpg">
</p>

# Monty: A Custom Monty Bytecode Interpreter

## General

### Stacks, Queues - LIFO, FIFO

The following repository covers programs written in C for the Data structures and Algorithms curriculum at Holberton School. It covers stacks (LIFO) and queues (FIFO). The data structures are considered to have a limited access.

For example, in a stack, elements can be added or removed by push or pop following a linear order of Last In, First Out. Think of a stack as an actual stack of books. To get to the first book at the bottom, you must first remove the top book followed by the other books after it--in order to get to the bottom of the stack. 

In contrast, elements in a queue can be added in a First in, First out basis. Therefore, elements are added by an enqueue and removed by a dequeue. Think of it as a line of people onboarding a train, but the first person in becomes the first person to exit the train when deboarding. It has two points of access (the front and the back). 

## Description

### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- All your files should end with a new line
- Code follows the [Betty](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) [Style](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- The prototypes of all your functions should be included in your header file called `monty.h`
- Header file should be include guarded

### Setup
```
  git clone https://github.com/ecaoili24/monty.git
  gcc -Wall -Werror -Wextra -pedantic *.c -o monty
  ```
 
 ### Usage Examples
 
 Implementing the push, pall, pop opcodes:
  ```
  $ cat bytecodes/07.m 
  push 1
  push 2
  push 3
  pall
  pop
  pall
  pop
  pall
  pop
  pall
  $ ./monty bytecodes/07.m 
  3
  2
  1
  2
  1
  1
  ```
  
  Implementing the pint opcode:
  ```
  $ cat bytecodes/06.m 
  push 1
  pint
  push 2
  pint
  push 3
  pint
  $ ./monty bytecodes/06.m 
  1
  2
  3
  ```
  
  Implementing the swap opcode:
  ```
  $ cat bytecodes/09.m 
  push 1
  push 2
  push 3
  pall
  swap
  pall
  $ ./monty bytecodes/09.m 
  3
  2
  1
  2
  3
  1
  ```
  ## Authors
  
  [Ben Keener](https://github.com/bean710)
  
  [Erika Caoili](https://github.com/ecaoili24)
 
