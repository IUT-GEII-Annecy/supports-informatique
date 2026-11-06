#include <stdio.h>

#define TAILLE_EQUIPE 3
#define NB_MONSTRES 2

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
} Personnage;

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

void afficher_monstres_numerotes(Personnage monstres[], int taille)
{
    for (int i = 0; i < taille; i++) {
        printf("%d. %s (PV: %d)\n", i, monstres[i].nom, monstres[i].stats.pv);
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

// Indice du premier personnage encore vivant dans un tableau, -1 si tous vaincus
int indice_premier_vivant(Personnage groupe[], int taille)
{
    for (int i = 0; i < taille; i++) {
        if (groupe[i].stats.pv > 0) {
            return i;
        }
    }
    return -1;
}

int choisir_cible_vivante(Personnage monstres[], int taille)
{
    int choix;
    for (;;) {
        printf("Quel monstre attaquer (numero) ? ");
        scanf("%d", &choix);
        if (choix >= 0 && choix < taille && monstres[choix].stats.pv > 0) {
            return choix;
        }
        printf("Choix invalide ou monstre deja vaincu, recommencez.\n");
    }
}

static Personnage saisir_personnage(const char *etiquette, int indice)
{
    Personnage p;
    printf("%s %d - Nom: ", etiquette, indice);
    scanf("%29s", p.nom);

    int classe_choisie;
    printf("%s %d - Classe (0=Guerrier, 1=Mage, 2=Archer): ", etiquette, indice);
    scanf("%d", &classe_choisie);
    p.classe = (Classe) classe_choisie;
    p.stats = stats_initiales(p.classe);
    return p;
}

int main(void)
{
    Personnage heros[TAILLE_EQUIPE];
    for (int i = 0; i < TAILLE_EQUIPE; i++) {
        heros[i] = saisir_personnage("Heros", i);
    }

    Personnage monstres[NB_MONSTRES];
    for (int i = 0; i < NB_MONSTRES; i++) {
        monstres[i] = saisir_personnage("Monstre", i);
    }

    Potion potion_de_soin = {"Potion de soin", SOIN, 20};

    printf("\n--- Equipe de heros ---\n");
    afficher_equipe(heros, TAILLE_EQUIPE);
    printf("\n--- Monstres ---\n");
    afficher_equipe(monstres, NB_MONSTRES);
    printf("\n");

    int tour = 1;
    while (indice_premier_vivant(heros, TAILLE_EQUIPE) != -1 &&
           indice_premier_vivant(monstres, NB_MONSTRES) != -1) {

        int ih = indice_premier_vivant(heros, TAILLE_EQUIPE);

        printf("--- Tour %d : %s ---\n", tour, heros[ih].nom);
        printf("0. Monstres: ");
        afficher_monstres_numerotes(monstres, NB_MONSTRES);
        printf("1. Attaquer\n");
        printf("2. Utiliser une potion\n");
        printf("Votre choix: ");
        int choix_action;
        scanf("%d", &choix_action);

        if (choix_action == 2) {
            heros[ih] = appliquer_potion(heros[ih], potion_de_soin);
            printf("%s boit %s (effet +%d)\n", heros[ih].nom, potion_de_soin.nom, potion_de_soin.valeur);
        } else {
            int im = choisir_cible_vivante(monstres, NB_MONSTRES);
            monstres[im] = subir_degats(monstres[im], heros[ih].stats.attaque);
            printf("%s attaque %s (PV restants: %d)\n", heros[ih].nom, monstres[im].nom, monstres[im].stats.pv);
            if (monstres[im].stats.pv == 0) {
                printf("%s est vaincu !\n", monstres[im].nom);
            }
        }

        int im = indice_premier_vivant(monstres, NB_MONSTRES);
        if (im != -1) {
            heros[ih] = subir_degats(heros[ih], monstres[im].stats.attaque);
            printf("%s attaque %s (PV restants: %d)\n", monstres[im].nom, heros[ih].nom, heros[ih].stats.pv);
            if (heros[ih].stats.pv == 0) {
                printf("%s est vaincu !\n", heros[ih].nom);
            }
        }

        tour++;
    }

    if (indice_premier_vivant(heros, TAILLE_EQUIPE) != -1) {
        printf("\nLes heros l'emportent !\n");
    } else {
        printf("\nLes monstres l'emportent !\n");
    }

    return 0;
}
