#!/bin/bash

echo "🚀 INIZIO CONVERSIONE - PRESERVANDO FORMATTAZIONE ORIGINALE"
echo "=========================================================="

# Crea cartelle di output
mkdir -p capitoli immagini_temp

# Contatore lezioni
conta=1

# Loop su Lez1 - Lez11
for cartella in Lez{1..11}; do
    if [ -d "$cartella" ]; then
        echo -e "\n📁 PROCESSO $cartella..."
        
        # Trova il file .md (ce n'è uno per cartella)
        file_md=$(find "$cartella" -name "*.md" | head -n 1)
        
        if [ -f "$file_md" ]; then
            echo "   📄 File markdown: $(basename "$file_md")"
            
            # ESTRAI IL TITOLO dal file md per usarlo come capitolo
            titolo=$(head -n 1 "$file_md" | sed 's/^# //' | tr -d '\n')
            
            # CONVERSIONE PRINCIPALE con Pandoc
            # Opzioni spiegate:
            # --from markdown+... = riconosce tabelle, formule, liste
            # --to latex = output LaTeX
            # --standalone = genera file completo
            # --extract-media = estrae TUTTE le immagini
            # --wrap=preserve = mantiene gli a capo originali
            
            pandoc "$file_md" \
                -o "capitoli/lezione$conta.tex" \
                --from markdown+pipe_tables+grid_tables+multiline_tables+tex_math_dollars+raw_tex \
                --to latex \
                --standalone \
                --extract-media="./immagini_temp/lezione$conta" \
                --wrap=preserve
            
            echo "   ✅ Convertito in capitoli/lezione$conta.tex"
            
            # Trova la cartella delle immagini ORIGINALE (quella dentro LezX)
            cartella_immagini=$(find "$cartella" -type d -not -path "$cartella" | head -n 1)
            
            if [ -d "$cartella_immagini" ]; then
                echo "   🖼️  Cartella immagini originale: $(basename "$cartella_immagini")"
                
                # COPIA TUTTE LE IMMAGINI ORIGINALI nella cartella temp
                cp "$cartella_immagini"/* ./immagini_temp/lezione$conta/ 2>/dev/null
                echo "   📸 Copiate $(ls -1 "$cartella_immagini" | wc -l) immagini originali"
            fi
            
            # Verifica che il file .tex sia stato creato e non sia vuoto
            if [ -s "capitoli/lezione$conta.tex" ]; then
                echo "   📊 Dimensione file: $(du -h "capitoli/lezione$conta.tex" | cut -f1)"
            else
                echo "   ⚠️  ATTENZIONE: File vuoto o non creato!"
            fi
            
            ((conta++))
        else
            echo "   ⚠️  Nessun file .md trovato in $cartella"
        fi
    fi
done

echo -e "\n📊 RIEPILOGO CONVERSIONE:"
echo "========================="
echo "✅ Lezioni convertite: $((conta-1))"
echo "📁 File .tex in: capitoli/"
echo "🖼️  Immagini in: immagini_temp/ (divise per lezione)"

# Chiedi se vuoi unire tutte le immagini in una cartella unica
echo -e "\n🔧 POST-PROCESSING:"
read -p "Vuoi unire tutte le immagini in un'unica cartella 'immagini/'? (s/n): " risposta
if [[ "$risposta" == "s" || "$risposta" == "S" ]]; then
    mkdir -p immagini
    cp -r immagini_temp/*/* ./immagini/ 2>/dev/null
    echo "   ✅ Immagini unite in 'immagini/'"
    
    # AGGIORNA I PERCORSI NEI FILE .TEX
    echo "   🔄 Aggiorno percorsi immagini nei file .tex..."
    for tex in capitoli/*.tex; do
        sed -i 's/\\includegraphics{/\\includegraphics[width=0.8\\textwidth]{..\/immagini\//g' "$tex"
        sed -i 's/\\includegraphics\[width=\\textwidth\]{/\\includegraphics[width=0.8\\textwidth]{..\/immagini\//g' "$tex"
    done
    echo "   ✅ Percorsi aggiornati"
fi

echo -e "\n🎉 OPERAZIONE COMPLETATA!"
echo "Ora hai i file .tex pronti per Overleaf nella cartella 'capitoli/'"