#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * Main function to test hash table operations.
 *
 * This program creates a hash table, adds multiple key-value pairs to it,
 * and retrieves and prints these values. It demonstrates updating an existing key
 * and querying a non-existent key.
 *
 * Return: Always returns EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    char *value;

    // Create a hash table with a specified size.
    ht = hash_table_create(1024);
    if (!ht) {
        fprintf(stderr, "Error: Could not create hash table\n");
        return EXIT_FAILURE;
    }

    // Add key-value pairs to the hash table.
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    // Demonstrating updating an existing key.
    hash_table_set(ht, "c", "isfun");

    // Retrieve and print values associated with specific keys.
    print_value(ht, "python");
    print_value(ht, "Bob");
    print_value(ht, "N");
    print_value(ht, "Asterix");
    print_value(ht, "Betty");
    print_value(ht, "98");
    print_value(ht, "c");
    // Attempt to retrieve a key that does not exist.
    print_value(ht, "javascript");

    // Free the hash table at the end to prevent memory leaks.
    hash_table_delete(ht);
    return EXIT_SUCCESS;
}

/**
 * Helper function to print the value associated with a given key in a hash table.
 * @param ht Pointer to the hash table.
 * @param key The key to look up in the hash table.
 */
void print_value(hash_table_t *ht, const char *key) {
    char *value = hash_table_get(ht, key);
    if (value) {
        printf("%s: %s\n", key, value);
    } else {
        printf("%s: (null)\n", key);
    }
}
