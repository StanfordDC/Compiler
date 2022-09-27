# Compiler
Compiler equipped with interpreter made in C++ and CMake

## High Level Overview

![cmpgif01](https://user-images.githubusercontent.com/69248457/192213074-a8aaf576-a59c-4fd6-b7b1-925bf54c3a14.gif)

Image from https://www.cs.man.ac.uk/~pjj/farrell/compmain.html

## Main Components
This compiler project is divided into three main components: `Tokenizer`, `Parser` and `Interpreter`

### Tokenizer
- The first step in compiling programming language is called tokenization. 

- The tokenizer reads human written code file line by line, character by character and breaks each term down into **lexeme**. 

- For each lexeme, a type is attached to it indicating what kind of lexeme it is, and a lexeme with a type is called a **token**.

- The process of generating tokens is known as ***Lexical Analysis*** and is performed using [Deterministic Finite Automata](https://en.wikipedia.org/wiki/Deterministic_finite_automaton).

### Parser
In parser, there are several phases to parse a token: ***Syntatic Analysis***, ***Semantic Analysis***, and ***Bytecode Generation***

* #### Syntatic Analysis
  Parser takes input stream of tokens from tokenizer and checks for syntax correctness to form a **parse tree/abstract syntax tree** using **Top-down Recursive Descent** parsing technique
  
  Illustration
![lexer-parser-center](https://user-images.githubusercontent.com/69248457/192459457-9d013781-38e0-4891-b89f-8beee8bf626d.png)


* #### Semantic Analysis
  Evaluates the parse tree from the previous phase while checking for semantic errors such as **type mismatch** (initializing a value to a variable that doesn't match its data type) and **reserved identifier misuse** (reserved keywords are used inappropriately)

* #### Bytecode Generation (Pending)

### Interpreter
**P.S.** A compiler doesn't usually come with an interpreter, but for this project, I decided to build my own interpreter for executing bytecode
- Interpreter is used to execute generated bytecode from parser as machine instructions (similar to the concept of how CPU executes machine code)

- The generated bytecode is modelled after machine instructions and can be found in `Instructions.h`

## TODO
- Generate custom bytecode from parse tree

- Integrate parser and interpreter
  
    
 
  

