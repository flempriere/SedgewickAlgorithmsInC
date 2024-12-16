/**
 * @file ex3_66.c
 * @author Felix Lempriere
 * @brief Uses Program 3.20 and Program 1.4 to determine
 * if a set of N points can be connected with edges of length
 * less than d
 * @version 0.1
 * @date 2024-12-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tgmath.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "point.h"

/**
 * @brief Clips a double to the region [0, 1]
 * 
 */
#define CLIP_DOUBLE(x) do {                     \
    if (x > 1.0) {                             \
        fprintf(stderr, "Clipped %g\n", x);     \
        x = 1.0;                                \
    }                                           \
    if (x < 0.0) {                             \
        fprintf(stderr, "Clipped %g\n", x);     \
        x = 0.0;                                \
    }                                           \
} while(0)                                      \

/**
 * @brief Maximum number of points that can be generated
 * 
 */
#define Nmax 100ULL

/**
 * @brief node structure containing a 2d cartesian
 * point, a pointer to the next node in the linkedlist
 * and a unique positive integer id (for use in UnionFind)
 * 
 */
typedef struct node node;
struct node {
    point p;
    size_t id;
    node* next;
};

//input related functions and variables

/**
 * @brief Input buffer
 * 
 */
char buf[BUFSIZ];

/**
 * @brief Extract and validate N and d from
 * the user input.
 * 
 * @param argc number of command line arguments
 * @param argv command line arguments
 * @param N size_t pointer to store the value for N in.
 * @param d double pointer to store the value for d in.
 * @return true if input is valid else
 * @return false 
 */
bool validateInput(int argc, char* argv[argc], size_t* N, double* d);

//Grid Related variables and functions

/**
 * @brief Global variable representing the unit square divided
 * into a 2d grid of width d, each grid square
 * contains a linked list
 * of the points contained in that squaare.
 * 
 */
node*** grid;

/**
 * @brief Global variable setting the maximum
 * length for edges to be counted.
 * 
 */
double d;

/**
 * @brief Global variable with the
 *  number of columns / rows in the grid.
 * 
 */
size_t G;

/**
 * @brief Dynamically allocates space for a 2d array
 * of type node*. 
 * 
 * @param row
 * @param col 
 * @return node*** pointer to the allocated array
 */
node*** malloc2d(size_t row, size_t col);

/**
 * @brief Creates and inserts a  new point
 * into the grid with (x,y) coodinates @x and @y
 * 
 * Delegates the unionFind to track connectivity
 * 
 * @param x double in [0, 1]
 * @param y double in [0, 1]
 * @param pid unique non-negative integer identifying the point
 * @param d maximum distance between connected points
 */
void gridInsert(double x, double y, size_t pid, double d);


//UnionFind variables and sections

/**
 * @brief id array for unionFind
 * 
 */
size_t* id;

/**
 * @brief sz array for unionFind
 * 
 */
size_t* sz;

/**
 * @brief Counter for number of disjoint sets
 * 
 */
size_t nUniqueSets;

/**
 * @brief Performs a find on the point represented
 * by @i and a find on the point represented by @j.
 * 
 * If @i and @j are in different sets they are then
 * unioned. Maintains the nUniqueSets counter on merging.
 * 
 * @param p id of the first point
 * @param q id of the second point
 */
void unionFind(size_t p, size_t q);

/**
 * @brief swap's x and y
 * 
 * @param x first item to be swapped
 * @param y first item to be swapped
 * 
 * Uses C23 typeof_unqual operator to
 * determine types of @x and @y for
 * temporary variable _t.
 */
#define SWAP(x,y) do {  \
    typeof_unqual(x) _t = x;      \
    x = y;              \
    y = _t;             \
} while(0)              \


int main(int argc, char* argv[argc]) {

    size_t N;
    double d;
    if(!validateInput(argc, argv, &N, &d)) return EXIT_FAILURE;
    //minor change to account for case that 1.0 < d < sqrt(2)
    G = sqrt(2) /d;
    grid = malloc2d(G+2, G+2);
    for (size_t i = 0; i < G + 2; i++) {
        for (size_t j = 0; j < G + 2; j++) {
            grid[i][j] = nullptr;
        }
    }

    id = malloc(N*sizeof(typeof(id)));
    sz = malloc(N*sizeof(typeof(sz)));

    double p, q;
    size_t nRead = 0;
    for (; nRead < N && fgets(buf, BUFSIZ, stdin);) {
        if (sscanf(buf, "%lg %lg\n", &p, &q) == 2) {
            CLIP_DOUBLE(p);
            CLIP_DOUBLE(q);
            gridInsert(p, q, nRead++, d);
        } else {
            fprintf(stderr, "Error: invalid input encounter in sscanf.\n"
                "Input should be the form p q\n");
            return EXIT_FAILURE;
        }
    }
    if (nRead < N) {
        fprintf(stderr, "Error:  only read %zu out of %zu points\n", nRead, N);
        return EXIT_FAILURE;
    }

    printf("The points can%s be connected by edges of length < %g\n", 
        (nUniqueSets <= 1) ? "" : "'t", d);
    
    return EXIT_SUCCESS;
}

bool validateInput(int argc, char* argv[argc], size_t* N, double* d) {

    if (argc != 3) {
        fprintf(stderr, "Error, Usage: ./%s N d\n", argv[0]);
        return false;
    }

    *N = strtoull(argv[1], nullptr, 0);

    if (*N > Nmax) {
        fprintf(stderr, "Error: N greater than Nmax (%llu)"
            ", clipping N to Nmax\n", Nmax);
        *N = Nmax;
    }

    *d = strtod(argv[2], nullptr);

    if (*d <= 0 || *d >= sqrt(2)) {
        fprintf(stderr, "Error: invalid value for d, d in (0, sqrt(2))\n");
        return false;
    }
    if (*d*(SIZE_MAX - 2) <= 1.0) {
        fprintf(stderr, "Error: grid size too large, try increasing d\n");
        return false;
    }
    return true;
}

node*** malloc2d(size_t row, size_t col) {
    node*** t = malloc(row * sizeof(typeof(*t)));
    for (row--; row < SIZE_MAX; row--) {
        t[row] = malloc(col * sizeof(typeof(**t)));
    }
    return t;
}

void gridInsert(double x, double y, size_t pid, double d) {
    size_t X = x*G + 1; //grid index;
    size_t Y = y*G + 1; //grid index;

    //make node
    node* t = malloc(sizeof(typeof(*t)));
    t->p.x = x;
    t->p.y = y;
    t->id = pid;

    //add to the unionFind array
    id[pid] = pid;
    sz[pid] = 1;
    nUniqueSets++;

    for (size_t i = X-1; i <= X+1; i++) {
        for (size_t j = Y-1; j <= Y+1; j++) {
            for (node* s = grid[i][j]; s != nullptr; s = s->next) {
                if (distance(s->p, t->p) < d) {
                    unionFind(s->id, t->id);
                }
            }
        } 
    }
    t->next = grid[X][Y];
    grid[X][Y] = t;
}

void unionFind(size_t p, size_t q) {

    size_t i, j;
    for (i = p; i != id[i]; i = id[i]) {id[i] = id[id[i]];}
    for (j = q; j != id[j]; j = id[j]) {id[j] = id[id[j]];}

    if (i == j) return;

    if (sz[i] < sz[j]) SWAP(i, j);
    id[j] = i;
    sz[i] += sz[j];
    nUniqueSets--;
}