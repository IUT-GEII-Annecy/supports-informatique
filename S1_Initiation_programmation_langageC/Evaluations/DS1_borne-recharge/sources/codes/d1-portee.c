void enregistrer_session(void)
{
    int compteur_total = 0;
    compteur_total++;
    printf("%d ", compteur_total);
}

int main(void)
{
    int compteur_total = 0;

    for (int i = 0; i < 3; i++)
    {
        enregistrer_session();
    }

    printf("| %d\n", compteur_total);

    return 0;
}
