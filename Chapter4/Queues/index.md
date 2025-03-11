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



