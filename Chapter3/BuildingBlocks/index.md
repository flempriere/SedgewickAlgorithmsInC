# Building Blocks

## Examples

### [Program 3.1](./Examples/Program3_1/program3_1_function_definition.c)

#### Function Definition

Demonstration of function definition in C.

### [Program 3.2](./Examples/Program3_2/program3_2_number_types.c)

#### Program Number Typedefs

Program to compute the average and standard deviation
of a sequence of numbers $x_1, ... , x_N$.

Demonstrates the use of a typedef to localise the reference
to the data type.

We also include an [implementation](./Examples/Program3_2/MultifileImplementation/) that demonstrates the seperation into a client, implementation and interface.

### [Program 3.3-4](./Examples/Program3_3-4/)

### Point interface and Implementation

Point data type interface and implementation.

## Exercises

### [Exercise 3.1](./Exercises/Ex3_1/ex3_1.c)

*Find the largest and smallest numbers that you can represent with the numeric types on your computer*

See output for my machine in [ex3_1.dat](./Exercises/Ex3_1/ex3_1.dat)

### [Exercise 3.2](./Exercises/Ex3_2/ex3_2.c)

*Test the random number generator on your system by generating
random `integers` between $0$ and $r-1$ with `rand() % r` and
compute the average and standard deviation for $r=10, 100$ and $1000$ and $N = 10^3, 10^4, 10^5, 10^6$.*

See sample output in [ex3_2.dat](./Exercises/Ex3_2/ex3_2.dat)

### [Exercise 3.3](./Exercises/Ex3_3/ex3_3.c)

*Test the random number generator on your system by generating
$N$ random numbers of type `double` between $0$ and $1$,
transforming them to `integers` between $0$ and $r-1$ by
multiplying by $r$ and truncating the result. Compute the average and standard deviation for $r = 10, 100$ and $1000$
with $N = 10^3, 10^4, 10^5, 10^6$.*

See sample output in [ex3_3.dat](./Exercises/Ex3_3/ex3_3.dat)

### [Exercise 3.4](./Exercises/Ex3_4/ex3_4.c)

*Do [Exercise 3.2](#exercises-32) and [3.3](#exercises-33) for r = 2,4, 16*.

See sample output in [ex3_4.dat](./Exercises/Ex3_4/ex3_4.dat)

### [Exercise 3.5](./Exercises/Ex3_5/ex3_5.c)

*Implement the necessary functions to allow [Program 3.2](#program-32) to be used for random `bits`.*

See sample output in [ex3_5.dat](./Exercises/Ex3_5/ex3_5.dat)

### [Exercise 3.6](./Exercises/Ex3_6/playing_card.h)

*Define a `struct` suitable for representing a playing card*

### [Exercise 3.7](./Exercises/Ex3_7/ex3_7.c)

*Write a client program that uses the point data type in
[Programs 3.3-4](#program-33-4) for the following task:*

*Read a sequence of points (pairs of numbers) from standard
input, and find the one that is closest to the first.*


We provide a [shell script](./Exercises/Ex3_7/testPoint.sh)
that runs randomised tests.

### [Exercise 3.8](./Exercises/Ex3_8/ex3_8.c)

*Write a client program that uses the point data type in [Programs 3.3-4](#program-33-4) that determines whether
or not three points are collinear to within a numerical
tolerance of $10^{-4}$.*

See sample output in [ex3_8.dat](./Exercises/Ex3_8/tests/ex3_8.dat).

### [Exercise 3.9](./Exercises/Ex3_9/polarPoint.c)

*Define a data type for points in the plane that is based on using polar coordinates instead of Cartesian coordinates.*

### [Exercise 3.10](./Exercises/Ex3_10/ex3_10.c)

*Define a data type for `triangles` in the unit square, including
a function that computes the area of a triangle. Then write a
client program that generates random triples of pairs of `floats`
between $0$ and $1$ and computes empirically the average of
the triangles generated*.

See sample output in [ex3_10.dat](./Exercises/Ex3_10/ex3_10.dat)

