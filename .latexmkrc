# Configuration latexmk pour supports-informatique
# Utilise pdflatex par défaut
$pdf_mode = 1;
$pdflatex = 'pdflatex -interaction=nonstopmode';
$clean_ext = 'aux log out toc fdb_latexmk fls synctex.gz bbl blg';

# TEXINPUTS optionnel - UPSTI devrait être dans ~/texmf
# Si UPSTI n'est pas trouvé automatiquement, décommenter:
# ensure_path('TEXINPUTS', '~/texmf/tex/latex/UPSTI//');
