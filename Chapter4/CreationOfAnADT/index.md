# Creation of a New ADT

## Examples

### [Program 4.6](./Examples/Program4_6/UnionFind.h)

#### Basic UnionFind Interface

*The ADT interface mechanism makes it convenient for us to encode precisely
our decision to consider the connectivity algorithm in terms of three abstract
operations: `initialise`, `find` whether two nodes are connected, and perform a
`union` to consider them connected henceforth.*

**Note:** Unlike the original implementation our `find` will return the parent node if both nodes are connected, else a reserved `NOT_FOUND` value is returned.

### [Program 4.7](./Examples/Program4_7/equivalence_relationsClient.c)

#### Equivalence-relations ADT Client

*The ADT of [Program 4.6](#program-46) seperates the connectivity algorithm from the `union-find` implementation, making that algorithm more accessible.*

### [Program 4.8](./Examples/Program4_8/)

#### UnionFind ADT Implementation

*This implementation of the weighted-quick-union code from [Chapter 1](../../Chapter1/index.md#program-13) together with the interface of [Program 4.6](#program-46), packages the code in a form that makes it convenient for use in other applications. This implementationn uses a local
function find.*

## Exercises

### [Exercise 4.26](./Exercises/Ex4_26/UnionFind_byHalving.c)

*Modify [Program 4.8](#program-48) to use path compression by halving*.

This is a straightforward copy across from [Program 1.4](../../Chapter1/index.md#program-14). We implement the path compression by halving in the `UFfindCanonical` static method.

### [Exercise 4.27](./Exercises/Ex4_27/)

*Remove the inefficiency mentioned in the text by adding an operation to [Program 4.6](#program-46) that combines `union` and `find`, providing an implementation in [Program 4.8](#program-48) and
modifying [Program 4.7](#program-47) accordingly.*

Note that the `union` already performs the `find`, and compares them for equality. So our `UFunionFind` implementation is identical to `UFunion` except with one difference: we return the shared parent `p` if the two nodes are connected, else we return `NOT_FOUND`.

### [Exercise 4.28](./Exercises/Ex4_28/UnionFind_v3.c)

*Modify the interface ([Program 4.6](./Examples/Program4_6/UnionFind.h)) and implementation ([Program 4.8](./Examples/Program4_8/UnionFind.c)) to provide a function that will return the number of nodes known to be connected to a given node.*

We extend off the previously [extended interface](./Exercises/Ex4_27/UnionFind_v2.h) implementation from [Exercise 4.27](#exercise-427).

This is straightforward, we perform a `UFfindCanonical` to get the parent `p` at the top of the set, then return `size[p]`. 

**Note** we cannot directly return `size[i]` for input `i` since a node's size is not updated once it is no longer a parent.

### [Exercise 4.29](./Exercises/Ex4_29/UnionFind_struct.c)

*Modify [Program 4.8](#program-48) to use an array of structures instead of parallel arrays for the underlying data structure.*

We modify the implementation in [Exercise 4.28](#exercise-428). This is fairly straightforward we introduce a struct `UFunionFindNode` that contains an `id` index, and a `size` field. We then initalise an array of these structs called `forest`.

The implementation then basically consists of two changes,
- `id[i]` -> `forest[i].idx`
- `sz[i]` -> `forest[i].size`

**Note:** We could use `UFunionFindNode*` pointers for the idx field instead (a top level node is then one that points to itself.) However, these structs and the array are internal to the implementation, so there's no reason not too. 

It would also be less straightforward to implement the find features because we would have to convert the final pointer to an index probably by scanning.




