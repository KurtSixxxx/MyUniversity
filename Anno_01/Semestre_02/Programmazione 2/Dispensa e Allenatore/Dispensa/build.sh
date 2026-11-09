#!/bin/bash
# Compila i 4 PDF (2 passate ciascuno) e riporta errori, overfull e pagine.
# Uso: bash build.sh
cd "$(dirname "$0")"
# MiKTeX installato "solo per l'utente" non sempre e' nel PATH della shell
MIK="$LOCALAPPDATA/Programs/MiKTeX/miktex/bin/x64"; [ -d "$MIK" ] && export PATH="$MIK:$PATH"
for f in dispensa-light dispensa-dark soluzioni-light soluzioni-dark; do
  pdflatex -interaction=nonstopmode -halt-on-error $f.tex >/dev/null 2>&1
  pdflatex -interaction=nonstopmode $f.tex >/dev/null 2>&1
  pagine=$(python -c "import pymupdf; print(len(pymupdf.open('$f.pdf')))" 2>/dev/null)
  echo "$f: errori $(grep -c '^!' $f.log), overfull $(grep -c Overfull $f.log), pagine $pagine"
  grep -n "^!" -A5 $f.log | head -12
done
rm -f *.aux *.out *.toc
