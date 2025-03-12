/**
 * @file ex4_36.c
 * @author Felix Lempriere
 * @brief Given two input sequences consisting of
 * letters, +, and *. Determine whether or not asterisks
 * can be added to make the first produce the second when
 * interpreted as a dequeue with the following rules:
 * 1. An upper case letter represents put at the beginning
 * 2. A lower case letter represents put at the end.
 * 3. + Represents remove from the beginning.
 * 4. * Represents remove from the end.
 *
 * The idea is similar to Ex 4.8 where we simulated a stack. We maintain
 * effectively two stacks, one of elements placed at the beginning, and
 * the other of elements placed at the end.
 *
 * We maintain a pointer to where we are in the second sequence. 
 * We scan over the first
 * sequence, we add a character in a stack-like manner to either the beginning
 * or end stack depending on the case. Then we check the second sequence
 *
 * If the character in s2 is on the top of the begin or end stack, we can get
 * them from the begin or end respectively. So we add the get symbol, remove
 * the match from the stack, and iterate s2.
 *
 * Alternatively if the character is on the bottom of the begin or end stack,
 * we can then remove them from the end or beginning respectively, if the other
 * stack is empty. We proceed as a above. We repeat until s2 no longer matches 
 * or reaches the end. Then iterate s1. 
 *
 * If we reach the end of s1 without reaching the end of s2, or reach the end of
 * s2 without reaching the end of s1, then s1 cannot be converted to s2, else if
 * they are both at the end of the sequence, then they do and we can print the
 * generated sequence out.
 *
 * Note: We use the similar principle of Ex4.24 by growing each stack from a different
 * end of the array.
 *
 * 
 *
 * @version 0.1
 * @date 2025-03-12
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <ctype.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #define MAX_SEQUENCE 100

 /**
  * @brief Determines if beginning and end get()
  * operations can be added to s1 to produce s2
  * when the first is interpreted as a dequeue
  * input and the second as dequeue output.
  * 
  * @param s1 string representation of the first sequence.
  * @param s2 string representation of the second sequence.
  *
  * @return true if s1 can be made to produce s2 else
  * @return false 
  *
  * @remark If the sequence is valid, then the modified sequence
  * with + and * representing get from the beginning and end respectively
  * will be printed.
  */
 bool canProduceSeq2fromSeq1(char* s1, char* s2);


 /**
 * @brief Given two sequences, determines if
 * we can add gete() operations to the first sequence
 * to produce the second sequence as dequeue output.
 * 
 * @param argv[1] - first sequence, entered  as alphabetical
 * characters without spaces. Each letter is taken as a sequence
 * element with lower case representing add to the end and upper
 * case representing add to the front.
 * @param argv[2] - second sequence, entered as alphanumeric
 * characters without spaces. Each digit is taken as a sequence element.
 * 
 * @return EXIT_SUCCESS on successful completion, else
 * @return EXIT_FAILURE
 * 
 */
 int main(int argc, char* argv[argc]) {

    if (!(argc == 3)) {
        fprintf(stderr, "Error: Usage %s seq1 seq2\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("s1: %s\n", argv[1]);
    printf("s2: %s\n", argv[2]);

    printf("s1 can%s be converted to s2\n",
    canProduceSeq2fromSeq1(argv[1], argv[2]) ? "" : "'t");

    return EXIT_SUCCESS;
 }

 bool canProduceSeq2fromSeq1(char* s1, char* s2) {
    // buffer to store the successful modified sequence.
    static char modified[2*MAX_SEQUENCE + 1];
    size_t mod_idx = 0; // next free idx.

    static char stacks[MAX_SEQUENCE];
    size_t btop = 0, bbtm = 0, etop = MAX_SEQUENCE, ebtm = MAX_SEQUENCE;

    for (char c; (c = *s1) != '\0'; s1++) {
        if (!isalpha(c)) {
            fprintf(stderr, "Error: sequence must be"
                "alphabetical\n");
                return false;
        }
        modified[mod_idx++] = c;
        if (isupper(c)) {
            stacks[btop++] = c;
        }
        else { //must be lower case
            stacks[--etop] = c;
        }

        bool matched = true;
        while ((*s2 != '\0') && matched) {
            //check if elements in beginning array
            bool begin_empty = (btop == bbtm);
            bool end_empty = (etop == ebtm);
            
            //if beginning not empty, try get from start
            if (!begin_empty && *s2 == stacks[btop-1]) {
                btop--;
                s2++;
                modified[mod_idx++] = '+';
            }
            // if end not empty, try get from finish
            else if (!end_empty && *s2 == stacks[etop]) {
                etop++;
                s2++;
                modified[mod_idx++] = '*';
            }
            // if beginning not empty, but end is
            // try get from finish
            else if ((!begin_empty && end_empty) && *s2 == stacks[bbtm]) {
                bbtm++;
                s2++;
                modified[mod_idx++] = '*';
            }
            // if end not empty, but beginning is
            // try get from beginning.
            else if ((begin_empty && !end_empty) && *s2 == stacks[ebtm-1]) {
                ebtm--;
                s2++;
                modified[mod_idx++] = '+';
            }
            else {
                matched = false;
            }
        }
        //second sequence exhausted
        //if first is not, then since we can make s2 a subsequence, we can't
        //s1 produce s2.
        if (*s2 == '\0' && !(*(s1+1) == '\0')) return false;
    }

    bool validSeq = (*s2 == '\0') ? true : false;
    modified[mod_idx] = '\0';
    if (validSeq) printf("Modified Sequence: %s\n", modified);

    return validSeq;
 }


