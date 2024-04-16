#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * Main function to test the hash table operations.
 *
 * This program demonstrates creating a hash table, inserting multiple
 * key-value pairs, including handling dynamic memory for keys and values,
 * and then printing and cleaning up the hash table.
 *
 * Return: Always returns EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *key;
    char *value;

    // Create a hash table with a size of 1024.
    ht = hash_table_create(1024);
    if (ht == NULL) {
        fprintf(stderr, "Failed to create hash table\n");
        return EXIT_FAILURE;
    }

    // Add several key-value pairs to the hash table.
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Streetz");

    // Handle dynamic memory allocation for a key-value pair.
    key = strdup("Tim");
    value = strdup("Britton");
    if (key == NULL || value == NULL) {
        free(key);  // Ensure no memory leak if allocation fails
        free(value);
        hash_table_delete(ht);
        return EXIT_FAILURE;
    }

    // Add dynamically allocated key-value pair.
    hash_table_set(ht, key, value);

    // Clear and free the dynamically allocated memory after it's been added to the hash table.
    free(key);
    free(value);

    // Demonstrate updating existing keys.
    hash_table_set(ht, "98", "Battery Street");
    hash_table_set(ht, "hetairas", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z");
    hash_table_set(ht, "mentioner", "Bob");
    hash_table_set(ht, "hetairas", "Bob Z Chu");

    // Print the hash table's current state.
    hash_table_print(ht);

    // Clean up the hash table to prevent memory leaks.
    hash_table_delete(ht);

    return EXIT_SUCCESS;
}
