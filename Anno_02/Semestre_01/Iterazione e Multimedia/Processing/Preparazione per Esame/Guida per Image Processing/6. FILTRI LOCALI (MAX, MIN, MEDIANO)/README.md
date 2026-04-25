```markdown
# Filtri Locali nelle Immagini

## PARTE 1: COSA SONO I FILTRI LOCALI?

Finora abbiamo fatto **filtri puntuali**: ogni pixel veniva modificato guardando SOLO se stesso.

Esempio puntuale (negativo):
```java
nuovo_valore = 255 - vecchio_valore
```

**Filtro locale**: ogni pixel viene modificato guardando anche i suoi **vicini**.

```
Esempio: pixel a (x,y) guarda i pixel intorno a lui:
    (x-1, y-1)    (x, y-1)    (x+1, y-1)
    (x-1, y)      (x, y)      (x+1, y)
    (x-1, y+1)    (x, y+1)    (x+1, y+1)
```

Questo gruppo di pixel si chiama **intorno** o **finestra**.

---

## PARTE 2: VISUALIZZIAMO CON UN ESEMPIO CONCRETO

Immagina un'immagine 5x5 con questi valori di luminosità:

```
10  20  30  40  50
15  25  35  45  55
20  30  40  50  60
25  35  45  55  65
30  40  50  60  70
```

Prendiamo il pixel al centro (x=2, y=2) che ha valore **40**.

Il suo intorno 3x3 è:

```
20  30  40
30  40  50
40  50  60
```

Ora, a seconda del filtro, calcoliamo il nuovo valore per il pixel centrale:

### Filtro MASSIMO

prendo il valore più alto dell'intorno → **60**

### Filtro MINIMO

prendo il valore più basso → **20**

### Filtro MEDIANO

ordino tutti i valori e prendo quello centrale:

Valori ordinati: 20, 30, 30, 40, 40, 40, 50, 50, 60

Mediano (5° valore) → **40**