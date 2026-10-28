#include <stdio.h>



/*Task 1
Replaces every space in str with '-' and returns how many spaces were replaced.
str is a pointer to the first character of the string.*/
int replace(char *str)
{
    int count = 0;                 // How many spaces we have replaced so far

    // Keeps looping until we reach the end-of-string marker '\0'
    while (*str != '\0') {
        if (*str == ' ') {         // Is the current character a space?
            *str = '-';            // Overwrite it with a minus sign
            count++;               // Record that we replaced one more
        }
        str++;                     // Move the pointer to the next character
    }

    return count;                  // Give back the total number replaced
}

// Task 2: encode lowercase letters using code1 and code2
void code(char *str)
{
    int i;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            for (i = 0; code1[i] != '\0'; i++) {
                if (code1[i] == *str) {
                    *str = code2[i];
                    break;
                }
            }
        }
        str++;
    }
}

int main(void)
{
    char line[100];                // Space to store one line of typed text (up to 99 characters + '\0')
    int n;                         // Number of spaces replaced

    printf("Enter a line of text:\n");

    // fgets reads a whole line, including spaces.
    // It stops at the newline or when the array is full.
    fgets(line, sizeof(line), stdin);

    // Remove the newline that fgets keeps at the end, if present
    line[strcspn(line, "\n")] = '\0';

    printf("String was : %s\n", line);

    n = replace(line);             // Task 1 changes the spaces
    printf("String is : %s\n", line);
    printf("Number replaced %d\n", n);

    code(line);                    // Task 2 encodes the letters
    printf("After coding: %s\n", line);

    return 0;
}