# Supports Pédagogiques - Informatique (BUT GEII)

Ressources LaTeX pour l'enseignement de l'informatique en BUT GEII (Génie Électrique et Informatique Industrielle).

## 📋 Contenu

### S1 - Initiation à la programmation en langage C

- **Chemin** : `S1_Initiation_programmation_langageC/`
- **Nombre de fichiers** : 103 documents LaTeX
- **Sujets** : Introduction à la programmation en C, algorithmique, structures de données
- **Niveau** : Première année BUT GEII

**Organisation** :
```
S1_Initiation_programmation_langageC/
├── Seq01_.../ (Séquence 1)
├── Seq02_.../ (Séquence 2)
├── ...
└── Evaluations/
```

## 🚀 Démarrage Rapide

### Prérequis

- **LaTeX** : TeX Live 2023+ ou MiKTeX
- **UPSTI v2.0** : Classe LaTeX installée dans `~/texmf` ([Installation](#installation-upsti))
- **(Optionnel)** [scaffolder-pedagogique](https://github.com/<votre-organisation>/scaffolder-pedagogique) pour générer de nouveaux documents

### Installation UPSTI

UPSTI (Union des Professeurs de Sciences et Techniques Industrielles) est la classe LaTeX utilisée par tous les documents.

```bash
# Installation dans ~/texmf (recommandé)
git clone https://github.com/Rydness/upsti-latex ~/texmf/tex/latex/UPSTI
texhash ~/texmf
```

Vérification :
```bash
kpsewhich UPSTI_Document.cls
# Devrait afficher: /home/<user>/texmf/tex/latex/UPSTI/UPSTI_Document.cls
```

### Compiler un document

**Méthode 1 : Script helper** (recommandé)
```bash
./compile.sh S1_Initiation_programmation_langageC/Seq01_.../TP01_.../tp01.tex
```

**Méthode 2 : pdflatex direct**
```bash
cd S1_Initiation_programmation_langageC/Seq01_.../TP01_...
pdflatex tp01.tex
pdflatex tp01.tex  # 2ème passe pour les références
```

**Méthode 3 : latexmk** (compilation automatique)
```bash
cd S1_Initiation_programmation_langageC/Seq01_.../TP01_...
latexmk -pdf tp01.tex
```

## 🛠️ Utilisation Avancée

### Générer un nouveau document (avec scaffolder)

```bash
# Installation scaffolder (une seule fois)
pip install -e ../scaffolder-pedagogique/

# Générer un nouveau TP
cd S1_Initiation_programmation_langageC/Seq01_...
scaffolder t tp "Les Pointeurs" --num 05
cd TP05_Les_Pointeurs/
pdflatex tp05.tex
```

### Profils UPSTI disponibles

Les documents peuvent utiliser différents profils établissements :

```latex
\documentclass[TP]{UPSTI_Document}
\usepackage{IUT_Annecy}      % BUT/IUT (par défaut)
% \usepackage{BUT_GEII}       % Profil BUT GEII générique
% \usepackage{CPGE_PSI}       % CPGE PSI
% \usepackage{Lycee_STI2D}    % Lycée STI2D
```

### Structure type d'un document

```latex
\documentclass[TP]{UPSTI_Document}
\usepackage{IUT_Annecy}

\titre{Introduction aux Tableaux}
\numero{03}
\classe{BUT 1 GEII}
\duree{2h}

\begin{document}

% Contenu du TP

\end{document}
```

## 📚 Documentation

- **Guide Utilisateur** : Consultez [docs/GUIDE_UTILISATEUR.md](docs/GUIDE_UTILISATEUR.md) pour les workflows quotidiens
- **UPSTI Documentation** : Référez-vous à `~/texmf/tex/latex/UPSTI/docs/` pour l'API complète

## 🤝 Contribution

### Ajouter un nouveau document

1. Utilisez le scaffolder (recommandé) ou copiez un document existant
2. Respectez les conventions de nommage (`TP##_Titre/`, `TD##_Titre/`)
3. Utilisez la classe `UPSTI_Document`
4. Testez la compilation avant de commiter

### Conventions de commit

```
Type: Description concise

Types:
- Add: Nouveau contenu (TP, TD, Cours)
- Fix: Correction d'erreur
- Update: Amélioration contenu existant
- Docs: Documentation uniquement

Exemples:
- Add: TP05 sur les pointeurs en C
- Fix: Correction énoncé TP03 exercice 2
- Update: Amélioration explications TD02
```

## 📊 Métriques

- **Fichiers .tex** : 103
- **Taille** : ~1.1 Go
- **Public** : Étudiants BUT GEII, enseignants

## 🔗 Ressources

- **Scaffolder** : [scaffolder-pedagogique](https://github.com/<votre-organisation>/scaffolder-pedagogique)
- **Supports RLI** : [supports-rli](https://github.com/<votre-organisation>/supports-rli)
- **UPSTI** : [upsti-latex](https://github.com/Rydness/upsti-latex)
- **LaTeX Project** : https://www.latex-project.org/

## 📧 Contact

Équipe Informatique - IUT Département GEII

## 📄 Licence

Contenu pédagogique distribué selon les termes de la licence académique.
Classe LaTeX UPSTI sous licence CC BY-NC-SA 2.0 FR.

---

**Version** : 1.0.0
**Dernière mise à jour** : Novembre 2025
**Source** : Extrait du monorepo supports_latex v2.0
