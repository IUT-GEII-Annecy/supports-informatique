int duree_min   = get_int("Durée en minutes : ");
int depassement = duree_min - 120;
int majoration  = depassement / 60 * 300 + 50;

printf("%d cts\n", majoration);
