#include <stdio.h>

int main() {
    // Appareil 1: Réfrigérateur
    float tension1 = 230.0;
    float courant1 = 0.5;
    float heures1 = 24.0;
    float puissance1 = tension1 * courant1;
    float energie1 = puissance1 * heures1;
    float cout1 = energie1 * 0.15;

    // Appareil 2: Four
    float tension2 = 230.0;
    float courant2 = 16.0;
    float heures2 = 2.0;
    float puissance2 = tension2 * courant2;
    float energie2 = puissance2 * heures2;
    float cout2 = energie2 * 0.15;

    // Appareil 3: Lampe LED
    float tension3 = 230.0;
    float courant3 = 0.05;
    float heures3 = 6.0;
    float puissance3 = tension3 * courant3;
    float energie3 = puissance3 * heures3;
    float cout3 = energie3 * 0.15;

    float total = cout1 + cout2 + cout3;
    printf("Coût total: %.2f euros\n", total);

    return 0;
}
