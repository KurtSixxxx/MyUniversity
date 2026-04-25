# Ripasso prerequisiti

## 1. LE FUNZIONI

Immagina una **macchinetta mangiasoldi**:

- Tu metti una moneta (input)
- La macchina ti dà una lattina (output)
- Ogni moneta → una specifica lattina

Una **funzione matematica** è esattamente così:

- È una **"macchina"** che trasforma numeri
- Tu gli dai un numero in **ingresso** (chiamato `x`)
- Lei ti restituisce un numero in **uscita** (chiamato `f(x)` o `y`)

Quando scrivo:

```
f(x) = 2x + 3
```

Significa:

- `f` = nome della macchina/funzione
- `(x)` = il numero che tu metti nella macchina
- `2x + 3` = cosa fa la macchina con il numero

**Esempio pratico:**

Se `x = 4`:

1. Prendi `x = 4`
2. La macchina fa: `2 × 4 + 3`
3. Risultato: `8 + 3 = 11`
4. Quindi `f(4) = 11`

Se ho una funzione: `g(t) = t² - 1`

Cosa significa `g(3)`? → 3² - 1 = 9 - 1 = 8

## 2. LE ONDE

### **Immagina di essere in spiaggia:**

1. **L'acqua sale** (arriva verso la spiaggia)
2. **Raggiunge il punto più alto** (cresta dell'onda)
3. **L'acqua scende** (torna indietro)
4. **Raggiunge il punto più basso** (ventre dell'onda)
5. **Poi ricomincia da capo**

Questo movimento **SU e GIÙ** che **SI RIPETE** è un'**onda**.

### **ALTRI ESEMPI CONCRETI DI ONDE NELLA VITA:**

1. **Un'altalena**: va avanti e indietro, avanti e indietro...
2. **Una molla** che oscilla: su e giù, su e giù...
3. **Il suono di una chitarra**: l'aria vibra in modo ripetitivo
4. **La luce**: anche se non la vediamo oscillare

### **A. AMPIEZZA**

<aside>
💡

**AMPIEZZA = QUANTO E’ ALTA UN’ONDA**

</aside>

- **A parole**: quanto è "alta" l'onda
- **Esempio concreto**:
    - Un'**onda alta 2 metri** in mare → ampiezza grande
    - Un'**onda alta 10 cm** in una pozzanghera → ampiezza piccola
    - Nell'altalena: quanto in alto va l'altalena

### **B. PERIODO**

<aside>
💡

**PERIODO = QUANTO IMPIEGA A FARE IL SUO CICLO COMPLETO**

</aside>

- **A parole**: quanto tempo ci mette a fare un ciclo COMPLETO
- **Esempio concreto**:
    - Se un'altalena impiega **3 secondi** per: andare avanti → tornare indietro → tornare al punto di partenza
    - Allora il suo **periodo è 3 secondi**

### **C. FREQUENZA**

<aside>
💡

**FREQUENZA = QUANTE VOLTE SI RIPETE IL CICLO IN UN DATO TEMPO**

</aside>

- **A parole**: quante volte si ripete in un secondo
- **Esempio concreto**:
    - Se il tuo cuore batte **60 volte al minuto**
    - Allora batte **1 volta al secondo** (frequenza = 1 battito/secondo)
    - Per le onde: se un'onda si ripete 2 volte al secondo → frequenza = 2

## 3. SENO E COSENO

<aside>
💡

**SENO = FUNZIONE CHE DESCRIVE IL MOVIMENTO SU E GIU DI UN’ONDA**

</aside>

**Immagina una ruota di bicicletta con un raggio rosso:**

1. La ruota gira in senso antiorario
2. Metti un punto ROSSO sul bordo della ruota
3. Ora guarda SOLO l'altezza (su/giù) del punto rosso
4. La ruota gira → il punto va su e giù

**Questo movimento SU e GIÙ del punto rosso è proprio la funzione SENO!**

## **2. VISUALIZZIAMOLO IN MODO ANCORA PIÙ CONCRETO:**

Prendi un **compasso**:

1. Apri il compasso di 5 cm (raggio)
2. Disegna un cerchio
3. Ora immagina che il compasso giri
4. La **puntina che scrive** va su e giù mentre gira

**L'altezza della puntina rispetto al centro** = **VALORE DEL SENO**

## **3. COSA MISURA REALMENTE IL SENO?**

Quando hai un cerchio di raggio 1:

- **Seno dell'angolo** = **quanto sei in ALTO** rispetto al centro
- **Coseno dell'angolo** = **quanto sei a DESTRA** rispetto al centro

**Esempio pratico:**

- Se stai in cima alla ruota panoramica (angolo = 90°):
    - Sei tutto in ALTO → **seno = 1** (massimo)
    - Non sei né a destra né a sinistra → **coseno = 0**

## **4. PERCHÉ CI SERVE PER LE ONDE?**

Perché il movimento **SU e GIÙ** della ruota che gira...

...è **IDENTICO** al movimento **SU e GIÙ** di:

- un'onda del mare
- un'altalena
- una corda di chitarra che vibra

Il **seno** è la **matematica delle cose che oscillano**!

## 4. GRADI E RADIANTI

### **I GRADI li conosci già:**

- Cerchio completo = 360°
- Mezzo giro = 180°
- Quarto di giro = 90°

**Problema con i gradi:** sono un'unità "inventata" (i Babilonesi usavano base 60)

### **I RADIANTI sono più "naturali":**

**Immagina di srotolare una circonferenza:**

1. Prendi un cerchio
2. Taglia il bordo
3. Stendilo dritto
4. **La lunghezza del bordo srotolato** si chiama **circonferenza**

Per un cerchio di raggio 1:

- Circonferenza = 2π × raggio = 2π × 1 = **2π**

## **2. COSA SONO I RADIANTI? CONCRETAMENTE**

**Un radiante** = l'angolo in cui **l'arco di circonferenza è LUNGO QUANTO IL RAGGIO**

**Esempio visivo:**

- Prendi una fetta di torta
- Se il bordo curvo è **lungo quanto il raggio**...
- ...allora l'angolo è **1 radiante**

**Quanto è grande 1 radiante in gradi?**

- Cerchio completo = 360° = 2π radianti
- Quindi: 1 radiante ≈ 360°/(2×3.14) ≈ 360°/6.28 ≈ **57.3°**

## **3. PERCHÉ I MATEMATICI USANO I RADIANTI?**

Perché con i radianti le formule diventano più SEMPLICI:

Con gradi:

text

```
sin(90°) = 1
(sin x)' = (π/180) cos x  ← formula complicata!
```

Con radianti:

text

```
sin(π/2) = 1
(sin x)' = cos x  ← formula bellissima e semplice!
```

## **4. CONVERSIONE FACILE:**

**Da gradi a radianti:**

text

```
radianti = gradi × π / 180
```

**Esempio pratico:**

- 90° → 90 × π/180 = π/2 radianti
- 180° → 180 × π/180 = π radianti
- 360° → 360 × π/180 = 2π radianti

Immagina una **torta perfettamente rotonda**:

**Situazione A - Con i GRADI:**

- Tagli la torta in 360 fette uguali
- Ogni fetta ha angolo = **1°**
- Ma... perché proprio 360? È un numero "storico" (i Babilonesi contavano in base 60)

**Situazione B - Con i RADIANTI:**

- Non conti le fette, ma misuri il **bordo della torta**
- Usi il **raggio della torta** come unità di misura

## **2. ESPERIMENTO MENTALE CONCRETO**

**Materiale:**

1. Una moneta da 1 euro (raggio ≈ 1.2 cm)
2. Un filo
3. Forbici

**Procedimento:**

1. Misura il **raggio** della moneta: ≈ 1.2 cm
2. Prendi il filo e tagliane un pezzo **lungo come il raggio** (1.2 cm)
3. Metti il filo sul bordo della moneta
4. **L'angolo che copre quel filo** = **1 RADIANTE**

**Cosa succede?**

- Il filo (lungo come il raggio) si piega lungo il bordo
- Copre un certo angolo
- Quell'angolo è circa **57.3°**

## **3. PERCHÉ PROPRIO IL RAGGIO?**

Perché è **NATURALE**:

Se prendo una circonferenza e la **srotolo**:

- Lunghezza totale = **2π × raggio**
- Se misuro gli angoli in radianti:
    - Angolo pieno = lunghezza totale / raggio = **2π**
    - Mezzo giro = π
    - Quarto di giro = π/2

**Vantaggio:** Le formule non hanno "fattori strani" come π/180!

## **4. VISUALIZZIAMO CON UN CERCHIO DI RAGGIO 1**

Prendiamo un cerchio di **raggio = 1 unità** (un "cerchio unitario"):

**Con i GRADI:**

- 360 fette
- Ogni fetta: angolo 1°, arco piccolo

**Con i RADIANTI:**

- Circonferenza totale = 2π × 1 = **2π unità**
- Se prendo un arco lungo **1 unità** (come il raggio!)...
- ...l'angolo corrispondente = **1 radiante**

## **5. TABELLA DI CONFRONTO CONCRETA**

| **Angolo** | **Gradi** | **Radianti** | **Cosa vedi nel cerchio** |
| --- | --- | --- | --- |
| Giro completo | 360° | 2π ≈ 6.28 | Tutt'intorno |
| Mezzo giro | 180° | π ≈ 3.14 | Da sinistra a destra |
| Quarto di giro | 90° | π/2 ≈ 1.57 | Da centro a cima |
| Un ottavo | 45° | π/4 ≈ 0.785 | Metà della salita |

## **6. ESERCIZIO PRATICO GUIDATO**

**Problema:** Ho un cerchio di raggio 5 cm.

Quanto è lungo l'arco che corrisponde a π/3 radianti?

**Ragioniamo insieme:**

1. Ricorda: **1 radiante** = arco lungo come il raggio
2. Qui raggio = 5 cm → 1 radiante = arco di 5 cm
3. L'angolo è π/3 radianti ≈ 1.047 radianti
4. Arco = angolo × raggio = (π/3) × 5 cm ≈ 5.24 cm

**Formula magica:** `Arco = Angolo(in radianti) × Raggio`

Con i gradi sarebbe: `Arco = (gradi × π/180) × Raggio` → più complicato!

1. **Seno/Coseno** → descrivono cose che oscillano (altalene, onde)
2. **Radianti** → modo "naturale" per misurare angoli (usa il raggio)
3. **Onda sinusoidale** = A × sin(2πft + φ) → descrive un'oscillazione pura
4. **Fourier** → dice che le cose complesse sono somme di cose semplici

```
Cose che oscillano → Seno/Coseno → Onde pure → Somma di onde → Fourier
       ↑                    ↑              ↑            ↑           ↑
   altalene           radianti        frequenza    musica      applicazioni
   suono              formule         ampiezza     immagini    reali
   luce               semplici        fase         telecom
```

## FOURIER

## **1. INTUIZIONE PRIMA DELLE FORMULE**

**Immagina di essere un DJ o un tecnico del suono:**

- Hai una **canzone complessa** (voce, chitarra, batteria, basso)
- Ogni strumento fa **onde diverse**
- Il suono finale è un **MISCUGLIO** di tutte queste onde

**Domanda:** Come fai a separare la voce dalla chitarra?

**Risposta:** Con l'analisi di Fourier!

## **2. L'IDEA GENIALE DI FOURIER (1807)**

Joseph Fourier scoprì che:

> QUALSIASI suono/seguale periodico, per quanto complesso,
> 
> 
> può essere scomposto in una **SOMMA di onde sinusoidali SEMPLICI**
> 

**Esempio concreto - Un accordo di pianoforte:**

- Premi DO, MI, SOL insieme
- Ottieni un suono "ricco"
- Fourier dice: "Questo suono = Onda DO pura + Onda MI pura + Onda SOL pura"

## **3. VISUALIZZIAMOLO CON LE ONDE DEL MARE**

**Scenario:**

1. **Onda A**: alta 1m, periodo 5 secondi
2. **Onda B**: alta 0.5m, periodo 3 secondi
3. **Onda C**: alta 0.3m, periodo 8 secondi

**Cosa vedi in mare?**

- Non vedi le 3 onde separate!
- Vedi un'onda **COMPLESSA** che sembra irregolare
- Ma in realtà è la **SOMMA** delle 3 onde semplici!

## **4. LA SERIE DI FOURIER IN POCHE PAROLE**

> Data un'onda complessa periodica,
> 
> 
> la Serie di Fourier ci dice:
> 
> 1. **Quali** onde sinusoidali ci sono dentro
> 2. Con che **ampiezza** (quanto sono forti)
> 3. Con che **fase** (quando iniziano)

**Formula concettuale (senza panico!):**

text

```
Onda complessa = A₁·sin(ω₁t+φ₁) + A₂·sin(ω₂t+φ₂) + A₃·sin(ω₃t+φ₃) + ...
```

Dove ω₁, ω₂, ω₃ sono frequenze multiple della fondamentale.

## **5. APPLICAZIONI REALI - DOVE SERVE?**

1. **🎵 AUDIO DIGITALE** (MP3, Spotify)
    - Comprimi la musica trovando le onde "principali"
    - Elimina quelle che l'orecchio non sente
2. **📡 COMUNICAZIONI** (Wi-Fi, telefoni)
    - Ogni canale ha una sua frequenza
    - Fourier separa i canali
3. **🩺 MEDICINA** (ECG, risonanza magnetica)
    - L'ECG è un'onda complessa
    - Fourier separa i battiti dai disturbi
4. **🖼️ IMMAGINI DIGITALI** (JPEG, Instagram)
    - Un'immagine = onde di colore in 2D
    - JPEG comprime con Fourier 2D