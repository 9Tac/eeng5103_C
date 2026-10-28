// Welcome to your project!

#include <stdio.h>
#define MAX 100

struct cg {                 // A "record" that holds one weight's x, y and mass
    float x, y, mass;
};
struct cg masses[MAX];      // A list that can hold up to MAX weights

// Reads the data from the keyboard into the masses list.
// Returns the number of weights read, or 0 if the input is invalid.
int readin(void)
{
    int n;                  // How many weights the user will enter
    int i;                  // Loop counter (which weight we're on)

    // Ask scanf to read one whole number (%d) into n.
    // scanf returns how many items it successfully read; we need 1.
    if (scanf("%d", &n) != 1)
        return 0;           // Input wasn't a number, so stop

    // Check the number is sensible: at least 1, and no more than MAX
    if (n < 1 || n > MAX)
        return 0;

    // Read one line per weight: "x y mass"
    for (i = 0; i < n; i++) {
        printf("Enter x, y, and mass for weight %d: ", i + 1); // Helpful prompt
        // &masses[i].x means "the address where x should be stored"
        // scanf needs addresses (the &) so it can put values into our variables
        if (scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass) != 3)
            return 0;       // A line was incomplete or not numbers, so stop
    }

    return n;               // Tell main how many weights we stored
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
    if (sum_of_mass == 0) {
        printf("Total mass is zero, so the centre of gravity is undefined.\n");
        return;
    }

    // Divide the weighted totals by the total mass to get the averages
    cg_x = sum_of_xmass / sum_of_mass;
    cg_y = sum_of_ymass / sum_of_mass;

    // Print the answer to 2 decimal places (%.2f)
    printf("CoG coordinates are: x = %.2f y = %.2f\n", cg_x, cg_y);
}

int main(void)
{
    int number;
    printf("Enter the number of weights: "); // Add this prompt!
    if ((number = readin()) > 0)
        computecg(number);
    else
        printf("Invalid input.\n");           // Helpful feedback
    return 0;
}