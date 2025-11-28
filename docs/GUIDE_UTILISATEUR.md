# Guide Utilisateur - Supports LaTeX

## Introduction

Ce dépôt contient des supports pédagogiques LaTeX pour différentes disciplines techniques (Informatique, RLI, etc.) basés sur la classe `UPSTI_Document` v2.0.

## Structure du Projet

```
supports_latex/
├── latex/              # Classe UPSTI_Document v2.0 et modules
│   ├── UPSTI_Document.cls
│   ├── core/          # Modules de base
│   ├── packages/      # Packages spécialisés (typo, SI, etc.)
│   ├── layout/        # Géométrie et mise en page
│   ├── profiles/      # Profils établissements (CPGE, IUT, Lycée)
│   └── logos/         # Logos et images
├── disciplines/       # Contenu disciplinaire
│   ├── informatique/  # Supports informatique
│   └── rli/           # Supports RLI
├── templates/         # Templates de documents
│   ├── base/          # Templates de base
│   └── disciplines/   # Templates disciplinaires
├── tools/             # Outils de développement
│   └── scaffolder/    # Générateur de squelettes
└── docs/              # Documentation projet
    ├── guides/        # Guides utilisateur/développeur
    └── architecture/  # Documentation technique
```

## Compiler un Document LaTeX

### Méthode 1 : Script helper (Recommandé)

Le projet fournit un script `compile.sh` qui configure automatiquement l'environnement de compilation :

```bash
cd /path/to/supports_latex
./compile.sh disciplines/informatique/S1_Initiation_programmation_langageC/Seq06_Types_structures/TP_01/tp05_fonctions.tex
```

### Méthode 2 : Compilation manuelle avec pdflatex

Si vous préférez compiler manuellement, vous devez configurer `TEXINPUTS` pour que LaTeX trouve tous les fichiers nécessaires :

```bash
cd /path/to/supports_latex

# Définir TEXINPUTS
export TEXINPUTS=".:latex//:latex/core//:latex/packages//:latex/layout//:latex/profiles//:$TEXINPUTS"

# Compiler le document
cd disciplines/informatique/S1_Initiation_programmation_langageC/Seq06_Types_structures/TP_01
pdflatex tp05_fonctions.tex
```

### Méthode 3 : Utiliser latexmk

Si vous utilisez `latexmk`, le fichier `.latexmkrc` à la racine du projet configure automatiquement les chemins :

```bash
cd /path/to/supports_latex/disciplines/informatique/.../
latexmk -pdf tp05_fonctions.tex
```

## Types de Documents Disponibles

La classe `UPSTI_Document` supporte différents types de documents :

- **Cours** : `\documentclass[cours]{UPSTI_Document}`
- **TD** : `\documentclass[td]{UPSTI_Document}`
- **TP** : `\documentclass[TP]{UPSTI_Document}`
- **QCM** : `\documentclass[QCM]{UPSTI_Document}`
- **Evaluation** : `\documentclass[eval]{UPSTI_Document}`

## Profils Disponibles

Différents profils d'établissements sont disponibles dans `latex/profiles/` :

- **CPGE PSI** : `profiles/CPGE_PSI.tex`
- **CPGE PT** : `profiles/CPGE_PT.tex`
- **BUT GEII** : `profiles/BUT_GEII.tex`
- **Lycée STI2D** : `profiles/Lycee_STI2D.tex`
- **IUT Annecy** : `profiles/IUT_Annecy.sty`

Pour utiliser un profil, incluez-le dans le préambule de votre document :

```latex
\documentclass[TP]{UPSTI_Document}
\usepackage{IUT_Annecy}  % Profil IUT Annecy
```

## Créer un Nouveau Document

### Option 1 : Utiliser le scaffolder

Le projet inclut un outil `scaffolder` pour générer automatiquement des squelettes de documents :

```bash
# Installer le scaffolder (si pas déjà fait)
cd tools/scaffolder
pip install -e .

# Générer un nouveau TP
scaffolder create --type TP --title "Mon nouveau TP" --output disciplines/informatique/S1_Initiation_programmation_langageC/mon_nouveau_tp
```

### Option 2 : Copier un template

Copiez un template existant depuis `templates/` et adaptez-le :

```bash
cp -r templates/base/TP_template disciplines/informatique/.../mon_nouveau_tp
cd disciplines/informatique/.../mon_nouveau_tp
# Éditez le fichier .tex
```

### Option 3 : Créer manuellement

Créez un nouveau fichier `.tex` avec la structure minimale :

```latex
\documentclass[TP]{UPSTI_Document}

% Préambule disciplinaire (si nécessaire)
\input{../../preamble_module.tex}

% Métadonnées
\discipline{Informatique}
\newcommand{\UPSTIidClasse}{1}
\newcommand{\UPSTItitreEnTete}{Titre du document}

\begin{document}

% Votre contenu ici

\end{document}
```

## Disciplines Disponibles

### Informatique

- **Chemin** : `disciplines/informatique/`
- **Contenu** : S1 - Initiation à la programmation en C
- **Préambule** : `preamble_module.tex`

### RLI (Réseaux et Logique Industrielle)

- **Chemin** : `disciplines/rli/`
- **Contenu** : S3 - EME Introduction GTB
- **Préambule** : `preamble_module.tex`

## Dépannage

### Erreur : "UPSTI_Document.cls not found"

**Solution** : Assurez-vous que `TEXINPUTS` inclut le dossier `latex/`. Utilisez le script `compile.sh` ou configurez manuellement :

```bash
export TEXINPUTS=".:latex//:$TEXINPUTS"
```

### Erreur : "Package ... not found"

**Solution** : Vérifiez que tous les sous-dossiers de `latex/` sont inclus dans `TEXINPUTS` :

```bash
export TEXINPUTS=".:latex//:latex/core//:latex/packages//:latex/layout//:latex/profiles//:$TEXINPUTS"
```

### Erreur : "File cc_by_nc_sa.png not found"

**Solution** : Ce logo de licence Creative Commons peut être absent. Vérifiez si l'image existe dans `latex/logos/`. Vous pouvez télécharger le logo depuis le site Creative Commons ou désactiver l'affichage du logo dans votre document.

### La compilation est lente

**Conseil** : Utilisez `pdflatex` avec l'option `-interaction=nonstopmode` pour éviter les pauses interactives, ou utilisez `latexmk` qui gère automatiquement les recompilations nécessaires.

## Ressources Supplémentaires

- **Guide Développeur** : `docs/guides/GUIDE_DEVELOPPEUR.md`
- **Guide Ajout Discipline** : `docs/guides/GUIDE_AJOUT_DISCIPLINE.md`
- **Documentation UPSTI** : `latex/docs/`
- **Notes de Refactoring** : `docs/architecture/REFACTORING_NOTES.md`

## Support

Pour signaler un problème ou demander de l'aide, consultez la documentation du projet ou contactez les mainteneurs.
