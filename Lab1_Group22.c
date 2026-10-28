#include <stdio.h>

// Replaces every space in str with '-' and returns how many spaces were replaced.
// str is a pointer to the first character of the string.
int replace(char *str)
{
    int count = 0;                 // How many spaces we have replaced so far

    // Keep looping until we reach the end-of-string marker '\0'
    while (*str != '\0') {
        if (*str == ' ') {         // Is the current character a space?
            *str = '-';            // Overwrite it with a minus sign
            count++;               // Record that we replaced one more
        }
        str++;                     // Move the pointer to the next character
    }

    return count;                  // Give back the total number replaced
}