# Monty

Monty is an interpreter for Monty bytecode files. It reads Monty bytecode files (.m) and executes the operations specified in them.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Bytecode Files](#bytecode-files)
- [Opcode Functions](#opcode-functions)
- [Brainf*ck Scripts](#brainfck-scripts)
- [Contributing](#contributing)
- [License](#license)

## Features

- Executes Monty bytecode files
- Supports various stack and queue operations
- Implements additional advanced opcodes
- Interprets Brainf*ck scripts
- Easy-to-use command line interface

## Getting Started

To get started with Monty, you can follow these steps:

1. Clone the repository:
   *git clone https://github.com/Ayamigah16/monty.git*

2. Change to the project directory:
    *cd monty*
3. Compile the source code:
    *gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty*
4. Run Monty with a bytecode file:
    *./monty bytecodes/file.m*

## Usage
Monty accepts bytecode files (.m) as input. You can pass a bytecode file to the interpreter to execute the specified operations.
    ./monty bytecodes/file.m

## Bytecode Files
Bytecode files contain a series of instructions that Monty interprets and executes. Each instruction is written on a separate line.

Example bytecode file (file.m):
    push 1
    push 2
    add
    pall
This bytecode file pushes two values onto the stack, adds them, and prints the result

## Opcode Functions
Monty supports various opcode functions that perform operations on the stack and queue. These functions are implemented in separate files in the opcode_functions/ directory.

To add a new opcode function, create a new file in the opcode_functions/ directory and implement the corresponding functionality.

## Brainf*ck Scripts
Monty also includes support for interpreting Brainfck scripts. Brainfck is an esoteric programming language.

Brainfck scripts should be stored in the bf/ directory. You can run a Brainfck script using the **bf** command:
    *bf bf/script.bf*

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.