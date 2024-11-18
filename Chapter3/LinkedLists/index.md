# Linked Lists

## Examples

### [Program 3.9](./Examples/Program3_9/program3_9_josephus_problem.c)

#### [Josephus Problem](https://en.wikipedia.org/wiki/Josephus_problem)

*To represent people arranged in a circle, we build a circular
linked list, with a link ffrom each person to the person on their left in the circle. The integer $i$ represents the $i$-th person in the circle. After building a one-node circular list for $1$, insert $2$ through $N$. $x$ is left pointing to $N$. Then we skip $M -1$ nodes, beginning with $1$ and set the link of the $M-1$-th to skip the $M$-th continuing
until only one node is left.*

**Note:** The solution as provided by Sedgewick leads to a memory leak on performing elimination of the $M$-th node.



## Exercises

### [Exercise 3.24](./Exercises/Ex3_24/ex3_24.c)

*Write a function that returns the number of nodes on a circular list given a pointer to one of the nodes `x` on the list*

**Solution**: place two pointers, one on `x` and the other on `x + 1`. While the pointer initially on `x+1 != x` iterate it
forward and increase the count by $1$.

### [Exercise 3.25](./Exercises/Ex3_25/ex3_25.c)

*Write a code fragment that determines the number of nodes that are between the nodes referenced by two given pointers `x` and `t` to nodes on a circular list.*

**Solution**: Similar as before, but this time repeat the chain
`x = x->next` until we reach `t`, increasing the counter each time. Since functions pass by
value this is non-destructive.

**Note**: We make two design decisions:
1. Directed: i.e. we count from `x` to `t`, this means that
`countNodesBetween(x,t)` may not be the same as `countNodesBetween(t, x)`.
2. Inclusive of endpoint: i.e. if we have `x->t` as the linked
list structure then `countNodesBetween(x,t)` will be one. This
means we can call the function as `countNodesBetween(x,x)` which has the well-defined value of `0`.

### [Exercise 3.26](./Exercises/Ex3_26/ex3_26.c)

*Write a code fragment that, given pointers `x` and `t` to
two disjoint circular lists, inserts the list pointed to by
`t` into the list pointed to by `x` at the point following `x`.*

**Solution**: Find the node `s` in the list `t` with the property `s->next = t`. From here *unwrap* the list containing
`t` and insert it into the list containing `x` with
`s->next = x->next; x->next = t`.

**Note:** There is an assumption here that by *pointed to by `t`* we mean make `x->next = t` in the merge.

### [Exercise 3.27](./Exercises/Ex3_27/ex3_27.c)

*Given pointers `x` and `t` to nodes on a circular list, write
a code fragment that node following `t` to the position following the node following `x` on the list.*



