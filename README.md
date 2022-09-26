# Compiler
Compiler equipped with interpreter made in C++ and CMake

## High Level Overview

![cmpgif01](https://user-images.githubusercontent.com/69248457/192213074-a8aaf576-a59c-4fd6-b7b1-925bf54c3a14.gif)

Image from https://www.cs.man.ac.uk/~pjj/farrell/compmain.html

## Main Components
This compiler project is divided into three main components: `Tokenizer`, `Parser` and `Interpreter`

### Tokenizer
The first step in compiling programming language is called tokenization. 

The tokenizer reads human written code file line by line, character by character and breaks each term down into **lexeme**. For each lexeme, a type is attached to it indicating what kind of lexeme it is, and a lexeme with a type is called a **token**.

The process of tagging lexeme is known as ***Lexical Analysis*** and is performed using [Deterministic Finite Automata](https://en.wikipedia.org/wiki/Deterministic_finite_automaton)
