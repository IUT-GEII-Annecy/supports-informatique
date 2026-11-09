# Corrections et Exemples — TP Types Structurés (mini-jeu de combat)

Ce TP est un **projet filé** : les étudiants travaillent sur un seul fichier `jeu_combat.c`
qu'ils enrichissent étape après étape. Ce document contient des corrections commentées
illustrant le contenu attendu du fichier à certaines étapes clés — chaque extrait montre
l'état du fichier à cette étape, pas un programme indépendant.

Pour des **versions complètes et compilables** du fichier à quatre points de contrôle de la
progression (fin de la partie 1, fin de la partie 2, fin de la partie 3, version finale), voir
le dossier `corrections_intermediaires/` (réservé à l'enseignant, à ne pas distribuer).

## Étape 1 — Personnage simple (solution complète)

```c
#include <cs50.h>
#include <stdio.h>

typedef struct {
    string nom;
    int pv;
    int attaque;
} Personnage;

int main(void)
{
    Personnage heros;

    heros.nom = get_string("Nom du personnage: ");

    heros.pv = get_int("Points de vie: ");
    heros.attaque = get_int("Attaque: ");

    printf("%s (PV: %d, ATQ: %d)\n", heros.nom, heros.pv, heros.attaque);

    return 0;
}
```

**Points importants :**
- On utilise `typedef` pour simplifier l'utilisation de la structure
- L'accès aux champs se fait avec l'opérateur `.`
- `get_string` renvoie un `string` (alias `char *` fourni par `cs50`) : on peut l'affecter
  directement à un champ de type `string`, sans copie manuelle
- `get_int` relit automatiquement la saisie tant qu'elle n'est pas un entier valide : pas besoin
  de vérifier de code de retour, contrairement à `scanf`

---

## Étape 3 — Stats imbriquées (solution complète)

```c
#include <cs50.h>
#include <stdio.h>

typedef struct {
    int pv;
    int attaque;
    int defense;
} Stats;

typedef struct {
    string nom;
    Stats stats;
} Personnage;

void afficher_personnage(Personnage p)
{
    printf("%s (PV: %d, ATQ: %d, DEF: %d)\n", p.nom, p.stats.pv, p.stats.attaque, p.stats.defense);
}

int main(void)
{
    Personnage perso;

    perso.nom = get_string("Nom du personnage: ");

    perso.stats.pv = get_int("Points de vie: ");
    perso.stats.attaque = get_int("Attaque: ");
    perso.stats.defense = get_int("Defense: ");

    afficher_personnage(perso);

    return 0;
}
```

**Points importants :**
- Structure imbriquée : `Personnage` contient un champ `Stats`
- Accès à un champ imbriqué : `perso.stats.pv` (on chaîne les `.`)

---

## Étape 5 — Subir des dégâts (solution complète)

```c
#include <cs50.h>
#include <stdio.h>

typedef struct {
    int pv;
    int attaque;
    int defense;
} Stats;

typedef enum { GUERRIER, MAGE, ARCHER } Classe;

typedef struct {
    string nom;
    Classe classe;
    Stats stats;
} Personnage;

Stats stats_initiales(Classe c)
{
    Stats s;
    switch (c) {
        case GUERRIER: s.pv = 35; s.attaque = 7;  s.defense = 6; break;
        case MAGE:      s.pv = 20; s.attaque = 10; s.defense = 2; break;
        case ARCHER:    s.pv = 25; s.attaque = 9;  s.defense = 3; break;
    }
    return s;
}

void afficher_personnage(Personnage p)
{
    printf("%s (PV: %d, ATQ: %d, DEF: %d)\n", p.nom, p.stats.pv, p.stats.attaque, p.stats.defense);
}

// Pas de pointeur : on renvoie la structure modifiee, l'appelant reaffecte.
Personnage subir_degats(Personnage cible, int degats)
{
    cible.stats.pv -= degats;
    if (cible.stats.pv < 0) {
        cible.stats.pv = 0;
    }
    return cible;
}

int main(void)
{
    Personnage heros;

    heros.nom = get_string("Nom du personnage: ");

    int classe_choisie = get_int("Classe (0=Guerrier, 1=Mage, 2=Archer): ");
    heros.classe = (Classe) classe_choisie;
    heros.stats = stats_initiales(heros.classe);

    printf("Avant : ");
    afficher_personnage(heros);

    int degats = get_int("Degats subis: ");

    heros = subir_degats(heros, degats);  // reaffectation : c'est elle qui "modifie" heros

    printf("Apres : ");
    afficher_personnage(heros);

    return 0;
}
```

**Points importants :**
- `subir_degats` reçoit une **copie** de `cible` : la modifier dans la fonction ne change rien à
  l'extérieur
- C'est le `return cible;` suivi de la réaffectation `heros = subir_degats(heros, degats);` qui
  fait que `heros` change réellement dans le `main`
- Le clamp (`if (... < 0) ... = 0;`) évite des PV négatifs

---

## Étape 7 — Équipe (tableau de structures, solution complète)

```c
#include <cs50.h>
#include <stdio.h>

#define TAILLE_EQUIPE 3

typedef struct {
    int pv;
    int attaque;
    int defense;
} Stats;

typedef enum { GUERRIER, MAGE, ARCHER } Classe;

typedef struct {
    string nom;
    Classe classe;
    Stats stats;
} Personnage;

Stats stats_initiales(Classe c)
{
    Stats s;
    switch (c) {
        case GUERRIER: s.pv = 35; s.attaque = 7;  s.defense = 6; break;
        case MAGE:      s.pv = 20; s.attaque = 10; s.defense = 2; break;
        case ARCHER:    s.pv = 25; s.attaque = 9;  s.defense = 3; break;
    }
    return s;
}

void afficher_personnage(Personnage p)
{
    printf("%s (PV: %d, ATQ: %d, DEF: %d)\n", p.nom, p.stats.pv, p.stats.attaque, p.stats.defense);
}

void afficher_equipe(Personnage equipe[], int taille)
{
    for (int i = 0; i < taille; i++) {
        afficher_personnage(equipe[i]);
    }
}

int pv_totaux(Personnage equipe[], int taille)
{
    int total = 0;
    for (int i = 0; i < taille; i++) {
        total += equipe[i].stats.pv;
    }
    return total;
}

int main(void)
{
    Personnage equipe[TAILLE_EQUIPE];

    for (int i = 0; i < TAILLE_EQUIPE; i++) {
        equipe[i].nom = get_string("Personnage %d - Nom: ", i);

        int classe_choisie = get_int("Personnage %d - Classe (0=Guerrier, 1=Mage, 2=Archer): ", i);
        equipe[i].classe = (Classe) classe_choisie;
        equipe[i].stats = stats_initiales(equipe[i].classe);
    }

    printf("\n");
    afficher_equipe(equipe, TAILLE_EQUIPE);
    printf("PV totaux de l'equipe: %d\n", pv_totaux(equipe, TAILLE_EQUIPE));

    return 0;
}
```

**Points importants :**
- Un tableau de structures se déclare et se parcourt comme un tableau "classique" :
  `equipe[i].stats.pv`
- Une fonction qui reçoit un tableau de structures doit toujours recevoir sa **taille** à côté
  (le tableau ne la connaît pas lui-même)

---

## Astuces générales

### Initialisation de structures

```c
// Methode 1 : champ par champ
Personnage p;
p.pv = 35;

// Methode 2 : initialisation a la declaration
Stats s = {35, 7, 6};

// Methode 3 : initialisation avec designateurs (C99)
Stats s2 = {.pv = 35, .attaque = 7, .defense = 6};
```

### Modifier une structure sans pointeur

Ce TP n'utilise **pas** les pointeurs. Pour faire évoluer une structure dans une fonction, le
seul moyen est donc de la **renvoyer** modifiée, puis de **réaffecter** la variable de l'appelant :

```c
Personnage subir_degats(Personnage cible, int degats) {
    cible.stats.pv -= degats;
    return cible;
}

heros = subir_degats(heros, 10);  // obligatoire : sinon heros ne change pas
```

### Débogage

```bash
gcc -g mon_programme.c -o mon_programme
gdb ./mon_programme
```

---

**Note :** Ces corrections sont fournies à titre indicatif. Il existe souvent plusieurs façons
correctes de résoudre un exercice !
