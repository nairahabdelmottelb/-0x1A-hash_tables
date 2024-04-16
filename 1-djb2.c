#include "hash_tables.h"

/**
 * Computes the hash of a string using the djb2 algorithm.
 * 
 * @param str The string to be hashed.
 * @return The 64-bit hash value of the string.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash = 5381;  // Initial hash value
    int c;  // Variable to store the character from the string

    // Loop over each character in the string until reaching the null terminator
    while ((c = *str++))
    {
        // Combine the previous hash value and the current character to compute the new hash
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    // Return the computed hash value
    return hash;
}
