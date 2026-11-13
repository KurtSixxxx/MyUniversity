#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Collaudo del compilatore: compila ed esegue le soluzioni a un solo file della dispensa
con il g++ trovato dall'app (MinGW su Windows, Apple clang sul Mac) e confronta l'output
con quello della dispensa.

Uso:  python collaudo.py [cartella della dispensa]
Usato dal workflow mac-prog2.yml. I file di lavoro vanno in una cartella temporanea
(ALLENATORE_DATI), così i dati veri dello studente non vengono toccati.
"""
import os
import sys
import tempfile

os.environ.setdefault('ALLENATORE_DATI', tempfile.mkdtemp(prefix='collaudo-prog2-'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import motore as M  # noqa: E402


def main():
    cat = M.carica_catalogo(sys.argv[1] if len(sys.argv) > 1 else '')
    gpp = M.trova_gpp()
    print('Compilatore:', gpp)
    if not gpp:
        sys.exit('Compilatore non trovato')
    non_compilati, diversi, ok, saltati = [], [], 0, 0
    for e in cat['esercizi']:
        s = e['soluzione']
        if len(s['files']) != 1 or not s['files'][0]['contenuto']:
            saltati += 1
            continue
        r = M.esegui_codice(gpp, 'collaudo-' + e['id'], s['files'][0]['contenuto'], s.get('input') or '', 20)
        if not r['compilato']:
            non_compilati.append(e['id'])
            print('\n### NON COMPILA:', e['id'], '\n' + r['messaggi'][:1500])
            continue
        atteso = s.get('output')
        if atteso is None or M.normalizza_output(r['stdout']) == M.normalizza_output(atteso):
            ok += 1
        else:
            diversi.append(e['id'])
            print('\n### OUTPUT DIVERSO:', e['id'], '(uscita %s %s)' % (r.get('uscita'), r.get('nota') or ''))
    print('\n== Riepilogo: %d giusti, %d con output diverso (spesso numeri casuali con rand), %d non compilano, %d saltati (più file)'
          % (ok, len(diversi), len(non_compilati), saltati))
    print('Output diversi:', ', '.join(diversi) or 'nessuno')
    print('Non compilano:', ', '.join(non_compilati) or 'nessuno')
    return 1 if non_compilati else 0


if __name__ == '__main__':
    sys.exit(main())
