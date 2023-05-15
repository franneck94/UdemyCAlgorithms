#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/*******************/
/*     INCLUDES    */
/*******************/

#include <math.h>
#include <stdbool.h>
#include <stdint.h>

/**********************/
/* DEFINES AND TYPES  */
/**********************/

typedef float value_type_t;
#define NO_VALUE (value_type_t)(INFINITY)

typedef struct node
{
    value_type_t value;
    struct node *left;
    struct node *right;
} node_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

node_t *createBST(const value_type_t value);

node_t *freeBST(node_t *node);

void printBST(const node_t *const node);

#endif // BINARY_SEARCH_TREE_H
