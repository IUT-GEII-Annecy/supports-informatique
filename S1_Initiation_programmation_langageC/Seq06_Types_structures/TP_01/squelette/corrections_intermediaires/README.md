# Corrections intermédiaires — usage enseignant uniquement

Le TP est un **projet filé** : les étudiants travaillent sur un seul fichier
(`jeu_combat.c`) qu'ils enrichissent étape après étape, du début à la fin de la séance.

Ce dossier contient, **pour l'enseignant seulement** (ne pas le distribuer aux
étudiants), des photographies du fichier `jeu_combat.c` à quatre points de
contrôle de la progression. Elles servent à :

- vérifier rapidement où un étudiant en retard devrait être arrivé ;
- dépanner un étudiant bloqué en comparant son fichier à la version de référence ;
- reprendre le TP d'une séance à l'autre si besoin.

## Fichiers

- `etape04_fin.c` — après la partie « Fiche de personnage » (étapes 1 à 4) :
  structure simple, fonction `soigner` sans pointeur, structure imbriquée
  `Stats`, `enum Classe` et `stats_initiales`
- `etape08_fin.c` — après la partie « Attaques et combats » (étapes 5 à 8) :
  ajoute `subir_degats`, le combat 1 contre 1, l'équipe (tableau de
  structures) et le groupe de plusieurs monstres
- `etape12_fin.c` — après la partie « Enrichir le jeu » (étapes 9 à 12) :
  ajoute la recherche du personnage le plus offensif, l'inventaire
  d'objets, les potions/effets et le classement par tri
- `etape13_fin.c` — mini-jeu complet, fin du mini-projet (étape 13) : combat
  de l'équipe de héros contre le groupe de monstres jusqu'à élimination d'un
  camp

Chaque fichier est **autonome et compile seul** (`gcc etapeXX_fin.c -o jeu`),
pour permettre de tester rapidement une étape sans dérouler tout le TP.
