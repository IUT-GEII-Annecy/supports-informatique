int total = 0;

for (int i = 1; i <= 3; i++){
    for (int j = 1; j <= i; j++){
        total = total + 2;
    }
}

printf("%i", total);
