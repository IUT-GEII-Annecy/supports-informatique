#!/usr/bin/env python3
"""Génère _site/index.html à partir de la liste des documents compilés/échoués.

Usage: gen_index.py OUT_DIR built_doc1.tex built_doc2.tex ... -- failed_doc1.tex ...
"""
import html
import sys
from collections import defaultdict
from pathlib import Path

args = sys.argv[1:]
out_dir = Path(args[0])
sep = args.index("--") if "--" in args else len(args)
built = [a for a in args[1:sep] if a]
failed = [a for a in args[sep + 1:] if a]

def top_level(doc_path: str) -> str:
    parts = Path(doc_path).parts
    # ex: ('.', 'S1_Initiation_programmation_langageC', 'Seq01_Hello-world', 'tp01-hello-world.tex')
    parts = [p for p in parts if p != "."]
    return parts[1] if len(parts) > 2 else parts[0]

groups = defaultdict(list)
for doc in built:
    p = Path(doc)
    pdf_rel = p.with_suffix(".pdf")
    # chemin relatif dans _site, sans le "./" initial
    rel = str(pdf_rel).removeprefix("./")
    groups[top_level(doc)].append((p.parent.name, rel))

for g in groups.values():
    g.sort()

sections_html = []
for section in sorted(groups):
    items = "\n".join(
        f'      <li><a href="{html.escape(rel)}">{html.escape(name)}</a></li>'
        for name, rel in groups[section]
    )
    sections_html.append(f"""
    <section>
      <h2>{html.escape(section)}</h2>
      <ul>
{items}
      </ul>
    </section>""")

failed_html = ""
if failed:
    items = "\n".join(f"      <li>{html.escape(f)}</li>" for f in sorted(failed))
    failed_html = f"""
    <section class="failed">
      <h2>Non disponibles (échec de compilation)</h2>
      <ul>
{items}
      </ul>
    </section>"""

page = f"""<!doctype html>
<html lang="fr">
<head>
<meta charset="utf-8">
<title>Supports Informatique - BUT GEII</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
  body {{ font-family: system-ui, sans-serif; max-width: 60rem; margin: 2rem auto; padding: 0 1rem; }}
  h1 {{ margin-bottom: 0.2rem; }}
  .subtitle {{ color: #555; margin-top: 0; }}
  section {{ margin-bottom: 1.5rem; }}
  h2 {{ border-bottom: 1px solid #ddd; padding-bottom: 0.2rem; }}
  ul {{ column-width: 18rem; }}
  li {{ margin: 0.2rem 0; break-inside: avoid; }}
  .failed {{ color: #888; }}
  .failed h2 {{ color: #a33; }}
  footer {{ margin-top: 2rem; color: #888; font-size: 0.85em; }}
</style>
</head>
<body>
  <h1>Supports Informatique - BUT GEII</h1>
  <p class="subtitle">PDF générés automatiquement depuis les sources LaTeX. Les évaluations (DS, contrôles) ne sont pas publiées ici.</p>
{''.join(sections_html)}
{failed_html}
  <footer>Généré automatiquement par GitHub Actions.</footer>
</body>
</html>
"""

out_dir.mkdir(parents=True, exist_ok=True)
(out_dir / "index.html").write_text(page, encoding="utf-8")
print(f"index.html généré ({len(built)} document(s), {len(failed)} échec(s))")
