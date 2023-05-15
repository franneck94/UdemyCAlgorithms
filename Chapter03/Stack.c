#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

stack_t *createStack(const uint32_t capacity)
{
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));

    if (NULL == stack)
    {
        return NULL;
    }

    const size_t data_size = capacity * sizeof(value_type_t);
    value_type_t *data = (value_type_t *)malloc(data_size);

    if (NULL == data)
    {
        free(stack);

        return NULL;
    }

    stack->size = 0U;
    stack->capacity = capacity;
    stack->data = data;

    return stack;
}

stack_t *freeStack(stack_t *stack)
{
    if (NULL == stack)
    {
        return NULL;
    }

    if (NULL != stack->data)
    {
        free(stack->data);
    }

    free(stack);

    return NULL;
}

void printStack(const stack_t *const stack)
{
    if (NULL == stack)
    {
        return;
    }

    printf("Stack has a size of %u and a capacity of: %u\n",
           stack->size,
           stack->capacity);

    for (uint32_t i = stack->size; i > 0; i--)
    {
        printf("Index: %d, Value: %f\n", i - 1u, stack->data[i - 1u]);
    }
}

bool isFull(const stack_t *const stack)
{
    return stack->size >= stack->capacity;
}

bool isEmpty(const stack_t *const stack)
{
    return stack->size == 0u;
}

value_type_t top(const stack_t *const stack)
{
    if (isEmpty(stack))
    {
        return NO_VALUE;
    }

    const uint32_t top_idx = stack->size - 1u;
    return stack->data[top_idx];
}

void push(stack_t *const stack, const value_type_t value)
{
    if (isFull(stack))
    {
        return;
    }

    stack->data[stack->size] = value;
    stack->size++;
}

value_type_t pop(stack_t *const stack)
{
    if (isEmpty(stack))
    {
        return NO_VALUE;
    }

    const value_type_t top_value = top(stack);
    stack->size--;
    return top_value;
}
