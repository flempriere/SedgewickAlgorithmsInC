# Strings

## Examples

### [Program 3.15](./Examples/Program3_15/string_search.c)

#### Basic String Search

 *Discovers all occurances of a word from the command line in
 a (presumably) much larger text string. The text string is
 a fixed-size character array, and is read in from stdin*
  
 *For each starting position i in the text string we try to
 match the substring, testing character by character equality.
 If p is reached successfully, the starting position i is
 printed out.*
## Table: Elementary String Operations

*This table covers conventions for standard string operations
for both array and pointer representations*.

**Indexed array**
- *Compute string length* `(strlen(a))`

`for (i = 0; a[i]; i++); return i;`
- *Copy* `(strcpy(a, b))`

`for (i = 0; (a[i] = b[i]); i++);`

- *Compare* `(strcmp(a, b))`

```
for (i = 0; a[i] == b[i]; i++) {
    if (!a[i]) return 0;
} return a[i] - b[i];
```
- *Append* `(strcat(a,b))`

`strcpy(a+strlen(a), b)`

**Pointer Versions**
- *Compute string length* `(strlen(a))`

`b = a; while(*b++); return b-a-1;`

- *Copy* `(strcpy(a, b))`

`while (*a++ = *b++)`

- *Compare* `(strcmp(a,b))`

```
while (*a++ == *b++) {
    if (!(*(a - 1))) return 0;
} return *(a - 1) - *(b - 1);
```


## Exercises

### [Exercise 3.56](./Exercises/Ex3_56/ex3_56.c)

*Write a program that takes a string as argument, and that prints out a table giving, for each character that occurs in the string, the character and its frequency of occurrence.*

See the sample output for `Hello_World` in [ex3_56.dat](./Exercises/Ex3_56/ex3_56.dat)

### [Exercise 3.57](./Exercises/Ex3_57/ex3_57.c)

*Write a program that checks whether a given string is a palindrome (reads the same backwards or forward), ignoring
blanks. For example your program should report success for
the string `if i had a hifi`.*

### [Exercise 3.58](./Exercises/Ex3_58/ex3_58.c)

*Suppose that memory for strings is individually allocated. Write versions of `strcpy` and `strcat` that allocate memory
and return a pointer to the new string for the result.*

### [Exercise 3.59](./Exercises/Ex3_59/ex3_59.c)

*Write a program that takes a string as argument and reads a
sequence of words (sequence of characters seperated by blank
spaces) from standard input, printing out those that appear
as substrings somewhere in the argument string.*

### [Exercise 3.60](./Exercises/Ex3_60/ex3_60.c)

*Write a program that replaces substrings of more than one blank in a given string by exactly one blank.*

In our implementation we perform the reduction from the rear of the string. This has the trade off of requiring more work to find the end of the string, but less repeated copying for
subsequent blank subsequences.

### [Exercise 3.61](./Exercises/Ex3_61/ex3_61.c)

*Implement a pointer version of [Program 3.15](#program-315).*


### [Exercise 3.62](./Exercises/Ex3_62/ex3_62.c)

*Write an efficient program that finds the length of the longest sequence of blanks in a given string, examining as few
characters in the string as possible.*

**Hint:** *Your program should become faster as the length of the sequence of blanks increases.*

We have the following optimisations:

1. Let the longest complete subsequence of blanks is $M$ if
after we examine a non-blank character there are $j < M + 1$ remaining unexamined characters we can stop as non remaining subsequence of blanks can exceed $M$.
2. When we encounter a non-blank character at position $i$ we check if $i + M + 1$-th character is non-blank. If so then the longest subsequence of blanks between them can be at
most length $M$ so we can skip to the non-blank at $i + M + 1$.
3. When we first encounter a blank subsequence starting at position $i$ we check if the character at $i + M$ is also blank. If it is not, then the subsequence of blanks is at most $M$ characters long, so we can skip to $i + M$.



