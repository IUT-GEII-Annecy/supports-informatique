# Image CI réutilisable pour compiler des documents LaTeX basés sur UPSTI.
# Contient une distribution TeX Live complète (évite les échecs "package
# manquant" au fil des documents) + les outils nécessaires pour checkout
# git via SSH (deploy key) et pour scripts/gen_index.py (python3).
#
# auto-multiple-choice (apt) : fournit automultiplechoice.sty, utilisé par
# tout document \documentclass[QCM, ...]{UPSTI_Document}. Ce paquet est
# DISTINCT de texlive-full : automultiplechoice.sty n'est pas sur le CTAN,
# il vit dans /usr/share/texmf/tex/latex/AMC/ (hors de l'arborescence
# TeX Live), donc texlive-full seul ne le fournit jamais. Resté invisible
# jusqu'ici car tous les documents QCM existants étaient sous Evaluations/
# (exclu de ce site) ; nécessaire dès qu'un document QCM public (hors
# Evaluations/) est ajouté au dépôt -- cf. S1.../Entrainement/.
#
# Image republiée après correction des accès GHCR (write_package).
# Publiée sur ghcr.io/iut-geii-annecy/texlive-upsti, réutilisable par
# n'importe quel repo du groupe (pas seulement supports-informatique).
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        texlive-full \
        latexmk \
        auto-multiple-choice \
        git \
        openssh-client \
        ca-certificates \
        python3 \
    && rm -rf /var/lib/apt/lists/*
