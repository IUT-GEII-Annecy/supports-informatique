# Templates Base

Templates communs à toutes les disciplines.

## Structure

```
base/
└── SX_SemestreTemplate/
    ├── preamble_module.tex        # Préambule semestre
    └── SeqXX_SemestreTemplate/
        ├── preamble.tex           # Préambule séquence
        └── TPXX_TPTemplate/       # Template TP
            ├── TPXX_TPTemplate.tex
            ├── main.tex
            └── sources/           # Ressources (images, code, etc.)
```

## Tokens

Les templates utilisent des tokens remplacés automatiquement par le scaffolder :

- `__SEMESTRE_NUM__` - Numéro semestre (S1, S2, etc.)
- `__SEMESTRE_TITRE__` - Titre du semestre
- `__SEQUENCE_NUM__` - Numéro séquence (01, 02, etc.)
- `__SEQUENCE_TITRE__` - Titre de la séquence
- `__T_TYPE__` - Type document (TP, TD, Cours, etc.)
- `__T_NUM__` - Numéro document (01, 02, etc.)
- `__T_TITRE__` - Titre du document
- `__DATE__` - Date de création

## Utilisation

Ces templates sont utilisés automatiquement par le scaffolder sauf si des overrides existent dans `disciplines/[nom]/overrides/`.

## Héritage

1. Le scaffolder cherche d'abord dans `templates/disciplines/[nom]/overrides/`
2. Si non trouvé, utilise `templates/base/`

Cela permet de personnaliser par discipline tout en partageant les templates communs.

## Ajout Template

Pour ajouter un nouveau type de template (ex: DS, DM) :

```bash
# Copier template TP existant
cp -r TPXX_TPTemplate DSXX_DSTemplate

# Modifier fichiers dans DSXX_DSTemplate/
# Mettre à jour tokens:
# - TPXX_ → DSXX_
# - TPTemplate → DSTemplate
# - TP → DS dans le contenu
```

Ensuite, le scaffolder pourra utiliser :

```bash
scaffolder t ds "Devoir Surveillé" --auto
```
