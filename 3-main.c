#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * Main function to test hash table creation and insertion.
 *
 * Return: EXIT_SUCCESS on successful operations, otherwise EXIT_FAILURE.
 */
int main(void)
{
    hash_table_t *ht;

    // Create a hash table with a specified size.
    ht = hash_table_create(1024);
    if (ht == NULL)
    {
        fprintf(stderr, "Failed to create hash table\n");
        return EXIT_FAILURE;
    }

    // Add a key-value pair to the hash table.
    if (hash_table_set(ht, "betty", "cool") == 0)
    {
        fprintf(stderr, "Failed to add key-value pair to hash table\n");
        // Properly clean up previously allocated hash table before exiting.
        hash_table_delete(ht);
        return EXIT_FAILURE;
    }

    // For demonstration purposes, print the value stored under "betty".
    printf("Value for 'betty': %s\n", hash_table_get(ht, "betty"));

    // Clean up the hash table at the end of the program.
    hash_table_delete(ht);
    
    return EXIT_SUCCESS;
}

