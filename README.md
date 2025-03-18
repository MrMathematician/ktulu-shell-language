# Ktulu Shell Language


## Description

A shell language interpreter written entirely in C++ that aims to provide simplicity of an interpreted language while providing the robust 
syntax and typing system of C.  


## Installation

The project is relatively small and can be compiled in less than a minute to run on any Linux system. You
have to make sure that you have `cmake` ,`make`, and `g++` installed. That's it!

```git clone https://github.com/MrMathematician/ktulu-shell-language/tree/master```

Then

```cd build```
```cmake CMakeLists.txt```
```make```
```cp ktulu /bin```

To run scripts, simply run

```ktulu <filepath>```

To make it the default shell, run

```sudo chsh -s ktulu```

#However, be aware that the project is still in early development, and is not yet stable enough to be used as a replacement
for the default shell terminal (e.g `bash`, `zsh`, `fish`, etc.). The project is welcome to contributors. 

## For Contributors

Any contributor must bear in mind that the project doesn't use premade tools for lexing and parsing (`bison`, `YACC`, `ANTLR`, etc.). It's
entirely written from scratch. The project also strongly follows an OOP approach which makes the modding and feature addition process much
easier, though it may not be similar to using a premade tool, but it still maintains strong modularity!


