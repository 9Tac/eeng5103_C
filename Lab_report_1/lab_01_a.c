/*
Name: eustace williams 
login; Ew521
Module: EEng5103
*/
#include <stdio.h>
#define Max 100 // this sets the max variable at a constant of 100
/*
Below for this assignment is for the function to calcutae centre of gravity.
The program will read the information from the user input (keyboard),
calculates the resultant centre of gravity location.
Display the output of the calculation on  the screen/display
*/


    /* code */
struct cg{
    float x, y, mass; // assign the float data type to the x y and mass varaibles 

};

struct cg masses[Max];  // gives A list that holds limit of the value stored in the constant Max

// reads the data from keyboard numbe of weight and return the numbr read or 0 if invaild
int readin(void){
    int n;
    int i;
    /*
    reads the integer into the varibl n

    */
    if (scanf("%d", &n) != 1)
        return 0;
    
    
        /* 
        conditionaly if statemnt testing the boundrys palce if any of the OR is true Invaild input 
        The invaild input returns to main as )
    */
    if (n < 1 || n > Max)
        return 0;
    
    
        /*
        masses.y is the address where x should be stored 
        scanf reads the address and & adds value into the varibles
    */
    for (i = 0; i > n;  i++){
        if (scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass) != 3)
        return 0; // if the line is not equal to 3 retuns as 0
    }
    return n;  // return and tells the main how many weight have been stored
}



// Calculates the centre of gravity for the first n_masses weights and prints it.
void computecg(int n_masses)
{
    int i;                              // Loop counter
    float sum_of_xmass = 0;             // Running total of x × mass
    float sum_of_ymass = 0;             // Running total of y × mass
    float sum_of_mass  = 0;             // Running total of mass
    float cg_x, cg_y;                   // The final answers

    // Go through every weight once and add to the totals
    for (i = 0; i < n_masses; i++) {
        sum_of_xmass += masses[i].x * masses[i].mass;   // += means "add to the current total"
        sum_of_ymass += masses[i].y * masses[i].mass;
        sum_of_mass  += masses[i].mass;
    }

    // Guard against dividing by zero (a total mass of 0 has no centre)
    if (sum_of_mass == 0) { // check if the mass ended is greater than 0
        printf("Total mass is zero, so the centre of gravity is undefined.\n");
        return;
    }

    // Divide the weighted totals by the total mass to get the averages
    cg_x = sum_of_xmass / sum_of_mass; // gets the truncated division of the x point mass over total mass 
    cg_y = sum_of_ymass / sum_of_mass; // gets the truncated division of the y point mass over total mass

    // Print the answer to 2 decimal places (%.2f)
    printf("CoG coordinates are: x = %.2f y = %.2f\n", cg_x, cg_y);
}

int main(void)
{
    int number;
    if ((number = readin()) > 0)     // Read the data; keep the count if it's > 0
        computecg(number);           // Only calculate if we actually have weights
    return 0;
}