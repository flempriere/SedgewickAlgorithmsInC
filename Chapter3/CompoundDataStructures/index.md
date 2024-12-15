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

## Exercises

