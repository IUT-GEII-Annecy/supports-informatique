float tarif_kwh = 0.1;
float total     = 0.0;

for (int i = 0; i < 3; i++)
{
    total = total + tarif_kwh;
}

if (total == 0.3)
{
    printf("EXACT\n");
}
else
{
    printf("ECART\n");
}
