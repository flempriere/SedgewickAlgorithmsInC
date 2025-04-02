/*
Exercise 3.37

Implement a function for linked lists that exchanges the positions of the
nodes after the nodes nodes referenced by two given links t and u.
*/

#include "List/Node/Node.h"
#include "MacroLibrary/Generic.h"
#include "MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Exlusive upper bound for random Node key values
 *
 */
constexpr unsigned int N = 10u;

/**
 * @brief Exchanges the nodes after @t
 * and @u
 *
 * @param t
 * @param u
 */
void exchange_after(NODENode t[const static 1], NODENode u[const static 1]);

/**
 * @brief Tests ExchangeAfter by generating N
 * nodes numbered 1 to N and calling ExchangeAfter
 * on a random pair of nodes.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    RAND_SEED_TIME;
    // generate a list of N nodes numbered 0 to 9 with a dummy head
    NODENode* const nodes = NODEbuild_lin_list_dummy_head(N, NODEgen_key_idx);
    if (!nodes) return EXIT_FAILURE;

    printf("Initial List:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    register size_t const i = RANDUINT(N);
    register size_t const j = RANDUINT(N - 1);    // don't want to generate last
                                                  // Node
    exchange_after(&nodes[i + 1], &nodes[j + 1]);

    printf("List after exchange of nodes after %zu & %zu\n", i, j);
    NODEprint_null_terminated_list(nodes[0].next);

    free(nodes);
    return EXIT_SUCCESS;
}

void exchange_after(NODENode t[const static 1], NODENode u[const static 1]) {
    NODENode* t_nxt = t->next;
    NODENode* u_nxt = u->next;

    // return if either is nullptr or they are the same Node
    if (!(t_nxt && u_nxt) || t == u) return;
    SWAP(t->next, u->next);
    SWAP(t_nxt->next, u_nxt->next);
}