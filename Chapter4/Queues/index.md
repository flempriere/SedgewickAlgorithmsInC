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
[F][I][R][S][ ][ ][ ][ ][ ][ ][ ] * (h = 1, t = 4)
[F][I][R][S][T][ ][ ][ ][ ][ ][ ] T (h = 1, t = 5)
[F][I][R][S][T][ ][ ][ ][ ][ ][ ] * (h = 2, t = 5)
[F][I][R][S][T][I][ ][ ][ ][ ][ ] I (h = 2, t = 6)
[F][I][R][S][T][I][N][ ][ ][ ][ ] N (h = 2, t = 7)
[F][I][R][S][T][I][N][ ][ ][ ][ ] * (h = 3, t = 7)
[F][I][R][S][T][I][N][ ][ ][ ][ ] * (h = 4, t = 7)
[F][I][R][S][T][I][N][ ][ ][ ][ ] * (h = 5, t = 7)
[F][I][R][S][T][I][N][F][ ][ ][ ] F (h = 5, t = 8)
[F][I][R][S][T][I][N][F][I][ ][ ] I (h = 5, t = 9)
[F][I][R][S][T][I][N][F][I][ ][ ] * (h = 6, t = 9)
[F][I][R][S][T][I][N][F][I][R][ ] R (h = 6, t = 0)
[S][I][R][S][T][I][N][F][I][R][ ] * (h = 7, t = 1)
[S][I][R][S][T][I][N][F][I][R][ ] * (h = 8, t = 1)
[S][I][R][S][T][I][N][F][I][R][ ] * (h = 9, t = 1)
[S][T][R][S][T][I][N][F][I][R][ ] T (h = 9, t = 2)
[S][T][R][S][T][I][N][F][I][R][ ] * (h = 10, t = 2)
[S][T][O][S][T][I][N][F][I][R][ ] O (h = 10, t = 3)
[S][T][O][U][T][I][N][F][I][R][ ] U (h = 10, t = 4)
[S][T][O][U][T][I][N][F][I][R][ ] T (h = 10, t = 5)
[S][T][O][U][T][I][N][F][I][R][ ] * (h = 1, t = 5)
[S][T][O][U][T][I][N][F][I][R][ ] * (h = 2, t = 5)
[S][T][O][U][T][I][N][F][I][R][ ] * (h = 3, t = 5)
[S][T][O][U][T][I][N][F][I][R][ ] * (h = 4, t = 5)
[S][T][O][U][T][I][N][F][I][R][ ] * (h = 5, t = 5)
```

**Note**: On `get` operations we don't actually clear
the array, we simply move the indices to `head` and `tail` this results in values that have been removed from the queue being *overwritten.*

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
AYsEEUtQsOIn
```

### Exercise 4.35

*Using the conventions of [Exercise 4.34](#exercise-434), give a way to insert plus and
asterisk signs in the sequence `EasY` so that the sequence of values returned by the `get` operations is*

1. `EsaY`
    - **Answer:** `E+sa**Y+`
2. `YasE`
    - **Answer:** Can't be done, for *Y* to be `get` first everything has to be on the deque. The deque is thus *[Y][E][a][s]*, as we can see
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

 The idea is similar to [Ex 4.8](../PushdownStack/index.md#exercise-48) where we simulated a stack. We maintain effectively two stacks, one of elements placed at the beginning, and the other of elements placed at the end.
 
 We maintain a pointer to where we are in the second sequence. We scan over the first sequence, we add a character in a stack-like manner to either the beginning or end stack depending on the case. 
 
 Then we check the second sequence:
 1. If the character in s2 is on the top of the begin or end stack, we can get them from the begin or end respectively. So we add the get symbol, remove the match from the stack, and iterate s2.

 2. Alternatively if the character is on the bottom of the begin or end stack, we can then remove them from the end or beginning respectively, if the other stack is empty. We proceed as a above. We repeat until s2 no longer matches or reaches the end. Then iterate s1. 

 3. If we reach the end of s1 without reaching the end of s2, or reach the end of s2 without reaching the end of s1, then s1 cannot be converted to s2, else if they are both at the end of the sequence, then they do and we can print the generated sequence out.
 
 **Note:** We use the similar principle of [Ex4.24](../PushdownStack/index.md#exercise-424) by growing each stack from a different end of the array.

### [Exercise 4.37](./Exercises/Ex4_37/Deque.h)

*Write an interface for the Deque ADT.*

We define the interface in [Deque.h](./Exercises/Ex4_37/Deque.h) and base it off the Queue interface with error handling introduced for [Exercise 4.32](#exercise-432). The main change is the introduction
of a enum to indicate if we `get` or `put` at the start
or end of the Deque.

### [Exercise 4.38](./Exercises/Ex4_38/DequeArray.c)

*Provide an implementation for the Deque interface from [Ex 4.37](#exercise-437) that uses an array for
the underlying data structure.*

This is a straightforward extension. For simplicity
we introduce internal helper functions `getfromBeginning`, `getfromEnd` and their respective put variants to simplify implementation. `DEQUEget` and `DEQUEput` will then defer to the correct version.

The actual code is basically just the queue code from [Ex 4.32](#exercise-432) but when we put on the beginning we decrement the `head` (wrapping as needed) and when we `get` from the end we decrement the `tail`.

### [Exercise 4.39](./Exercises/Ex4_39/DequeList.c)

*Provide an implementation for your deque interface ([Ex 4.37](#exercise-439)) that uses a doubly linked list for the underlying data structure.*

This is actually very straightforward to do with a *circular doubly-linked list with a dummy head.* In this case, we add to the beginning by inserting the new node as `head->next`, and add to the end by adding the new node as `head->prev`. The removal is equally straightforward. 

The other modifications are then our `DEQUEempty` condition becomes `head = head->next`, i.e. just a self-referential dummy node and `DEQUEinit` now instantiating the dummy node.



### [Exercise 4.40](./Exercises/Ex4_40/Queue_circularList.c)

*Provide an implementation for the `FIFO` queue interface in the text ([Program 4.9](#program-49)) that uses a circular list for the underlying data structure.* 

A singly linked circular list doesn't provide a natural structure for the Queue, since if we naively
insert nodes at the beginning the the first node to remove points back to the head, i.e. the opposite direction. 

This implementation ends up being similar to
the linear approach in [Program 4.10](#program-410). We use a `head` and `tail` to keep track of the start and end of the list.
-  We set the head to a `nullptr` for an initial empty list, and on first insert of a node `new` set `head = tail = new`.
- For normal puts, insert the new node at the end and adjust the tail, maintaining circularity. `tail->next = new; tail = new; new->next = head`.
- For gets simply remove the first and adjust the head, but we have to additionally check, if the list is going to be *empty* `(head == tail)` to set head back to `nullptr`.
- The empty condition is still `head == nullptr`.


### [Exercise 4.41](./Exercises/Ex4_41/)

*Write a client that tests your Deque ADT ([Exercise 4.37](#exercise-437)) by reading, as the first argument on the command line, a string of commands like those given in [Exercise 4.34](#exercise-434) then performing the indicated operations. Add a function DQdump to the interface and implementations and print out the contents of the deque after each operation.*

The implementations of these are all straight forward. See the [test file](./Exercises/Ex4_41/run_Deque.c), the [array implementation](./Exercises/Ex4_41/DequeArray_v2.c) and the [linked list implementation](./Exercises/Ex4_41/DequeList_v2.c).


### [Exercise 4.42](./Exercises/Ex4_42/)

*Build a Random-Queue ADT by writing an interface and implementation that uses an array as the underlying data structure. Make sure each operation takes constant time.*

The [interface](./Exercises/Ex4_42/RandomQueue.h)  is identical to the error handling queue interface from [Exercise 4.32](#exercise-432). The changed behaviour is encoded in the commented spec for `RANDOMQUEUEget` which requires that the returned element is selected uniformly at random from those elements on the Random-Queue.

The array implementation is very similar to the stack. We maintain an array, and a pointer to the next free element, filling bottom up.
- On `put` calls, we place the new element in the first free index and iterate the pointer like a stack.
- On `get` calls we uniformly select the idx of the item to remove, then swap the contents with the item in the last idx. We the return the last idx, now containing this value, and decrease the size.

This strategy avoids having shift the entire array contents down when we remove an idx that isn't the top. The 'removed' value is overwritten by subsequent `puts`. 


### [Exercise 4.43](./Exercises/Ex4_43/)

*Build a random-queue ADT by writing an interface and implementation that uses a linked list as the underlying data structure. Provide implementations for `insert` and `delete`that are as efficient as you can make them, and analyse their worst-case cost.*

**TODO**: Implement.

### [Exercise 4.44](./Exercises/Ex4_44/lottery.c)

*Write a client that picks numbers for a lottery by putting the numbers `1` through `99` on a rondom queue, then prints the result of removing five of them.*

This is a straightforward exercise in using the random queue ADT. We simply call `put` to put the numbers on the queue then call `get` five times and print the output.





