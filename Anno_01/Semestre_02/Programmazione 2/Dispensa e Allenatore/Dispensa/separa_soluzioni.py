# Sposta le soluzioni degli esercizi da moduloNN.tex a soluzioniNN.tex.
# Uso: python separa_soluzioni.py            (tutti i moduli che hanno ancora le soluzioni dentro)
#      python separa_soluzioni.py 08 09      (solo alcuni)
# Nel modulo resta un rimando al PDF delle soluzioni.
import re, sys, os, glob

os.chdir(os.path.dirname(os.path.abspath(__file__)))
MARCATORE = "\\subsection*{Soluzioni}"

numeri = sys.argv[1:] or sorted(f[6:8] for f in glob.glob("modulo[0-9][0-9].tex"))
for nn in numeri:
    f = f"modulo{nn}.tex"
    s = open(f, encoding="utf-8", newline="").read()
    if MARCATORE not in s:
        print(f"{f}: niente da spostare")
        continue
    nl = "\r\n" if "\r\n" in s else "\n"
    prima, dopo = s.split(MARCATORE, 1)
    titolo = re.search(r"\\chapter\{(.*)\}", s).group(1)
    sol = (f"% Soluzioni degli esercizi del {titolo.split(' -- ')[0]} (generato da separa_soluzioni.py)" + nl
           + f"\\chapter{{Soluzioni -- {titolo}}}" + nl + dopo.lstrip())
    open(f"soluzioni{nn}.tex", "w", encoding="utf-8", newline="").write(sol)
    rimando = (MARCATORE.replace("Soluzioni", "Soluzioni") + nl
               + "Le soluzioni commentate, con il codice e l'output reale, sono nel PDF separato" + nl
               + "\\textbf{Soluzioni} (\\texttt{soluzioni-light.pdf} / \\texttt{soluzioni-dark.pdf})," + nl
               + "allo stesso numero di esercizio. Il codice è anche in \\texttt{codice/m" + nn + "/}." + nl)
    open(f, "w", encoding="utf-8", newline="").write(prima + rimando)
    print(f"{f}: soluzioni spostate in soluzioni{nn}.tex")
