# Corrections et Exemples - TP Types Structurés

Ce document contient des corrections commentées pour certains exercices clés du TP.

## Exercice 1.1 - Point Simple (Solution complète)

```c
#include <stdio.h>

// Déclaration de la structure Point
typedef struct {
    float x;
    float y;
} Point;

int main(void)
{
    Point p1;  // Déclaration d'une variable de type Point

    // Demande des coordonnées
    printf("Entrez x: ");
    scanf("%f", &p1.x);

    printf("Entrez y: ");
    scanf("%f", &p1.y);

    // Affichage du point
    printf("Point: (%.1f, %.1f)\n", p1.x, p1.y);

    return 0;
}
```

**Points importants :**
- On utilise `typedef` pour simplifier l'utilisation
- L'accès aux champs se fait avec l'opérateur `.`
- `%.1f` affiche un float avec 1 décimale

---

## Exercice 1.3 - Distance entre deux points (Solution complète)

```c
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

// Fonction qui calcule la distance entre deux points
float distance(Point p1, Point p2)
{
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

int main(void)
{
    Point p1, p2;

    printf("Point 1 - x: ");
    scanf("%f", &p1.x);
    printf("Point 1 - y: ");
    scanf("%f", &p1.y);

    printf("Point 2 - x: ");
    scanf("%f", &p2.x);
    printf("Point 2 - y: ");
    scanf("%f", &p2.y);

    float dist = distance(p1, p2);
    printf("Distance: %.2f\n", dist);

    return 0;
}
```

**Compilation :** `gcc distance.c -lm -o distance`

---

## Exercice 2.3 - Capteurs température (Solution complète)

```c
#include <stdio.h>

typedef struct {
    int id;
    float temperature;
    int actif;  // 1 pour actif, 0 pour inactif
} Capteur;

int main(void)
{
    Capteur capteurs[30];
    int n;

    printf("Nombre de capteurs: ");
    scanf("%d", &n);

    // Lecture des capteurs
    for (int i = 0; i < n; i++) {
        printf("Capteur %d - ID: ", i);
        scanf("%d", &capteurs[i].id);
        printf("Temperature: ");
        scanf("%f", &capteurs[i].temperature);
        printf("Actif (1/0): ");
        scanf("%d", &capteurs[i].actif);
    }

    // Calcul de la moyenne des capteurs actifs
    float somme = 0;
    int nb_actifs = 0;

    for (int i = 0; i < n; i++) {
        if (capteurs[i].actif == 1) {
            somme += capteurs[i].temperature;
            nb_actifs++;
        }
    }

    if (nb_actifs == 0) {
        printf("Aucun capteur actif\n");
    } else {
        float moyenne = somme / nb_actifs;
        printf("Temperature moyenne: %.2f\n", moyenne);
    }

    return 0;
}
```

**Points importants :**
- Tableau de structures : `Capteur capteurs[30]`
- Accès à un champ : `capteurs[i].temperature`
- Il faut gérer le cas où aucun capteur n'est actif

---

## Exercice 3.1 - Rectangle aire (Solution complète)

```c
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point coin_haut_gauche;
    Point coin_bas_droit;
} Rectangle;

int main(void)
{
    Rectangle rect;

    printf("Coin haut-gauche - x: ");
    scanf("%f", &rect.coin_haut_gauche.x);
    printf("Coin haut-gauche - y: ");
    scanf("%f", &rect.coin_haut_gauche.y);

    printf("Coin bas-droit - x: ");
    scanf("%f", &rect.coin_bas_droit.x);
    printf("Coin bas-droit - y: ");
    scanf("%f", &rect.coin_bas_droit.y);

    // Calcul de la largeur et hauteur
    float largeur = fabs(rect.coin_bas_droit.x - rect.coin_haut_gauche.x);
    float hauteur = fabs(rect.coin_bas_droit.y - rect.coin_haut_gauche.y);

    // Calcul de l'aire
    float aire = largeur * hauteur;

    printf("Aire: %.2f\n", aire);

    return 0;
}
```

**Points importants :**
- Structure imbriquée : `Rectangle` contient deux `Point`
- Accès à un champ imbriqué : `rect.coin_haut_gauche.x`
- Utilisation de `fabs()` pour la valeur absolue de float

---

## Exercice 3.3 - Étudiants moyenne (Solution avec fonction)

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    char nom[50];
    float note1;
    float note2;
    float note3;
} Etudiant;

// Fonction pour calculer la moyenne d'un étudiant
float calculer_moyenne(Etudiant e)
{
    return (e.note1 + e.note2 + e.note3) / 3.0;
}

int main(void)
{
    Etudiant etudiants[30];
    int n;

    printf("Nombre d'etudiants: ");
    scanf("%d", &n);

    // Lecture des étudiants
    for (int i = 0; i < n; i++) {
        printf("Etudiant %d - Numero: ", i);
        scanf("%d", &etudiants[i].numero);

        // Important : l'espace avant % consomme le '\n' résiduel
        printf("Nom: ");
        scanf(" %[^\n]", etudiants[i].nom);

        printf("Note 1: ");
        scanf("%f", &etudiants[i].note1);
        printf("Note 2: ");
        scanf("%f", &etudiants[i].note2);
        printf("Note 3: ");
        scanf("%f", &etudiants[i].note3);
    }

    // Affichage des moyennes
    printf("\nMoyennes:\n");
    for (int i = 0; i < n; i++) {
        float moyenne = calculer_moyenne(etudiants[i]);
        printf("Etudiant %d - %s: %.2f\n",
               etudiants[i].numero,
               etudiants[i].nom,
               moyenne);
    }

    return 0;
}
```

**Points importants :**
- Chaîne de caractères dans une structure : `char nom[50]`
- Lecture d'une chaîne : `scanf(" %[^\n]", nom)` lit jusqu'au retour à la ligne
- L'espace avant `%` consomme les espaces/retours à la ligne résiduels
- Fonction qui prend une structure en paramètre

---

## Astuces générales

### Passage de structures aux fonctions

**Par valeur (copie) :**
```c
void afficher(Point p) {
    printf("(%.1f, %.1f)\n", p.x, p.y);
}
```

**Par adresse (modification possible) :**
```c
void deplacer(Point *p, float dx, float dy) {
    p->x += dx;  // Notation -> pour les pointeurs
    p->y += dy;
}

// Utilisation :
Point p = {0, 0};
deplacer(&p, 5, 3);  // Passer l'adresse avec &
```

### Initialisation de structures

```c
// Méthode 1 : Initialisation lors de la déclaration
Point p1 = {3.5, 2.8};

// Méthode 2 : Champ par champ
Point p2;
p2.x = 3.5;
p2.y = 2.8;

// Méthode 3 : Initialisation avec désignateurs (C99)
Point p3 = {.x = 3.5, .y = 2.8};
```

### Compilation avec math.h

N'oubliez jamais le flag `-lm` :
```bash
gcc mon_programme.c -lm -o mon_programme
```

### Débogage

Utilisez `gdb` ou l'extension VS Code pour déboguer :
```bash
gcc -g mon_programme.c -lm -o mon_programme
gdb ./mon_programme
```

---

**Note :** Ces corrections sont fournies à titre indicatif. Il existe souvent plusieurs façons correctes de résoudre un exercice !
