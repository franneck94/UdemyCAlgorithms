#ifndef STACK_H
#define STACK_H

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
#define NO_VALUE (value_type_t)(INFINITY);

typedef struct stack
{
    uint32_t size;
    uint32_t capacity;
    value_type_t *data;
} stack_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

stack_t *createStack(const uint32_t capacity);

stack_t *freeStack(stack_t *stack);

void printStack(const stack_t *const stack);

bool isFull(const stack_t *const stack);

bool isEmpty(const stack_t *const stack);

value_type_t top(const stack_t *const stack);

void push(stack_t *const stack, const value_type_t value);

value_type_t pop(stack_t *const stack);

#endif // STACK_H
