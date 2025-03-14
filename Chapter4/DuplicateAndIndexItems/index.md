# Duplicate and Index Items

## Examples

### [Program 4.12](./Examples/Program4_12/IndexedStack_IgnoreNew.c)

#### Stack with Index Items and an Ignore-the-New No Duplicates Policy

*This pushdown-stack implementation assumes that all items are integers between `0` and `maxN - 1`, so that it can maintain array `seen` that has a nonzero value correspondiing to each item in the stack. The array enables `STACKpush` to test quickly whether its argument is already on tthe stack, and to take no action if the test succeeds.*

*We update the [interface](./Examples/Program4_12/IndexedStack.h) to highlight we are explicitly using a index set.*

**Note:** We use only one bit per entry in `seen` so we could save space by using a `bit` array rather than an array of `bool` values.

## Exercises

### Exercise 4.47

*Draw a figure indicating the state of the stack for the input*
```
LA*STI*N*FIR*ST***OU*T***
```
*where the stack has a **forget the old** no duplicates policy.*

```
L       L
A       L
*   A   L
S       L S
T       L S T
I       L S T I
*   I   L S T
N       L S T N
*   N   L S T
F       L S T F
I       L S T F I
R       L S T F I R
*   R   L S T F I
S       L T F I S
T       L F I S T
*   T   L F I S
*   S   L F I
*   I   L F
O       L S O
U       L S O U
*   U   L S O
T       L S O T
*   T   L S O
*   O   L S
*   S   L
```

### [Exercise 4.48](./Exercises/Ex4_48/Stack_Array_ignoreNew.c)

*Modify the standard array-based stack implementation in [Program 4.4](../PushdownStack/index.md#program-44) to disallow duplicates with an **ignore-the-new-item** policy. Use a **brute-force** approach that involves scanning through the whole stack.*

This is a straightforward update to the `push` function, we perform a scan and break early if we find a match. 

### [Exercise 4.49](./Exercises/Ex4_49/Stack_Array_forgetOld.c)

*Modify the standard array-based stack implementation in [Program 4.4](../PushdownStack/index.md#program-44) to disallow duplicates with a **forget-the-old** item policy. Use a **brute-force** approach that involves scanning through, and possibly rearranging the entire stack.*

Again this is a simple update to `push`, we scan through the stack, and if we find an index with a match, then we shuffle the array done, and put the new item at the top of the stack.


### [Exercise 4.50](./Exercises/Ex4_50/)

*Do [Exercise 4.48](#exercise-448) and [Exercise 4.49](#exercise-449) for the linked-list-based stack implementation in [Program 4.5](../PushdownStack/index.md#program-45).*

The **ignore-new** [implementation](./Exercises/Ex4_50/Ex4_50a/Stack_List_ignoreNew.c) is very similar to the array, we simply scan and break early if we find a match. The **forget-old** [implementation](./Exercises/Ex4_50/Ex4_50b/Stack_List_forgetOld.c) is a bit different. We check if the new item matches the existing head and if so exit early. Otherwise, we iterate over the linked list until the *next* node equals the item, we then move this to the new head with link manipulation.

### [Exercise 4.51](./Exercises/Ex4_51/IndexedStack_List_forgetOld.c)

*Develop a pushdown-stack implementation that disallows duplicates using a **forget-the-old-item** policy for integer items between `0` and `M-1`, and that uses constant time both `push` and `pop`. **Hint**: Use a doubly linked list representation for the stack and keep pointers to nodes, rather than `0-1` values in an item-indexed array.*

We use a linear doubly linked list, with `nullptr`'s for the ends of the list. When we `put` an `index` on the stack, we check to see if the array indicates its presence in the list. If so we then move this node to be the new head, otherwise we insert a new node at the head. The `pop` is the same as for normal stacks with the caveat that we have to make sure that we zero the array element pointing to the removed node.

### [Exercise 4.52](./Exercises/Ex4_52/)

*Do [Exercise 4.48](#exercise-448) and [Exercise 4.49](#exercise-449) for the FIFO queue ADT.*

This is straightforward and similar to the stack implementation in the linked exercises. We have to be careful to properly account for the Queue wrapping around in the array buffer.

### [Exercise 4.53]
*Do [Exercise 4.50](#exercise-450) for the FIFO Queue ADT.*

Again this is straightforward and similar to the FIFO implementations. We change the list representation to use a dummy head and self-referential tail because this makes it easy to perform the find where we look for the node `cur` such that `cur->next` is the matching node so we can easily move the matching node to the tail.

### [Exercise 4.54]

*Do [Exercise 4.51](#exercise-451) for the FIFO Queue ADT.*

### [Exercise 4.55]

### [Exercise 4.56]
