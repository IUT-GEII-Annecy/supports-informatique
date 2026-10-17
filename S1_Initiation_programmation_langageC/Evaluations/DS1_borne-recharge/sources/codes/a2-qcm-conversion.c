int duree_min      = 185;
int heures_entamees = (duree_min + 59) / 60;
int reste_min      = duree_min % 60;

printf("%d %d\n", heures_entamees, reste_min);
