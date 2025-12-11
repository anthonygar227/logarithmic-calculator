# Logarithmic Calculator

A C++ calculator that computes natural logarithms and logarithms of any base using the Maclaurin Series.

## Overview

This calculator leverages mathematical principles to create a reliable computation tool for logarithmic functions. It was developed as an honors project for Calculus II at Las Positas College.

## Mathematical Foundation

The calculator uses a derived Maclaurin series that converges for all positive x values:
```
ln(x) = 2 * Σ ((x-1)/(x+1))^(2m-1) / (2m-1)
```

This formula was derived by manipulating the series for ln(1+y) and ln(1-y), providing accurate computations for any positive input.

## Features

- Computes natural logarithms (base e)
- Computes logarithms of any positive base (except 1)
- Input validation for domain errors
- High precision output (8 decimal places)
- Supports multiple calculations in one session

## How to Run

### Compile
```bash
g++ -o calculator main.cpp
```

### Execute
```bash
./calculator
```

## Example Usage
```
------ Logarithmic Calculator ------

What is the base, b? Recall that log_b(a): 10
What is the input, a? Recall that log_10(a): 100
The logarithm base 10 of 100 is approximately 2.00000000

Would you like to try another calculation? (Y/N): n

------ Exiting the program. Thank you for using the calculator! ------
```

## Technical Details

- **Language:** C++
- **Algorithm:** Maclaurin Series expansion
- **Precision:** 10,000,000 terms for accuracy
- **Input normalization:** Values are normalized between 1 and 10 for stable convergence

## What I Learned

- Implementation of complex mathematical algorithms
- Numerical stability and precision management
- Input validation and error handling
- Practical application of calculus concepts

## Author

Anthony Garcia-Marquez  
Las Positas College — Calculus II Honors Project (May 2024)

## Reference

Oscar Lanzi. "Is There Any Equivalent of Taylor/Maclaurin Series of ln(1+x) for |x| > 1." Mathematics Stack Exchange, 26 Apr. 2019.

## Full Report

See [REPORT.md](REPORT.md) for the complete project writeup, including mathematical derivations and development process.
