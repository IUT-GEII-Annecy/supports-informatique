int   nb_sessions    = get_int("Nombre de sessions : ");
float energie_totale = 0.0;
int   i              = 0;

while (i < nb_sessions)
{
    float energie_kwh = get_float("Energie de la session (kWh) : ");
    energie_totale = energie_totale + energie_kwh;
}

printf("Energie totale : %.1f kWh\n", energie_totale);