#include <stdio.h>
#include <cs50.h>

/* Fonction disponible, supposee correcte (codes : -1, 0, 1, 2, 3) */
int determiner_mode(float puissance_kw, int cable_verrouille);

float tarif_applicable(int heure, float puissance_kw)
{
