# Guide Enseignant - TP Types Structurés

## Vue d'ensemble du TP

**Durée estimée :** 1h30
**Niveau :** BUT GEII 1ère année
**Prérequis :** Fonctions, tableaux, pointeurs (notions de base)
**Objectif principal :** Maîtriser les types structurés en C

## Structure du TP

Le TP est organisé en 4 sections progressives totalisant 16 exercices :

### 1. Premiers pas avec les structures (4 exercices)
- **Objectif :** Découverte des structures avec des points 2D simples
- **Exercices :**
  - 1.1 : Déclaration et affichage d'un point
  - 1.2 : Distance à l'origine (introduction des fonctions avec structures)
  - 1.3 : Distance entre deux points
  - 1.4 : Fonctions créant et affichant des points

**Concepts clés :** Déclaration, initialisation, accès aux champs, passage en paramètre

### 2. Tableaux de structures (4 exercices)
- **Objectif :** Manipuler des collections de données structurées
- **Exercices :**
  - 2.1 : Périmètre d'un polygone
  - 2.2 : Point le plus proche de l'origine
  - 2.3 : Température moyenne de capteurs actifs
  - 2.4 : Alertes de capteurs au-dessus d'un seuil

**Concepts clés :** Tableaux de structures, parcours, filtrage, calculs agrégés

### 3. Structures imbriquées (4 exercices)
- **Objectif :** Créer des structures contenant d'autres structures
- **Exercices :**
  - 3.1 : Aire d'un rectangle (structure contenant deux points)
  - 3.2 : Point à l'intérieur d'un cercle
  - 3.3 : Moyenne d'étudiants
  - 3.4 : Classement d'étudiants selon un seuil

**Concepts clés :** Structures imbriquées, chaînes de caractères, applications réalistes

### 4. Exercices bonus (4 exercices)
- **Objectif :** Approfondir et consolider
- **Exercices :**
  - 4.1 : Top 3 des articles les plus chers
  - 4.2 : Calcul de jours écoulés depuis le début de l'année
  - 4.3 : Distribution de cartes
  - 4.4 : Mini base de données de contacts avec menu

**Concepts clés :** Tri de structures, manipulation avancée, projet intégratif

## Philosophie pédagogique

### Progression
Le TP suit une progression en 3 phases conformément à la philosophie GEII :

1. **Phase guidée (exercices 1.1-1.4)** : Introduction douce avec des squelettes
2. **Phase semi-guidée (exercices 2.1-3.4)** : Autonomie croissante, énoncés détaillés
3. **Phase autonome (exercices 4.1-4.4)** : Défis nécessitant synthèse et créativité

### Squelettes fournis
Des squelettes de code sont fournis pour 5 exercices clés :
- `01_point_simple.c` - Premier contact
- `02_distance_origine.c` - Première fonction avec structure
- `07_capteurs_temperature.c` - Premier tableau de structures
- `09_rectangle_aire.c` - Première structure imbriquée
- `11_etudiants_moyenne.c` - Application réaliste

**Rationale :** Les squelettes aident à démarrer les nouveaux concepts, mais les étudiants doivent coder from scratch pour les exercices suivants.

## Ressources pédagogiques

### Documents fournis
- **PDF principal** : `types_structures.pdf` (13 pages)
  - Introduction avec objectifs et consignes
  - Théorie complète sur les structures
  - 16 exercices avec cahiers des charges

- **Squelettes** : dossier `squelette/`
  - 5 fichiers .c avec TODO commentés
  - README.md avec instructions d'utilisation
  - CORRECTIONS_EXEMPLES.md avec solutions commentées

### Validation automatique
Tous les exercices sont validables avec `check50` :
```bash
check50 IUT-GEII-Annecy/exercices/2025/info1/tp_structures/nom_exercice
```

**Note :** Les tests check50 doivent être créés séparément (non inclus dans ce TP).

## Conseils pour l'animation

### Points d'attention

1. **Syntaxe des structures** (10 premières minutes)
   - Bien insister sur la différence avec/sans typedef
   - Montrer l'opérateur `.` vs `->`
   - Expliquer le passage par valeur vs par adresse

2. **Exercice 2.3 (Capteurs)** - Point critique
   - Premier exercice avec filtre (actif/inactif)
   - Gestion du cas "aucun capteur actif"
   - Vérifier la compréhension avant de continuer

3. **Exercice 3.3 (Étudiants)** - Difficulté scanf
   - Les étudiants ont souvent des problèmes avec `scanf` pour les chaînes
   - Bien expliquer `scanf(" %[^\n]", nom)` et l'espace avant %
   - Avoir un exemple au tableau

4. **Exercices bonus** - Différenciation
   - Pour les étudiants en avance
   - Peuvent être donnés en TP supplémentaire ou en DM
   - Le 4.4 (contacts) est un mini-projet complet

### Timing suggéré (1h30)

- 0-10 min : Rappel théorique et présentation du TP
- 10-30 min : Exercices 1.1 à 1.4 (premiers pas)
- 30-60 min : Exercices 2.1 à 2.4 (tableaux de structures)
- 60-80 min : Exercices 3.1 à 3.4 (structures imbriquées)
- 80-90 min : Bonus ou approfondissement selon le niveau

### Évaluation formative

**Points de contrôle suggérés :**
- Après 1.2 : Vérifier la compréhension du passage de structure en paramètre
- Après 2.3 : Vérifier la maîtrise des tableaux de structures
- Après 3.1 : Vérifier la compréhension des structures imbriquées

## Variantes et adaptations

### Pour une séance plus courte (1h)
- Exercices obligatoires : 1.1, 1.2, 1.3, 2.3, 3.1
- Exercices au choix parmi les autres

### Pour une séance plus longue (2h)
- Ajouter les exercices bonus comme obligatoires
- Demander des fonctions supplémentaires (par ex. tri des étudiants)

### Pour un TP noté
Suggérer une grille :
- Exercices 1.x : 4 points (1 point chacun)
- Exercices 2.x : 6 points (1.5 points chacun)
- Exercices 3.x : 6 points (1.5 points chacun)
- Bonus : 4 points
- **Total : 20 points**

## Prolongements possibles

- **Projet suivant :** Système de gestion (bibliothèque, stock, etc.)
- **Approfondissement :** Structures avec allocation dynamique (malloc)
- **Lien avec autres UE :** Bases de données (modélisation)

## Questions fréquentes des étudiants

**Q : Pourquoi utiliser typedef ?**
R : Pour simplifier l'écriture. Au lieu de `struct Point p`, on écrit juste `Point p`.

**Q : Quelle est la différence entre `.` et `->` ?**
R : `.` pour les structures, `->` pour les pointeurs vers structures. `p->x` équivaut à `(*p).x`.

**Q : Peut-on comparer deux structures avec == ?**
R : Non, il faut comparer champ par champ ou écrire une fonction de comparaison.

**Q : Comment initialiser tous les champs à zéro ?**
R : `Point p = {0};` initialise tous les champs à 0.

**Q : Peut-on retourner une structure depuis une fonction ?**
R : Oui ! C'est valide et pratique. La structure est copiée.

## Support technique

### Compilation
- Standard C99 ou supérieur recommandé
- Flag `-lm` nécessaire pour les exercices avec sqrt()
- Exemple : `gcc -std=c99 -Wall fichier.c -lm -o programme`

### Environnement
- CS50 IDE (recommandé pour check50)
- VS Code avec extension C/C++
- Tout environnement C standard

## Fichiers du TP

```
TP_01/
├── types_structures.tex          # Fichier principal LaTeX
├── types_structures.pdf          # PDF compilé (13 pages)
├── main.tex                      # Structure du document
├── sources/                      # Sources LaTeX
│   ├── introduction.tex          # Introduction du TP
│   ├── methodo.tex              # Théorie sur les structures
│   ├── premiers_pas.tex         # Section 1
│   ├── tableaux_structures.tex  # Section 2
│   ├── structures_imbriquees.tex # Section 3
│   └── bonus.tex                # Section 4
└── squelette/                   # Squelettes pour étudiants
    ├── README.md                # Guide d'utilisation
    ├── CORRECTIONS_EXEMPLES.md  # Solutions commentées
    ├── 01_point_simple.c
    ├── 02_distance_origine.c
    ├── 07_capteurs_temperature.c
    ├── 09_rectangle_aire.c
    └── 11_etudiants_moyenne.c
```

## Auteur et licence

Ce TP a été conçu pour le module S1 Initiation à la programmation en langage C du BUT GEII, suivant la philosophie pédagogique établie dans les TPs précédents de la séquence.

---

**Bon TP !**
