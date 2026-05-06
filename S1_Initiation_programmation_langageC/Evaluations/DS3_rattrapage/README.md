# DS3 Rattrapage - Sujet de rattrapage

Ce dossier contient le sujet de rattrapage pour les étudiants absents au DS3.

## Structure identique au DS3

Le sujet suit exactement la même structure que le DS3 :
- Durée : 55 minutes
- Barème identique : Exercice 1 (2 pts), Exercice 2 (6 pts), Exercice 3 (6 pts), Exercice 4 (6 pts)
- Même niveau de difficulté
- Mêmes types d'exercices

## Différences de contenu (pour éviter la copie)

### Exercice 1 : Appels de fonctions (2 points)
**DS3 :**
- `void bonjour(void);`
- `float cos(float angle);`
- `void affiche(int nbre, char lettre);`
- `bool kbhit(void);`

**DS3_rattrapage :**
- `void aurevoir(void);` (au lieu de bonjour)
- `float sin(float angle);` (au lieu de cos)
- `void ecrire(char symbole, int nombre);` (ordre des paramètres inversé, nom différent)
- `bool estPresse(void);` (nom en français au lieu de kbhit)

### Exercice 2 : Fonctions (6 points)
**DS3 :**
- Fonction `pair()` : retourne 1 si entier pair
- Fonction `arrondi()` : retourne l'entier le plus proche d'un réel
- Fonction `gereCompteur()` : incrémente/décrémente un compteur selon un booléen (+1/-1)

**DS3_rattrapage :**
- Fonction `impair()` : retourne 1 si entier impair (logique inversée)
- Fonction `tronque()` : retourne la partie entière sans arrondir (différent)
- Fonction `gereDistance()` : augmente de 10 ou diminue de 5 une distance (valeurs et type différents)

### Exercice 3 : Tableaux (6 points)
**DS3 :**
- Contexte : Mesure de vitesse d'un robot
- Durée : 1 minute
- Fréquence : 1 mesure par seconde (60 mesures)
- Unité : cm/s
- Calcul : Accélération (dérivée de la vitesse)
- Fonction fournie : `max()` pour trouver la vitesse maximale
- Fonctions : `delay()`, `mesureVitesse()`

**DS3_rattrapage :**
- Contexte : Mesure de température d'un four industriel
- Durée : 2 heures
- Fréquence : 1 mesure toutes les 2 minutes (60 mesures)
- Unité : degrés Celsius
- Calcul : Variation thermique (dérivée de la température)
- Fonction fournie : `min()` pour trouver la température minimale (inverse)
- Fonctions : `attendre()`, `lireTemperature()` (noms différents)

### Exercice 4 : Structures (6 points)
**DS3 :**
- Mesure double : vitesse + puissance consommée
- Unités : cm/s + milliWatt
- Calcul final : Énergie (Wh) = somme des puissances × Δt
- Fonction : `mesurePuissance()`

**DS3_rattrapage :**
- Mesure double : température + humidité relative
- Unités : °C + pourcentage
- Calcul final : Eau évaporée (grammes) = somme des humidités × 0,5 × Δt
- Fonction : `lireHumidite()`

## Compilation

```bash
cd /home/ubuntu/supports-informatique/S1_Initiation_programmation_langageC/Evaluations/DS3_rattrapage
TEXMFHOME=~/texmf lualatex -interaction=nonstopmode DS3_rattrapage.tex
TEXMFHOME=~/texmf lualatex -interaction=nonstopmode DS3_rattrapage.tex
```

Deux passes sont nécessaires pour résoudre les références croisées.

## Fichiers

```
DS3_rattrapage/
├── DS3_rattrapage.tex              # Fichier principal
├── sources/
│   ├── exercice_appels_fonctions.tex
│   ├── exercice_fonctions.tex
│   └── exercice_tableaux.tex
└── README.md                        # Ce fichier
```

## Notes pédagogiques

Les modifications ont été conçues pour :
1. **Maintenir le même niveau de difficulté** : les concepts testés sont identiques
2. **Empêcher la copie directe** : tous les noms, valeurs et contextes sont différents
3. **Préserver l'équité** : les étudiants en rattrapage ont un examen de qualité équivalente
4. **Éviter la reconnaissance** : même la logique de certaines fonctions est inversée (pair/impair, max/min)
