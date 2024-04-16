#include "hash_tables.h"

/**
 * Prints all the key-value pairs stored in the hash table.
 * The output format is a JSON-like object with keys and values as strings.
 *
 * @param ht Pointer to the hash table to be printed.
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;  // Iterator for hash table array indices
    hash_node_t *bucket;  // Pointer to traverse linked list at each array index
    int not_first_item = 0;  // Flag to handle comma placement

    // Guard clause to handle a NULL hash table
    if (!ht) {
        return;
    }

    printf("{");
    // Iterate over the hash table array
    for (i = 0; i < ht->size; i++)
    {
        bucket = ht->array[i];  // Get the first node of the linked list at array index i
        while (bucket)
        {
            // Check if this isn't the first key-value pair for comma placement
            if (not_first_item) {
                printf(", ");
            }
            // Print the key-value pair
            printf("'%s': '%s'", bucket->key, bucket->value);
            not_first_item = 1;  // Set the flag after printing the first key-value pair

            bucket = bucket->next;  // Move to the next node in the linked list
        }
    }
    printf("}\n");
}
