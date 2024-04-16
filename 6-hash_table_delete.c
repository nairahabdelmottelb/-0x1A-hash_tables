#include "hash_tables.h"

/**
 * Frees a hash table and all associated nodes.
 * This function goes through each index of the hash table array, frees all nodes
 * in the linked list at that index, and finally frees the hash table itself.
 *
 * @param ht Pointer to the hash table to be freed.
 */
void hash_table_delete(hash_table_t *ht)
{
    hash_node_t *current_node, *next_node;
    unsigned long int i;  // For loop control

    if (!ht)
        return;  // Early exit if the hash table pointer is NULL

    // Iterate over each bucket in the array
    for (i = 0; i < ht->size; i++)
    {
        current_node = ht->array[i];  // Head of the list at this index

        // Traverse the linked list and free each node
        while (current_node != NULL)
        {
            next_node = current_node->next;  // Save the next node

            // Free the key and value, then the node itself
            free(current_node->key);
            free(current_node->value);
            free(current_node);

            current_node = next_node;  // Move to the next node in the list
        }
    }

    // After all nodes are freed, free the array and the hash table structure
    free(ht->array);
    free(ht);
}
