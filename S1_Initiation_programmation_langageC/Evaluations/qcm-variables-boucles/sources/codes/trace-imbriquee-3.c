int total = 0;

for (int i = 1; i <= 4; i++){
    for (int j = 1; j <= i; j++){
        total = total + 1;
    }
}

printf("%i", total);
