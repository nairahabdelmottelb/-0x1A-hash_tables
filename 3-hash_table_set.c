#include "hash_tables.h"

/**
 * Adds or updates an element in the hash table.
 *
 * @param ht Pointer to the hash table.
 * @param key The key under which to store the value.
 * @param value The value to store.
 * @return 1 on success, 0 on failure (e.g., memory allocation failure or null inputs).
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index = 0;
    char *value_copy, *key_copy;
    hash_node_t *current_node, *new_node;

    // Validate input parameters.
    if (!ht || !key || !*key || !value)
        return 0;

    // Create a copy of the value.
    value_copy = strdup(value);
    if (!value_copy)
        return 0;

    // Compute the index for this key using the hash function.
    index = key_index((const unsigned char *)key, ht->size);
    current_node = ht->array[index];

    // Search for the key in the linked list.
    while (current_node != NULL)
    {
        if (strcmp(key, current_node->key) == 0)
        {
            // Key found, update the value.
            free(current_node->value);
            current_node->value = value_copy;
            return 1;
        }
        current_node = current_node->next;
    }

    // Key not found, create a new node.
    new_node = calloc(1, sizeof(hash_node_t));
    if (new_node == NULL)
    {
        free(value_copy);
        return 0;
    }

    // Create a copy of the key.
    key_copy = strdup(key);
    if (!key_copy)
    {
        free(value_copy);
        free(new_node);
        return 0;
    }

    // Initialize and link the new node.
    new_node->key = key_copy;
    new_node->value = value_copy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}
