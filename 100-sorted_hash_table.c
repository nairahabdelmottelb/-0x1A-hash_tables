#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * Inserts a new node into the sorted linked list within the hash table.
 * @param ht Pointer to the sorted hash table.
 * @param new_node New node to insert in sorted order.
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node) {
    shash_node_t *current = ht->shead;

    // Handle the case where the sorted list is empty
    if (current == NULL) {
        ht->shead = ht->stail = new_node;
        new_node->snext = new_node->sprev = NULL;
        return;
    }

    // Traverse the list to find the insertion point
    while (current != NULL && strcmp(new_node->key, current->key) > 0) {
        current = current->snext;
    }

    // Insert before the found node
    if (current == ht->shead) {
        new_node->snext = current;
        new_node->sprev = NULL;
        current->sprev = new_node;
        ht->shead = new_node;
    } else if (current == NULL) {  // Insert at the end of the list
        new_node->sprev = ht->stail;
        new_node->snext = NULL;
        ht->stail->snext = new_node;
        ht->stail = new_node;
    } else {  // Insert in the middle
        new_node->sprev = current->sprev;
        new_node->snext = current;
        current->sprev->snext = new_node;
        current->sprev = new_node;
    }
}

/**
 * Creates a sorted hash table.
 * @param size Size of the hash table.
 * @return Pointer to the newly created hash table.
 */
shash_table_t *shash_table_create(unsigned long int size) {
    shash_table_t *table = calloc(1, sizeof(shash_table_t));
    if (table == NULL || size == 0) {
        free(table);
        return NULL;
    }

    table->size = size;
    table->array = calloc(size, sizeof(shash_node_t *));
    if (table->array == NULL) {
        free(table);
        return NULL;
    }
    return table;
}

/**
 * Adds an element to the sorted hash table.
 * @param ht Pointer to the hash table.
 * @param key Key of the element to add.
 * @param value Value of the element to add.
 * @return 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value) {
    unsigned long int index;
    char *value_copy, *key_copy;
    shash_node_t *node, *new_node;

    if (!ht || !key || !value || *key == '\0') return 0;

    index = key_index((const unsigned char *)key, ht->size);
    for (node = ht->array[index]; node != NULL; node = node->next) {
        if (strcmp(key, node->key) == 0) {
            free(node->value);
            node->value = strdup(value);
            return 1;
        }
    }

    value_copy = strdup(value);
    if (!value_copy) return 0;
    key_copy = strdup(key);
    if (!key_copy) {
        free(value_copy);
        return 0;
    }

    new_node = calloc(1, sizeof(shash_node_t));
    if (!new_node) {
        free(key_copy);
        free(value_copy);
        return 0;
    }

    new_node->key = key_copy;
    new_node->value = value_copy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    sorted_list(ht, new_node);
    return 1;
}

/**
 * Retrieves the value associated with a key in the hash table.
 * @param ht Pointer to the hash table.
 * @param key Key to retrieve the value for.
 * @return Value associated with the key, or NULL if the key does not exist.
 */
char *shash_table_get(const shash_table_t *ht, const char *key) {
    unsigned long int index;
    shash_node_t *node;

    if (!ht || !key || *key == '\0') return NULL;

    index = key_index((const unsigned char *)key, ht->size);
    for (node = ht->array[index]; node != NULL; node = node->next) {
        if (strcmp(key, node->key) == 0) return node->value;
    }
    return NULL;
}

/**
 * Prints the sorted hash table in order from head to tail.
 * @param ht Pointer to the hash table.
 */
void shash_table_print(const shash_table_t *ht) {
    shash_node_t *node;
    int first = 1;

    if (!ht) return;
    printf("{");
    for (node = ht->shead; node != NULL; node = node->snext) {
        if (!first) printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
    }
    printf("}\n");
}

/**
 * Prints the sorted hash table in reverse order from tail to head.
 * @param ht Pointer to the hash table.
 */
void shash_table_print_rev(const shash_table_t *ht) {
    shash_node_t *node;
    int first = 1;

    if (!ht) return;
    printf("{");
    for (node = ht->stail; node != NULL; node = node->sprev) {
        if (!first) printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
    }
    printf("}\n");
}

/**
 * Deletes the hash table and frees all associated memory.
 * @param ht Pointer to the hash table to delete.
 */
void shash_table_delete(shash_table_t *ht) {
    shash_node_t *current, *tmp;
    unsigned long int i;

    if (!ht) return;

    for (i = 0; i < ht->size; i++) {
        current = ht->array[i];
        while (current) {
            tmp = current;
            current = current->next;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
        }
    }
    free(ht->array);
    free(ht);
}
