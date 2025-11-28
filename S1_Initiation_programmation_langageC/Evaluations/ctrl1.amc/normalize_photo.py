#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import csv
import os
import re
import sys
import unicodedata
from pathlib import Path

GROUP_RE = re.compile(r"^[A-Z]\d\s+", re.UNICODE)

# Extensions d'images gérées
IMG_EXTS = {".jpg", ".jpeg", ".png", ".bmp", ".tif", ".tiff", ".heic", ".webp", ".gif"}

def strip_accents(s: str) -> str:
    return "".join(c for c in unicodedata.normalize("NFKD", s) if not unicodedata.combining(c))

def collapse_spaces(s: str) -> str:
    return re.sub(r"\s+", " ", s).strip()

def normalize_hyphens(s: str) -> str:
    # remplace doubles tirets et tirets exotiques par un seul '-'
    s = re.sub(r"[‐-‒–—―]+", "-", s)  # différents tirets Unicode
    s = re.sub(r"-{2,}", "-", s)
    return s

def split_surname_given(base_no_group: str):
    """
    Heuristique :
    - NOM = suite de tokens en MAJUSCULES (peuvent contenir apostrophes/traits)
    - prénom(s) = à partir du 1er token contenant une minuscule
    """
    tokens = base_no_group.split(" ")
    surname_tokens, given_tokens = [], []
    switched = False
    for tok in tokens:
        if not switched and re.search(r"[a-zàâçéèêëîïôûùüÿñæœ]", tok):
            switched = True
        (given_tokens if switched else surname_tokens).append(tok)
    # garde-fou : si tout est en MAJUSCULES (pas de prénom détecté), on coupe au dernier token
    if given_tokens == [] and len(surname_tokens) > 1:
        given_tokens = [surname_tokens.pop()]
    return " ".join(surname_tokens), " ".join(given_tokens)

def sanitize_filename(s: str, keep_accents: bool, keep_spaces: bool) -> str:
    # Supprime apostrophes, convertit caractères non sûrs
    # Conserve lettres/chiffres/ _ - . et espaces éventuellement
    if not keep_accents:
        s = strip_accents(s)
    s = s.replace("’", "'")  # apostrophe typographique → ASCII
    s = s.replace("'", "")   # retire les apostrophes dans les noms (CLERC'H -> CLERCH)

    # Remplace tout ce qui n'est pas alnum/_/ - /. / espace par un underscore
    allowed_space = " " if keep_spaces else ""
    s = re.sub(fr"[^0-9A-Za-z_\-\.{allowed_space}]", "_", s)

    # Espaces → underscores si demandé
    if not keep_spaces:
        s = re.sub(r"\s+", "_", s)

    # Nettoyage underscores/tirets multiples
    s = re.sub(r"_+", "_", s)
    s = re.sub(r"-{2,}", "-", s)
    s = s.strip("._-")
    return s

def choose_new_name(dirpath: Path, target_stem: str, ext: str) -> Path:
    candidate = dirpath / f"{target_stem}{ext}"
    if not candidate.exists():
        return candidate
    i = 2
    while True:
        c = dirpath / f"{target_stem}_{i}{ext}"
        if not c.exists():
            return c
        i += 1

def process_file(fp: Path, args, writer) -> Path | None:
    orig_name = fp.name

    # ignorer fichiers non images
    ext = fp.suffix.lower()
    if ext not in IMG_EXTS:
        return None

    # base sans extension, nettoyage des espaces autour
    base = collapse_spaces(fp.stem)
    base = normalize_hyphens(base)

    # enlève le groupe au début : "A1 " / "B2 " / etc.
    base = GROUP_RE.sub("", base)
    base = collapse_spaces(base)

    # parfois il reste un espace final juste avant l'extension dans le nom initial → déjà traité par collapse_spaces

    # détection NOM / prénom(s)
    surname_raw, given_raw = split_surname_given(base)

    # normalisations de casse
    surname_norm = collapse_spaces(surname_raw.upper())
    given_norm = " ".join(w.capitalize() if w else "" for w in collapse_spaces(given_raw).split(" ")).strip()

    # si pas de prénom détecté, on garde tout en NOM
    if not given_norm:
        target_stem = surname_norm
    else:
        target_stem = f"{surname_norm} {given_norm}"

    # extension cible en .jpg
    target_ext = ".jpg"

    # Sanitize final
    target_stem = normalize_hyphens(target_stem)
    target_stem = collapse_spaces(target_stem)
    safe_stem = sanitize_filename(target_stem, keep_accents=args.keep_accents, keep_spaces=args.keep_spaces)

    new_path = choose_new_name(fp.parent, safe_stem, target_ext)

    # DRY RUN ?
    if args.dry_run:
        print(f"[DRY] {orig_name}  ->  {new_path.name}")
    else:
        try:
            fp.rename(new_path)
            print(f"[OK ] {orig_name}  ->  {new_path.name}")
        except Exception as e:
            print(f"[ERR] {orig_name}  !!  {e}", file=sys.stderr)
            return None

    # log mapping
    writer.writerow({"old_name": orig_name, "new_name": new_path.name})
    return new_path

def main():
    ap = argparse.ArgumentParser(description="Normaliser des noms de fichiers photos étudiants et enlever le groupe (A1, B2, ...).")
    ap.add_argument("directory", nargs="?", default=".", help="Dossier contenant les photos (défaut: .)")
    ap.add_argument("--dry-run", action="store_true", help="Simulation : n'effectue pas les renommages, affiche seulement.")
    ap.add_argument("--keep-accents", action="store_true", help="Ne pas translittérer les accents (par défaut, on les enlève).")
    ap.add_argument("--keep-spaces", action="store_true", help="Conserver les espaces au lieu de les remplacer par des underscores.")
    ap.add_argument("--csv", default="rename_map.csv", help="Nom du fichier CSV de mapping (défaut: rename_map.csv)")
    args = ap.parse_args()

    dirpath = Path(args.directory).resolve()
    if not dirpath.is_dir():
        print(f"Erreur: {dirpath} n'est pas un dossier", file=sys.stderr)
        sys.exit(1)

    csv_path = dirpath / args.csv
    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=["old_name", "new_name"])
        writer.writeheader()

        count = 0
        for fp in sorted(dirpath.iterdir()):
            if fp.is_file():
                if process_file(fp, args, writer):
                    count += 1

    mode = "DRY-RUN" if args.dry_run else "RENOMMAGE"
    print(f"\n[{mode}] Terminé. {count} fichier(s) traités. Mapping écrit dans: {csv_path}")

if __name__ == "__main__":
    main()
