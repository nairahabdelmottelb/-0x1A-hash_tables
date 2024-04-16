#include "hash_tables.h"

/**
 * Creates a hash table of a given size.
 * 
 * @param size The number of elements in the hash table.
 * @return A pointer to the newly created hash table; returns NULL if the creation fails.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    // Return NULL if size is zero, as a hash table cannot be created with zero elements
    if (size == 0)
    {
        return NULL;
    }

    // Allocate memory for the hash table structure
    hash_table_t *table = calloc(1, sizeof(hash_table_t));
    if (table == NULL)
    {
        return NULL;  // Return NULL if memory allocation fails
    }

    // Set the size of the hash table
    table->size = size;

    // Allocate memory for the array of pointers to hash nodes
    table->array = calloc(size, sizeof(hash_node_t *));
    if (table->array == NULL)
    {
        free(table);  // Free the hash table structure if array allocation fails
        return NULL;
    }

    // Return the pointer to the newly created hash table
    return table;
}
