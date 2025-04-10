# Examples

## [Program 2.1](./Examples/program2_1_sequential_search.c)

### Sequential Search

This function checks if the number `v` is in a previously
stored set of numbers in `a[1],...,a[r]`, by comparing
against each number sequentially, starting at the beginning.

If we reach the end without finding the number stored, then
we return `NOT_FOUND`.

## [Program 2.2](./Examples/Program2_2/program2_2_binary_search.c)

### Binary Search

Has the same functionality as Program 2.1, but utilises a
sorted array for greater efficiency.

# Exercises

## [Exercise 2.1](./Exercises/Ex2_1/unionFind.py)

**Problem Statement**

_Translate the programs in Chapter 1 to another programming language, and answer [Exercise 1.22](../Chapter1/index.md#exercise-122) for your implementations._

**Solution**

For simplicity we have reimplemented [Exercise 1.22](../Chapter1/index.md#exercise-122) and the underlying [Program 1.4](../Chapter1/index.md#program-14) in python. We have additionally
compared the average time it takes both implementations to run.

The results abbreviated from [results.txt](./Exercises/Ex2_1/20250408/results.txt) are:

| Implementation | Real   | User   | System |
| -------------- | ------ | ------ | ------ |
| C              | 0.589  | 0.584  | 0.004  |
| Python         | 11.658 | 11.616 | 0.041  |

## [Exercise 2.2](./Exercises/Ex2_2/ex2_2.c)

**Problem Statement**

_Determine the amount of time it takes to run the
following code snippet for $`N = 10, 100, 1000`$. If
your compiler has optimisation features test the
impact of these._

```
int i, j, k, count = 0
for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
            count++;
        }
    }
}
```

**Solution**

Sample timings on my machine can be found in [ex2_2.dat](./Exercises/Ex2_2/ex2_2.dat).

## Exercise 2.3

**Problem Statement**

_Develop an expression of the form $`c_o + c_1N + c_2N^2 + c_3N^3`$ to describe the runtime of [Exercise 2.2](#exercise-22)._

**Solution**

We estimate by converting the loops to machine code, each loop effectively has 4 machine steps

1. branch if condition fails
2. reset the next inner loop variable (if it exists)
3. execute the inner loop or increment count
4. increment loop variable
5. goto branch check
   Each loop does this $`N`$ times, then has a final instruction consisting of the branch check failing and jumping to another.

So the inner loop has a term like $`4N + 1`$. While the outer
loops have expressions like $`4N + N \times \text{loop} + 1`$.

We then have the initialisation of $`\text{count} = 0`$ and the initialisation of $`i = 0`$. We can assume that declaring the variables `i,j,k` without values does not need machine instructions.

These leads to a runtime expression:

```math
\begin{align}
f\left(N\right) &= 4n^3 + 5n^2 + 5n + 3
\end{align}
```

Using [Godbolt](https://godbolt.org/) we get for gcc-14 x86-64, the following expression
for machine instructions in the result (ignoring setup and teardown instructions).

```math
\begin{align}
    f\left(N\right) &= 4n^3 + 7n^2 + 6n + 5.
\end{align}
```

Which shows that our estimate was pretty good!

## Exercise 2.4

**Problem Statement**

_Develop an expression that accurately describes the running time of [Program 1.1](../Chapter1/index.md#program-11)._

**Solution**

Using a similar strategy and considering all conditional `if` statements to always execute, and that the I/O functions only need 2 instructions (one for each variable) we get

```math
\begin{align}
    f\left(M, N\right) &= 5NM + 3M + 4N + 2
\end{align}
```

Again putting only the core in godbolt:

```math
\begin{align}
    f\left(M, N\right) &= 90MN + 315M + 4N + 3
\end{align}
```

where the large factors in $`M`$ and $`MN`$ largely comes from error-checking code and calls to `printf`, `fgets` and `sscanf`.

## [Exercise 2.5](./Exercises/Ex2_5/ex2_5.c)

**Problem Statement**

_For what values of $`N`$ is $`10N\lg(N) > 2N^2`$?_

**Solution**:

Observe the following:

```math
\begin{align*}
    N = 1 \implies 10N\lg(N) &= 0\\
    2N^2 &= 1 \\
    N = 2 \implies 10N\lg(N) &= 20\\
    2N^2 & = 8\\
    N = 32 \implies 10N\lg(N) &= 1600\\
    2N^2 &= 2048
\end{align*}
```

So the we have that the crossover points must be at
some $`x_1 < 2`$ and $`x_2 < 32`$. Using [Newtons Method](./Exercises/Ex2_5/ex2_5.c) to solve numerically leads to
$` 1.177 < N < 22.44`$.

## [Exercise 2.6](./Exercises/Ex2_6/ex2_6.c)

**Problem Statement**

_For what values of $`N`$ is $`N^{3/2}`$ between $`N\left(\lg(N)^2/2\right)`$ and $`2N\left(\lg(N)^2\right)`$?_

**Solution**:
Observe the following:

```math
\begin{align*}
    N = 1 \implies N\lg(N)^2 &= 0 \\
    N^(3/2) &= 1\\
    N = 4 \implies N\lg(N)^2 &= 16\\
    2N^(3/2) & = 8
\end{align*}
```

So we can see that regions of interest are around $`N=1`$
and $`N = 4`$. Using newton's method again we find the regions
to be

```math
\begin{align}
    0.448369 \leq N \leq 0.6445474\\
    1.7584 \leq N \leq 4.
\end{align}
```

## [Exercise 2.7](./Exercises/Ex2_7/ex2_7.c)

**Problem Statement**

_For what values of $`N`$ is $`2NH_N - N < N\lg N + 10N`$?_

**Solution**:
We approximate $`H_N`$ by

```math
\begin{align}
H_n = \lg(N) + \gamma
\end{align}
```

where $`\gamma`$ is Euler's constant. Then

```math
\begin{align}
2NH_N - N &< N\lg\left(N\right) + 10N\\
2N\lg(N) + 2N\gamma - N &< N\lg(N) + 10N\\
\implies \lg(N) &< 10\\
\implies N &< 2^{10}.
\end{align}
```

Solving using Newtons Method we find

```math
\begin{align}
0 < N < 47035526.49.
\end{align}
```

## Exercise 2.8

**Problem Statement**

_What is the smallest value of $`N`$ for which $`\log_{10}\log_{10}N > 8`$?_

**Solution**:

```math
\begin{align}
\log_{10}N > 10^{8}\\
\implies N > 10^{10^8}.
\end{align}
```

## Exercise 2.9

**Problem Statement**

_Prove that $`\text{floor}(\lg(N)) + 1`$ is the number of bits required to represent $`N`$ in binary._

**Proof**.

Suppose $`N`$ has $`d`$ binary digits. Then

```math
\begin{align}
    2^{d - 1} &\leq n \leq 2^{d} - 1 \\
    \implies  d - l &\leq \lg\left(N\right) \leq \lg\left(2^d - 1\right) \\
    \implies d - 1 &\leq \text{floor}\left(\lg\left(N\right)\right) \leq \text{floor}\left(\lg\left(2^d - 1\right)\right).
\end{align}
```

Examining the term on the right we have.

```math
\begin{align}
\lg\left(2^d - 1\right) &< \lg\left(2^d\right)\\
\implies \text{floor}\left(\lg\left(2^d - 1\right)\right) &< d\\
&\leq d - 1.
\end{align}
```

Which returning to the original expression gives

```math
\begin{align}
d - 1 &\leq \text{floor}\left(\lg\left(N\right)\right) \leq d -1 \\
\implies d &= \text{floor}\left(\lg\left(N\right)\right) + 1.
\end{align}
```

## Exercise 2.10-11

**Problem Statement**

_Add columns to Table 2.1 for $`N(\lg(N))^2`$, $`N^{(3/2)}`$, and $`10^7`$, $`10^8`$ operations per second_

**Solution**

| Operations per second | Problem size 1 million |              |              |         |         |
| --------------------- | ---------------------- | ------------ | ------------ | ------- | ------- |
|                       | $`N`$                      | $`NlgN`$         | $`N(lgN)^2`$     | $`N^(3/2)`$ | $`N^2`$     |
| 10^6                  | seconds                | seconds      | seconds      | minutes | weeks   |
| 10^7                  | milliseconds           | milliseconds | seconds      | minutes | days    |
| 10^8                  | instant                | instant      | milliseconds | seconds | hours   |
| 10^9                  | instant                | instant      | instant      | seconds | hours   |
| 10^12                 | instant                | instant      | instant      | instant | seconds |

| Operations per second | Problem size 1 billion |         |          |         |         |
| --------------------- | ---------------------- | ------- | -------- | ------- | ------- |
|                       | $`N`$                      | $`NlgN`$    | $`N(lgN)^2`$ | $`N^(3/2)`$ | $`N^2`$     |
| 10^6                  | hours                  | hours   | days     | years   | never   |
| 10^7                  | minutes                | minutes | hours    | weeks   | never   |
| 10^8                  | seconds                | minutes | minutes  | days    | never   |
| 10^9                  | seconds                | seconds | minutes  | hours   | decades |
| 10^12                 | instant                | instant | instant  | seconds | weeks   |

## [Exercise 2.12](./Exercises/Ex2_12/ex2_12.c)

**Problem Statement**

_Write a C function that computes $`H_N`$ using the `log`
function from the standard math library._

**Solution**

We implement the approximation given in the book

```math
H_n \approx \ln\left(N\right) + \gamma + \frac{1}{12N}
```

where $`\gamma = 0.57721`$ is the truncation of _Euler's constant_.

However, we argument the function such that for the first two values
of $`N \text{ } \left(1, 2\right)`$ we return the known exact values, $`1, 1.5`$.

If we were to write a function to calculate $`H_n`$ exactly from the definition we could make successive calls to this function faster by using
dynamic programming and caching the result of a call $`H_{n}`$.
Since a call to $`H_{n+1}`$ can then just access the cache and add $`1/\left(n + 1\right)`$.

See the [results](./Exercises/Ex2_12/sample_output.dat) for the first 20 harmonics.

## [Exercise 2.13](./Exercises/Ex2_13/ex2_13.c)

**Problem Statement**

_Write an efficient C function that computes $`\text{ceil}\left(\lg\left(\lg\left(N\right)\right)\right)`$ without use of a library function._

**Solution**

Let us consider a number $`2^{2^i}`$, then the power laws give
us

```math
\begin{align}
2^{2^{i - 1}} \times 2^{2^{i - 1}} &= 2^{2^{i - 1} + 2^{i - 1}}\\
&= 2^{2^{2^{1}\left(2^{i - 1}\right)}}\\
&= 2^{2^i}
\end{align}
```

By the same argument as for the quick calculation of $`\text{ceil}\left(\lg\left(N\right)\right)`$, we only need to consider these nested powers of two.

We can then use a similar formula to $`\text{ceil}\left(\lg\left(N\right)\right)`$, but rather than index over `i` in to count the number of terms of the form $`2^i`$ we iterate over $`2^i`$ to remove successive terms of the form $`2^{2^i}`$.

```
lglg(size_t n) {
    lglgN = 0;
    for (size_t t = 2; t < n; lglgN++, t *= t);
    return lglgN;
}
```

See the [results](./Exercises/Ex2_13/sample_output.dat) which validates the above function by comparison with a computation by calling the `log2` library function.

## [Exercise 2.14](./Exercises/Ex2_14/ex2_14.c)

**Problem Statement**

_How many digits are there in decimal representation of 1 million factorial?_

**Solution**

We can represent this easily since,

```math
\begin{align}
d &= \text{floor}\left(\log\left(n!\right)\right) + 1 \\
 &= \text{floor}\left(\log\left(\Pi_{m=1}^{n}m\right)\right) + 1 \\
 &= \text{floor}\left(\Sigma_{m = 2}^{n}\log\left(m\right)\right) + 1
\end{align}
```

Which can be easily computed programatically to generate the following table:
| $`N!`$ | Digits |
|---------|----------|
| 1 | 1 |
| 10 | 7 |
| 100 | 158 |
| 1000 | 2568 |
| 10000 | 35660 |
| 100000 | 456574 |
| 1000000 | 5565709 |

As to be expected from the results above, the digits show growth that appears to be faster than linear growth in $`N`$, but not by much.

_Note:_ Stirlings formula suggests the growth rate in the number of digits should approach $`N\log\left(N\right)`$ as $`N`$ gets large. See the [raw output](./Exercises/Ex2_14/sample_output.dat) which compares the calculated number with $`N\log\left(N\right)`$.

## [Exercise 2.15](./Exercises/Ex2_15/ex2_15.c)

**Problem Statement**

_How many bits are there in the binary representation of $`\lg(N!)`$?_

**Solution**

In principle $`\lg(N!)`$ is not a positive integer, so we consider the number of digits in the integer truncation.

From stirlings formula we can estimate,

```math
\begin{align}
\lg\left(N!\right) &\approx N\lg\left(N\right).
\end{align}
```

The number of digits is then approximated as

```math
\begin{align}
\text{digits} &\approx \text{floor}\left(\lg\left(\lg\left(N!\right)\right)\right) + 1 \\
            &\approx \lg\left(N\right) + \lg\left(\lg\left(N\right)\right) \\
            &\approx \lg\left(N\right).
\end{align}
```

We [compare](./Exercises/Ex2_15/sample_output.dat) the computation of $`\lg\left(\lg\left(N!\right)\right)`$ to $`\lg\left(N\right)`$ to demonstrate the relative growth rates. Which is repeated in the below table.

| $`N`$     | Digits | $`\lg\left(N\right)`$ |
|-----------|--------|-----------------------|
| 1         | 0      | 0                     |
| 10        | 6      | 3.321928              |
| 100       | 11     | 6.643856              |
| 1000      | 15     | 9.965784              |
| 10000     | 18     | 13.287712             |
| 100000    | 22     | 16.609640             |
| 1000000   | 29     | 23.253497             |
| 10000000  | 33     | 26.575425             |
| 100000000 | 36     | 29.897353             |

## Exercise 2.16

**Problem Statement**

_How many bits are there in the binary representation of $`H_n`$?_

**Solution**

In principle $`H_n`$ is not a positive real number, so we cannot guarantee that it has an
exact representation in binary.

If we were to truncate $`H_n`$ as an integer, then we
could approximate the number of digits as,

```math
\begin{align}
H_n \approx \ln\left(n\right) + \gamma\\
\implies \lg\left(H_n\right) \approx \lg\left(\lg\left(n\right)/\lg\left(e\right)\right) \\
\approx \lg\left(\lg\left(n\right)\right) - \lg\left(e\right)\\
\text{digits}\left(H_n\right) \approx \text{floor}\left(\lg\left(\lg\left(n\right)\right)\right) + 1.
\end{align}
```

Recall that the double logarithm of $`2^{256}`$ is $`8`$, this means that $`H_n`$ never grows very large.

See the comparison in the provided [data](./Exercises/Ex2_16/sample_output.dat) which looks at harmonic numbers indexed up to $`N = 1,000,000,000`$. The table is repeated below

| $`N`$     | $`H_n`$   | digits | $`\lg\lg\left(N\right)`$ |
|-----------|-----------|--------|------------------------|
| 1         | 1         | 1      | $`-\infty`$            |
| 10        | 2.888128  | 2      | 1                      |
| 100       | 5.183214  | 3      | 2                      |
| 1000      | 7.485049  | 3      | 2                      |
| 10000     | 9.787559  | 4      | 2                      |
| 100000    | 14.392721 | 4      | 2                      |
| 1000000   | 16.695306 | 5      | 3                      |
| 10000000  | 18.997891 | 5      | 3                      |
| 100000000 | 21.300476 | 5      | 3                      |

## [Exercise 2.17](./Exercises/Ex2_17/ex2_17.c)

**Problem Statement**

*Give a simple expression for $`\text{floor}\left(\lg\left(F_N\right)\right)`$
where $`F_N`$ is the $`N`$-th fibbonaci number.*

**Solution:**

An approximate solution is given by noting

```math
\begin{align}
F_N &= \text{round}\left(\frac{\phi^N}{\sqrt{5}}\right)\\
\implies \log(F_N) &\approx N\lg(\phi) - \frac{1}{2}\lg(5)
\end{align}
```

where $`\phi`$ is the golden ratio. See the implementation
in [exercise 2.17](./Exercises/Ex2_17/ex2_17.c). We provide results comparing this to an [exact calculation](./Exercises/Ex2_17/sample_output.dat), where we can see using an initial lookup table for the fibonnaci numbers $`F_{n \leq 3}`$ gives us agreement with the exact calculation for all $`n`$ looked at.

## [Exercise 2.18](./Exercises/Ex2_18/ex2_18.c)

**Problem Statement**

*Give the smallest value of $`N`$ for which $`\text{floor}\left(H_n\right) = i`$ for $`i \leq i \leq 10`$.*

**Solution**

The following table was generated using the linked c implementation. We also compare the result for using a direct calculation vs our approximation in the [raw data](./Exercises/Ex2_18/sample_output.dat). This implementation for calculating $`H_n`$ exactly uses a cache as discussed in [Exercise 2.12](#exercise-212).

There are discrepencies between the exact and approximate methods for $`1 < i \leq 5`$ but after that both methods agree.

| $`i`$   | $`N`$     | $`H_N`$   |
| --- | ----- | --------- |
| 1   | 1     | 1.0000    |
| 2   | 4     | 2.0833    |
| 3   | 11    | 3.0199    |
| 4   | 31    | 4.0272    |
| 5   | 83    | 5.0021    |
| 6   | 227   | 6.0043    |
| 7   | 616   | 7.0013    |
| 8   | 1674  | 8.0005    |
| 9   | 4550  | 9.0002    |
| 10  | 12367 | 10.0000   |

## [Exercise 2.19](./Exercises/Ex2_19/ex2_19.c)

**Problem Statement**

*Give the largest value of $`N`$ for which you can solve
a problem requiring $`f\left(N\right)`$ instructions on a machine that can execute $`10^9`$ instructions per second for the following functions*

1. $`N^{3/2}`$
2. $`N^{5/4}`$
3. $`2NH_{n}`$
4. $`N\lg\left(N\right)\lg\left(\lg\left(N\right)\right)`$
5. $`N^2\lg\left(N\right)`$

**Solution**

We take the largest value to mean that the computation completes in less than a second. Similar to the previous exercises we use an
implementation of Newton's method to calculate the
points.

| $`f\left(N\right)`$          | Largest $`N`$ |
| ------------- | --------- |
| $`N^{3/2}`$   | 1000000   |
| $`N^{5/4}`$   | 15848932  |
| $`2NH_{n}`$   | 28197672  |
| $`N\lg N\lg\lg N`$ | 9512470   |
| $`N^2\lg N`$    | 8739      |

The raw data can be seen in the [output](./Exercises/Ex2_19/sample_output.dat).

We can see that the relative growth rates of the functions are then $`2NH_n < N^{5/4} < N\lg N\lg\lg N < N^{3/2} < N^2\lg N`$.

## Big-O Notation

For the next section recall the definition of Big-O is given by: $`g`$ is $`\mathcal{O}\left(f\right)`$ if there $`c_0, N_0`$ s.t.

```math
\begin{align}
\left|g\left(N\right)\right| \leq c_0 \left|f\left(N\right)\right| \; \text{for all} \;  N > N_0
\end{align}
```

Often in Computer Science we can make the more restrictive assumption that $`f`$ and $`g`$ are defined
on the positive integers and the functions themselves are
positively-valued.

## Exercise 2.20

**Problem Statement**

*Prove that $`\mathcal{O}\left(1\right)`$ is the same as $`\mathcal{O}\left(2\right)`$.*

**Solution**

By definition a function $`g`$ is $`\mathcal{O}\left(1\right)`$ means, there exists $`c_o`$, $`N_0`$ s.t

```math
\begin{align}
\left|g\left(N\right)\right| \leq c_0 \; \text{for all} \;  N > N_0
\end{align}
```

Trivially define $`c_1 = c_0/2`$ then $`g`$ satisfies

```math
\begin{align}
\left|g\left(N\right)\right| < c_1 2 \; \text{for all} \;  N > N_0
\end{align}
```

and is thus trivially also $`\mathcal{O}\left(2\right)`$.

## Exercise 2.21

**Problem Statement**

*Prove that we can make any of the following transformations in the expression that uses the $`\mathcal{O}`$ notation:*

- $`f\left(N\right) \rightarrow \mathcal{O}\left(f\left(N\right)\right)`$

**Solution**

By definition a function $`f`$ is $`\mathcal{O}\left(f\left(N\right)\right)`$. Take any $`c_0 = 1`$ then any choice of $`N_0`$.

**Problem Statement**

- $`c\mathcal{O}\left(f\left(N\right)\right) \rightarrow \mathcal{O}\left(f\left(N\right)\right)`$.

**Solution**

From the definition, let $`g`$ be a function that is $`c \mathcal{O}\left(f\left(N\right)\right)`$. Then by definition there exists $`c_0, N_0`$ s.t.

```math
\begin{align}
\left|g\left(N\right)\right| \leq c\left(c_0\left|f\left(N\right)\right|\right) \; \text{for all} \;  N > N_0
\end{align}
```

Then define $`c_1 = cc_0`$. Then,

```math
\begin{align}
    \left|g\left(N\right)\right| \leq c_1\left|f\left(N\right)\right| \; \text{for all} \;  N > N_0.
\end{align}
```
Which is by definition $`\mathcal{O}\left(f\left(N\right)\right)`$.

**Problem Statement**

- $`\mathcal{O}\left(f\left(cN\right)\right) \rightarrow \mathcal{O}\left(f\left(N\right)\right)`$

**Solution**

From the definition, let $`g`$ be a function that is $`\mathcal{O}\left(cf\left(N\right)\right)`$. Then by definition there exists $`c_0, N_0`$ s.t.

```math
\begin{align}
\left|g\left(N\right)\right| \leq c_0\left|cf\left(N\right)\right| \; \text{for all} \;  N > N_0
\end{align}
```

Then define $`c_1 = cc_0`$. Then,

```math
\begin{align}
    \left|g\left(N\right)\right| \leq c_0c\left|f\left(N\right)\right| \; \text{for all} \;  N > N_0.\\
    \left|g\left(N\right)\right| \leq c_1\left|f\left(N\right)\right| \; \text{for all} \;  N > N_0.\\
\end{align}
```

Which is by definition $`\mathcal{O}\left(f\left(N\right)\right)`$.

**Problem Statement**

- $`f\left(N\right) - g\left(N\right) = \mathcal{O}\left(h\left(N\right)\right) \rightarrow f\left(N\right) = g\left(N\right) + \mathcal{O}\left(h\left(N\right)\right)`$.

**Solution**

```math
\begin{align}
    \left|f\left(N\right) - g\left(N\right)\right| &\leq c_0\left|h\left(N\right)\right| \; \text{for all} \;  N > N_0. \\
    \left|f\left(N\right) - g\left(N\right)\right| + g\left(N\right) &\leq c_0\left|h\left(N\right)\right| +g\left(N\right) \; \text{for all} \;  N > N_0 \\
    \left|f\left(N\right)\right| &\leq  c_0\left|h\left(N\right)\right| +g\left(N\right) \; \text{for all} \;  N > N_0\\
    \implies f\left(N\right) &= g\left(N\right) + \mathcal{O}\left(h\left(N\right)\right).
\end{align}
```

**Problem Statement**

- $`\mathcal{O}\left(f\left(N\right)\right)\mathcal{O}\left(g\left(N\right)\right) \rightarrow \mathcal{O}\left(f\left(N\right)g\left(N\right)\right)`$

**Solution**:

Let $`\tilde{f}`$ be a function s.t $`\tilde{f} = \mathcal{O}\left(f\left(N\right)\right)`$ and $`\tilde{g}`$ be a function s.t $`\tilde{g} = \mathcal{O}\left(g\left(N\right)\right)`$ with coefficients, $`c_f`$, $`N_f`$ and $`c_g`$, $`N_g`$ respectively. Then

```math
\begin{align}
\left|\tilde{f}\left(N\right)\tilde{g}\left(N\right)\right| &= \left|\tilde{f}\left(N\right)\right|\left|\tilde{g}\left(N\right)\right| \\
&\leq c_f\left|f\left(N\right)\right|c_g\left|g\left(N\right)\right| \; \text{ for all } N > N_f \text{ and } N_g\\
\end{align}
```

Define $`c = c_fc_g`$ and $`N_0 = \text{max}\left(N_f, N_g\right)`$, then

```math
\begin{align}
\left|\tilde{f}\left(N\right)\tilde{g}\left(N\right)\right| &\leq c\left|f\left(N\right)g\left(N\right)\right| \text{ for all } N > N_0.\\
\implies \left|\tilde{f}\left(N\right)\tilde{g}\left(N\right)\right| &= \mathcal{O}\left(f\left(N\right)g\left(N\right)\right)\\
\implies \mathcal{O}\left(f\left(N\right)\right)\mathcal{O}\left(g\left(N\right)\right) &\rightarrow \mathcal{O}\left(f\left(N\right)g\left(N\right)\right)
\end{align}
```

**Problem Statement**

- $`\mathcal{O}\left(f\left(N\right)\right) + \mathcal{O}\left(g\left(N\right)\right) \rightarrow \mathcal{O}\left(g\left(N\right)\right)`$ if $`f\left(N\right) =  \mathcal{O}\left(g\left(N\right)\right)`$

**Solution**

Let $`\tilde{f}\left(N\right)`$ and $`\tilde{g}\left(N\right)`$ be $`\mathcal{O}\left(f\left(N\right)\right)`$ and $`\mathcal{O}\left(g\left(N\right)\right)`$ with coefficients and indices,
$`c_f, N_f`$ and $`c_g`$, $`N_g`$ respectively. Moreover assume $`f\left(N\right)`$ is $`\mathcal{O}\left(g\left(N\right)\right)`$ with coefficients and indices $`c_h`$ and $`N_h`$.

```math
\begin{align}
\left|\tilde{f}\left(N\right) + \tilde{g}\left(N\right)\right| &\leq  \left|\tilde{f}\left(N\right)\right| + \left|\tilde{g}\left(N\right)\right|\\
&\leq c_f\left|f\left(N\right)\right| + c_g\left|g\left(N\right)\right| \text { for all } N > N_f \text{ and } N_g\\
&\leq (c_fc_h + c_g)\left|g\left(N\right)\right| \text{ for all } N > N_f, N_h \text{ and } N_g.
\end{align}
```

Take $`c = c_fc_h + c_g`$ and $`N_0 = \text{max}\left(N_f, N_h, N_g\right)`$ and the result follows trivially.

## Exercise 2.22

**Problem Statement**

*Show that $`\left(N + 1\right)\left(H_n + \mathcal{O}\left(1\right)\right) = N\ln N + \mathcal{O}\left(N\right)`$.*

**Solution**

Expanding out:

```math
\begin{align}
\left(N + 1\right)\left(H_n + \mathcal{O}\left(1\right)\right) &= NH_n + H_n + N\mathcal{O}\left(1\right) + \mathcal{O}\left(1\right) \\
&= NH_n + H_n + \mathcal{O}\left(N\right) + \mathcal{O}\left(N\right) \\
&= NH_n + H_n + \mathcal{O}\left(N\right).
\end{align}
```

From the approximation $`H_n = \log\left(N\right) + \gamma + 1/\left(2N\right)`$ we then have
```math
\begin{align}
\left(N + 1\right)\left(H_n + \mathcal{O}\left(1\right)\right) &= N\log\left(N\right) + \left(N + 1\right)\gamma + \frac{1}{2}\left(1 + \frac{1}{N}\right) + \log\left(N\right) + \mathcal{O}\left(N\right). 
\end{align}
```
We can see that all of the terms besides the leading $`N\log\left(N\right)`$ term are $`\mathcal{O}\left(N\right)`$ and can be absorbed into the big-O to give,

```math
\begin{align}
\left(N + 1\right)\left(H_n + \mathcal{O}\left(1\right)\right) &= N\log N + \mathcal{O}\left(N\right)
\end{align}
```

## Exercise 2.23

**Problem Statement**

*Show that $`N\log\left(N\right) = \mathcal{O}\left(N^{3/2}\right)`$*

**Solution**

For this we need the brief lemma below

**Lemma 1**

```math
\begin{align}
\lim_{x \rightarrow \infty}\frac{f\left(x\right)}{g\left(x\right)} \neq \infty &\implies f\left(x\right) = \mathcal{O}\left(g\left(x\right)\right).
\end{align}
```

**Proof**

Let the limit be $`x_0`$, then by the limit definition $`\forall \epsilon > 0 \text{ } \exists c > 0`$ such that
```math
\begin{align}
\left|\frac{f\left(x\right)}{g\left(x\right)} - x_0\right| &< \epsilon, \text{ } \forall x > c.\\
\implies \left|f\left(x\right) - x_0g\left(x\right)\right| &< \epsilon\left|g\left(x\right)\right|, \text{ } \forall x > c.
\end{align}
```
Let any $`c`$ be $`N_0`$ and let $`c_0`$ be the corresponding $`\epsilon`$ then, we easily see that
```math
\begin{align}
f\left(x\right) - x_0g\left(x\right) &= \mathcal{O}\left(g\left(x\right)\right)\\
\implies f\left(x\right) &= \mathcal{O}\left(g\left(x\right)\right)
\end{align}
```

Now we can prove the main statement indirectly, consider the limit
```math
\begin{align}
\lim_{x \to \infty}\frac{N\ln N}{N^{3/2}} &= \lim_{x \to \infty}\frac{\ln N + 1}{\frac{3}{2}N^{1/2}}\\
&= \lim_{x \to \infty}\frac{\frac{1}{N}}{\frac{3}{4N^{1/2}}}\\
&= \lim_{x \to \infty}\frac{4}{3N^{1/2}} \\
&= 0.
\end{align}
```
Which from the above lemma gives $`N\lg N = \mathcal{O}\left(N^{3/2}\right)`$.

## Exercise 2.24

**Problem Statement**

*Show that $`N^{M} = \mathcal{O}\left(\alpha^{N}\right)`$ for any $`M`$ and any constant $`\alpha > 1`$.*

**Solution**

Consider the limit
```math
\lim_{x \rightarrow \infty}\frac{N^{M}}{\alpha^N}.
```
For $`\alpha > 1`$,  $\alpha^N$ clearly goes to $`\infty`$. If $`M < 0`$, then $`N^M`$ clearly goes to $`0`$. Else if $`M < 1`$, $`N^{M} < N`$ so we need only examine $`M \geq 1`$.

Then
```math
\begin{align}
\lim_{x \rightarrow \infty} \frac{N^{M}}{\alpha} &= \lim_{x \rightarrow \infty} \left(\frac{N}{\alpha^{N/M}}\right)^{M}
\end{align}
```
Consider the $`M`$-th root of the above, then this defines a sequence
```math
a_n = \left(\frac{N}{c^N}\right)
```
where $`c = \alpha^{M} > 1`$. Now let $`c = d + 1`$, then from the binomial theorem
```math
\begin{align}
c^n = \left(1 + d \right)^n &\geq 1 + 2n + \frac{d}{2}n\left(n - 1\right) > \frac{d^2}{2}n\left(n - 1\right)\\
\implies \frac{n}{c^n} &< \frac{2n}{d^2n\left(n - 1\right)}\\
\implies \lim_{x \rightarrow \infty} 0 &< \lim_{x \rightarrow \infty}\frac{n}{c^n} < \lim_{x \to \infty}\frac{2}{d^2\left(n - 1\right)} \rightarrow 0
\end{align}
```
So we have the limit of $n/c^n$ goes to $0$. But we then also have $`\left(n/c^n\right)^M < \left(n/c^n\right)`$ so

```math
\begin{align}
\lim_{x \to \infty}\frac{N^M}{\alpha^N} \rightarrow 0.
\end{align}
```

and from our initial case analysis this holds for all $`M`$ and all $`\alpha > 1`$.

Which from the previous exercise immediately tells us that under the same conditions,

```math
\begin{align}
N^M = \mathcal{O}\left(\alpha^N\right).
\end{align}
```

## Exercise 2.24

**Problem Statement**

*Prove that*

```math
\begin{align}
\frac{N}{N + \mathcal{O}\left(1\right)} &= 1 + \mathcal{O}\left(\frac{1}{N}\right)
\end{align}
```

**Solution**

We are asked to prove that
```math
\begin{align}
f\left(N\right) = 1 + \mathcal{O}\left(\frac{1}{n}\right)
\end{align}
```
or formally,
```math
\begin{align}
f\left(N\right) - 1 = \mathcal{O}\left(\frac{1}{N}\right)
\end{align}
```
We can also say that
```math
\begin{align}
f\left(N\right) &= \frac{N}{N + \mathcal{O}\left(1\right)} \\
\implies f\left(N\right) &= \frac{N}{N + g\left(N\right)}
\end{align}
```
where $`g\left(N\right)`$ is some $`\mathcal{O}\left(1\right)`$ function. Combining the two equations gives,
```math
\begin{align}
\left|f\left(N\right) - 1\right| &= \left|\frac{N}{N + g\left(N\right)} - 1\right| \\
&= \left|\frac{g\left(N\right)}{N + g\left(N\right)}\right| \\
&< \left|\frac{g\left(N\right)}{N}\right| \\
\end{align}
```
But since $`g\left(N\right)`$ is $`\mathcal{O}\left(1\right)`$ there exists $`c_0, N_0`$ s.t for all $`N > N_0`$
```math
\begin{align}
\left|f\left(N\right)\right| &< c_0\left|\frac{1}{N}\right| \\
\implies f\left(N\right) - 1 &= \mathcal{O}\left(\frac{1}{N}\right)\\
\implies f\left(N\right) &= 1 + \mathcal{O}\left(1\right).
\end{align}
```
**Note** here we need the leading order in exact form else we can't bound the denominator.

## [Exercise 2.26](./Exercises/Ex2_26/ex2_26.c)

**Problem Statement**

*Suppose that $`H_{k} = N`$, give an approximate formula that expresses $`k`$ as a function of $`N`$.*

**Solution**

Recall we have the approximation






## [Exercise 2.33](./Exercises/Ex2_33/ex2_33.c)

**Problem Statement**

*Give a table of the values of $`C_N`$ given*

```math
\begin{align}
C_N = C_{N/2} + 1
\end{align}
```

**Solution**

For $`1 \leq N \leq 32`$, interpreting $`N/2`$ to mean
the $`floor(N/2)`$ we generate the below table from our
C implementation.

| N   | $C_N$ |
| --- | ----- |
| 1   | 1     |
| 2   | 2     |
| 3   | 2     |
| 4   | 3     |
| 5   | 3     |
| 6   | 3     |
| 7   | 3     |
| 8   | 4     |
| 9   | 4     |
| 10  | 4     |
| 11  | 4     |
| 12  | 4     |
| 13  | 4     |
| 15  | 4     |
| 16  | 5     |
| 17  | 5     |
| 18  | 5     |
| 19  | 5     |
| 20  | 5     |
| 21  | 5     |
| 22  | 5     |
| 23  | 5     |
| 24  | 5     |
| 25  | 5     |
| 26  | 5     |
| 27  | 5     |
| 28  | 5     |
| 29  | 5     |
| 30  | 5     |
| 31  | 5     |
| 32  | 6     |

See the raw [results](./Exercises/Ex2_33/sample_output.dat).

## [Exercise 2.34](./Exercises/Ex2_34/ex2_34.c)

**Problem Statement**

*Give a table of the values of $`C_N`$ given*

```math
\begin{align}
C_N = C_{N/2} + 1
\end{align}
```

*for $`1 \leq N \leq 32`$, interpreting $`N/2`$ to mean
the $`\text{ceil}\left(N/2\right)`$.*

**Solution**

See the table generated below

| N   | $C_N$ |
| --- | ----- |
| 1   | 1     |
| 2   | 2     |
| 3   | 3     |
| 4   | 3     |
| 5   | 4     |
| 6   | 4     |
| 7   | 4     |
| 8   | 4     |
| 9   | 5     |
| 10  | 5     |
| 11  | 5     |
| 12  | 5     |
| 13  | 5     |
| 15  | 5     |
| 16  | 5     |
| 17  | 6     |
| 18  | 6     |
| 19  | 6     |
| 20  | 6     |
| 21  | 6     |
| 22  | 6     |
| 23  | 6     |
| 24  | 6     |
| 25  | 6     |
| 26  | 6     |
| 27  | 6     |
| 28  | 6     |
| 29  | 6     |
| 30  | 6     |
| 31  | 6     |
| 32  | 6     |

See the raw [output](./Exercises/Ex2_34/sample_output.dat) from the C program used to generate this.

## [Exercise 2.35](./Exercises/Ex2_35/ex2_35.c)

**Problem Statement**

*Give a table of the values of $`C_N`$ given*

```math
\begin{align}
C_N = C_{N/2} + N
\end{align}
```

*for $`1 \leq N \leq 32`$, interpreting $`N/2`$ to mean
the $`\text{ceil}\left(N/2\right)`$.*

**Solution**

See the table generated below

| N   | $C_N$ |
| --- | ----- |
| 1   | 0     |
| 2   | 2     |
| 3   | 5     |
| 4   | 6     |
| 5   | 10    |
| 6   | 11    |
| 7   | 13    |
| 8   | 14    |
| 9   | 19    |
| 10  | 20    |
| 11  | 22    |
| 12  | 23    |
| 13  | 26    |
| 15  | 27    |
| 16  | 30    |
| 17  | 36    |
| 18  | 37    |
| 19  | 39    |
| 20  | 40    |
| 21  | 43    |
| 22  | 44    |
| 23  | 46    |
| 24  | 47    |
| 25  | 51    |
| 26  | 52    |
| 27  | 54    |
| 28  | 55    |
| 29  | 58    |
| 30  | 59    |
| 31  | 61    |
| 32  | 62    |

and the corresponding raw [output](./Exercises/Ex2_35/sample_output.dat) file.

## [Exercise 2.49](./Exercises/Ex2_49/ex2_49.c)

**Problem Statement**

*Write a driver program that generates $`M`$ random integers
and puts them in an array, then counts the number of $`N`$
random integers that matches one of the numbers in the
array, using sequential search. Run your program for
$`M = 10, 100`$, and $`1000`$ and $`N = 10, 100`$, and $`1000`$.*

**Solution**

See the implementation in [ex2.49](./Exercises/Ex2_49/ex2_49.c) and the sample output in [ex2_49.dat](./Exercises/Ex2_49/ex2_49.dat).
