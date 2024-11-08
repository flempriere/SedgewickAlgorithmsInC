
# Examples

## [Program 1.1](./Examples/UnionFind_1_1.c)

### QuickFind Solution to the Connectivity Problem

Reads in a sequence of pairs of non-negative integers less than N from standard input. Input is structured as `p q` to mean connect `p` to `q`. If `p q` are not yet connected then they are reprinted
out.

Uses an array `id` of size `N` with the property
`id[p] == id[q]` iff `p` and `q` are connected.

This approach allows us to check connectivity in constant time, but requires linear time to update
the array for joins.

For processing `M` unions on `N` objects this takes $MN$ operations since we must iterate over the entire array $MN$ times.
## [Program 1.2](./Examples/UnionFind_1_2.c)

### QuickUnion solution to the Connectivity Problem

Replaces the body of the `while` loop in [Program 1.1](#program-11) with code that performs faster
unions at the cost of slower finds. Each connected component is stored as a tree with `id[p]`
representing the parent of `p`. If `p` is the head of the tree then `id[p] == p`.

To perform the find we follow `id[]` up to the root for both `p` and `q` and check if they are the
same. To perform the union we set `id[i]` to `j` where `i` is the root of the tree containing `p`
and `j` is the root of the tree containing `q`. 

Unions are now constant time, finds in the worst case require us to traverse the whole array for
`p` and `q`, but in general are faster.

For processing `M` finds on `N` objects the algorithm could take more than $MN/2$ operations since the `union` operation may create a line. But in general this approach is faster than [Program 1.1](#program-11).

## [Program 1.3](./Examples/UnionFind_1_3.c)

### Weighted version of Quick Union

Modified Quick Union. An additional array `sz[]` now tracks the size of the subtree rooted at `p`. `Find` is still performed the same way, but `unions` are now performed by linking the smaller tree to the larger tree, this prevents the growth
of long paths in the structure.

*Note:* Once a node stops being a root it cannot become one again, so we only need to ensure that `sz[p]` is maintained as long as `p` is a root node.

Trees can longer grow to a depth greater than $\log(N)$ for $N$ objects, so the total cost of processing $M$ edges on $N$ objects becomes $M\log(N)$.

## [Program 1.4](./Examples/UnionFind_1_4.c)
### Path compression by halving

Improves on [Program 1.3](#program-13) by implementing path compression. Here as we perform `find` operations we adjust the parent of each node, to be it's current grandparent. This nearly halves the path length.

Asymptotically this flattens the tree giving near constant runtime. 
# Exercises

## [Exercise 1.4](./Exercises/Ex1_4/ex1_4.c)

Shows the contents of the `id` after each union operation using [QuickFind](#program-11)
for the input contained in [sample_data.dat](./Exercises/sample_data.dat). Also counts
the number of times the `id` array is accessed. See [ex1_4.dat](./Exercises/Ex1_4/ex1_4.dat)
for output.


## [Exercise 1.5](./Exercises/Ex1_5/ex1_5.c)
Repeats [Exercise 1.4](#exercise-14) but for [Quick-Union](#program-12). 
See [ex1_5.dat](./Exercises/Ex1_6/ex1_5.dat) for output.


## [Exercise 1.6](./Exercises/Ex1_6/ex1_6.dat)
Gives the contents of the `id` array after each `union` for [Weighted Quick Union](#program-13)
running on the examples for Figure 1.7 and Figure 1.8. See [ex1_6.dat](./Exercises/Ex1_6/ex1_6.dat)
for output.


## [Exercise 1.7](./Exercises/Ex1_7/ex1_7.c)
Repeats [Exercise 1.4](#exercise-14) but for [Weighted Quick Union](#program-13). 
See [ex1_4.dat](./Exercises/Ex1_7/ex1_7.dat) for output.


## [Exercise 1.8](./Exercises/Ex1_8/ex1_8.c)
Repeats [Exercise 1.4](#exercise-14) but for 
[Weighted Quick Union with Path Compression by Halving](#program-14). 
See [ex1_8.dat](./Exercises/Ex1_8/ex1_8.dat) for output.

## [Exercise 1.14](./Exercises/Ex1_14/ex1_14.dat)

Gives a sequence of input pairs that causes the [Weighted Quick Union](#program-13)
to produce a path of length $4$. Use [Exercise 1.7](./Exercises/Ex1_7/ex1_7.c) to validate.
(This will need to be compiled with `N >= 16`)

We simply Extend Figure 1.8 (where the path from 7->0 has length 3) to the next power of two
($2^4 = 16$) and copy the pattern to generate a path length of 4 in this case.

## [Exercise 1.15](./Exercises/Ex1_15/ex1_15.dat)

Give a sequence of input pairs that causes the weighted quick-union algorithim to produce
a path of length $4$.

**Solution:** Path compression only occurs when we perform a union with a non-root node. In
the solution for exercise 1.14 we only ever connect root nodes together to get a path
length of $4$. This means that the input for [exercise 1.14](./Exercises/Ex1_14/ex1_14.dat)
also leads to a path length of 4. See [ex1_15.dat](./Exercises/Ex1_15/ex1_15.dat) to validate.

## [Exercise 1.16](./Exercises/Ex1_16-17/ex1_16.c)

Show how to modify [Program 1.3](#program-13) to implement full path compression, where we
complete each `union` operation by making every node that we touch point to the root of
the new tree.

## [Exercise 1.17](./Exercises/Ex1_16-17/ex1_17.dat)
Repeats [Exercise 1.4](#exercise-14) but for [Weighted Quick Union with full compression](#exercise-116). 
See [ex1_17.dat](./Exercises/Ex1_16-17/ex1_17.dat) for output.

## [Exercise 1.18](./Exercises/Ex1_18/ex1_18.dat)

Give a sequence of input pairs that causes the weighted quick-union algorithm with full path
compression ([Exercise 1.16](#exercise-116)) to produce a path of length $4$.

**Solution**: Observe that our same observation for path compression with halving holds. There is no
compression when we perform a union of two root nodes. This means that the input for [exercise 1.14](./Exercises/Ex1_14/ex1_14.dat)
also leads to a path length of 4. See [ex1_18.dat](./Exercises/Ex1_18/ex1_18.dat) to validate.

## [Exercise 1.19](./Exercises/Ex1_19/ex1_19.c)

Demonstrate that modifying [Quick Union](#program-12) to implement [full path compression](#exercise-116)
is not sufficient to ensure that trees have no long paths.

See the implementation in [ex1_19.c](./Exercises/Ex1_19/ex1_19.c). A path of length $N - 1$ on $N$ input
objects and $N - 1$ input edges can be generated by the pattern $(N-2, N-1), (N-3, N-2) ...$, where we
assume the items objects are indexed $0...N-1$. See [ex1_19.in](./Exercises/Ex1_19/ex1_19.in) for a
sample input and [ex1_19.dat](./Exercises/Ex1_19/ex1_19.dat) for the corresponding output with $N = 10$.

## [Exercise 1.20](./Exercises/Ex1_20/ex1_20.c)

Modify [Program 1.3](#program-13) to use the *height* of the trees (longest path from any node to the
root), instead of the weight, to decide wether to set `id[i] = j` or `id[j] = i`. Run emprical studies
to compare this variant with [Program 1.3](#program-13).

We use the a [Shell Script](./Exercises/Ex1_20/Tests/testRuntime.sh) to time the program, (this has
some inefficiencies due to timing factors other than just the inner loop, such as debugging I/O.) Our
results when taking the average over $50$ runs, involving $10000$ randomly generated pairs from $0-9999$
shows that the average difference is around $30$ milliseconds, with the tree implementation being slightly
better. This is not a huge difference however and we do not measure the std deviation.

## [Exercise 1.22](./Exercises/Ex1_22/ex1_22.c)

Modification of [Program 1.4](#program-14) to generate random pairs rather than through standard input.
Then for the test cases $N = 10^3, 10^4, 10^5, 10^6$ evaluate how many random pairs are generated
before $N-1$ `unions` are performed. (i.e. the set is fully connected.)

See [ex1_22.dat](./Exercises/Ex1_22/ex1_22.dat) for the results.

## [Exercise 1.23](./Exercises/Ex1_23/ex1_23.c)

Modification of [Exercise 1.22](#exercise-122) to print out the number of edges generated to connect
$N$ items for $100 \leq N \leq 1000$. See [ex1_23.dat](./Exercises/Ex1_23/ex1_23.dat) for results.