#include <cs50.h>
#include <stdio.h>

// --- Etape 2 : structure imbriquee ---
typedef struct {
    int pv;
    int attaque;
    int defense;
} Stats;

// --- Etape 3 : type enumere ---
typedef enum {
    GUERRIER,
    MAGE,
    ARCHER
} Classe;

// --- Etape 1->3 : la structure Personnage s'est enrichie progressivement ---
typedef struct {
    string nom;
    Classe classe;
    Stats stats;
} Personnage;

// Etape 3 : statistiques de depart selon la classe
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

// Etape 2 : affichage de la fiche complete
void afficher_personnage(Personnage p)
{
    printf("%s (PV: %d, ATQ: %d, DEF: %d)\n", p.nom, p.stats.pv, p.stats.attaque, p.stats.defense);
}

int main(void)
{
    Personnage heros;

    heros.nom = get_string("Nom du personnage: ");

    int classe_choisie = get_int("Classe (0=Guerrier, 1=Mage, 2=Archer): ");
    heros.classe = (Classe) classe_choisie;
    heros.stats = stats_initiales(heros.classe);

    afficher_personnage(heros);

    return 0;
}
