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

// Etape 4 : modifier une structure SANS pointeur -> return + reaffectation
Personnage subir_degats(Personnage cible, int degats)
{
    cible.stats.pv -= degats;
    if (cible.stats.pv < 0) {
        cible.stats.pv = 0;
    }
    return cible;
}

// Etape 6 : fonctions sur un tableau de structures
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
    // Etape 5 (rappel, non reutilise directement ici) : combat 1 vs 1 entre deux Personnage,
    // deja valide a l'etape precedente -- on passe directement a l'equipe complete.

    Personnage equipe[TAILLE_EQUIPE];
    for (int i = 0; i < TAILLE_EQUIPE; i++) {
        equipe[i] = saisir_personnage("Personnage", i);
    }

    Personnage monstres[NB_MONSTRES];
    for (int i = 0; i < NB_MONSTRES; i++) {
        monstres[i] = saisir_personnage("Monstre", i);
    }

    printf("\n--- Equipe de heros ---\n");
    afficher_equipe(equipe, TAILLE_EQUIPE);
    printf("PV totaux de l'equipe: %d\n", pv_totaux(equipe, TAILLE_EQUIPE));

    printf("\n--- Monstres ---\n");
    afficher_equipe(monstres, NB_MONSTRES);

    printf("\n");
    for (int i = 0; i < NB_MONSTRES; i++) {
        equipe[0] = subir_degats(equipe[0], monstres[i].stats.attaque);
        printf("%s subit l'attaque de %s : PV restants %d\n",
               equipe[0].nom, monstres[i].nom, equipe[0].stats.pv);
    }

    return 0;
}
