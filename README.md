# Simple-compiler
This project is a basic compiler for a minimal subset of the Pascal programming language, developed as passing project of a compiler techniques course. It implements core components of a compiler, including lexical analysis, parsing, semantic analysis, and code generation. Here is a link to another compiler to compare the generated code: https://neo.dmcs.pl/tk/web.html
# Building and running the project
Use make to compile all necessary files:
```
make
```
To run the compiler on a test input file written in the Pascal subset, use:
```
./test path_to_test_file
```
To remove all compiled files and reset the workspace, run:
```
make clean
```
Planned updates:
- improving display function for array types
- refactoring of the project

