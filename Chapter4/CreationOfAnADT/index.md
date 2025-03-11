# Creation of a New ADT

## Examples

### [Program 4.6](./Examples/Program4_6/UnionFind.h)

#### Basic UnionFind Interface

*The ADT interface mechanism makes it convenient for us to encode precisely
our decision to consider the connectivity algorithm in terms of three abstract
operations: `initialise`, `find` whether two nodes are connected, and perform a
`union` to consider them connected henceforth.*

### [Program 4.7](./Examples/Program4_7/equivalence_relationsClient.c)

#### Equivalence-relations ADT Client

*The ADT of [Program 4.6](#program-46) seperates the connectivity algorithm from the `union-find` implementation, making that algorithm more accessible.*

### [Program 4.8](./Examples/Program4_8/)

#### UnionFind ADT Implementation

*This implementation of the weighted-quick-union code from [Chapter 1](../../Chapter1/index.md#program-13) together with the interface of [Program 4.6](#program-46), packages the code in a form that makes it convenient for use in other applications. This implementationn uses a local
function find.*

