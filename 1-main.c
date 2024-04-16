#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"  // Assume hash_djb2 function is declared here

/**
 * main - Entry point to test the djb2 hash function.
 *
 * Return: Always returns EXIT_SUCCESS indicating successful execution.
 */
int main(void)
{
    char *s;  // Pointer to hold strings to be hashed

    s = "cisfun";  // Test string 1
    printf("Hash of '%s': %lu\n", s, hash_djb2((unsigned char *)s));
    
    s = "Don't forget to tweet today";  // Test string 2
    printf("Hash of '%s': %lu\n", s, hash_djb2((unsigned char *)s));

    s = "98";  // Test string 3
    printf("Hash of '%s': %lu\n", s, hash_djb2((unsigned char *)s));

    return EXIT_SUCCESS;  // Return success code
}
