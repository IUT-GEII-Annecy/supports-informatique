#include <stdio.h>

#define TAILLE_EQUIPE 3

typedef struct {
    int pv;
    int attaque;
    int defense;
} Stats;

typedef enum {
    GUERRIER,
    MAGE,
    ARCHER
} Classe;

typedef struct {
    char nom[30];
    Classe classe;
    Stats stats;
    int degats_infliges;   // Etape 11
} Personnage;

// Etape 9 : nouveau type de structure, independant de Personnage
typedef struct {
    char nom[30];
    int bonus_attaque;
} Objet;

// Etape 10 : enum imbrique dans une structure
typedef enum {
    SOIN,
    POISON
} TypeEffet;

typedef struct {
    char nom[30];
    TypeEffet effet;
    int valeur;
} Potion;

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

Personnage subir_degats(Personnage cible, int degats)
{
    cible.stats.pv -= degats;
    if (cible.stats.pv < 0) {
        cible.stats.pv = 0;
    }
    return cible;
}

// Etape 8 : recherche d'indice sur un tableau de structures
int indice_plus_fort(Personnage equipe[], int taille)
{
    int meilleur = 0;
    for (int i = 1; i < taille; i++) {
        if (equipe[i].stats.attaque > equipe[meilleur].stats.attaque) {
            meilleur = i;
        }
    }
    return meilleur;
}

// Etape 9 : tableau de structures Objet + equipement
int indice_meilleur_objet(Objet butin[], int taille)
{
    int meilleur = 0;
    for (int i = 1; i < taille; i++) {
        if (butin[i].bonus_attaque > butin[meilleur].bonus_attaque) {
            meilleur = i;
        }
    }
    return meilleur;
}

Personnage equiper(Personnage p, Objet o)
{
    p.stats.attaque += o.bonus_attaque;
    return p;
}

// Etape 10 : application d'un effet de potion
Personnage appliquer_potion(Personnage cible, Potion p)
{
    switch (p.effet) {
        case SOIN:
            cible.stats.pv += p.valeur;
            if (cible.stats.pv > 50) {
                cible.stats.pv = 50;
            }
            break;
        case POISON:
            cible.stats.pv -= p.valeur;
            if (cible.stats.pv < 0) {
                cible.stats.pv = 0;
            }
            break;
    }
    return cible;
}

// Etape 11 : tri par selection sur un tableau de structures
void trier_par_degats(Personnage equipe[], int taille)
{
    for (int i = 0; i < taille - 1; i++) {
        int indice_max = i;
        for (int j = i + 1; j < taille; j++) {
            if (equipe[j].degats_infliges > equipe[indice_max].degats_infliges) {
                indice_max = j;
            }
        }
        if (indice_max != i) {
            Personnage temp = equipe[i];
            equipe[i] = equipe[indice_max];
            equipe[indice_max] = temp;
        }
    }
}

int main(void)
{
    Personnage equipe[TAILLE_EQUIPE];
    for (int i = 0; i < TAILLE_EQUIPE; i++) {
        printf("Personnage %d - Nom: ", i);
        scanf("%29s", equipe[i].nom);
        int classe_choisie;
        printf("Personnage %d - Classe (0=Guerrier, 1=Mage, 2=Archer): ", i);
        scanf("%d", &classe_choisie);
        equipe[i].classe = (Classe) classe_choisie;
        equipe[i].stats = stats_initiales(equipe[i].classe);
        printf("Personnage %d - Degats infliges: ", i);
        scanf("%d", &equipe[i].degats_infliges);
    }

    printf("\nAttaquant principal : indice %d\n", indice_plus_fort(equipe, TAILLE_EQUIPE));

    trier_par_degats(equipe, TAILLE_EQUIPE);
    printf("\nClassement :\n");
    for (int i = 0; i < TAILLE_EQUIPE; i++) {
        printf("%d. %s : %d\n", i + 1, equipe[i].nom, equipe[i].degats_infliges);
    }

    return 0;
}
