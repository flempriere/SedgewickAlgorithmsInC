/**
 * @file compiler.c
 * @author Felix Lempriere
 * @brief Transpiler component of a compiler for a mathematical language
 * consisting of a series of variable assignments followed by evaluation.
 * 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h> 

/**
 * @brief Converts mathematical expression into intermediate C code to
 * be combined with head.partial and tail.partial.
 * 
 * @param argc Number of arguments
 * @param argv[1] file to read from
 * @return int 
 */
 int main(int argc, char* argv[argc]) {

    size_t nbrackets = 0;
    size_t nbracketsAtSqrt = 0;

    if (!(argc == 2))  {
        fprintf(stderr, "Error: usage %s infile\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* in = fopen(argv[1], "r");
    if (!in) {
        fprintf(stderr, "Error: could not find input file name: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    char* outputfileName = "out.partial";
    FILE* out = fopen(outputfileName, "w");
    if (!out) {
        fprintf(stderr, "Error, failed to open output file\n");
        return EXIT_FAILURE;
    }

    char ch;
    bool newline = true;
    bool inSqrt = false;
    while ((ch = fgetc(in)) != EOF) {
        if (newline) { //store result assignment
            fputs("result = ", out);
            newline = false;
        }
        if (ch == '\n') {
            fputc(';', out);
            newline = true; //reset newline; 
        }
        else if (ch == '$') {
            fputs("sqrt(", out);
            nbracketsAtSqrt = nbrackets;
            inSqrt = true;
            continue;
        }
        else if (ch == ')') {
            if (inSqrt && nbrackets == nbracketsAtSqrt) {
                fputc(')', out);
                inSqrt = false;
            }
            nbrackets--;
        }
        else if (ch == '(') nbrackets++;
        fputc(ch, out); //output char
    }
    if (!newline) fputc(';', out); //didn't end with a \n
    fputc('\n', out);
    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
 }