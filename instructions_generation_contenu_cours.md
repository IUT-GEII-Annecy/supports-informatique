# Consignes pour la génération de contenu pédagogique (CM / TD / TP)

Ce document complète `instruction_poly_a_trou.md` (qui porte spécifiquement sur un format
« poly à trous distribué pendant un CM tapé en direct au tableau »). Les consignes ci-dessous
couvrent le cas plus général : rédaction ou révision d'un support LaTeX/UPSTI complet
(CM, TD, TP, DS) destiné à être lu et complété par l'étudiant de façon autonome ou semi-autonome,
en version étudiant et en version professeur. Elles ont été établies à partir des retours de
l'enseignant sur plusieurs supports réels (notamment la séquence « Types structurés » du S1 et
le DS1 « Borne de recharge »).

## 1. Public et niveau

Étudiants de BUT GEII, filière technologique, débutants en programmation (S1) ou en
automatisme/robotique (BUT3). La programmation ou le formalisme est un outil, pas une fin en
soi. Toujours vérifier, avant de rédiger un exemple, que les notions utilisées ont bien été
introduites dans les séquences précédentes (pas de pointeurs/`malloc` non vus en C S1 avant leur
séquence dédiée, pas de notation non encore introduite dans un document GEII, etc.). En cas de
doute, consulter rapidement les séquences antérieures plutôt que de supposer le niveau.

## 2. Le document doit se suffire à lui-même

Un support qui sera donné sans son cours oral (ou lu par un étudiant absent) ne doit **jamais**
renvoyer à une notion « vue en cours », « déjà rencontrée en TP X » ou à un document externe sans
la réintroduire. Toute notion utilisée doit être définie ou rappelée dans le document où elle est
utilisée, avec un renvoi interne (`\label`/`\ref`) si elle est développée ailleurs dans le même
support.

Vérifier également l'**ordre d'introduction des notions** : ne jamais utiliser ou questionner sur
un objet/bloc/mot-clé avant de l'avoir présenté. Ce point mérite une relecture dédiée (cf. §6).

## 3. Philosophie des activités et des trous

### 3.1 Ce qui mérite un trou

Un trou (qu'il s'agisse d'un `UPSTIquadrillage` libre ou d'un trou inséré dans du code, cf. §4)
doit porter sur une **application d'un concept important**, jamais sur une définition pure ou sur
une information déjà donnée ailleurs dans l'énoncé (y compris dans le nom d'une variable/fonction
à retrouver). L'objectif est de faire réfléchir l'étudiant quelques secondes avant de lui donner
la correction, pour mieux assimiler — pas de tester le par cœur.

À proscrire systématiquement :
- une question dont la réponse est déjà contenue dans l'énoncé ou dans le nom de l'élément à
  identifier (ex. « bloc `VAL_` ou `MC_` ? » quand le nom du bloc le dit déjà) ;
- une question purement définitionnelle (« qu'est-ce qu'une structure ? », « quel mot-clé... ? »).

À privilégier :
- compléter un corps de fonction, une condition, une boucle sur un cas concret proche d'un TP réel ;
- choisir entre plusieurs structures de données/outils pour modéliser une situation donnée ;
- repérer et corriger des erreurs dans un extrait de code plausible ;
- une question diagnostique construite autour d'un usage réel du TP associé, plutôt qu'une
  question conceptuelle isolée.

Quand un support (CM, TD) accompagne des TP réels, les activités doivent autant que possible
être **cohérentes avec la pratique effective du TP** : si le TP n'autorise jamais d'agir
directement sur un objet donné mais impose de passer par des blocs dédiés, aucune activité ne
doit laisser croire le contraire ni évaluer l'inverse.

### 3.2 Densité et longueur

- Activités courtes : privilégier des trous à compléter dans un code déjà largement écrit plutôt
  que de faire rédiger un programme complet, sauf exercice de synthèse explicitement voulu long
  (TD d'application de fin de séquence, par exemple).
- Quelques activités par section suffisent (densité du type de `C03_fonctions` : 1 à 2 activités
  par sous-section, pas une avalanche).
- Supprimer un `UPSTIquadrillage` quand la totalité de la réponse est déjà capturée par les trous
  du code qui le précède : un quadrillage vide à côté d'un code déjà complété par trous est
  redondant.

## 4. Le trou à réponse intégrée — mécanisme par défaut

Le mécanisme à privilégier par défaut, pour un code à compléter **comme pour une question
ouverte courte**, est le trou à réponse intégrée (modèle de
`03_chaine_conversion`, `02_AutomatismeRobotique/03_chaine_conversion/preamble.tex`) :

```latex
\newcommand{\trou}[2][]{%
    \tikz[baseline=(trou.base)]{%
        \node[draw=gray!70, dashed, rounded corners=2pt, inner sep=2pt,
              minimum width=#2, minimum height=1.6em, fill=white,
              anchor=base] (trou) {\strut\ifnumequal{1}{\UPSTIidVersionDocumentDef}%
                {\UPSTIcorrection[1]{\ttfamily #1}}{}};%
    }%
}
```

`\trou[réponse]{largeur}` affiche un cadre pointillé vide en version étudiant
(`\documentVersion{E}`) et, en version professeur (`\documentVersion{P}`), la réponse en rouge
dans le cadre (via `\UPSTIcorrection`, déjà disponible dans la classe UPSTI — pas besoin de la
redéfinir). `\ifnumequal` et `\UPSTIidVersionDocumentDef` viennent d'`etoolbox`, déjà chargé par
la classe UPSTI : aucun `\usepackage` supplémentaire n'est nécessaire.

- **Dans un listing** (modèle du DS1,
  `S1_Initiation_programmation_langageC/Evaluations/DS1_borne-recharge/DS1.tex`) : insérer
  `\trou[réponse]{largeur}` via `escapeinside={(*}{*)}` (ou un délimiteur équivalent, cohérent
  dans tout le document), à l'endroit exact où l'étudiant doit écrire.
- **Dans le texte courant** (hors listing), pour une question ouverte courte : placer
  `\trou[réponse]{largeur}` directement dans la phrase de la question, à l'endroit de la réponse
  attendue — ce qui remplace avantageusement un `\UPSTIquadrillage` quand la réponse est brève
  (une valeur, une expression, une justification en une phrase). Un `UPSTIquadrillage` séparé
  reste légitime uniquement pour une réponse véritablement longue ou multi-points qui ne se prête
  pas à un remplissage ponctuel (ex. une identification de plusieurs erreurs distinctes dans un
  code, à traiter plutôt comme une série de petits trous, un par ligne fautive, cf. §4.2).

**Conséquence sur les blocs de correction** : quand toutes les sous-questions d'une activité sont
couvertes par des trous à réponse intégrée, le bloc séparé
`\begin{UPSTIprofOnlyEnv}\begin{UPSTIcorrectionP}{...}\end{UPSTIcorrectionP}\end{UPSTIprofOnlyEnv}`
devient inutile et doit être supprimé : la réponse s'affiche déjà dans le trou en version
professeur. Ne garder un bloc `UPSTIcorrectionP` qu'en complément, pour une explication ou une
justification qui va au-delà de la simple valeur remplie (rare une fois la question elle-même
convertie en trou, cf. §4.2).

### 4.1 Contrainte de largeur

Les trous doivent être **larges sur la page**, pour laisser suffisamment de place à l'écriture
manuscrite (plusieurs centimètres, voire l'essentiel de la largeur de la ligne ; mettre le trou sur
sa propre ligne dans le listing plutôt que de le coller à du texte dense, dès qu'une expression
complète est attendue). Un trou trop étroit ne sert à rien sur un document imprimé.

### 4.2 Piège à connaître : crochets dans la réponse

L'argument optionnel `[réponse]` de `\trou` est délimité par des crochets `[` `]` au sens de
LaTeX. Si la réponse contient elle-même des crochets non protégés — très fréquent en C avec
l'indexation de tableau (`tableau[i]`, `promo[i].note`) — la lecture de l'argument optionnel
échoue et la compilation produit une cascade d'erreurs `pgfmath`/`Extra }`. **Systématiquement
envelopper d'une paire d'accolades supplémentaire toute réponse contenant `[` ou `]`** :
`\trou[{promo[i].note}]{6cm}` plutôt que `\trou[promo[i].note]{6cm}`. Les accolades
supplémentaires sont transparentes (standard LaTeX, argument optionnel brace-aware) et n'apparaissent
pas dans le rendu.

La macro `\trou` est définie localement dans le fichier racine du document qui l'utilise (pas dans
un préambule partagé), sur le modèle de `03_chaine_conversion` — chaque support reste autonome.

## 5. Structure et conventions de fichiers

- Un CM/TD/TP suit la structure de référence déjà en place :
  `<Nom>.tex` (racine : `\documentclass`, `\input{../preamble.tex}`, `\input{../../preamble_module.tex}`,
  `\documentVersion{E}`) + `main.tex` (liste des `\input{sources/...}` séparés par `\pagebreak`,
  terminé par `\section{Ce qu'il faut retenir}` + `\tabledesdefinitions` pour un CM) + un
  fichier par section/thème dans `sources/`.
- Avant de créer un nouveau support, lire intégralement un support de référence équivalent déjà
  validé dans le dépôt (même type de document : CM, TD, TP, DS) pour en reproduire exactement les
  mécanismes, plutôt que d'inventer une nouvelle convention.
- Après compilation, déplacer le `.pdf` final (et le `.tdf` associé, index UPSTI des définitions)
  dans un sous-dossier `pdf/` à côté du `.tex` racine, comme c'est déjà fait dans les supports
  existants. Ne pas laisser les artefacts de build (`.aux .log .fls .fdb_latexmk .out .toc
  .synctex.gz`) dans le dossier final.
- Ne jamais modifier un fichier hors du périmètre explicitement demandé (un autre TD/TP, un
  préambule partagé, un sujet d'évaluation) sans une raison explicite et validée.

## 6. Relecture de cohérence

Avant de considérer un support terminé, relire (ou faire relire par un agent dédié) :

1. **L'ordre des notions** : aucune question ni aucun exemple n'utilise une notion non encore
   introduite dans le document (cf. §2).
2. **La cohérence avec les TP réels associés**, quand ils existent : les objets, blocs et noms
   utilisés dans les activités doivent correspondre à l'usage réel attendu en TP (et aux
   notations imposées par les sujets de TP officiels, si elles existent — vérifier les PDF sources
   avant de renommer quoi que ce soit qui y est prescrit littéralement).
3. **La rédaction complète des corrections** en version professeur, pour chaque trou créé.
4. **La compilation des deux versions** (cf. §7).

## 7. Vérification — ne jamais se contenter du rapport d'un agent

Toute génération ou révision de contenu doit être vérifiée **indépendamment** avant d'être
considérée comme terminée, même après délégation à un agent (fable ou autre) :

- Compiler la version étudiant (`\documentVersion{E}`, celle du fichier racine) avec
  `latexmk -pdf -interaction=nonstopmode -f -g <Nom>.tex` et vérifier l'absence de ligne `^! `
  dans le `.log`.
- Compiler également une copie temporaire en version professeur
  (`\documentVersion{P}`) pour s'assurer que les corrections et les trous remplis s'affichent
  correctement ; supprimer ensuite cette copie et ses artefacts.
- Relire par échantillonnage le contenu réellement produit (pas seulement le résumé donné par
  l'agent) : au moins les sections les plus modifiées, pour confirmer le respect du ton, de la
  philosophie des trous (§3) et de l'absence de commentaire méta.
- Confirmer que les seuls fichiers touchés sont ceux explicitement dans le périmètre de la
  demande (`git status`/`ls` ciblé), avant de rapporter le travail comme terminé.

## 8. Ton et forme

- Ton pédagogique et professionnel, sans familiarité excessive.
- Aucun commentaire méta sur le document lui-même (pas de « nous allons voir dans ce cours... »,
  pas de justification du choix pédagogique dans le texte destiné à l'étudiant).
- Réutiliser les environnements UPSTI déjà présents dans les supports de référence
  (`UPSTIinfor`, `UPSTIremarque`, `UPSTIwarning`, `UPSTIactivite`, `UPSTIquestion`,
  `UPSTIquadrillage`, `UPSTIprofOnlyEnv`, `UPSTIcorrectionP`) plutôt que d'en introduire de
  nouveaux.

## 9. Délégation à un agent fable

La rédaction ou la révision de contenu long peut être confiée à un agent fable, à condition de
lui fournir dans le prompt :
- les fichiers de référence à imiter (structure, mécanismes de trous) ;
- le contenu pédagogique attendu, section par section ;
- les contraintes des §2 à §6 ci-dessus, explicitées pour le cas précis traité ;
- la liste exacte des fichiers à créer/modifier et le périmètre à ne pas dépasser ;
- la procédure de vérification du §7, à exécuter par l'agent lui-même avant de rapporter.

Le rapport de l'agent reste une donnée à vérifier, jamais une confirmation suffisante (§7).
