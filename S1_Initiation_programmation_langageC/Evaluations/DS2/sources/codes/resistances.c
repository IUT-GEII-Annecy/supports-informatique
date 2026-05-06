float r1 = 100.0;
float r2 = 200.0;
float r3 = 150.0;

// Calcul résistance série
float req_serie = r1 + r2;
printf("Serie R1+R2: %.1f ohms\n", req_serie);

// Calcul résistance parallèle
float req_parallele = (r1 * r2) / (r1 + r2);
printf("Parallele R1//R2: %.1f ohms\n", req_parallele);

// Calcul résistance série à 3
req_serie = r1 + r2 + r3;
printf("Serie R1+R2+R3: %.1f ohms\n", req_serie);

// Calcul résistance parallèle à 3
req_parallele = 1.0 / ((1.0/r1) + (1.0/r2) + (1.0/r3));
printf("Parallele R1//R2//R3: %.1f ohms\n", req_parallele);
