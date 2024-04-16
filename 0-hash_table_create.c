#include "hash_tables.h"

/**
 * Creates a hash table of a given size.
 * 
 * @param size The number of elements in the hash table.
 * @return A pointer to the newly created hash table; returns NULL if the creation fails.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *table;  /* Declare variables at the start of the block */
    hash_node_t **array;  /* Additional pointer to handle array allocation */

    /* Return NULL if size is zero, as a hash table cannot be created with zero elements */
    if (size == 0)
    {
        return NULL;
    }

    /* Allocate memory for the hash table structure */
    table = calloc(1, sizeof(hash_table_t));
    if (table == NULL)
    {
        return NULL;  /* Return NULL if memory allocation fails */
    }

    /* Allocate memory for the array of pointers to hash nodes */
    array = calloc(size, sizeof(hash_node_t *));
    if (array == NULL)
    {
        free(table);  /* Free the hash table structure if array allocation fails */
        return NULL;
    }

    /* Set the size of the hash table */
    table->size = size;
    table->array = array;  /* Assign the allocated array to the table's array pointer */

    /* Return the pointer to the newly created hash table */
    return table;
}
