#include "hash_tables.h"

/**
 * Computes the index at which a key should be stored in a hash table.
 *
 * This function uses the djb2 algorithm to hash the string 'key' and then
 * calculates the corresponding index within the hash table by using the modulo
 * operator with the size of the table.
 *
 * @param key Pointer to the string key to hash.
 * @param size The size of the hash table.
 * @return The calculated index in the hash table for the given key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    // Ensure the size is greater than zero to avoid division by zero
    if (size == 0) {
        return 0; // Optionally handle this error more robustly
    }

    // Calculate the hash using the djb2 algorithm and then find the index
    unsigned long int hash_value = hash_djb2(key);
    unsigned long int index = hash_value % size;

    return index;
}
