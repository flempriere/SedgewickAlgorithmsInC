# Compound Data Structures

## Examples

### [Program 3.16](./Examples/Program3_16/two_dimArrayAllocation.c)

#### Two Dimensional Array allocation

*Dynamically allocates the memory for a
two-dimensional array, as an array of arrays.*

*We first allocate an array of pointers, then
allocate memory for each row.*
 
*malloc2d(M,N) allocates an M by N integer array*

### [Program 3.17](./Examples/Program3_17/stringSorting.c)

#### String Sorting

*This program illustrates an important
string processing-function: rearranging a set of
strings into sorted order. We read strings into
a buffer large enough to hold them all, maintaining
a pointer to each string in an array, then rearrange
the the pointers to put the pointer to the smallest
string in the first position etc.* 

*We make use of the library function qsort.*

### [Program 3.18](./Examples/Program3_18/adjacencyMatrix.c)
#### Adjacency Matrix

*This program reads a set of edges that define an
undirected graph and builds an adjacency matrix representation
for the graph, setting a[i][j] and a[j][i] to 1, if there is
an edge from i to j or j to i in the graph, or to 0 if there
is no such edge.*
 
*The program assumes that the number of vertices V is a compile
time constant. Otherwise, it would need to dynamically
allocate the adjacency matrix (see [Ex. 3.72](#exercise-372))*

### [Program 3.19](./Examples/Program3_19/adjacencyList.c)

*This program reads a set of edges that define a graph and builds
an adjacency-matrix representation for the graph. An adjacency list
for a graph is an array of lists, one for each vertex, where
the $j$th list contains a linked-list of the nodes connected to
the $j$th vertex.*

### [Program 3.20](./Examples/Program3_20/program3_20.c)

*This program illustrates the use of effectiveness of proper
data structure choices, for the geometric computation of
program 3.8. The unit square is divided into a grid, a two
dimensional array of linked lists, with one list corresponding
to each grid square. The grid is chosen to be sufficiently fine
that all points within distance $d$ of any given point are either
in the same grid square or an adjacent one.*

**Note**: In a unit square the maximum distance between two points
is $\sqrt{2}$. The original book code has an invalid memory access
error when $d < 1$ caused by $G = 1.0/d$ becoming $0$. We fix this
by making the grid size determined by $G = \sqrt{2}/d$.

See the [sample output](./Examples/Program3_20/program3_20.dat) and
the corresponding [test script](./Examples/Program3_20/testProgram3_20.sh).

**Note**: This program has a rare bug causing a crash if 1.0 as a coordinate is exactly generated due an array out of bounds error.

## Exercises

### [Exercise 3.63](./Exercises/Ex3_63/ex3_63.c)

*Write a version of [Program 3.16](#program-316) that handles
**three**-dimensional arrays.*

This is a straightforward extension from the two dimensional case
using a higher-order point. For a three dimensional array of size $L$ by $M$ by $N$ the equivalent one-dimensional representation has
the index calculation
```
3DArray[i][j][k] = i*(M*N) + j*(N) + k;
```

### [Exercise 3.64](./Exercises/Ex3_64/ex3_64.c)

*Modify [Program 3.17](#program-317) to process input strings, individually (allocate memory for each string after reading it from
the input). You can assume that strings have less than 100 characters*

Again this a straightforward change. We use `string.h` library
functions to update `extractWord`. This choice is made to preserve
the behaviour of the function returning the extracted word length.

This requires us to use a `char**` pointer to store the dynamic allocation, i.e. a pointer to where the `char*` buffer is. We could
work directly with a `char*` if we returned the pointer, but
this would alter the behaviour of the function significantly compared to [Program 3.17](#program-317).

### [Exercise 3.65](./Exercises/Ex3_65/ex3_65.c)

*Write a program to fill in a two-dimensional array of `0-1` (in our version `bool`) values by settings `a[i][j]` to `1` if the greatest common divisor of `i` and `j` is `1`, else `0`. (i.e. if they are coprime.)*

This is a straightforward exercise. Compute the `gcd`, and store the appropriate result in a dynamically allocated 2D array. We can
squeeze out somme extra efficiency by noting `gcd(i, j) = gcd(j, i)`
and `gcd(i, i) = i`. So we have `a[i][i] == 1 <=> i = 1` and we only
need to perform the nested loop
```
for (i = 0; i < N; i++) {
    a[i][i] = (i == 1);
    for (j = 0; j < i; j++) {
        a[i][j] = (gcd(i, j) == 1);
        a[j][i] = a[i][j];
    }
}
```
which removes about half of the calls to `gcd`. One could note that while computing `gcd(i, j)` we compute a bunch of intermediate values which could also be stored directly in the array. This potential improvement is left for the readers enjoyment.

See the [sample output](./Exercises/Ex3_65/ex3_65.dat) for $N = 10$.

### [Exercise 3.66](./Exercises/Ex3_66/ex3_66.c)

*Use [Program 3.20](#program-320) in conjunction with [Program 1.4](../../Chapter1/index.md#program-14) to develop an efficient program
that can determine whether a set of $N$ points can be connected with edges of length less than $d$.*

The idea is to perform the grid construction as for [Program 3.20](#program-320), however we now add a disjoint set structure on top.
For simplicity we extend our nodes with a unique id corresponding to an index in the disjoint set array.

We then maintain a counter of the number of disjoint sets.
When we add a point, we add it to the disjoint set array and increment the number of disjoint sets by one. As with [Program 3.20](#program-320) we then check adjacent grid squares and check if the
distance to any point is $< d$. If so we perform a `unionFind` operation. If these two points aren't already connected we have merged two sets and we decrement our counter.

Then once we have read in and performed the `unionFind` operations for all `N` points  we check if the number of disjoint sets is less than or equal to $1$. (**Note**: the set counter will only be zero when $N = 0$, in which point the solution is trivially true.)

**Note**: While our code implementation is quite large compared to some of the other exercises this largely comes from a large amount of error checking on the input.


**Note**: Currently has a bug arising from an array out of bounds error when a point contains an $x$ or $y$ coordinate that is exactly $1.0$.


