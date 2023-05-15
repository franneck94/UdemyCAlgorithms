#ifndef DOUBLE_LINKES_LIST_H
#define DOUBLE_LINKES_LIST_H

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
    struct node *next;
    struct node *prev;
    value_type_t *value;
} node_t;

typedef struct list
{
    node_t *front;
    node_t *back;
    uint32_t size;
} list_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

node_t *createNode(const value_type_t value);

node_t *freeNode(node_t *node);

list_t *createList(void);

list_t *freeList(list_t *list);

void pushBack(list_t *const list, node_t *const node);

value_type_t popBack(list_t *const list);

void pushFront(list_t *const list, node_t *node);

value_type_t popFront(list_t *const list);

value_type_t popNode(list_t *const list, const uint32_t idx);

void pushNode(list_t *const list, node_t *const node, const uint32_t idx);

value_type_t valueAtIdx(const list_t *const list, const uint32_t idx);

void printList(const list_t *const list);

#endif // DOUBLE_LINKES_LIST_H
