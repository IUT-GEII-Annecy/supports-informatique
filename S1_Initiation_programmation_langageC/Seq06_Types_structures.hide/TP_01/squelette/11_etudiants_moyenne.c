#include <stdio.h>

// TODO: Déclarer la structure Etudiant avec:
//   - int numero
//   - char nom[50]
//   - float note1, note2, note3

int main(void)
{
    // TODO: Déclarer un tableau d'étudiants (max 30)

    int n;
    printf("Nombre d'etudiants: ");
    scanf("%d", &n);

    // TODO: Lire les informations de chaque étudiant
    for (int i = 0; i < n; i++) {
        printf("Etudiant %d - Numero: ", i);
        // ... lire numero, nom, note1, note2, note3
        // ATTENTION: Pour lire une chaîne après un int, utiliser:
        // scanf(" %[^\n]", nom);  // L'espace avant % consomme le '\n' résiduel
    }

    printf("\nMoyennes:\n");

    // TODO: Pour chaque étudiant, calculer et afficher sa moyenne
    for (int i = 0; i < n; i++) {
        // moyenne = (note1 + note2 + note3) / 3.0
        // Afficher: "Etudiant numero - nom: moyenne"
    }

    return 0;
}
