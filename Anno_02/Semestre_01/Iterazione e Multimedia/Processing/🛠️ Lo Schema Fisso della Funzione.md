Ho capito perfettamente. Per dominare l'**Esercizio 2** in ogni esame, devi avere in mente uno schema a "tre strati": la **struttura** (il contenitore PImage), la **scansione** (i cicli for) e la **manipolazione** (il calcolo del colore). 

+4



Ecco il manuale definitivo per risolvere qualsiasi variante della manipolazione immagini.

------

### 🛠️ Lo Schema Fisso della Funzione

Qualunque sia il nome della funzione (`wow`, `gray_mean`, `sBlock`), la struttura è sempre questa: 

+4



Java

```
PImage nomeFunzione(PImage I) {
  // 1. Crea lo spazio per il risultato (stessa dimensione dell'originale)
  PImage out = createImage(I.width, I.height, RGB); [cite: 39, 72, 97]
  
  // 2. Carica i pixel in memoria (fondamentale!)
  I.loadPixels();
  out.loadPixels();
  
  // 3. Scansione a matrice (x = colonne, y = righe)
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      
      // Calcola l'indice del pixel nell'array monodimensionale
      int pos = x + y * I.width; 
      
      // Prendi il colore del pixel originale
      color c = I.pixels[pos]; 
      
      // --- QUI INSERISCI LA LOGICA DI MANIPOLAZIONE ---
      // Esempio: out.pixels[pos] = color(red(c), green(c), blue(c));
    }
  }
  
  out.updatePixels(); // Applica i cambiamenti
  return out; // Restituisce l'immagine finita
}
```

------

### 🧠 Prontuario delle Logiche Ricorrenti

In base alle tracce che hai caricato, ecco come scrivere il codice dentro il ciclo `for`:

1. Inversione Canali (R, G, B) 

+1



Se la traccia chiede di "invertire rosso e blu":

Java

```
float r = red(c);
float b = blue(c);
out.pixels[pos] = color(b, green(c), r); // Scambio r con b
```

2. Media dei Grigi (Grayscale) 

+1



Java

```
float media = (red(c) + green(c) + blue(c)) / 3;
out.pixels[pos] = color(media, media, media);
```

3. Divisione in Aree (Metà, Terzi, Percentuali) 

+1



Se devi fare una cosa a sinistra e un'altra a destra:

Java

```
if (x < I.width/2) {
  // Logica per metà sinistra
} else {
  // Logica per metà destra
}
```

Per i terzi: `if (x < I.width/3)` (sinistra), `else if (x < I.width*2/3)` (centro), `else` (destra). 



4. Area centrata sul Mouse (il quadrato KS) 



Java

```
// Se il pixel (x,y) è dentro il quadrato di lato KS centrato nel mouse
if (x > mouseX - KS/2 && x < mouseX + KS/2 && y > mouseY - KS/2 && y < mouseY + KS/2) {
  // Applica modifica (es. gray_mean)
} else {
  out.pixels[pos] = c; // Lascia l'originale
}
```

------

### ⚠️ Errori da evitare (per non essere bocciati)

- 

  **Non dimenticare `loadPixels()` e `updatePixels()`**: senza questi, l'immagine risulterà vuota o darà errore. 

  +2

  

- 

  **Indice fuori dai bordi**: se lavori con lo scaling o lo shift, assicurati che `pos` non sia mai `< 0` o `> pixels.length`. 

  

  

- 

  **Copia dell'immagine**: lavora sempre su una nuova `PImage out`, non modificare direttamente `I` se devi fare confronti tra pixel originali e nuovi. 

  +1

  



**Vuoi che proviamo a risolvere insieme il punto (c) della traccia "wow" (7 Febbraio)?** È quella più tosta perché mischia scambi di posizione e inversione di colori. 