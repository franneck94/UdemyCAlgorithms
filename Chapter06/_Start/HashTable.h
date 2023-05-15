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

#define TABLE_SIZE (uint32_t)13u
#define MAX_NAME_SIZE (uint32_t)256u
#define DELETED_KEY "DELETED"
#define DELETED_KEY_SIZE (uint32_t)8u

typedef struct item
{
    char key[MAX_NAME_SIZE];
    value_type_t value;
} item_t;

typedef struct hash_table
{
    uint32_t size;
    uint32_t capacity;
    item_t *data;
} hash_table_t;

/**********************/
/*     FUNCTIONS      */
/**********************/

hash_table_t *createHashTable(void);

hash_table_t *freeHashTable(hash_table_t *hash_table);

uint32_t hash(const char key[MAX_NAME_SIZE]);

void printHashTable(const hash_table_t *const hash_table);

#endif // QUEUE_H
