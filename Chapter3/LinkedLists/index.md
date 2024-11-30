# Linked Lists

## Examples

### [Program 3.9](./Examples/Program3_9/program3_9_josephus_problem.c)

#### [Josephus Problem](https://en.wikipedia.org/wiki/Josephus_problem)

*To represent people arranged in a circle, we build a circular
linked list, with a link ffrom each person to the person on their left in the circle. The integer $i$ represents the $i$-th person in the circle. After building a one-node circular list for $1$, insert $2$ through $N$. $x$ is left pointing to $N$. Then we skip $M -1$ nodes, beginning with $1$ and set the link of the $M-1$-th to skip the $M$-th continuing
until only one node is left.*

**Note:** The solution as provided by Sedgewick leads to a memory leak on performing elimination of the $M$-th node.

### [Program 3.10](./Examples/Program3_10/program3_10_list_reversal.c)
#### List Reversal

*Function that reverses the links in a list, returning a pointer to the node, which then points to the next-to-final node, and so forth, with the link in the first node of the
original list set to `nullptr`. To accomplish this, links are
maintained to three consecutive nodes in the list.*

### [Program 3.11](./Examples/Program3_11/program3_11_list_insertion_sort.c)

*This code generates $N$ random integers between $0$ and $999$,
builds a linked list with one number per node and then sorts
the list such that the numbers appear in order when we traverse the list.*

*This program maintains a **sorted** and **unsorted** list, one each iteration a node is removed from the **unsorted** list and placed in the correct position in the **sorted**
list.*

*In this case the linked lists use dummy head nodes*

### [Program 3.12-14](./Examples/Program3_12-14_ListImplementation/list.c)

#### List Processing Interface and Implementation

*A sample interface and implementation of the fundamental list processing operations:*

```
typedef struct node node;

void initNodes(int);
node* newNode(int);
void freeNode(node*);
void insertNext(node*, node*);
node* deleteNext(node*, node*);
node* next(node*);
int Item(node*);
```

### [Program 3.13](./Examples/Program3_13_Josephus/josephus.c)

*Modified version of [Program 3.9](#program-39) utilising
the list-processing interface of [Program 3.12-14](#program-312-14)*.

## Linked List Implementation Table

*This table covers conventions for standard linked list representations and the standard operations*.

**Circular, never empty**
- *first insert*: `head->next = head`.
- *insert t after x*: `t->next; x->next = t;`
- *delete after x*: `x->next = x->next->next`
- *traversal loop*: `t = head; do {..., t = t->next;} while(t != head);`

**Head pointer, nullptr tail**
- *initialise*: `head == nullptr`
- *insert t after x*: `if (x == nullptr) {head = t; head->next = nullptr} else {t->next = x->next; x->next = t}`
- *delete after x*: `t = x->next;  x->next = t->next;`
- *traversal loop*: `for (t = head; t != nullptr; t = t->next)`
- *test if empty*: `if (head == nullptr)`

**Dummy head, nullptr tail**
- *initialise*: `head == malloc(sizeof (*head)); head->next = nullptr`
- *insert t after x*: `t->next = x->next; x->next = t;`
- *delete after x*: `t = x->next; x->next = t->next`
- *traversal loop*: `for (t = head; t != nullptr; t = t->next)`
- *test if empty*: `if (head->next == nullptr)`.

**Dummy head, and tail**
- *initialise*: `head == malloc(sizeof (*head)); z = malloc(sizeof (*z)); head->next = z;` 
- *insert t after x*: `t->next = x->next; x->next = t;`
- *delete after x*: `x->next = x->next->next`
- *traversal loop*: `for (t = head; t != z; t = t->next)`
- *test if empty*: `if (head->next == z)`.

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

**Solution**: Pretty straight forward link manipulation. But we do have to be careful of ensuring the edge cases `x == t`
`x->next = t` and `t->next = x` work correctly.

In our solution this requires us to treat the first edge case
seperately.

### [Exercise 3.28](./Exercises/Ex3_28/ex3_28.c)

*Modify [Program 3.9](#program-39) to remove the etraneous
connections made when building the initial list due to
preserving a circular list after every insert*

**Solution**: Maintain a pointer to the head node `t`, then only perform the connection `x->t` for every `x` inserted if
`x` is the last node.

### Exercise 3.29

*Give the running time of the Josephus function in Big-O notation*. 

**Note**: The question specifically states to give the run time
up to *a* constant factor.

**Solution**: 
- At each step we eliminate one node, and we do so until all
but one node remains. So there are $\mathcal{O}(N)$ iterations
of the outer loop.
- During the inner loop we move around the list $\mathcal{O}(M)$ times.
- Eliminating a node is a constant time operation.

So approximate runtime is $\mathcal{O}(MN)$.

### [Exercise 3.30](./Exercises/Ex3_30/ex3_30.c)

*Use [Program 3.9](#program-39) to determine the value of the
Josephus function for $M = 2,3,5,10$ and $N = 10^3, 10^4, 10^5, 10^6$.*

See the sample output in [ex3_30.dat](./Exercises/Ex3_30/ex3_30.dat).

### [Exercise 3.31](./Exercises/Ex3_31/ex3_31.c)

*Use [Program 3.9](#program-39) to plot the Josephus function
vs $N$ for $M = 10$ and $2 <= N <= 1000$.*

See the sample output in [ex3_31.dat](./Exercises/Ex3_31/ex3_31.dat).

### [Exercise 3.32](./Exercises/Ex3_32/ex3_32.txt)

*Give a table of the `item` and `next` array as well as the
value of the `item` eliminated at each step of the Josephus
Problem when the value of the `N-i`th node is `i` (counting from 0) for `N = 9, M = 5`.*

See the output in [ex3_32.txt](./Exercises/Ex3_32/ex3_32.txt) obtained by modifying the key initialisation of [Exercise 3.33](#exercise-333) as required.

### [Exercise 3.33](./Exercises/Ex3_33/ex3_33.c)

*Develop a version of [Program 3.9](#program-39) that uses
an array of indices to implement the linked list*.

### [Exercise 3.34](./Exercises/Ex3_34/ex3_34.c)
*Write a function that moves the largest item on a given
list to be the final node on the list.*

See sample output in [ex3_34.dat](./Exercises/Ex3_34/ex3_34.dat).

### [Exercise 3.35](./Exercises/Ex3_35/ex3_35.c)
*Write a function that moves the smallest item on a given
list to be the final node on the list*

See sample output in [ex3_35.dat](./Exercises/Ex3_35/ex3_35.dat).

### [Exercise 3.36](./Exercises/Ex3_36/ex3_36.c)
*Write a function that rearranges a linked list to put the
nodes in even positions after the nodes in odd positions
in the list, preserving the relative order of both the
evens and the odds.*

See sample output in [ex3_36.dat](./Exercises/Ex3_36/ex3_36.dat).

### [Exercise 3.37](./Exercises/Ex3_37/ex3_37.c)
*Implement a code fragment for a linked list that exchanges
the positions of the nodes after the nodes referenced by
two given links `t` and `u`.*

See sample output in [ex3_37.dat](./Exercises/Ex3_37/ex3_37.dat).

### [Exercise 3.38](./Exercises/Ex3_38/ex3_38.c)
*Write a function that takes a link to a list as argument and returns a link to a copy of the list (a new list that contains
the same items, in the same order)*

In our implementation we make the assumption that the copy is
a deep copy. i.e. that a new unique instance of each key is
generated.

See sample output in [ex3_38.dat](./Exercises/Ex3_38/ex3_38.dat).

### [Exercise 3.39](./Exercises/Ex3_39/ex3_39.c)
*Write a function that takes two arguments - a link to a list and a function that takes a link as argument - and removes
all items on the given list for which the function returns a nonzero value.*

Our solution demonstrates this with a test function eliminating even keyed nodes. See [ex3_39.dat](./Exercises/Ex3_39/ex3_39.dat).

### [Exercise 3.40](./Exercises/Ex3_40/ex3_40.c)
*Solve [Exercise 3.39](#exercise-339), but makes copies of the nodes that pass the test and returns a link to a list containing those nodes, in the order that they appear in the original list.*

See sample output in [ex3_40.dat](./Exercises/Ex3_40/ex3_40.dat).

### [Exercise 3.41](./Exercises/Ex3_41/ex3_41.c)
*Implement a version of [Program 3.10](#program-310) that
uses a head node*.

See sample output in [ex3_41.dat](./Exercises/Ex3_41/ex3_41.dat).

We can see that our implementation requires little modification. `Reverse` is modified to skip over the initial
dummy head, then proceed as usual.

Finally as the last step the dummy head is then reattached to
the new reversed list.



### [Exercise 3.42](./Exercises/Ex3_42/ex3_42.c)

*Implement a version of [Program 3.11](#program-311) that does
not use head nodes*.

See sample output in [ex3_42.dat](./Exercises/Ex3_42/ex3_42.dat). Observe that we have to deal with two edge cases:

1. Adding the first node to a list
2. Inserting a node as the new first node i.e. changing the head.

Neither of these have to do be done in the case of a dummy node implementation.

Ideally if we did have to return a non-dummy node list then it would be best to use a dummy node for the construction and then remove this prior to returning the sorted list.

### [Exercise 3.43](./Exercises/Ex3_43/ex3_43.c)

*Implement a version of Program 3.9 that uses a head node.*

Observe that the implementation is now less elegant as we have to account for the case while counting to $M$ that we run
off the end of the list (and need to reset to the start), 
and the case that once we reach $M$ we are at the end of the
list (and need to adjust what the dummy head points to.)

**The lesson?:** Use a list implementation that suits the architecture of the problem.




