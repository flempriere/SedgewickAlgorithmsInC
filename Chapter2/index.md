# Examples

## [Program 2.1](./Examples/program2_1_sequential_search.c)
### Sequential Search

This function checks if the number `v` is in a previously
stored set of numbers in `a[1],...,a[r]`, by comparing
against each number sequentially, starting at the beginning.

If we reach the end without finding the number stored, then 
we return `NOT_FOUND` (an alias for `SIZE_MAX`).

## [Program 2.2](./Examples/Program2_2/program2_2_binary_search.c)
### Binary Search

Has the same functionality as Program 2.1, but utilises a
sorted array for greater efficiency.

# Exercises

## [Exercise 2.2](./Exercises/Ex2_2/ex2_2.c)

*Determine the amount of time it takes to run the 
following code snippet for $N = 10, 100, 1000$. If
your compiler has optimisation features test the
impact of these.*

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
Sample timings on my machine can be found in [ex2_2.dat](./Exercises/Ex2_2/ex2_2.dat).

## [Exercise 2.5](./Exercises/Ex2_5/ex2_5.c)

*For what values of $N$ is $10N\lg(N) > 2N^2$?*

**Solution**:

Observe the following:
$$
\begin{align*}
N = 1 \implies 10N\lg(N) &= 0\\
2N^2 &= 1\\

N = 2 \implies 10N\lg(N) &= 20\\
2N^2 & = 8\\

N = 32 \implies 10N\lg(N) &= 1600\\
2N^2 &= 2048
\end{align*}
$$
So the we have that the crossover points must be at
some $x_1 < 2$ and $x_2 < 32$. Using [Newtons Method](./Exercises/Ex2_5/ex2_5.c) to solve numerically leads to
$ 1.177 < N < 22.44$.

## [Exercise 2.6](./Exercises/Ex2_6/ex2_6.c)

*For what values of N is $N^{3/2}$ between $N\left(\lg(N)^2/2\right)$ and $2N\left(\lg(N)^2\right)$?*

**Solution**:
Observe the following:
$$
\begin{align*}
N = 1 \implies N\lg(N)^2 &= 0\\
N^(3/2) &= 1\\

N = 4 \implies N\lg(N)^2 &= 16\\
2N^(3/2) & = 8\\
\end{align*}
$$
So we can see that regions of interest are around $N=1$
and $N = 4$. Using newton's method again we find the regions
to be
$$
\begin{align}
0.448369 \leq N \leq 0.6445474\\
1.7584 \leq N \leq 4.
\end{align}
$$

## [Exercise 2.7](./Exercises/Ex2_7/ex2_7.c)

*For what values of $N$ is $2NH_N - N < NlgN + 10N$?*

**Solution**:
We approximate $H_N$ by
$$
\begin{align}
H_n = \lg(N) + \gamma
\end{align}
$$
where $\gamma$ is Euler's constant. Then
$$
\begin{align}
2NH_N - N &< NlgN + 10N\\
2N\lg(N) + 2N\gamma - N &< N\lg(N) + 10N\\
\implies \lg(N) &< 10\\
\implies N &< 2^{10}.
\end{align}
$$
Solving using Newtons Method we find
$$
\begin{align}
0 < N < 47035526.49.
\end{align}
$$

## Exercise 2.8
*what is the smallest value of $N$ for which $\log_{10}\log_{10}N > 8$?*

**Solution**:
$$
\begin{align}
\log_{10}N > 10^{8}\\
\implies N > 10^{10^8}.
\end{align}
$$

## Exercise 2.10-11

*Add columns to Table 2.1 for $N(\lg(N))^2$, $N^{(3/2)}$, and $10^7$, $10^8$ operations per second*

| Operations per second | Problem size 1 million |              |              |         |         |
|-----------------------|------------------------|--------------|--------------|---------|---------|
|                       | N                      | NlgN         | N(lgN)^2     | N^(3/2) | N^2     |
| 10^6                  | seconds                | seconds      | seconds      | minutes | weeks   |
| 10^7                  | milliseconds           | milliseconds | seconds      | minutes | days    |
| 10^8                  | instant                | instant      | milliseconds | seconds | hours   |
| 10^9                  | instant                | instant      | instant      | seconds | hours   |
| 10^12                 | instant                | instant      | instant      | instant | seconds |

| Operations per second | Problem size 1 billion |         |          |         |         |
|-----------------------|------------------------|---------|----------|---------|---------|
|                       | N                      | NlgN    | N(lgN)^2 | N^(3/2) | N^2     |
| 10^6                  | hours                  | hours   | days     | years   | never   |
| 10^7                  | minutes                | minutes | hours    | weeks   | never   |
| 10^8                  | seconds                | minutes | minutes  | days    | never   |
| 10^9                  | seconds                | seconds | minutes  | hours   | decades |
| 10^12                 | instant                | instant | instant  | seconds | weeks   |

## [Exercise 2.12](./Exercises/Ex2_12/ex2_12.c)

*Write a C function that computes $H_N$ using the `log`
function from the standard math library.*

## [Exercise 2.13](./Exercises/Ex2_13/ex2_13.c)

*Write an efficient C function that computes $ceil(lg(lg(N)))$ without use of a library function.*

## [Exercise 2.17](./Exercises/Ex2_17/ex2_17.c)

*Give a simple expression for $floor(\lg(F_N))$
where $F_N$ is the $N$-th fibbonaci number.*

**Solution:** An approximate solution is given by noting
$$
\begin{align}
F_N &= \frac{\phi^N}{\sqrt{5}}\\
\implies \log(F_N) &= N\lg(\phi) - \frac{1}{2}\lg(5)
\end{align}
$$
where $\phi$ is the golden ratio. See the implementation
in [exercise 2.17](./Exercises/Ex2_17/ex2_17.c).

## [Exercise 2.18](./Exercises/Ex2_18/ex2_18.c)

*Give the smallest value of $N$ for which $floor(H_n) = i$
for $i \leq i \leq 10$.*

| i  | N     | $H_N$     |
|----|-------|---------|
| 1  | 1     | 1.0000  |
| 2  | 4     | 2.0833  |
| 3  | 11    | 3.0199  |
| 4  | 31    | 4.0272  |
| 5  | 83    | 5.0021  |
| 6  | 227   | 6.0043  |
| 7  | 616   | 7.0013  |
| 8  | 1674  | 8.0005  |
| 9  | 4550  | 9.0002  |
| 10 | 12367 | 10.0000 |

## [Exercise 2.33](./Exercises/Ex2_33/ex2_33.c)

*Give a table of the values of $C_N$ given*
$$
\begin{align}
C_N = C_{N/2} + 1
\end{align}
$$
*for $1 \leq N \leq 32$, interpreting $N/2$ to mean
the $floor(N/2)$.*

| N  | $C_N$ |
|----|-----|
| 1  | 1   |
| 2  | 2   |
| 3  | 2   |
| 4  | 3   |
| 5  | 3   |
| 6  | 3   |
| 7  | 3   |
| 8  | 4   |
| 9  | 4   |
| 10 | 4   |
| 11 | 4   |
| 12 | 4   |
| 13 | 4   |
| 15 | 4   |
| 16 | 5   |
| 17 | 5   |
| 18 | 5   |
| 19 | 5   |
| 20 | 5   |
| 21 | 5   |
| 22 | 5   |
| 23 | 5   |
| 24 | 5   |
| 25 | 5   |
| 26 | 5   |
| 27 | 5   |
| 28 | 5   |
| 29 | 5   |
| 30 | 5   |
| 31 | 5   |
| 32 | 6   |

## [Exercise 2.34](./Exercises/Ex2_34/ex2_34.c)

*Give a table of the values of $C_N$ given*
$$
\begin{align}
C_N = C_{N/2} + 1
\end{align}
$$
*for $1 \leq N \leq 32$, interpreting $N/2$ to mean
the $ceil(N/2)$.*


| N  | $C_N$ |
|----|-----|
| 1  | 1   |
| 2  | 2   |
| 3  | 3   |
| 4  | 3   |
| 5  | 4   |
| 6  | 4   |
| 7  | 4   |
| 8  | 4   |
| 9  | 5   |
| 10 | 5   |
| 11 | 5   |
| 12 | 5   |
| 13 | 5   |
| 15 | 5   |
| 16 | 5   |
| 17 | 6   |
| 18 | 6   |
| 19 | 6   |
| 20 | 6   |
| 21 | 6   |
| 22 | 6   |
| 23 | 6   |
| 24 | 6   |
| 25 | 6   |
| 26 | 6   |
| 27 | 6   |
| 28 | 6   |
| 29 | 6   |
| 30 | 6   |
| 31 | 6   |
| 32 | 6   |

## [Exercise 2.35](./Exercises/Ex2_35/ex2_35.c)

*Give a table of the values of $C_N$ given*
$$
\begin{align}
C_N = C_{N/2} + N
\end{align}
$$
*for $1 \leq N \leq 32$, interpreting $N/2$ to mean
the $ceil(N/2)$.*

| N  | $C_N$ |
|----|-----|
| 1  | 0   |
| 2  | 2   |
| 3  | 5   |
| 4  | 6   |
| 5  | 10  |
| 6  | 11  |
| 7  | 13  |
| 8  | 14  |
| 9  | 19  |
| 10 | 20  |
| 11 | 22  |
| 12 | 23  |
| 13 | 26  |
| 15 | 27  |
| 16 | 30  |
| 17 | 36  |
| 18 | 37  |
| 19 | 39  |
| 20 | 40  |
| 21 | 43  |
| 22 | 44  |
| 23 | 46  |
| 24 | 47  |
| 25 | 51  |
| 26 | 52  |
| 27 | 54  |
| 28 | 55  |
| 29 | 58  |
| 30 | 59  |
| 31 | 61  |
| 32 | 62  |

## [Exercise 2.49](./Exercises/Ex2_49/ex2_49.c)

*Write a driver program that generates $M$ random integers
and puts them in an array, then counts the number of $N$
random integers that matches one of the numbers in the
array, using sequential search. Run your program for
$M = 10, 100$, and $1000$ and $N = 10, 100$, and $1000$.*

See the implementation in [ex2.49](./Exercises/Ex2_49/ex2_49.c) and the sample output in [ex2_49.dat](./Exercises/Ex2_49/ex2_49.dat).





