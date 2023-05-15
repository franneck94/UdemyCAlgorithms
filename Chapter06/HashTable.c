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

void insertItem(hash_table_t *const hash_table, item_t *const item)
{
    if (hash_table->size == hash_table->capacity)
    {
        return;
    }

    uint32_t hash_value = hash(item->key);
    int32_t compare =
        strncmp(hash_table->data[hash_value].key, item->key, MAX_NAME_SIZE);

    while (NO_VALUE != hash_table->data[hash_value].value)
    {
        if (0 == compare)
        {
            break;
        }

        hash_value = (hash_value + 1u) % TABLE_SIZE;
        compare =
            strncmp(hash_table->data[hash_value].key, item->key, MAX_NAME_SIZE);
    }

    hash_table->data[hash_value] = *item;

    if (0 != compare)
    {
        hash_table->size++;
    }
}

value_type_t getValue(const hash_table_t *const hash_table,
                      const char key[MAX_NAME_SIZE])
{
    if (0u == hash_table->size)
    {
        return NO_VALUE;
    }

    const size_t key_len = strlen(key);

    uint32_t hash_value = hash(key);
    const item_t *item = &hash_table->data[hash_value];

    uint32_t cnt = 0U;
    while (0 != strncmp(item->key, key, key_len))
    {
        hash_value = (hash_value + 1u) % TABLE_SIZE;
        item = &hash_table->data[hash_value];

        if (cnt >= TABLE_SIZE)
        {
            break;
        }

        ++cnt;
    }

    return item->value;
}

value_type_t removeItem(hash_table_t *const hash_table,
                        const char key[MAX_NAME_SIZE])
{
    if (0u == hash_table->size)
    {
        return NO_VALUE;
    }

    const size_t key_len = strlen(key);

    uint32_t hash_value = hash(key);
    const item_t *item = &hash_table->data[hash_value];

    uint32_t cnt = 0U;
    while (0 != strncmp(item->key, key, key_len))
    {
        hash_value = (hash_value + 1u) % TABLE_SIZE;
        item = &hash_table->data[hash_value];

        if (cnt >= TABLE_SIZE)
        {
            break;
        }

        ++cnt;
    }

    const value_type_t value = item->value;

    hash_table->data[hash_value].value = NO_VALUE;
    strncpy(hash_table->data[hash_value].key, DELETED_KEY, DELETED_KEY_SIZE);
    hash_table->size--;

    return value;
}
