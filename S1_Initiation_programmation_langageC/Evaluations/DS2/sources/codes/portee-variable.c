void incrementer() {
    int compteur = 0;
    compteur++;
    printf("Dans la fonction: %d\n", compteur);
}

int main() {
    int compteur = 10;
    incrementer();
    printf("Dans le main: %d", compteur);
    return 0;
}
