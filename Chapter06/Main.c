#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "HashTable.h"

int main()
{
    hash_table_t *hash_table = createHashTable();

    item_t item_jan = {.key = "Jan", .value = 26.0f};
    item_t item_maxi = {.key = "Maxi", .value = 27.0f};
    item_t item_lena = {.key = "Lena", .value = 21.0f};
    item_t item_peter = {.key = "Peter", .value = 42.0f};
    item_t item_lara = {.key = "Lara", .value = 31.0f};

    printf("Key: %s, Idx: %u\n", item_jan.key, hash(item_jan.key));
    printf("Key: %s, Idx: %u\n", item_maxi.key, hash(item_maxi.key));
    printf("Key: %s, Idx: %u\n", item_lena.key, hash(item_lena.key));
    printf("Key: %s, Idx: %u\n", item_peter.key, hash(item_peter.key));
    printf("Key: %s, Idx: %u\n", item_lara.key, hash(item_lara.key));

    insertItem(hash_table, &item_jan);
    insertItem(hash_table, &item_maxi);
    insertItem(hash_table, &item_lena);
    insertItem(hash_table, &item_peter);
    insertItem(hash_table, &item_lara);

    printHashTable(hash_table);

    assert(0 == strncmp("Jan", hash_table->data[4].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Maxi", hash_table->data[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lara", hash_table->data[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Peter", hash_table->data[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lena", hash_table->data[11].key, MAX_NAME_SIZE));

    item_t item_jan_duplicate = {.key = "Jan", .value = -26.0f};
    insertItem(hash_table, &item_jan_duplicate);
    const value_type_t new_value_jan = getValue(hash_table, item_jan.key);
    assert(-26.0f == new_value_jan);

    printHashTable(hash_table);

    assert(0 == strncmp("Jan", hash_table->data[4].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Maxi", hash_table->data[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lara", hash_table->data[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Peter", hash_table->data[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp("Lena", hash_table->data[11].key, MAX_NAME_SIZE));

    const value_type_t value_jan = removeItem(hash_table, item_jan.key);
    const value_type_t value_maxi = removeItem(hash_table, item_maxi.key);
    const value_type_t value_lena = removeItem(hash_table, item_lena.key);
    const value_type_t value_peter = removeItem(hash_table, item_peter.key);
    const value_type_t value_lara = removeItem(hash_table, item_lara.key);

    assert(-26.0f == value_jan);
    assert(27.0f == value_maxi);
    assert(21.0f == value_lena);
    assert(42.0f == value_peter);
    assert(31.0f == value_lara);

    assert(0 == strncmp(DELETED_KEY, hash_table->data[0].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[1].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[2].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[3].key, MAX_NAME_SIZE));
    assert(0 == strncmp(DELETED_KEY, hash_table->data[4].key, MAX_NAME_SIZE));

    assert(NO_VALUE == hash_table->data[0].value);
    assert(NO_VALUE == hash_table->data[1].value);
    assert(NO_VALUE == hash_table->data[2].value);
    assert(NO_VALUE == hash_table->data[3].value);
    assert(NO_VALUE == hash_table->data[4].value);

    printHashTable(hash_table);

    hash_table = freeHashTable(hash_table);
    assert(NULL == hash_table);
}
