# Come pubblicare su MyUniversity

Repository: https://github.com/KurtSixxxx/MyUniversity (licenza CC BY-NC-SA 4.0, PDF in Git LFS).

| Cosa | Dove va nel repository |
|---|---|
| tutto il contenuto di questa cartella (tranne `_radice_repo/` e `rilascio/`) | `Anno_01/Semestre_02/Programmazione 2/Dispensa e Allenatore/` |
| `_radice_repo/.github/workflows/telefono-prog2.yml` | `.github/workflows/telefono-prog2.yml` (radice del repository) |
| `rilascio/Allenatore Prog2.exe` | **Releases** del repository (non nel codice: è un binario da 13 MB) |

## Una volta sola

1. **Settings → Pages → Build and deployment → Source: GitHub Actions.**
   Al primo push il workflow pubblica `docs/` su https://kurtsixxxx.github.io/MyUniversity/ (la versione per telefono).
2. **Releases → Draft a new release**: tag `prog2-v3.0`, titolo «Allenatore Prog2 3.0», allega `rilascio/Allenatore Prog2.exe`.
3. Nel `README.md` principale del repository, sotto Programmazione 2, un link a `Dispensa e Allenatore/`.

## Aggiornare

Dalla cartella di sviluppo `Allenatore` (quella con `.ambiente`):

```
.ambiente\Scripts\python prepara_pubblicazione.py --exe
```

poi copia di nuovo la cartella nel repository, commit e push (il telefono si aggiorna da solo tramite il workflow) e, se è cambiato l'exe, una nuova Release.
I link (playlist, telefono, progetto) sono in `Allenatore/web/config.js`.
