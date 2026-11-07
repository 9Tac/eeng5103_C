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
void showMenu(void){
    printf("Pick the following choices:\n");
    printf("Function 1 Enter data [1]\n");
    printf("Function 2 Save data to file [2]\n");
    printf("Function 3 Read data from file [3]\n");
    printf("Function 4 Print out the catalogue to screen [4]\n");
    printf("Function 5 Exit the program [5]\n");
    printf("Enter your choice now: ");

    int option;
    scanf("%d", &option);
    return option;
}
void enterData(void);
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