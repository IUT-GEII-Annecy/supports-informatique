int temps_s   = 0;
int nb_essais = 0;

while (temps_s < 60)
{
    temps_s = temps_s + 15;
    nb_essais++;
}

printf("%d %d\n", nb_essais, temps_s);
