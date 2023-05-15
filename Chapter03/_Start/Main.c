#include <assert.h>
#include <stdio.h>

#include "Stack.h"

int main(void)
{
    uint32_t capacity = 4u;
    stack_t *stack = createStack(capacity);

    push(stack, 0.0f);
    push(stack, 1.0f);
    push(stack, 2.0f);
    push(stack, 3.0f);

    printStack(stack);

    assert(0.0f == stack->data[0]);
    assert(1.0f == stack->data[1]);
    assert(2.0f == stack->data[2]);
    assert(3.0f == stack->data[3]);
    assert(4u == stack->capacity);
    assert(4u == stack->size);
    assert(NULL != stack);

    value_type_t value_pop1 = pop(stack);
    value_type_t value_pop2 = pop(stack);

    assert(0.0f == stack->data[0]);
    assert(1.0f == stack->data[1]);
    assert(3.0f == value_pop1);
    assert(2.0f == value_pop2);
    assert(4u == stack->capacity);
    assert(2u == stack->size);
    assert(NULL != stack);

    value_type_t value_top1 = top(stack);
    value_type_t value_pop3 = pop(stack);
    value_type_t value_top2 = top(stack);
    value_type_t value_pop4 = pop(stack);

    assert(1.0f == value_top1);
    assert(0.0f == value_top2);
    assert(1.0f == value_pop3);
    assert(0.0f == value_pop4);
    assert(4u == stack->capacity);
    assert(0u == stack->size);
    assert(NULL != stack);

    printStack(stack);

    stack = freeStack(stack);
    assert(NULL == stack);
}
