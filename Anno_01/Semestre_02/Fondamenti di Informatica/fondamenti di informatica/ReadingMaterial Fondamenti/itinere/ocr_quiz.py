import os
from PIL import Image
import pytesseract

# 🔧 Indica dove si trova Tesseract
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'

# Cartella principale dove ci sono tutte le sottocartelle cap1, cap2, ecc.
cartella_base = "quiz_png"

# File di output
output = open("quiz_estratto.txt", "w", encoding="utf-8")

# Cerca tutte le immagini nelle sottocartelle
for root, dirs, files in os.walk(cartella_base):
    for file in sorted(files):
        if file.lower().endswith(".png"):
            path_completo = os.path.join(root, file)
            nome_cartella = os.path.basename(root)

            img = Image.open(path_completo)
            testo = pytesseract.image_to_string(img, lang='ita')  # usa 'eng' se il quiz è in inglese

            output.write(f"\n--- {nome_cartella}/{file} ---\n")
            output.write(testo + "\n")

output.close()
print("✅ Testo estratto! File salvato come quiz_estratto.txt")
