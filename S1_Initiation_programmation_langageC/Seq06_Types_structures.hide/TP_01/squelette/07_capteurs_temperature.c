#include <stdio.h>

// TODO: Déclarer la structure Capteur avec:
//   - int id
//   - float temperature
//   - int actif (1 pour actif, 0 pour inactif)

int main(void)
{
    // TODO: Déclarer un tableau de Capteurs (taille maximale 30)
    // Capteur capteurs[30];

    int n;
    printf("Nombre de capteurs: ");
    scanf("%d", &n);

    // TODO: Lire les informations pour chaque capteur
    for (int i = 0; i < n; i++) {
        printf("Capteur %d - ID: ", i);
        // ... scanf pour id, temperature, actif
    }

    // TODO: Calculer la température moyenne des capteurs ACTIFS seulement
    // Compter le nombre de capteurs actifs
    // Faire la somme des températures des capteurs actifs
    // Calculer la moyenne

    // TODO: Afficher le résultat avec 2 décimales
    // Attention: si aucun capteur actif, afficher "Aucun capteur actif"

    return 0;
}
