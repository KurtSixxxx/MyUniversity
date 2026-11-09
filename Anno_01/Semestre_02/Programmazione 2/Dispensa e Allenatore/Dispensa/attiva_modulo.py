# Attiva un modulo nella dispensa e nel volume Soluzioni (decommenta le righe \input).
# Uso: python attiva_modulo.py 09
import sys, os, re
os.chdir(os.path.dirname(os.path.abspath(__file__)))
nn = sys.argv[1]
for f, nome in (("corpo.tex", f"modulo{nn}"), ("corpo-soluzioni.tex", f"soluzioni{nn}")):
    s = open(f, encoding="utf-8", newline="").read()
    nuovo = re.sub(r"^% \\input\{" + nome + r"\}[^\r\n]*", lambda m: "\\input{" + nome + "}", s, flags=re.M)
    if nuovo != s:
        open(f, "w", encoding="utf-8", newline="").write(nuovo)
        print(f"{f}: attivato {nome}")
    else:
        print(f"{f}: {nome} già attivo o non trovato")
