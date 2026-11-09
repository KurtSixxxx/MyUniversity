#!/bin/bash
# Compila ed esegue tutti i programmi della dispensa e ne salva l'output.
#   uso:  bash verifica_codice.sh            (tutti i moduli)
#         bash verifica_codice.sh m01 m03    (solo alcuni)
# Per ogni codice/mNN/X.cpp:
#   - compila con -Wall -Wextra (gli avvisi vengono mostrati)
#   - se esiste codice/mNN/input/X.txt lo usa come tastiera
#   - salva l'output in codice/mNN/output/X.txt (incluso nella dispensa)
cd "$(dirname "$0")/codice" || exit 1
TMP="${TMPDIR:-/tmp}/dispensa_bin"; mkdir -p "$TMP"
moduli="$*"; [ -z "$moduli" ] && moduli=$(ls -d m[0-9][0-9] | tr '\n' ' ')
errori=0
# Toglie i \r di Windows e trasforma i tab in spazi allineati a colonne di 8,
# come in un terminale (listings non gestisce bene i tab).
pulisci() { sed 's/\r$//' "$1" | expand -t 8 > "$TMP/pulito.txt" && mv "$TMP/pulito.txt" "$1"; }
for m in $moduli; do
  mkdir -p "$m/output"
  for f in "$m"/*.cpp; do
    nome=$(basename "$f" .cpp)
    case "$nome" in *_vecchio) continue;; esac
    if ! g++ -Wall -Wextra -g "$f" -o "$TMP/$m-$nome.exe" 2> "$TMP/err.txt"; then
      echo "ERRORE DI COMPILAZIONE: $f"; cat "$TMP/err.txt"; errori=$((errori+1)); continue
    fi
    [ -s "$TMP/err.txt" ] && { echo "AVVISI in $f:"; cat "$TMP/err.txt"; }
    if [ -f "$m/input/$nome.txt" ]; then
      timeout 10 "$TMP/$m-$nome.exe" < "$m/input/$nome.txt" > "$m/output/$nome.txt" 2>&1
    else
      timeout 10 "$TMP/$m-$nome.exe" < /dev/null > "$m/output/$nome.txt" 2>&1
    fi
    rc=$?
    pulisci "$m/output/$nome.txt"
    [ $rc -ne 0 ] && { echo "USCITA $rc: $f"; errori=$((errori+1)); }
    echo "ok  $f"
  done
  # Esercizi su più file: una sottocartella mNN/esXX/ con main.cpp + altri .cpp
  for d in "$m"/es*/; do
    [ -f "$d/main.cpp" ] || continue
    nome=$(basename "$d")
    if ! g++ -Wall -Wextra -g "$d"/*.cpp -o "$TMP/$m-$nome.exe" 2> "$TMP/err.txt"; then
      echo "ERRORE DI COMPILAZIONE: $d"; cat "$TMP/err.txt"; errori=$((errori+1)); continue
    fi
    [ -s "$TMP/err.txt" ] && { echo "AVVISI in $d:"; cat "$TMP/err.txt"; }
    inp=/dev/null; [ -f "$m/input/$nome.txt" ] && inp="$m/input/$nome.txt"
    timeout 10 "$TMP/$m-$nome.exe" < "$inp" > "$m/output/$nome.txt" 2>&1 || { echo "USCITA $?: $d"; errori=$((errori+1)); }
    pulisci "$m/output/$nome.txt"
    echo "ok  $d (multi-file)"
  done
done
echo "Problemi: $errori"
