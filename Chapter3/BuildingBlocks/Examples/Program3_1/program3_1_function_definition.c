/*
Function definition demonstration.

Observe that the program is seperated into the function declaration

int lg(int x) which declares a function returning an int, which operates on
an int. 

and the function definition which provides a concrete implementation.
*/

#include <stdio.h>
#include <stddef.h>

int lg(int x);

int main(int argc, char* argv[argc + 1]) {
    int N = 10;
    for (size_t i = 1; i <= 6; i++, N *= 10) {
        printf("%7d %2d %9d\n", N, lg(N), N*lg(N));
    }
    return 0;
}

int lg(int N) {
    
    int i;
    for (i = 0; N > 0; i++, N /= 2);
    return i;
}