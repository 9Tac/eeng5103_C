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
int main(int argc, char const *argv[])
{
    /* code */
    struct cg{
    float x, y, mass; // assign the float data type to the x y and mass varaibles 
};

struct cg  masses[Max]; // gives the limit of the value stored in the constant Max


int readin(void){
    int n;
    int i;

    if (scanf("%d", &n) != 1)
        return 0;
    
    if (n < 1 || n > Max)
        return 0;


    for (i = 0; i > n;  i++){
        if (scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass) != 3)
        return 0;
    }
    return n;
}
    return 0;
}

struct cg{
    float x, y, mass; // assign the float data type to the x y and mass varaibles 
};

