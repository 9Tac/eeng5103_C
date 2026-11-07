#include <stdio.h>
int main()
{
 
    FILE *fp;   		/* declare a file pointer*/
    FILE *fptr;

    // Open a file in writing mode
    fptr = fopen("task", "w");

    // Write some text to the file
    fprintf(fptr, "Save data to file [2] ");

      // Append some text to the file
    fprintf(fptr, "\nHi everybody!");

    // Close the file
    fclose(fptr);

}

int read_file(){
    FILE *fp;
    char ch;
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
    return 0;

}
