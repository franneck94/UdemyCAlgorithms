#ifndef HEAP_H
#define HEAP_H

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

typedef struct heap
{
    uint32_t size;
    uint32_t capacity;
    value_type_t *data;
} heap_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

heap_t *createHeap(const uint32_t capacity);

heap_t *freeHeap(heap_t *heap);

void printHeap(const heap_t *const heap);

#endif // HEAP_H
