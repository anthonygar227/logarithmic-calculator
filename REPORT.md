# Logarithmic Calculator — Full Project Report

**Anthony Garcia**  
**Professor Olavarietta**  
**Math 2 — Calculus II Honors**  
**14 May 2024**

---

## Introduction

The calculator is designed to efficiently and accurately compute natural logarithms and logarithms of any base using the Maclaurin Series. The purpose of this calculator is to leverage mathematical principles to create a reliable computation tool, improving understanding of logarithmic functions and providing precise calculations fundamental for scientific applications.

Logarithmic functions are foundational in mathematics, with extensive applications in science, engineering, finance, and much more. The natural logarithm is important for solving equations involving growth and decay among other exponential phenomena.

## Mathematical Foundation

The project focuses on developing a calculator that utilizes the Maclaurin series to compute natural logarithms efficiently and accurately. The Maclaurin series is a representation of functions as an infinite sum of terms calculated from the derivatives of the function at a single point.

Oscar Lanzi provided a derivation showing how to develop a series for ln(x). The series for ln(1+y) and ln(1-y) are given by:
```
ln(1+y) = Σ (n=1 to ∞) (-1)^(n-1) * y^n / n
ln(1-y) = Σ (n=1 to ∞) (-1)^n * y^n / n
```

By subtracting these two series and manipulating the resulting expression, he derived a series that converges for all positive x values:
```
ln((1+y)/(1-y)) = 2 * Σ (m=1 to ∞) y^(2m-1) / (2m-1)
```

After solving for y, the equation becomes:
```
ln(x) = 2 * Σ (m=1 to ∞) ((x-1)/(x+1))^(2m-1) / (2m-1)
```

This formula provides the foundation for the computation method used in the calculator.

## Convergence Proof

We need to check whether the series converges for all positive values of x. We know the domain of y is:
```
y = (x-1)/(x+1)
```

To determine the range of y: -1 < (x-1)/(x+1) < 1

**Left inequality:** -1 < (x-1)/(x+1)
- -1(x+1) < x-1
- -x-1 < x-1
- -1 < 2x - 1
- 0 < 2x
- 0 < x

**Right inequality:** (x-1)/(x+1) < 1
- x-1 < x+1
- -1 < 1 ✓

The inequality -1 < (x-1)/(x+1) < 1 holds true for all x > 0. Therefore, the series converges for all positive x > 0.

## Development Process

The development of the calculator was a complex process that began with:

1. **Theoretical Study** — Thorough understanding of the mathematical foundations of logarithms and the Maclaurin series.

2. **Tool Selection** — Selecting and setting up appropriate programming libraries and tools that would support high-precision mathematical computations.

3. **Algorithm Design** — Translating theoretical concepts of the Maclaurin series into a practical computational algorithm that follows mathematical precision and computational efficiency.

4. **Implementation** — Carried out in C++, focused on coding important functionalities and securing numerical stability.

5. **Testing and Optimization** — Verifying accuracy of logarithmic computations and refining performance. The number of terms in the Maclaurin series was adjusted to achieve optimal balance between computational speed and precision.

## Implementation Details

### Main Function

The `main()` function is the starting point of the logarithmic calculator program. It begins by initializing variables for user inputs and calculated results:

- `try_again` — determines if the user wants to repeat calculations
- `x_input` and `base_input` — store user inputs for the number and base
- `x`, `b`, `ln_b`, and `log_base_b` — double precision variables for numerical values

The program uses a `do-while` loop to allow multiple calculations without restarting. Within this loop, user inputs are validated through nested `while(true)` loops:

- For the base: input is recognized as "e" or checked to be a valid positive number not equal to one
- For the number: input must be greater than zero (mathematical requirement for logarithms)

### Normalization Algorithm

The input `x` needs to fall within a range optimal for logarithmic computation using the Maclaurin series, specifically between 1 and 10. The `powerOfTen` variable tracks adjustments:

- If x ≥ 10: divide by 10 until below 10, increment `powerOfTen`
- If x < 1: multiply by 10 until above 1, decrement `powerOfTen`

This ensures the logarithm calculation is performed on a number where the series converges efficiently and accurately.

### Series Calculation

The `ln_series` function calculates the natural logarithm of a number `y` by:

1. Transforming `y` into `z` using: `z = (y - 1) / (y + 1)`
2. Computing terms of the Maclaurin series: `pow(z, 2 * m - 1) / (2 * m - 1)`
3. Summing all terms
4. Returning `2 * sum` for the final logarithmic value

## Challenges Faced

### Mathematical Complexity
Understanding the mathematical intricacies of the Maclaurin series, specifically how it applies to computing natural logarithms, was challenging. Maintaining convergence and managing computational precision for inputs near the boundaries required thorough understanding of calculus and numerical methods.

### Input Conversion
The use of the `stod` function to convert user input from string to double required careful programming to handle different forms of valid and invalid inputs without causing crashes.

### Numerical Stability
Maintaining numerical stability and precision was especially important given the complexities of logarithmic functions. Very large or very small numbers can quickly lead to significant computational errors.

## What I Learned

- **Complex Algorithm Implementation** — Important for achieving precise and reliable calculations
- **Input/Output Operations** — Improved ability to design intuitive and efficient user interfaces
- **Software Stability** — Learned the importance of intensive testing and validation
- **Precision in Development** — Understood how slight errors can lead to significant differences in results
- **Practical Application** — Applied theoretical knowledge in a practical setting, preparing for more advanced software development projects

## References

Oscar Lanzi. "Is There Any Equivalent of Taylor/Maclaurin Series of ln(1+x) for |x| > 1." Mathematics Stack Exchange, 26 Apr. 2019. [Link](https://math.stackexchange.com/questions/3227258/is-there-any-equivalent-of-taylor-maclaurin-series-of-ln1x-for-x-1/3227686#3227686)
