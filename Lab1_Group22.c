#include <stdio.h>
#include <string.h>
//Global list varible that cna be used in all functions 
char code1[] = "abcdefghijklmnopqrstuvwxyz"; //character storing from a-z lowerchase 
char code2[] = "zyxwvutsrqponmlkjihgfedcba";

/*Task 1
Replaces every space in str with '-' and returns how many spaces were replaced.
str is a pointer to the first character of the string.*/
int replace(char *str)
{
    int count = 0;

    // Loop through the string using its length
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            str[i] = '-';
            count++;
        }
    }

    return count;
}

// Task 2: encode lowercase letters using code1 and code2
void code(char *str)
{
    int i;
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            for (i = 0; code1[i] != '\0'; i++) { // Loop through each character in code1 until the end of the string is reached.
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

     // Clear instructions make it easy for anyone to use!
    printf("--- Text Encoder ---\n");
    printf("Please enter a sentence to encode: ");

    // fgets reads a whole line, including spaces.
    // It stops at the newline or when the array is full.
    fgets(line, sizeof(line), stdin);

    // Remove the newline that fgets keeps at the end, if present
    line[strcspn(line, "\n")] = '\0';

    printf("String was : %s\n", line);

    n = replace(line);             // Task 1 changes the spaces
    printf("String is : %s\n", line);
    printf("Numbers replaced %d\n", n);

    code(line);
    // Change the printf to match the expected "String is :" format
    printf("String is : %s\n", line);

    return 0;
}