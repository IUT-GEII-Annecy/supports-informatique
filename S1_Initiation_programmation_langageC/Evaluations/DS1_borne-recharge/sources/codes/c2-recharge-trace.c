int niveau_pct = 40;
int gain_pct   = 20;
int minutes    = 0;

while (niveau_pct < 90)
{
    if (niveau_pct >= 80)
    {
        gain_pct = 5;
    }
    else if (niveau_pct >= 60)
    {
        gain_pct = 10;
    }

    niveau_pct = niveau_pct + gain_pct;
    minutes    = minutes + 10;
}

printf("%d %d\n", minutes, niveau_pct);
