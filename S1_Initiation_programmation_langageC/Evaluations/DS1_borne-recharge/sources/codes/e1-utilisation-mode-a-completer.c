#include <stdio.h>
#include <cs50.h>

int determiner_mode(float puissance_kw, int cable_verrouille);

int main(void)
{
    int nb_sessions = get_int("Nombre de sessions : ");
    int nb_refus    = 0;

    for (int i = 1; i <= nb_sessions; i++)
    {
        float puissance_kw     = get_float("Puissance demandee (kW) : ");
        int   cable_verrouille = get_int("Cable verrouille (1/0) : ");

        int code = (*\trou{12cm}*);

        switch ((*\trou{4cm}*))
        {
            (*\trou{4cm}*):
                printf("Session %d : mode lent\n", i);
                break;
                
            (*\trou{4cm}*):
                printf("Session %d : mode rapide\n", i);
                break;

            (*\trou{4cm}*):
                printf("Session %d : mode ultra rapide\n", i);
                break;

            (*\trou{4cm}*):
            (*\trou{4cm}*):
                printf("Session %d : refus\n", i);
                nb_refus++;
                break;
                
        }
    }

    printf("Sessions refusees : %d\n", nb_refus);

    return 0;
}

/* La definition de determiner_mode se trouve ici (supposee correcte). */
