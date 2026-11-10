/*
The User Interface of the program should be based on the following text-based menu: The following 
options are available: 
• Enter data [1] 
• Save data to file [ 2] 
• Read data from file [3] 
• Print out the catalogue to screen [ 4] 
• Exit Program [ 5] 
• Enter your choice now:  
*/

#include <stdio.h>
#include <stdlib.h> //atof, atoi
#include <string.h> // sttrtok, strncpy, strcspn, strchr


#define MAX_SONGS 100 // Limits on the amount of songs as a constant

typedef struct {        // defines structure alongside the name given a shorter name
    char band[50];      // applies a charter max on the band 
    char song[50];      // applies a limit on the song charaters 
    float price;        // cast the price as a float datatype 
    int year;           // cast year as an integer data type 
} Song;                 // new type name 

Song catalogue[MAX_SONGS];   // global: every function can see the songs 
int songCount = 0;           // global: how many songs are stored so far


void showMenu(void){        // This is a function that is added so the options are outputted each time the user goes back to the input*/
    printf("Pick the following choices:\n");
    printf("Function 1 Enter data [1]\n");
    printf("Function 2 Save data to file [2]\n");
    printf("Function 3 Read data from file [3]\n");
    printf("Function 4 Print out the catalogue to screen [4]\n");
    printf("Function 5 Exit the program [5]\n");
    printf("Enter your choice now: ");
}


void enterData(void){
    if (songCount >= MAX_SONGS) {       // check tha the number of songs inputted does not increase 100 charaters
        printf("The catalogue is full.\n");
        return;
    }

    Song s;   // temporary song, copied into the array once it's complete 

    // fgets reads a whole line, so names with spaces work */
    printf("Enter the name of the band or singer: ");
    fgets(s.band, sizeof(s.band), stdin);
    s.band[strcspn(s.band, "\n")] = '\0';   // remove the newline fgets keeps 

    printf("Enter the name of the song: ");
    fgets(s.song, sizeof(s.song), stdin);
    s.song[strcspn(s.song, "\n")] = '\0';

    // scanf reads the number, but leaves the Enter key in the buffer 
    printf("Enter the price: ");
    scanf("%f", &s.price);

    printf("Enter the year of release: ");
    scanf("%d", &s.year);

    // Discard the newline left after the year, so the next prompt waits for input 
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    // Add the song to the end of the array and update the count 
    catalogue[songCount] = s;
    songCount++;

    printf("Song added.\n");
}


void saveData(void){
       // "w" creates songs.txt, or replaces its contents if it already exists 
    FILE *fp = fopen("songs.txt", "w");

    // fopen returns NULL if the file can't be opened, e.g. no write permission 
    if (fp == NULL) {
        printf("Could not open songs.txt for writing.\n");
        return;
    }

    // Write one line per song, with fields separated by '|' 
    for (int i = 0; i < songCount; i++) {
        fprintf(fp, "%s|%s|%.2f|%d\n",
                catalogue[i].band, catalogue[i].song,
                catalogue[i].price, catalogue[i].year);
    }

    fclose(fp);   /* close the file so the data is written to disk */
    printf("%d song(s) saved to songs.txt.\n", songCount);

}



void readData(void){
    FILE *fp = fopen("songs.txt", "r");   /* "r" opens the file for reading */

    if (fp == NULL) {
        printf("No saved file found. Save data first.\n");
        return;
    }

    songCount = 0;   /* the file is the source of truth, so start the array again */

    char line[200];  /* large enough for one saved line */

    // Read one line at a time until the file ends or the array is full */
    while (songCount < MAX_SONGS && fgets(line, sizeof(line), fp) != NULL) {
        Song s;

        // strtok splits the line wherever it finds the separator */
        char *bandPart  = strtok(line, "|");
        char *songPart  = strtok(NULL, "|");
        char *pricePart = strtok(NULL, "|");
        char *yearPart  = strtok(NULL, "\n");

        /* Skip any line that doesn't have all four fields */
        if (bandPart == NULL || songPart == NULL ||
            pricePart == NULL || yearPart == NULL) {
            continue;
        }

        // Copy the text into the struct, keeping room for '\0' 
        strncpy(s.band, bandPart, sizeof(s.band) - 1);
        s.band[sizeof(s.band) - 1] = '\0';

        strncpy(s.song, songPart, sizeof(s.song) - 1);
        s.song[sizeof(s.song) - 1] = '\0';

        s.price = (float)atof(pricePart);   /* text to decimal number */
        s.year  = atoi(yearPart);           // text to whole number */

        catalogue[songCount] = s;           // store the song */
        songCount++;
    }

    fclose(fp);
    printf("%d song(s) loaded from songs.txt.\n", songCount);

}


void outputCatalogue(void){
    // Nothing to print if no songs have been entered or loaded */
    if (songCount == 0) {
        printf("The catalogue is empty.\n");
        return;
    }

    // Copy the songs so sorting doesn't change the original order in catalogue */
    Song sorted[MAX_SONGS];
    for (int i = 0; i < songCount; i++) {
        sorted[i] = catalogue[i];
    }

    // Bubble sort by year, newest first.
    /* Each pass compares neighbouring songs and swaps them if the
       older one comes before the newer one. */
    for (int i = 0; i < songCount - 1; i++) {
        for (int j = 0; j < songCount - 1 - i; j++) {
            if (sorted[j].year < sorted[j + 1].year) {
                Song temp = sorted[j];        // swap the two songs */
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    // Print each song with a label, in the sorted order //
    printf("\n--- Song Catalogue (newest to oldest) ---\n");
    for (int i = 0; i < songCount; i++) {
        printf("Name of Band: %s\n", sorted[i].band);
        printf("Name of Song: %s\n", sorted[i].song);
        printf("Price: %.2f\n", sorted[i].price);
        printf("Year of Release: %d\n\n", sorted[i].year);
    }
}


void exitProgram(void){ 
    printf("Goodbye!\n");
}


int main(void) {
    int option;     //the menu choice the user typed 
    int result;     //what scanf returned: 1 on success, 0 on bad input, End of FIle(EOF) at end of input
    
    // Keep asking for a choice until the user exits or input ends
    while (1) {
        
        showMenu();

        result = scanf("%d", &option);      //try to read an integer into option

        //EOF means there is no more input (e.g. Ctrl+D), so stop the menu
        if (result == EOF) {         
            break;
        }


        //result is 0 if the input wasn't a number, such as letters (validation)
        if (result != 1) {           
            printf("Please enter a number between 1 and 5.\n");
            
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;                     // discard the bad input 
            continue;                 //skip the rest of this loop and ask again
        }

        // Discard the rest of the line (e.g. the newline after the number) */
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;



            // further validation of the inputted range 
        if (option < 1 || option > 5) {
            printf("Invalid choice. Enter an option between 1 and 5.\n");
            continue;
        }


        // calls the valid funtion in relate to the option given
        switch (option) {
            case 1: 
                enterData();
                break;
            case 2: 
                saveData();         
                break;
            case 3: 
                readData();        // reads amount of entrys in the file 
                break;
            case 4: 
                outputCatalogue();  // buble sort to output in occurdence with year
                break;
            case 5: 
                exitProgram(); // exits the program     
                return 0;
        }
    }

    return 0;
}