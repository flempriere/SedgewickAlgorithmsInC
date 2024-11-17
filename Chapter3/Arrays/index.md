# Arrays

## Examples

### [Program 3.5](./Examples/Program3_5/program3_5_sieve.c)

#### Sieve of Eratosthenes

*Finds all the primes up to N using an array. All array
elements are initially set to `true`. We then iterate over the array, when we find an element `i` set to `true` indicating it is prime, we then set all its multiples `ij < N` to false and continue looping.*

See sample output in [program3_5.dat](./Examples/Program3_5/program3_5.dat)

### [Program 3.6](./Examples/Program3_6/program3_6_dynamic_allocation.c)

#### Dynamic Memory Allocation

*We can modify [Program 3.5](#program-35) to accept
the largest number $N$ from the command line. This then needs us to dynamically allocate the array size. This program demonstrates how such an allocation is done*

### [Program 3.7](./Examples/Program3_7/program3_7_coin_flipping.c)

#### Coin-flipping simulation

*Simulates a sequence of $N$ coin tosses, $M$ times, counting the number of heads in each instance, and then
prints out the distribution. An array is used to store
the distribution counts*.

See sample output for $N = 32$, $M = 1000$ in [Program3_7.dat](./Examples/Program3_7/program3_7.dat)

### [Program 3.8](./Examples/Program3_8/program3_8_closest_point.c)

#### Closest-point Computation

*This program illustrates the use of an array of
structures, and is representative of the typical
situation where we save items in an array to pairs of $N$ randomly generated points in the unit square that
can be connected by a straight line of length less
than $d$, using the data type for points in [Section 3.1](../BuildingBlocks/index.md). The running time is
$\mathcal{O}(N^2)$.*

## Exercises

### [Exercise 3.11](./Exercises/Ex3_11/ex3_11.c)

*Suppose that `a` is declared as `int a[99]`. Give the
contents of the array after the following two
statements are executed:*

```
for (i = 0; i < 99; i++) a[i] = 98-i;
for (i = 0; i < 99; i++) a[i] = a[a[i]];
```
See [ex3_11.dat](./Exercises/Ex3_11/ex3_11.dat) for output.

We have an array that ascends from `0` to the midpoint,
then descends back to `0`.

### [Exercise 3.12](./Exercises/Ex3_12/ex3_12.c)

*Modify the implementation of the sieve of Eratosthenes
([Program 3.5](#program-35)) to use an array of*

1. chars
2. bits

*Determine the effects of these changes on the amount of
space and time used by the program.*

Note in our original solution we used `Bool` as the array type which on our system has the same width
as a `char` so we only look at the `bit` implementation.

Testing for $N = 100000$ we find that the `char/Bool` implementation is twice as fast as the `bit` implementation. But it uses $8$ times more memory.

### [Exercise 3.13](./Exercises/Ex3_13/ex3_13.c)

*Use the Sieve of Eratosthenes to determine the number
of primes less than $N$, for $N = 10^3, 10^4, 10^5, 10^6$.*

See the sample output in [ex3_13.dat](./Exercises/Ex3_13/ex3_13.dat)

### [Exercise 3.14](./Exercises/Ex3_14/ex3_14.c)

*Use the sieve of Eratosthenes to draw a plot of $N$ versus the number of primes less than $N$ for $N$ between $1$ and $1000$.*

See the sample output in [ex3_14.dat](./Exercises/Ex3_14/ex3_14.dat)

### [Exercise 3.15](./Exercises/Ex3_15/ex3_15.c)

*Empirically determine the effect of removing the
test `if (a[i])` that guards the inner loop of
[Program 3.5](#program-35) for $N = 10^3, 10^4, 10^5, 10^6$.*

See the results in [ex3_15.dat](./Exercises/Ex3_15/ex3_15.dat). For small $N$ the unguarded and guarded
have comparable runtimes. But the runtime of the unguarded approach grows much faster.

### Exercise 3.16

*Analyse [Program 3.5](#program-35) to explain the
observed effect*

**Solution**: Observe that with the guard we only perform the inner loop when we encounter a new prime.

However now each time we go through the array we perform the inner loop. The number of iterations at index $i$ of the inner loop are $N/i$. So the function behaves grows like

$$
\begin{align}
    \sum_{i = 2}^{N}\frac{N}{i} & = NH_n.
\end{align}
$$
So in this case the runtime is exactly like our approximation. Where as with the guard, primes grow
more sparse at higher $N$ and we perform the inner
loop less and less so the relative performance diverges for large $N$.

### [Exercise 3.17](./Exercises/Ex3_17/ex3_17.c)

*Write a program that determines empirically the number of random positive integers less than $1000$ that you can expect to generate before getting a repeated value.*

See the [testing script](./Exercises/Ex3_17/testEx3_17.sh) and the [sample output](./Exercises/Ex3_17/tests/20241117/ex3_17.dat) for 10 tests, generating 100 numbers and the [results](./Exercises/Ex3_17/tests/20241117/ex3_17.dat)
for 1 test generating 10000 numbers.

### [Exercise 3.18](./Exercises/Ex3_18/ex3_18.c)

*Write a program that determines empirically the number of random positive integers less than $1000$ that you can expect
to generate before getting a repeated value*

See [ex3_18.dat](./Exercises/Ex3_18/ex3_18.dat) for generated output with $M = 1000$.

### [Exercise 3.19](./Exercises/Ex3_19/ex3_19.c)

*Write a program that determines empirically the number of
random positive integers less than 1000 that you can expect
to generate before getting each value at least once.*

See [ex3_19.dat](./Exercises/Ex3_19/ex3_19.dat) for generated
output with $M = 1000$.

### [Exercise 3.20](./Exercises/Ex3_20/ex3_20.c)

*Modify [Program 3.7](#program-37) to simulate a situation
where the coin turns up heads with probability $p$. Run
$1000$ trials for an experiment with $32$ flips with $p =1/6$
to get output that can be compared with the sample output for [Program 3.7](./Examples/Program3_7/program3_7.dat).*

See the sample output in [ex3_20.dat](./Exercises/Ex3_20/ex3_20.dat)

### [Exercise 3.21](./Exercises/Ex3_21/ex3_21.c)

*Modify [Program 3.7](#program-37) to simulate a situation
where the coin turns up heads with probability $\lambda/N$.*

*Run $1000$ trials for an experiment with $32$ flips to get
output that you can compare with the sample output for 
[Program 3.7](./Examples/Program3_7/program3_7.dat). This distribution is the classical **Poisson distribution***.

See the sample output in [ex3_21.dat](./Exercises/Ex3_21/ex3_21.dat)

### [Exercise 3.22](./Exercises/Ex3_22/ex3_22.c)

*Modify [Program 3.8](#program-38) to print out the coordinates
of the closest pair of points.*

### [Exercise 3.23](./Exercises/Ex3_23/ex3_23.c)

*Modify [Program 3.8](#program-38) to perform the same
computation in $d$ dimensions.*








