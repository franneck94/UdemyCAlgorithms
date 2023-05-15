#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

hash_table_t *createHashTable(void)
{
    hash_table_t *hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));

    if (NULL == hash_table)
    {
        return NULL;
    }

    const size_t data_size = TABLE_SIZE * sizeof(item_t);
    item_t *data = (item_t *)malloc(data_size);

    if (NULL == data)
    {
        free(hash_table);

        return NULL;
    }

    for (uint32_t i = 0; i < TABLE_SIZE; i++)
    {
        strncpy(data[i].key, DELETED_KEY, DELETED_KEY_SIZE);
        data[i].value = NO_VALUE;
    }

    hash_table->size = 0u;
    hash_table->capacity = TABLE_SIZE;
    hash_table->data = data;

    return hash_table;
}

hash_table_t *freeHashTable(hash_table_t *hash_table)
{
    if (NULL != hash_table)
    {
        if (NULL != hash_table->data)
        {
            free(hash_table->data);
        }

        free(hash_table);
    }

    return NULL;
}

uint32_t hash(const char key[MAX_NAME_SIZE])
{
    uint32_t hash_value = 0u;

    for (uint32_t i = 0; i < MAX_NAME_SIZE; i++)
    {
        if ('\0' != key[i])
        {
            hash_value = ((uint32_t)(hash_value * 128U) + (uint32_t)(key[i])) %
                         TABLE_SIZE;
        }
        else
        {
            break;
        }
    }

    return hash_value;
}

void printHashTable(const hash_table_t *const hash_table)
{
    if (NULL == hash_table)
    {
        return;
    }

    printf("\nHashTable contains %u elements with a capcity of %u.\n",
           hash_table->size,
           hash_table->capacity);

    for (uint32_t i = 0u; i < TABLE_SIZE; i++)
    {
        const item_t *const item = &hash_table->data[i];
        printf("Index: %u, Key: %s, Value %f\n", i, item->key, item->value);
    }
}
