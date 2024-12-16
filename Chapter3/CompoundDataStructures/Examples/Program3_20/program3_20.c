/**
 * @file program3_20.c
 * @brief Illustrates the use of effectiveness of proper
 * data struucture choices, for the geometric computation of
 * Program 3.8. The unit square is divided into a grid, a two
 * dimensional array of linked lists, with one list corresponding
 * to each grid square. The grid is chosen to be sufficiently fine
 * that all points within distance $d$ of any given point are either
 * in the same grid square or an adjacent one.
 * @version 0.1
 * @date 2024-12-15
 */

#include <tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "point.h"

/**
 * @brief LinkedList node element containing
 * a 2d cartesian point an a link to the next node.
 * 
 */
typedef struct node node;
struct node {
    point p;
    node* next;
};

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
 * @brief number of edges in the grid shorter than @d
 * 
 */
size_t cnt;

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
 * @param x 
 * @param y 
 */
void gridInsert(double x, double y);

/**
 * @brief Generates a random double between
 * 0 and 1.
 * 
 * @return double 
 */
double randFloat(void);

/**
 * @brief Randomly generates N points in the unit square
 * and then determines how many points can be joined
 * by a line of length less than d. Where N and d are
 * command line arguments.
 * 
 * @param argv[1] N, the number of points to generate
 * @param argv[2] d, the maximum distance between connected points
 * @return EXIT_SUCCESS on success, else 
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {

    if (argc != 3) {
        fprintf(stderr, "Error: Usage ./%s N d\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t N = strtoull(argv[1], nullptr, 0);
    d = strtod(argv[2], nullptr);
    if (d <= 0 || d >= sqrt(2)) {
        fprintf(stderr, "Error: invalid value for d, d in (0, sqrt(2))\n");
        return EXIT_FAILURE;
    }
    if (d*(SIZE_MAX - 2) <= 1.0) {
        fprintf(stderr, "Error: grid size too large, try increasing d\n");
        return EXIT_FAILURE;
    }
    //minor change to account for case that 1.0 < d < sqrt(2)
    G = sqrt(2) /d;
    grid = malloc2d(G+2, G+2);
    for (size_t i = 0; i < G + 2; i++) {
        for (size_t j = 0; j < G + 2; j++) {
            grid[i][j] = nullptr;
        }
    }
    srand(time(nullptr));
    for (size_t i = 0; i < N; i++) {
        gridInsert(randFloat(), randFloat());
    }
    printf("%zu edges shorter than %f\n", cnt, d);
    return EXIT_SUCCESS;
}

void gridInsert(double x, double y) {
    size_t X = x*G + 1; //grid index;
    size_t Y = y*G + 1; //grid index;

    node* t = malloc(sizeof(typeof(*t)));
    t->p.x = x;
    t->p.y = y;
    for (size_t i = X-1; i <= X+1; i++) {
        for (size_t j = Y-1; j <= Y+1; j++) {
            for (node* s = grid[i][j]; s != nullptr; s = s->next) {
                if (distance(s->p, t->p) < d) cnt++;
            }
        } 
    }
    t->next = grid[X][Y];
    grid[X][Y] = t;
}

node*** malloc2d(size_t row, size_t col) {
    node*** t = malloc(row * sizeof(typeof(*t)));
    for (row--; row < SIZE_MAX; row--) {
        t[row] = malloc(col * sizeof(typeof(**t)));
    }
    return t;
}

double randFloat(void) {
    return 1.0*rand() / RAND_MAX;
}



