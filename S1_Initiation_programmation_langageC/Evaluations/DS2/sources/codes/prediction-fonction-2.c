int somme = 0;

void ajouter(int valeur) {
    somme = somme + valeur;
}

int main() {
    ajouter(5);
    ajouter(3);
    ajouter(2);
    printf("%d", somme);
    return 0;
}
