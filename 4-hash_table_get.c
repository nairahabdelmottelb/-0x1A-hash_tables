#include "hash_tables.h"

/**
 * Retrieves the value associated with a specific key in the hash table.
 * 
 * This function uses the hash function to determine the index of the array where
 * the key-value pair should be located. It then traverses the linked list at that
 * index to find the key and return the corresponding value.
 *
 * @param ht Pointer to the hash table.
 * @param key The key for which to retrieve the value.
 * @return The value associated with the key, or NULL if the key is not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *bucket;

    // Validate input parameters.
    if (!ht || !key || !*key) // Check for NULL hash table, key, or empty key string.
    {
        return NULL;
    }

    // Calculate the index for this key using the hash function.
    index = key_index((const unsigned char *)key, ht->size);

    // Access the bucket at the calculated index.
    bucket = ht->array[index];

    // Traverse the linked list at this bucket to find the key.
    while (bucket != NULL)
    {
        if (strcmp(key, bucket->key) == 0) // Compare the current node's key with the target key.
        {
            return bucket->value; // Return the found value.
        }
        bucket = bucket->next; // Move to the next node in the list.
    }

    // If the key is not found, return NULL.
    return NULL;
}
