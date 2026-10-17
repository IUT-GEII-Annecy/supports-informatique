#include <stdio.h>
#include <cs50.h>

int determiner_mode(float puissance_kw, int cable_verrouille);

int main(void)
{
    int nb_sessions = get_int("Nombre de sessions : ");
    int nb_refus    = 0;

    for (int i = 1; (*\trou{4cm}*); i++)
    {
        float puissance_kw     = get_float("Puissance demandee (kW) : ");
        int   cable_verrouille = get_int("Cable verrouille (1/0) : ");

        int code = (*\trou{8cm}*);

        switch ((*\trou{2.5cm}*))
        {
            case (*\trou{1.5cm}*):
            case 3:
                nb_refus++;
                break;
            case (*\trou{1.5cm}*):
                printf("Session %d : mode lent\n", i);
                break;
            (*\trou{2.5cm}*)
                printf("Session %d : mode rapide ou ultra-rapide\n", i);
                break;
        }
    }

    printf("Sessions refusees : %d\n", nb_refus);

    return 0;
}

/* La definition de determiner_mode se trouve ici (supposee correcte). */
