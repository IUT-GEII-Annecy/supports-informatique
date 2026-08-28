# Image CI réutilisable pour compiler des documents LaTeX basés sur UPSTI.
# Contient une distribution TeX Live complète (évite les échecs "package
# manquant" au fil des documents) + les outils nécessaires pour checkout
# git via SSH (deploy key) et pour scripts/gen_index.py (python3).
#
# Publiée sur ghcr.io/iut-geii-annecy/texlive-upsti, réutilisable par
# n'importe quel repo du groupe (pas seulement supports-informatique).
FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        texlive-full \
        latexmk \
        git \
        openssh-client \
        ca-certificates \
        python3 \
    && rm -rf /var/lib/apt/lists/*
