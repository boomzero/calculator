# Calculator
[![CI/build+test](https://github.com/Thomas311926/calculator/actions/workflows/main.yml/badge.svg)](https://github.com/Thomas311926/calculator/actions/workflows/main.yml)
[![Publish](https://github.com/Thomas311926/calculator/actions/workflows/publish.yml/badge.svg)](https://github.com/Thomas311926/calculator/actions/workflows/publish.yml)

A smart calculator that calculates the value of a expression.
***
It supports the following operators:

* \+
* \-
* \*
* / 
* ^ 
* sqrt

* pi=3.14159265358979
## Examples
Input:
```
(0.1+2)*3-4
```
Output:
```
2.3
```
Input:
```
(0.1+(0.2-0.3)/2)^2
```
Output:
```
0.0025
```
## Building
```
cmake ./
make
```
This should build two binaries, calculator and checker. Checker is only used for unit tests.
