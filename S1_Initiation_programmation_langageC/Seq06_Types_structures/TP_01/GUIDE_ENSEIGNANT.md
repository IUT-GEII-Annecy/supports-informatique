# Guide Enseignant — TP Types Structurés (mini-jeu de combat RPG)

## Vue d'ensemble du TP

**Durée estimée :** 3h
**Niveau :** BUT GEII 1ère année (S1)
**Prérequis :** Fonctions, tableaux (dont tri par sélection), bases du C — **pas** les pointeurs
ni `malloc`
**Objectif principal :** Maîtriser les types structurés en C (structures simples, imbriquées,
tableaux de structures, énumérations) à travers un fil rouge motivant : un mini-jeu de combat
console au tour par tour, construit étape par étape.

**Contrainte de conception :** aucun exercice ne fait appel aux pointeurs. Pour modifier une
structure dans une fonction, on utilise systématiquement le patron `x = f(x, ...);` (la fonction
renvoie la valeur modifiée, l'appelant réaffecte) — exactement comme dans le cours.

**Format du TP : un projet filé, pas une collection d'exercices.** Les étudiants travaillent sur
**un seul fichier**, `jeu_combat.c`, du début à la fin de la séance. Chaque étape ne crée pas un
nouveau programme : elle **reprend le fichier de l'étape précédente** et l'enrichit (nouveau
champ, nouvelle structure, nouvelle fonction, nouveau comportement). Chaque énoncé dans le PDF
liste explicitement ce qui doit être **ajouté** ou **modifié** par rapport à la version
précédente du fichier, sous forme de puces de type diff. En fin de séance, les étudiants
rendent un unique fichier `jeu_combat.c` constituant le mini-jeu complet et fonctionnel (après
l'étape 12).

## Structure du TP

Le TP est organisé en 4 sections progressives totalisant 14 étapes (13 étapes principales +
1 variante), toutes appliquées sur le **même fichier** `jeu_combat.c`.

### 1. Fiche de personnage (étapes 1-3)
- **Objectif :** découverte des structures avec une fiche de personnage simple
- 1. Personnage simple (nom, pv, attaque)
- 2. Structure imbriquée (`Stats` dans `Personnage`)
- 3. Énuméré `Classe` + initialisation par `switch`

**Concepts clés :** déclaration, initialisation, accès aux champs (dont champs imbriqués),
`enum`, fonction qui renvoie une structure

### 2. Attaques et combats (étapes 4-7)
- 4. `subir_degats` : modifier une structure **sans pointeur** (return + réaffectation), clamp
- 5. Combat 1 contre 1, boucle jusqu'à élimination
- 6. Équipe (premier tableau de structures `Personnage equipe[]`)
- 7. **Plusieurs monstres** : un second tableau de structures côté adversaires, l'équipe de
  héros affronte un **groupe**, pas un monstre isolé

**Concepts clés :** modification via return, tableaux de structures, deux tableaux de structures
manipulés en parallèle

### 3. Enrichir le jeu (étapes 8-11)
- 8. Trouver l'indice du personnage le plus offensif dans un tableau de structures
- 9. Inventaire : **nouveau** tableau de structures (`Objet`), butin après combat
- 10. Potions et effets : `enum TypeEffet` imbriqué dans une structure `Potion`
- 11. Classement de l'équipe par dégâts infligés : tri par sélection sur un tableau de structures

**Concepts clés :** recherche d'indice, plusieurs types de structures qui interagissent entre
eux, enum imbriqué, tri de structures (réinvestissement de la séquence Tableaux)

### 4. Mini-projet final (étapes 12-13)
- 12. **Capstone** : combat de l'équipe de héros contre le groupe de monstres, jusqu'à
  élimination d'un camp — mobilise tableaux de structures, structures imbriquées, énumérations
  et fonctions à tableau de structures en paramètre, dans le même fichier. C'est la version
  finale de `jeu_combat.c`, celle qui est rendue.
- 12bis. Variante (si le temps le permet) : équiper toute l'équipe de butin avant le combat
- 13. Bonus ultime (facultatif, sur copie du fichier) : plusieurs vagues de monstres successives

**Concepts clés :** synthèse de toutes les notions du TP, réutilisation de code déjà écrit

## Philosophie pédagogique

### Progression
1. **Phase guidée (étapes 1-4)** : introduction douce, squelettes fournis pour les structures
   simple, imbriquée, et le patron `return` sans pointeur
2. **Phase semi-guidée (étapes 5-11)** : autonomie croissante, énoncés détaillés, squelettes
   fournis uniquement pour les tout premiers tableaux de structures (6, 7) et les nouvelles
   structures (9)
3. **Phase autonome — mini-projet (étapes 12-13)** : synthèse, l'étape 13 est volontairement
   ouverte

### Squelette fourni

Un seul squelette de départ est fourni : `squelette/jeu_combat.c` (équivalent à l'étape 1,
structure `Personnage` minimale avec `// TODO`). Les étudiants travaillent **uniquement** sur
ce fichier pendant toute la séance : chaque étape reprend le fichier précédent et l'enrichit, il
n'y a pas de nouveau squelette à télécharger en cours de route.

### Versions de référence intermédiaires (enseignant uniquement)

Le dossier `squelette/corrections_intermediaires/` contient quatre photographies **complètes et
compilables** de `jeu_combat.c` à des points de contrôle de la progression — à ne **pas**
distribuer aux étudiants, elles servent uniquement à l'enseignant pour dépanner ou vérifier
l'avancement :
- `etape03_fin.c` — fin de la partie « Fiche de personnage » (structure imbriquée + enum)
- `etape07_fin.c` — fin de la partie « Attaques et combats » (équipe + plusieurs monstres)
- `etape11_fin.c` — fin de la partie « Enrichir le jeu » (inventaire, potions, classement)
- `etape12_fin.c` — mini-jeu complet (capstone)

**Rationale :** un seul fil conducteur de code, cohérent avec le principe de projet filé ; les
versions intermédiaires permettent à l'enseignant de recaler rapidement un étudiant en
difficulté sans avoir à relire tout son code.

## Ressources pédagogiques

### Documents fournis
- **PDF principal** : `types_structures.pdf`
  - Introduction (objectifs, contrainte "pas de pointeurs", principe du projet filé, conseils)
  - Théorie complète sur les structures (dont le patron de modification sans pointeur)
  - 14 étapes avec cahiers des charges sous forme de diffs ("ajouter"/"modifier") par rapport au
    fichier de l'étape précédente

- **Squelette et références** : dossier `squelette/`
  - `jeu_combat.c` — l'unique squelette de départ distribué aux étudiants, avec `TODO` commentés
  - `corrections_intermediaires/` — 4 versions de référence complètes du fichier à des points de
    contrôle de la progression (réservé enseignant)
  - `README.md` avec instructions d'utilisation
  - `CORRECTIONS_EXEMPLES.md` avec extraits commentés pour les étapes 1, 2, 4 et 6

## Conseils pour l'animation

### Points d'attention

1. **Modifier sans pointeur** (étape 4) — point critique du TP
   - Bien insister : `cible` dans `subir_degats` est une **copie**
   - Rappeler la syntaxe vue en cours : `point_a = translater(point_a, ...);`
   - Faire visualiser au tableau pourquoi `subir_degats(heros, 10);` seul (sans réaffectation)
     ne change rien

2. **Étape 6-7 (tableaux de structures)**
   - Rappeler le lien avec la séquence Tableaux : `equipe[i].stats.pv` combine indexation et
     accès à un champ
   - Insister sur la nécessité de transmettre la taille en paramètre, comme pour un tableau
     "classique"
   - L'étape 7 introduit **volontairement** un second tableau de structures (`monstres[]`) tôt
     dans la progression : ne pas attendre le mini-projet final pour manipuler plusieurs
     structures en tableau

3. **Étape 9 (scanf et chaînes)**
   - Les étudiants ont souvent des problèmes avec `scanf("%s", ...)` pour les noms contenant des
     espaces (non traité ici, les noms sont sans espace) — rappeler `%29s` avec la taille du
     tableau moins 1

4. **Étape 12 (capstone)**
   - Bien faire identifier, avant de coder, les deux tableaux (`heros[]`, `monstres[]`) et la
     fonction commune `indice_premier_vivant`, réutilisable sur l'un ou l'autre tableau car ce
     sont tous deux des tableaux de `Personnage`

### Timing suggéré (3h)

- 0-15 min : rappel théorique (structures, imbrication, patron sans pointeur)
- 15-45 min : étapes 1 à 3 (fiche de personnage)
- 45-90 min : étapes 4 à 7 (attaques, combats, équipes, plusieurs monstres)
- 90-135 min : étapes 8 à 11 (enrichissements : analyse, inventaire, potions, classement)
- 135-165 min : étape 12 (mini-projet final)
- 165-180 min : étape 13 (bonus) ou consolidation selon le niveau

### Évaluation formative

**Points de contrôle suggérés :**
- Après l'étape 4 : vérifier la compréhension du patron `return` + réaffectation
- Après l'étape 7 : vérifier la maîtrise des tableaux de structures et de leur taille en paramètre
- Après l'étape 12 : vérifier que les étudiants savent combiner toutes les notions sans aide

## Variantes et adaptations

### Pour une séance plus courte (1h30)
- Exercices obligatoires : 1, 2, 4, 6, 7
- Le reste (8-11, 12-13) au choix ou en travail à la maison

### Pour une séance plus longue ou un TP noté
- Ajouter l'étape 13 (vagues de monstres) comme obligatoire
- Suggestion de grille sur 20 points :
  - Étapes 1-3 (fiche de personnage) : 4 points
  - Étapes 4-7 (attaques et combats) : 6 points
  - Étapes 8-11 (enrichissements) : 6 points
  - Étape 12 (mini-projet) : 4 points
  - Étape 13 : bonus
