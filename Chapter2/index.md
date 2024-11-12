# Examples

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

Tasks

[ ] - check correct understanding of ex2.6

