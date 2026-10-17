#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float tension_v = get_float("Tension reseau (V)  : ");
    float courant_a = get_float("Courant demande (A) : ");
    int   mode      = get_int("Mode de charge (0/1/2) : ");
    int   defaut    = 0;

    if (360.0 <= tension_v <= 440.0)
    {
        printf("Tension hors plage\n");
        defaut = 1;
    }

    if (courant_a > 63.0 && mode = 2)
    {
        printf("Surintensite en mode ultra-rapide\n");
        defaut = 1;
    }

    if (defaut == 1);
    {
        printf("Charge interrompue\n");
    }

    return 0;
}
