/**
 * @file ex4_8.c
 * @author Felix Lempriere
 * @brief Given two sequences give an algorithm
 * for determining whether or not asterisks can
 * be added to make the first produce the second,
 * when interpreted as a sequence of stack operations
 * in the sense of Exercise 4.7.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE 100

/**
 * @brief Determines if pop() operations can be
 * added to s1 to s2 when the first is interpreted
 * as stack input and the second as stack output.
 * 
 * @param s1Len length of the input sequence
 * @param s1 input sequence
 * @param s2Len length of the output sequence
 * @param s2 output sequence
 * @return true if s1 can be made to produce s2 else
 * @return false 
 * 
 * @remarks If the sequence is valid, then the modified
 * sequence with '*' will be printed.
 */
bool canProduceSeq2fromSeq1(size_t s1Len, char s1[s1Len], size_t s2Len, char s2[s2Len]);

/**
 * @brief Given two sequences, determines if
 * we can add pop() operations to the first sequence
 * to produce the second sequence as stack output.
 * 
 * @param argv[1] - first sequence, entered  as alphanumeric
 * characters without spaces. Each digit is taken as a sequence
 * element.
 * @param argv[2] - second sequence, entered as alphanumeric
 * characters without spaces. Each digit is taken as a sequence element.
 * 
 * @return EXIT_SUCCESS on successful completion, else
 * @return EXIT_FAILURE
 * 
 */
int main(int argc, char* argv[argc]) {

    if (!(argc == 3)) {
        fprintf(stderr, "Error: Usage ./%s seq1 seq2\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t s1len = strlen(argv[1]);
    size_t s2len = strlen(argv[2]);

    printf("s1: %s\n", argv[1]);
    printf("s2: %s\n", argv[2]);

    printf("S1 can%s be converted to S2\n",
    canProduceSeq2fromSeq1(s1len, argv[1], s2len, argv[2]) ? "" : "'t");

    return EXIT_SUCCESS;
}

bool canProduceSeq2fromSeq1(size_t s1Len, 
    char s1[s1Len], size_t s2Len, char s2[s2Len]) {

    if (s1Len != s2Len) return false;
    
    /**
     * @brief Stores the modified version of s1
     * 
     */
    static char modifiedSeq[2*MAX_SEQUENCE];
    size_t modSeqIdx = 0;

    size_t s = 0; //stack pointer -> denotes next free
    size_t i = 0; //pushed pointer
    size_t j = 0; //popped pointer

    for (; i < s1Len; i++) {

        s1[s++] = s1[i];  //push next item onto stack
        modifiedSeq[modSeqIdx++] = s1[i];

        while (s && (s1[s-1] == s2[j])) {
            s--;
            j++;
            modifiedSeq[modSeqIdx++] = '*';
        }
    }

    bool validSeq = (!s) ? true : false;
    modifiedSeq[modSeqIdx] = '\0';
    if (validSeq) printf("Modified sequence:\n %s\n", modifiedSeq);

    return validSeq;
}
