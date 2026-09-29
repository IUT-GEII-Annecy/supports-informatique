int total = 0;

for (int i = 1; i <= 3; i++){
    for (int j = 1; j <= i; j++){
        total = total + j;
    }
}

printf("%i", total);