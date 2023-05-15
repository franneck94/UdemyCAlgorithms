#ifndef QUEUE_H
#define QUEUE_H

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

typedef struct queue
{
    uint32_t front_idx;
    uint32_t back_idx;
    uint32_t size;
    uint32_t capacity;
    value_type_t *data;
} queue_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

queue_t *createQueue(const uint32_t capacity);

queue_t *freeQueue(queue_t *queue);

void printQueue(const queue_t *const queue);

bool isFull(const queue_t *const queue);

bool isEmpty(const queue_t *const queue);

void push(queue_t *const queue, const value_type_t value);

value_type_t pop(queue_t *const queue);

value_type_t front(queue_t *const queue);

value_type_t back(queue_t *const queue);

#endif // QUEUE_H
