/**
 * @file ex2_16.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-16 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 * 
 * Demonstrates the growth rate of the number of digits of the integer
 * truncation of the Harmonic numbers and compares this to the assymptotic
 * estimate of lglg(n).
 * 
 * @version 0.1
 * @date 2025-04-10
 *
 * @copyright Copyright (c) 2025
 *
 */

 #include "MacroLibrary/Utility.h"
 #include "MacroLibrary/Mathematics.h"

 #include <stdio.h>
 #include <stdlib.h>
 #include <tgmath.h>
 /**
  * @brief index N of the largest harmonic number to compute.
  *
  */
 constexpr size_t N = 1000000000u;
 
 /**
  * @brief Calculates the number of digits in the binary representation of the
  * integer truncation of the n-th harmonic number H_n.
  *
  * @param argc
  * @param argv
  * @return EXIT_SUCCESS
  */
 int main(int argc, char* argv[argc + 1]) {
     for (register size_t i = 1; i <= N; i *= 10) {
        register long double const h_n = MATHharmonic_number(CAST(long double) i);
         register long double const digits = floor(log2(floor(h_n)));
         printf("N: %10zu\tH_n: %Lf\tdigits: %Lf\tlglg(N): %Lf\n", i, h_n, digits + 1, floor(log2(log2(h_n))) + 1);
     }
     return EXIT_SUCCESS;
 }