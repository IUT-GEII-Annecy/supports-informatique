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
**un seul fichier**, `jeu_combat.c`, du début à la fin de la séance : chaque étape enrichit le
code déjà écrit, sans repartir d'un nouveau programme. Le cahier des charges de chaque étape
décrit le comportement attendu (de façon de plus en plus ouverte au fil du TP, voir plus bas),
pas la marche à suivre. En fin de séance, les étudiants rendent un unique fichier
`jeu_combat.c` constituant le mini-jeu complet et fonctionnel (après l'étape 13).

**Interactivité : un vrai jeu, pas une simulation qui se déroule seule.** À partir de l'étape 6,
le joueur doit prendre de vraies décisions au clavier (fonctions `cs50` : `get_int`,
`get_string`) pendant la partie : choisir
d'attaquer, choisir sa cible parmi plusieurs monstres, décider d'utiliser une potion plutôt que
d'attaquer. L'IA des monstres reste volontairement simple (attaque automatique) : c'est le
joueur qui doit avoir des choix à faire, pas le jeu qui s'affiche tout seul.

## Structure du TP

Le TP est organisé en 4 sections progressives totalisant 15 étapes (14 étapes principales +
1 variante), toutes appliquées sur le **même fichier** `jeu_combat.c`.

### 1. Fiche de personnage (étapes 1-4)
- **Objectif :** découverte des structures avec une fiche de personnage simple
- 1. Personnage simple (nom, pv, attaque)
- 2. Soigner un personnage : fonction qui reçoit une structure simple en paramètre et la
  renvoie modifiée (return + réaffectation), sans imbrication ni enum
- 3. Structure imbriquée (`Stats` dans `Personnage`)
- 4. Énuméré `Classe` + initialisation par `switch`

**Concepts clés :** déclaration, initialisation, accès aux champs (dont champs imbriqués),
`enum`, fonction qui renvoie une structure

### 2. Attaques et combats (étapes 5-8)
- 5. `subir_degats` : réinvestit le patron return + réaffectation (vu à l'étape 2) en y ajoutant
  un clamp, sur une structure imbriquée cette fois
- 6. Combat 1 contre 1 : le joueur choisit l'action de son personnage à chaque tour via un menu
  au clavier (première interaction réelle du TP)
- 7. Équipe (premier tableau de structures `Personnage equipe[]`)
- 8. **Plusieurs monstres** : un second tableau de structures côté adversaires ; le joueur doit
  désormais **choisir sa cible** parmi les monstres encore vivants (saisie + validation)

**Concepts clés :** modification via return, tableaux de structures, deux tableaux de structures
manipulés en parallèle, lecture et validation d'un choix utilisateur

### 3. Enrichir le jeu (étapes 9-12)
- 9. Trouver l'indice du personnage le plus offensif dans un tableau de structures
- 10. Inventaire : **nouveau** tableau de structures (`Objet`), butin après combat
- 11. Potions et effets : `enum TypeEffet` imbriqué dans une structure `Potion` ; le joueur
  choisit, via un menu, entre attaquer et utiliser une potion
- 12. Classement de l'équipe par dégâts infligés : tri par sélection sur un tableau de structures

**Concepts clés :** recherche d'indice, plusieurs types de structures qui interagissent entre
eux, enum imbriqué, tri de structures (réinvestissement de la séquence Tableaux)

### 4. Mini-projet final (étapes 13-14)
- 13. **Capstone** : combat de l'équipe de héros contre le groupe de monstres, jusqu'à
  élimination d'un camp — mobilise tableaux de structures, structures imbriquées, énumérations
  et fonctions à tableau de structures en paramètre, dans le même fichier, **avec un vrai menu
  de tour de jeu pour le héros actif** (attaquer avec choix de cible, ou utiliser une potion) ;
  l'IA des monstres reste automatique. C'est la version finale de `jeu_combat.c`, celle qui est
  rendue.
- 13bis. Variante (si le temps le permet) : équiper toute l'équipe de butin avant le combat
- 14. Bonus ultime (facultatif, sur copie du fichier) : plusieurs vagues de monstres successives

**Concepts clés :** synthèse de toutes les notions du TP, réutilisation de code déjà écrit

## Philosophie pédagogique

### Progression
1. **Phase guidée (étapes 1-5)** : introduction douce, squelettes fournis pour la structure
   simple, le patron `return` sans pointeur (introduit dès l'étape 2), la structure imbriquée,
   et son enrichissement
2. **Phase semi-guidée (étapes 6-12)** : autonomie croissante, énoncés détaillés, squelettes
   fournis uniquement pour les tout premiers tableaux de structures (7, 8) et les nouvelles
   structures (10)
3. **Phase autonome — mini-projet (étapes 13-14)** : synthèse, l'étape 14 est volontairement
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
- `etape04_fin.c` — fin de la partie « Fiche de personnage » (structure simple, fonction
  `soigner` sans pointeur, structure imbriquée + enum)
- `etape08_fin.c` — fin de la partie « Attaques et combats » (équipe + plusieurs monstres,
  avec menu de choix de cible interactif)
- `etape12_fin.c` — fin de la partie « Enrichir le jeu » (inventaire, potions, classement)
- `etape13_fin.c` — mini-jeu complet et interactif (capstone : menu attaquer/potion, choix de
  cible, IA des monstres automatique)

**Rationale :** un seul fil conducteur de code, cohérent avec le principe de projet filé ; les
versions intermédiaires permettent à l'enseignant de recaler rapidement un étudiant en
difficulté sans avoir à relire tout son code.

## Ressources pédagogiques

### Documents fournis
- **PDF principal** : `types_structures.pdf`
  - Introduction (objectifs, contrainte "pas de pointeurs", principe du projet filé, conseils)
  - Théorie complète sur les structures (dont le patron de modification sans pointeur)
  - 15 étapes avec cahiers des charges sous forme de diffs ("ajouter"/"modifier") par rapport au
    fichier de l'étape précédente

- **Squelette et références** : dossier `squelette/`
  - `jeu_combat.c` — l'unique squelette de départ distribué aux étudiants, avec `TODO` commentés
  - `corrections_intermediaires/` — 4 versions de référence complètes du fichier à des points de
    contrôle de la progression (réservé enseignant)
  - `README.md` avec instructions d'utilisation
  - `CORRECTIONS_EXEMPLES.md` avec extraits commentés pour les étapes 1, 3, 5 et 7

## Conseils pour l'animation

### Points d'attention

1. **Modifier sans pointeur** (introduit à l'étape 2, réinvesti à l'étape 5) — point critique
   du TP
   - Dès l'étape 2 (`soigner`), bien insister : la structure reçue en paramètre est une
     **copie** ; c'est le `return` suivi de la réaffectation qui fait changer la variable de
     l'appelant
   - Rappeler la syntaxe vue en cours : `point_a = translater(point_a, ...);`
   - À l'étape 5, faire visualiser au tableau pourquoi `subir_degats(heros, 10);` seul (sans
     réaffectation) ne change rien — le même principe, sur une structure imbriquée et avec un
     clamp en plus

2. **Étape 6 (premier menu joueur)**
   - C'est la première fois que le joueur prend une décision au clavier pendant la partie
     (et non plus seulement à la création des personnages) : vérifier que chacun sait lire un
     entier avec `get_int(...)` pour un choix de menu (pas besoin de vérifier un code retour,
     `get_int` relit automatiquement tant que la saisie n'est pas un entier valide)

3. **Étape 7-8 (tableaux de structures)**
   - Rappeler le lien avec la séquence Tableaux : `equipe[i].stats.pv` combine indexation et
     accès à un champ
   - Insister sur la nécessité de transmettre la taille en paramètre, comme pour un tableau
     "classique"
   - L'étape 8 introduit un second tableau de structures (`monstres[]`) tôt dans la
     progression, et demande au joueur de **choisir sa cible** : bien faire valider que l'indice
     saisi est dans les bornes **et** correspond à un monstre encore vivant avant d'attaquer
     (sinon redemander la saisie)

4. **Étape 10 (`get_string` et chaînes)**
   - Avec `get_string`, la saisie d'un nom contenant des espaces (par exemple « Jean Dupont »)
     fonctionne nativement, contrairement à `scanf("%s", ...)` qui s'arrête au premier espace —
     mais ce TP suppose des noms sans espace pour rester simple ; signaler ce point si un
     étudiant s'interroge sur la différence avec `scanf`

5. **Étape 11 (menu attaquer/potion)**
   - Même logique de menu qu'à l'étape 6, avec un choix supplémentaire : insister sur le fait
     que c'est le joueur qui décide, l'action n'est jamais déclenchée automatiquement

6. **Étape 13 (capstone)**
   - Bien faire identifier, avant de coder, les deux tableaux (`heros[]`, `monstres[]`) et la
     fonction commune `indice_premier_vivant`, réutilisable sur l'un ou l'autre tableau car ce
     sont tous deux des tableaux de `Personnage`
   - Vérifier que le menu (attaquer/potion) et le choix de cible ne concernent que le
     **héros actif** côté joueur : les monstres continuent d'attaquer automatiquement

### Timing suggéré (3h)

- 0-15 min : rappel théorique (structures, imbrication, patron sans pointeur)
- 15-45 min : étapes 1 à 4 (fiche de personnage)
- 45-90 min : étapes 5 à 8 (attaques, combats, équipes, plusieurs monstres)
- 90-135 min : étapes 9 à 12 (enrichissements : analyse, inventaire, potions, classement)
- 135-165 min : étape 13 (mini-projet final)
- 165-180 min : étape 14 (bonus) ou consolidation selon le niveau

### Évaluation formative

**Points de contrôle suggérés :**
- Après l'étape 5 : vérifier la compréhension du patron `return` + réaffectation
- Après l'étape 8 : vérifier la maîtrise des tableaux de structures et de leur taille en paramètre
- Après l'étape 13 : vérifier que les étudiants savent combiner toutes les notions sans aide

## Variantes et adaptations

### Pour une séance plus courte (1h30)
- Exercices obligatoires : 1, 3, 5, 7, 8
- Le reste (9-12, 13-14) au choix ou en travail à la maison

### Pour une séance plus longue ou un TP noté
- Ajouter l'étape 14 (vagues de monstres) comme obligatoire
- Suggestion de grille sur 20 points :
  - Étapes 1-4 (fiche de personnage) : 4 points
  - Étapes 5-8 (attaques et combats) : 6 points
  - Étapes 9-12 (enrichissements) : 6 points
  - Étape 13 (mini-projet) : 4 points
  - Étape 14 : bonus
