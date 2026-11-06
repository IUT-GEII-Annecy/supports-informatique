#include <cs50.h>
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

// Etape 7 : afficher la liste des monstres avec leur numero, pour que le joueur choisisse
void afficher_monstres_numerotes(Personnage monstres[], int taille)
{
    for (int i = 0; i < taille; i++) {
        printf("%d. %s (PV: %d)\n", i, monstres[i].nom, monstres[i].stats.pv);
    }
}

// Etape 7 : lecture au clavier d'une cible valide (vivante) parmi les monstres
int choisir_cible_vivante(Personnage monstres[], int taille)
{
    for (;;) {
        int choix = get_int("Quel monstre attaquer (numero) ? ");
        if (choix >= 0 && choix < taille && monstres[choix].stats.pv > 0) {
            return choix;
        }
        printf("Choix invalide ou monstre deja vaincu, recommencez.\n");
    }
}

static Personnage saisir_personnage(const char *etiquette, int indice)
{
    Personnage p;
    p.nom = get_string("%s %d - Nom: ", etiquette, indice);

    int classe_choisie = get_int("%s %d - Classe (0=Guerrier, 1=Mage, 2=Archer): ", etiquette, indice);
    p.classe = (Classe) classe_choisie;
    p.stats = stats_initiales(p.classe);
    return p;
}

// Renvoie 1 s'il reste au moins un monstre vivant, 0 sinon
int groupe_vivant(Personnage groupe[], int taille)
{
    for (int i = 0; i < taille; i++) {
        if (groupe[i].stats.pv > 0) {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
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
    afficher_monstres_numerotes(monstres, NB_MONSTRES);

    // Le joueur choisit sa cible, tour apres tour, tant qu'il reste un monstre vivant
    // et que equipe[0] est en vie (l'IA des monstres reste simple : premier vivant riposte)
    while (groupe_vivant(monstres, NB_MONSTRES) && equipe[0].stats.pv > 0) {
        printf("\n--- Monstres ---\n");
        afficher_monstres_numerotes(monstres, NB_MONSTRES);

        int cible = choisir_cible_vivante(monstres, NB_MONSTRES);
        monstres[cible] = subir_degats(monstres[cible], equipe[0].stats.attaque);
        printf("%s attaque %s : PV restants %d\n", equipe[0].nom, monstres[cible].nom, monstres[cible].stats.pv);

        if (monstres[cible].stats.pv > 0) {
            equipe[0] = subir_degats(equipe[0], monstres[cible].stats.attaque);
            printf("%s subit l'attaque de %s : PV restants %d\n", equipe[0].nom, monstres[cible].nom, equipe[0].stats.pv);
        }
    }

    return 0;
}
