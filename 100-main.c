#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"  // Assumes the shash_table functions are defined here

/**
 * main - Demonstrates the functionality of the sorted hash table.
 *
 * Return: Always returns EXIT_SUCCESS indicating successful execution.
 */
int main(void)
{
    shash_table_t *ht;  // Pointer to the sorted hash table

    // Create a new sorted hash table with a capacity for 1024 entries
    ht = shash_table_create(1024);
    if (ht == NULL)
    {
        fprintf(stderr, "Failed to create hash table.\n");
        return EXIT_FAILURE;
    }

    // Insert key-value pairs into the hash table and print the table after each insertion
    shash_table_set(ht, "y", "0");
    shash_table_print(ht);  // Print the current state of the hash table

    shash_table_set(ht, "j", "1");
    shash_table_print(ht);

    shash_table_set(ht, "c", "2");
    shash_table_print(ht);

    shash_table_set(ht, "b", "3");
    shash_table_print(ht);

    shash_table_set(ht, "z", "4");
    shash_table_print(ht);

    shash_table_set(ht, "n", "5");
    shash_table_print(ht);

    shash_table_set(ht, "a", "6");
    shash_table_print(ht);

    shash_table_set(ht, "m", "7");
    shash_table_print(ht);

    // Print the hash table in reverse order
    shash_table_print_rev(ht);

    // Clean up by deleting the hash table and freeing its memory
    shash_table_delete(ht);

    return EXIT_SUCCESS;  // Return success code
}
