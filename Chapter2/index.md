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