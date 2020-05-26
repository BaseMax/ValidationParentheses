# Validation Parentheses

Tiny C program to validation Parentheses `()` `[]` `{}` and symbols.

## Structure

```c
bool validSyntax(char* input);
```

## Examples

### True test

```c
TEST("(){[]}")
TEST("{()[]}")
TEST("[[]]({})")
TEST("a(dfgdfgdfgdfg)")
TEST("a(dfgdfgd{dfdfgdfg}fgdfg)")
TEST("((()))")
TEST("{{{}}}")
TEST("{{{\n}}}")
```

### False test

```c
TEST("{(}")
TEST("())")
TEST("({[])}")
TEST("a(dfgdfgdfgdfg")
TEST("a(dfgdfgd{dfdfgdfgfgdfg)")
TEST("a(dfgdfgd{dfdfgdfgfgdfg")
```

---------

# Max Base

My nickname is Max, Programming language developer, Full-stack programmer. I love computer scientists, researchers, and compilers. ([Max Base](https://maxbase.org/))

## Asrez Team

A team includes some programmer, developer, designer, researcher(s) especially Max Base.

[Asrez Team](https://www.asrez.com/)
