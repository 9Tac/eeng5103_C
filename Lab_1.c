#include <stdio.h>
#define MAX 100

struct cg {                  // structure to hold x and y coordinates and mass
    float x, y, mass;
};
struct cg masses[MAX];

int readin(void)
{
    int n, i;
    if (scanf("%d", &n) != 1)
        return 0;
    if (n < 1 || n > MAX)
        return 0;
    for (i = 0; i < n; i++) {
        if (scanf("%f %f %f", &masses[i].x, &masses[i].y, &masses[i].mass) != 3)
            return 0;
    }
    return n;
}

void computecg(int n_masses)
{
    int i;
    float sum_of_xmass = 0, sum_of_ymass = 0, sum_of_mass = 0;
    float cg_x, cg_y;

    for (i = 0; i < n_masses; i++) {
        sum_of_xmass += masses[i].x * masses[i].mass;
        sum_of_ymass += masses[i].y * masses[i].mass;
        sum_of_mass  += masses[i].mass;
    }

    if (sum_of_mass == 0) {
        printf("Total mass is zero, so the centre of gravity is undefined.\n");
        return;
    }

    cg_x = sum_of_xmass / sum_of_mass;
    cg_y = sum_of_ymass / sum_of_mass;
    printf("CoG coordinates are: x = %.2f y = %.2f\n", cg_x, cg_y);
}

int main(void)
{
    int number;
    if ((number = readin()) > 0)     // Read the data; keep the count if it's > 0
        computecg(number);           // Only calculate if we actually have weights
    return 0;
}