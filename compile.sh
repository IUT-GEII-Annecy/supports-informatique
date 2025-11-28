#!/bin/bash
# Script de compilation simple pour supports-informatique
# Usage: ./compile.sh path/to/document.tex

if [ -z "$1" ]; then
    echo "Usage: $0 <fichier.tex>"
    echo "Exemple: $0 S1_Initiation_programmation_langageC/Seq01_.../TP01_.../tp01.tex"
    exit 1
fi

FILE="$1"

if [ ! -f "$FILE" ]; then
    echo "❌ Erreur: Le fichier '$FILE' n'existe pas"
    exit 1
fi

DIR=$(dirname "$FILE")
BASENAME=$(basename "$FILE" .tex)

echo "📄 Compilation: $FILE"
echo "📁 Répertoire: $DIR"
echo ""

# Aller dans le répertoire du fichier
cd "$DIR" || exit 1

# Compilation (2 passes pour les références)
echo "🔨 Passe 1/2..."
pdflatex -interaction=nonstopmode "$BASENAME.tex" > /dev/null

echo "🔨 Passe 2/2..."
pdflatex -interaction=nonstopmode "$BASENAME.tex"

if [ -f "$BASENAME.pdf" ]; then
    echo ""
    echo "✅ PDF généré: $DIR/$BASENAME.pdf"
    ls -lh "$BASENAME.pdf"
else
    echo ""
    echo "❌ Erreur: PDF non généré. Vérifiez les erreurs LaTeX ci-dessus."
    exit 1
fi
