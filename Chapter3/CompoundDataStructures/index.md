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

**Note**: To be updated to remove the dependency on `scanf`.

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

**Note**: Currently this solution isn't working and has an infinite
loop on reading input

## Exercises

