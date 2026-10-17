int capteur_tension_hs(float tension_v)
{
    printf("[lecture capteur]\n");
    return (tension_v > 440.0);
}

int main(void)
{
    float courant_a = 70.0;
    float tension_v = 500.0;

    if (courant_a > 63.0 || capteur_tension_hs(tension_v))
    {
        printf("Coupure\n");
    }

    return 0;
}
