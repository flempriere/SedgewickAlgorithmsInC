# Abstract Objects and Collections of Objects

## Examples

### Sample Item.h interface

[integer version](./Examples/intItem/Item.h):
```
typdef int Item
#define eq(A, B) (A == B)
```

[string version](./Examples/strItem/Item.h):
```
typedef char* Item;
#define eq(A, B) (strcmp(A, B) == 0)
```

Demonstrates use of an interface to provide a data type and corresponding operations.

## Exercises

### [Exercise 4.1](./Exercises/Ex4_1/Item.h)

*Give a definition for `Item` and `eq` that might be used for
floating-point numbers, where two floating point numbers are considered to be equal if the absolute value of their difference divided by the larger (in absolute value) of the two
numbers is less than $10^{-6}$.*

See the implementation. Note that since the `eq` in this case is more involved we implement it as an inline function rather than a macro. There is a simple [demonstration file](./Exercises/Ex4_1/ex4_1.c).


### [Exercise 4.2](./Exercises/Ex4_2/ex4_2.c)

*Give a definition for `Item` and `eq` that might be used for points in the plane. See [Program 3.3 and Program 3.4](../../Chapter3/BuildingBlocks/index.md#program-33-4).*

In our implementation we use a `point.h` similar to previous implementations but with a `Coordinate` type and macros based on
[Exercise 4.1](#exercise-41) (i.e. using the definition for floating-point equality from before.) We then wrap this interface in the `Item.h` interface and implement `eq` by deferring to the coordinate `eq` for each coordinate.

See the [demonstration file](./Exercises/Ex4_2/ex4_2.c).

### [Exercise 4.3](./Exercises/Ex4_3/Item.c)

*Add a macro `ITEMshow` to the generic object type definitions
for integers and strings described in the text. Your macro should print the value of the item on standard input*

For simplicity we have implemented this as a numeric item and a
stringlike item in the same header. In practicality we would use one interface or the other.

See the usage [demonstration file](./Exercises/Ex4_3/ex4_3.c).

### [Exercise 4.4](./Exercises/Ex4_4/Item.h)

*Give definitions for `Item` and `ITEMshow` that might be used in programs that process playing cards.*

We follow the approach of [Exercise 4.2](#exercise-42) by wrapping the [playing card interface](./Exercises/Ex4_4/PlayingCard.h) from [Exercise 3.6](../../Chapter3/BuildingBlocks/index.md#exercise-36) in the `Item` interface.

To simplify the printing we use precomputed symbol tables for the suit and value with special cases to handle the red and black joker.

### [Exercise 4.5](./Exercises/Ex4_5/)

*Rewrite [Program 3.2](../../Chapter3/BuildingBlocks/index.md#program-32) to use a generic object type interface in a file
`Item.h`. Your object type should include `ITEMshow` and `ITEMrand`, so that the progra can be used for any type of number for which `+` and `\` are defined.*

The original question asked to rewrite [Program 3.1](../../Chapter3/BuildingBlocks/index.md#program-31) in which case it makes no sense to have an `ITEMrand()`. So we assume given the type-genericity theme that this is a typo for Program 3.2.

There are still some inconsistencies since this requires the use of the `*` operator and we store the average and std. dev. as doubles regardless so we have no need for `ITEMshow` but conveys the theme of seperating item implementation from the item. 