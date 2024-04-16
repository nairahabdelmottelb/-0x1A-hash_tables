#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * Main function to demonstrate the usage of hash functions.
 * Computes hash values and their respective indices in the hash table for several strings.
 *
 * Return: Always returns EXIT_SUCCESS.
 */
int main(void)
{
    char *s;  // Pointer to the string to be hashed
    unsigned long int hash_table_array_size = 1024;  // Size of the hash table

    // Test with the string "cisfun"
    s = "cisfun";
    printf("Hash of '%s': %lu\n", s, hash_djb2((unsigned char *)s));
    printf("Index in hash table: %lu\n", key_index((unsigned char *)s, hash_table_array_size));

    // Test with the string "Don't forget to tweet today"
    s = "Don't forget to tweet today";
    printf("Hash of '%s': %lu\n", s, hash_djb2((unsigned char *)s));
    printf("Index in hash table: %lu\n", key_index((unsigned char *)s, hash_table_array_size));

    // Test with the string "98"
    s = "98";
    printf("Hash of '%s': %lu\n", s, hash_djb2((unsigned char *)s));
    printf("Index in hash table: %lu\n", key_index((unsigned char *)s, hash_table_array_size));

    return EXIT_SUCCESS;  // Indicate successful execution
}
