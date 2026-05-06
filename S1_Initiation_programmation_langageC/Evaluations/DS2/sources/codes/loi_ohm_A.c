float u = 12.0;    // Tension en Volts
float r = 4.0;     // Résistance en Ohms

// Calcul du courant I1
float i1 = u / r;
printf("Courant I1: %.1f A\n", i1);

// Calcul de la puissance P1
float p1 = u * i1;
printf("Puissance P1: %.1f W\n", p1);

// Calcul du courant I2 avec résistance doublée
float r2 = r * 2.0;
float i2 = u / r2;
printf("Courant I2: %.1f A\n", i2);

// Calcul de la tension U2
float u2 = r * 10.0;
printf("Tension U2: %.1f V\n", u2);
