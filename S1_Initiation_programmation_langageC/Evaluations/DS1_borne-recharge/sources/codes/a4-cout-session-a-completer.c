#include <stdio.h>
#include <cs50.h>

int main(void)
{
    (*\trou{2.5cm}*) puissance_kw = (*\trou{9cm}*) ;
    (*\trou{2.5cm}*) duree_min    = (*\trou{9cm}*) ;
    (*\trou{2.5cm}*) tarif_kWh    = (*\trou{9cm}*) ;
    float frais_service = 0.50;

    float duree_h   = (*\trou{10cm}*);

    float energie_kwh = (*\trou{10cm}*);

    float montant_euros = (*\trou{10cm}*);

    printf("Energie delivree : %.2f kWh\n", energie_kwh);
    printf("Montant a payer  : %.2f euros\n", montant_euros);

    return 0;
}
