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


#define MAX_SONGS 100 // Limits on the amount of songs as a constant

typedef struct {        // defines structure alongside the name given a shorter name
    char band[50];      // applies a charter max on the band 
    char song[50];      // applies a limit on the song charaters 
    float price;        // cast the price as a float datatype 
    int year;           // cast year as an integer data type 
} Song;                 // new type name 

Song catalogue[MAX_SONGS];   // global: every function can see the songs 
int songCount = 0;           // global: how many songs are stored so far


void showMenu(void){/* This is a function that is added so the options are outputted each time the user goes back to the input*/
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

    Song s;   /* temporary song, copied into the array once it's complete */

    /* fgets reads a whole line, so names with spaces work */
    printf("Enter the name of the band or singer: ");
    fgets(s.band, sizeof(s.band), stdin);
    s.band[strcspn(s.band, "\n")] = '\0';   /* remove the newline fgets keeps */

    printf("Enter the name of the song: ");
    fgets(s.song, sizeof(s.song), stdin);
    s.song[strcspn(s.song, "\n")] = '\0';

    /* scanf reads the number, but leaves the Enter key in the buffer */
    printf("Enter the price: ");
    scanf("%f", &s.price);

    printf("Enter the year of release: ");
    scanf("%d", &s.year);

    /* Discard the newline left after the year, so the next prompt waits for input */
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    /* Add the song to the end of the array and update the count */
    catalogue[songCount] = s;
    songCount++;

    printf("Song added.\n");
}


void saveData(void);
void readData(void);
void outputCatalogue(void);
void exitProgram(void);

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

        /* Discard the rest of the line (e.g. the newline after the number) */
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
                readData();        
                break;
            case 4: 
                outputCatalogue();  
                break;
            case 5: 
                exitProgram(); // exits the program     
                return 0;
        }
    }

    return 0;
}

void saveData(void)         { printf("[saveData called]\n"); }
void readData(void)         { printf("[readData called]\n"); }
void outputCatalogue(void)  { printf("[outputCatalogue called]\n"); }
void exitProgram(void)      { printf("Goodbye!\n"); }