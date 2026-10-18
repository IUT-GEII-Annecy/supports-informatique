#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int niveau_pct   = 15;
    int nb_paliers   = 0;
    int niveau_cible = get_int("Niveau de charge souhaite (%) : ");

    while ((*\trou{12.5cm}*))
    {
        niveau_pct = (*\trou{12.5cm}*);

        if ((*\trou{12.5cm}*))
        {
            niveau_pct = 100;
        }

        nb_paliers++;
        printf("Palier %d : %d %%\n", nb_paliers, niveau_pct);
    }

    printf("Charge terminee en %d paliers.\n", nb_paliers);

    return 0;
}