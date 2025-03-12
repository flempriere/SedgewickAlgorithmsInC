# FIFO Queues and Generalised Queues

## Examples

### [Program 4.9](./Examples/Program4_9/Program4_9.h)

#### FIFO Queue ADT Interface

*This interface is identical to the pushdown stack interface of [Program 4.1](../PushdownStack/index.md#program-41), except for the names of the structure. The two ADTs differ only in the specification, which is not reflected in the code, only the interface documentation*.

### [Program 4.10](./Examples/Program4_10/QueueList.c)

#### FIFO Queue Linked-list Implementation

*The difference between a FIFO Queue and a pushdown stack ([Program 4.5](../PushdownStack/index.md#program-45)) is that new items are inserted at the end, rather than the beginning.*

*Accordingly, this program keeps a pointer `tail` to the last node of the list, so that the function `QUEUEput` can add a new node by linking that node to the node referenced by `tail`, and then updating `tail` to point to the new node. The functions `QUEUEget`, `QUEUEinit` and `QUEUEempty` are all identical to their counterparts for the linked-list pushdown stack implemented in Program 4.5.*

**Note:** We modify the book implementation to make the internal `NEW` function static, since it does not need to be used externally.

### [Program 4.11](./Examples/Program4_11/QueueArray.c)

#### FIFO Queue Array Implementation

*The contents of the queue are all the elements in
the array between `head` and `tail`, taking into account the wrap around back to `0` when the end of
the array is encountered. If `head` and `tail` are equal then we consider the queue to be empty; but if `put` would make them equal, then we consider it to be full. As usua, we do not check such error conditions, but we make the size of the array 1 greater than the maximum number of elements that the client expects to see in the queue, so that we could argument the program to make such checks.*

## Exercises

### Exercise 4.30

*Give the contents of the Queue array after the execution of the operations in the chain:*

```
FIRS*T*IN***FI*RS***T*OUT*****
```
*interpreting a letter as `put` the letter on the Queue and a \* as a `get` operation. **Assume maxN is 10***

```
[F][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ] F (h = N, t = 1)
[F][I][ ][ ][ ][ ][ ][ ][ ][ ][ ] I (h = N, t = 2)
[F][I][R][ ][ ][ ][ ][ ][ ][ ][ ] R (h = N, t = 3)
[F][I][R][S][ ][ ][ ][ ][ ][ ][ ] S (h = N, t = 4)
[ ][I][R][S][ ][ ][ ][ ][ ][ ][ ] * (h = 1, t = 4)
[ ][I][R][S][T][ ][ ][ ][ ][ ][ ] T (h = 1, t = 5)
[ ][ ][R][S][T][ ][ ][ ][ ][ ][ ] * (h = 2, t = 5)
[ ][ ][R][S][T][I][ ][ ][ ][ ][ ] I (h = 2, t = 6)
[ ][ ][R][S][T][I][N][ ][ ][ ][ ] N (h = 2, t = 7)
[ ][ ][ ][S][T][I][N][ ][ ][ ][ ] * (h = 3, t = 7)
[ ][ ][ ][ ][T][I][N][ ][ ][ ][ ] * (h = 4, t = 7)
[ ][ ][ ][ ][ ][I][N][ ][ ][ ][ ] * (h = 5, t = 7)
[ ][ ][ ][ ][ ][I][N][F][ ][ ][ ] F (h = 5, t = 8)
[ ][ ][ ][ ][ ][I][N][F][I][ ][ ] I (h = 5, t = 9)
[ ][ ][ ][ ][ ][ ][N][F][I][ ][ ] * (h = 6, t = 9)
[ ][ ][ ][ ][ ][ ][N][F][I][R][ ] R (h = 6, t = 0)
[S][ ][ ][ ][ ][ ][N][F][I][R][ ] S (h = 6, t = 1)
[S][ ][ ][ ][ ][ ][ ][F][I][R][ ] * (h = 7, t = 1)
[S][ ][ ][ ][ ][ ][ ][ ][I][R][ ] * (h = 8, t = 1)
[S][ ][ ][ ][ ][ ][ ][ ][ ][R][ ] * (h = 9, t = 1)
[S][T][ ][ ][ ][ ][ ][ ][ ][R][ ] T (h = 9, t = 2)
[S][T][ ][ ][ ][ ][ ][ ][ ][ ][ ] * (h = 10, t = 2)
[S][T][O][ ][ ][ ][ ][ ][ ][ ][ ] O (h = 10, t = 3)
[S][T][O][U][ ][ ][ ][ ][ ][ ][ ] U (h = 10, t = 4)
[S][T][O][U][T][ ][ ][ ][ ][ ][ ] T (h = 10, t = 5)
[ ][T][O][U][T][ ][ ][ ][ ][ ][ ] * (h = 1, t = 5)
[ ][ ][O][U][T][ ][ ][ ][ ][ ][ ] * (h = 2, t = 5)
[ ][ ][ ][U][T][ ][ ][ ][ ][ ][ ] * (h = 3, t = 5)
[ ][ ][ ][ ][T][ ][ ][ ][ ][ ][ ] * (h = 4, t = 5)
[ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ] * (h = 5, t = 5)
```

### Exercise 4.31

*A letter means `put` and an asterisk means `get` in the sequence,*
```
EAS*Y*QUE***ST***IO*N***
```
*Give the sequence of values returned by the `get`  operations when this sequence of operations is performed on an initially empty FIFO Queue.*

```
EASYQUESTION
```

### [Exercise 4.32](./Exercises/Ex4_32/QueueArray_v2.c)

*Modify the array-based FIFO queue implementation in the text ([Program 4.11](#program-411)) to call 
a function `QUEUEerror` if the client attempts to `get` when the queue is empty, to `put` when the
queue is full or the `malloc` on `init` fails.*

We replicate the approach of [Exercise 4.20](../PushdownStack/index.md#exercise-420) by converting functions that can fail to return a `bool` to indicate success. (Meaning `QUEUEget` now takes a pointer argument to store the result). `QUEUEerror` like `STACKerror` in the aforementioned program takes a descriptive string of the encountered error
and reports it on `stderr`.

### [Exercise 4.33](./Exercises/Ex4_33/QueueList_v2.c)

*Modify the linked-list-based FIFO queue implemention in the text ([Program 4.10](#program-410)) to call a function `QUEUEerror` if the client attempts to `get` when the queue is empty or if there no memory available for `malloc` from `put`.*

Similar to [Exercise 4.21](../PushdownStack/index.md#exercise-421) we copy the interface defined by the previous exercise ([Exercise 4.32](#exercise-432)) and adapt the linked list, returning `bool` where appropriate to indicate success and using pointers to return the `get` value.

### Exercise 4.34

*An uppercase letter means `put` at the beginning, a lowercase letter means `put` at the end, a plus sign means `get` from the beginning, and an asterisk means `get` from the end of the sequence.*

*Given the sequence*
```
EAs+Y+QUE**+st+*+IO*n++*.
```
*give the sequence of values returned by `get` operations when this sequence of operations is performed on an initially empty deque*.

**Answer:**
```
AYsEEUtQsIn
```

### Exercise 4.35

*Using the conventions of [Exercise 4.34](#exercise-434), give a way to insert plus and
asterisk signs in the sequence `EasY` so that the sequence of values returned by the `get` operations is*

1. `EsaY`
    - **Answer:** `E+sa++Y+`
2. `YasE`
    - **Answer:** Can't be done, for `Y` to be `get` first everything has to be on the deque. The deque is thus `[Y][E][a][s]`, as we can see
    we need to `+` to `get` the `Y`, but then `a` is not at either end.
3. `aYsE`
    - **Answer:** `Ea*sY+*+`.
4. `asYE`
    - **Answer:** `Ea*s*Y++`.


### [Exercise 4.36](./Exercises/Ex4_36/)

*Given two sequences, give an algorithm for
determining whether or not it is possible to
add plus signs and asterisks to make the first
produce the second when interpreted as a sequence
of deque operations in the sense of [Exercise 4.35](#exercise-435).*





