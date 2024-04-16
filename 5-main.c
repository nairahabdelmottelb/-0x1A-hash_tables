#include <stdlib.h>   // For memory allocation functions
#include <stdio.h>    // For input and output functions
#include "hash_tables.h" // Include custom hash table functionality

/**
 * Main function to demonstrate creation and usage of a hash table.
 *
 * Initializes a hash table, inserts several key-value pairs, and prints the
 * contents of the hash table. Demonstrates the initial state (empty) and the state
 * after multiple insertions.
 *
 * Return: EXIT_SUCCESS on successful execution, otherwise EXIT_FAILURE.
 */
int main(void)
{
    hash_table_t *ht;

    // Create a hash table with a predefined size
    ht = hash_table_create(1024);
    if (!ht) {
        fprintf(stderr, "Failed to create hash table\n");
        return EXIT_FAILURE;
    }

    // Print the empty hash table
    printf("Initial hash table:\n");
    hash_table_print(ht);

    // Insert key-value pairs into the hash table
    if (!hash_table_set(ht, "c", "fun") ||
        !hash_table_set(ht, "python", "awesome") ||
        !hash_table_set(ht, "Bob", "and Kris love asm") ||
        !hash_table_set(ht, "N", "queens") ||
        !hash_table_set(ht, "Asterix", "Obelix") ||
        !hash_table_set(ht, "Betty", "Cool") ||
        !hash_table_set(ht, "98", "Battery Street")) {
        fprintf(stderr, "Failed to add one or more key-value pairs\n");
        hash_table_delete(ht);
        return EXIT_FAILURE;
    }

    // Print the hash table after insertions
    printf("Updated hash table:\n");
    hash_table_print(ht);

    // Clean up by freeing the hash table
    hash_table_delete(ht);

    return EXIT_SUCCESS;
}

