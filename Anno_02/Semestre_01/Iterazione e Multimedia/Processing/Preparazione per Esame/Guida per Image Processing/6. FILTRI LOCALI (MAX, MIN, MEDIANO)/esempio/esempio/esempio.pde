PImage Im;

void setup() {
  size(1024, 256); // Finestra per ospitare 4 immagini da 256px
  
  Im = loadImage("lena.png"); // Sostituisci con una tua immagine
  if (Im == null) {
    Im = createImage(256, 256, RGB); // Fallback se manca il file
  }
  Im.resize(256, 256);
  Im.filter(GRAY);
  
  PImage rumorosa = aggiungiRumore(Im);
  
  // Esecuzione filtri
  PImage massimo = filtroMassimo(rumorosa, 3);
  PImage minimo = filtroMinimo(rumorosa, 3);
  PImage mediano = filtroMediano(rumorosa, 3);
  
  // Visualizzazione
  image(rumorosa, 0, 0);   // Originale con rumore
  image(massimo, 256, 0);  // Risultato Max
  image(minimo, 512, 0);   // Risultato Min
  image(mediano, 768, 0);  // Risultato Mediano
}

PImage aggiungiRumore(PImage I) {
  PImage out = I.copy();
  out.loadPixels();
  for (int i = 0; i < out.pixels.length; i++) {
    if (random(100) < 5) {  
      out.pixels[i] = color(random(255));  
    }
  }
  out.updatePixels();
  return out;
}

// --- FILTRI SPAZIALI ---

PImage filtroMassimo(PImage originale, int N) {
  PImage risultato = originale.copy();
  originale.loadPixels(); // Carica pixel sorgente 
  risultato.loadPixels(); // Carica pixel destinazione
  
  int raggio = N/2;
  
  for (int y = raggio; y < originale.height - raggio; y++) {
    for (int x = raggio; x < originale.width - raggio; x++) {
      
      PImage intorno = originale.get(x - raggio, y - raggio, N, N);
      intorno.loadPixels();
      
      float maxVal = 0;
      for (int i = 0; i < intorno.pixels.length; i++) {
        float val = brightness(intorno.pixels[i]); // Calcola luminosità
        if (val > maxVal) maxVal = val;
      }
      
      int pos = x + y * originale.width; // Formula corretta indice 
      risultato.pixels[pos] = color(maxVal);
    }
  }
  risultato.updatePixels();
  return risultato;
}

PImage filtroMinimo(PImage originale, int N) { // Corretto nome funzione
  PImage risultato = originale.copy();
  originale.loadPixels();
  risultato.loadPixels();
  
  int raggio = N/2;
  
  for (int y = raggio; y < originale.height - raggio; y++) {
    for (int x = raggio; x < originale.width - raggio; x++) {
      
      PImage intorno = originale.get(x - raggio, y - raggio, N, N);
      intorno.loadPixels();
      
      float minVal = 255;
      for (int i = 0; i < intorno.pixels.length; i++) {
        float val = brightness(intorno.pixels[i]);
        if (val < minVal) minVal = val;
      }
      
      int pos = x + y * originale.width; // Aggiunta dichiarazione pos
      risultato.pixels[pos] = color(minVal);
    } // Chiusura for x corretta
  } // Chiusura for y corretta
  
  risultato.updatePixels();
  return risultato;
}

PImage filtroMediano(PImage originale, int N) {
  PImage risultato = originale.copy();
  originale.loadPixels();
  risultato.loadPixels();
  
  int raggio = N/2;
  
  for (int y = raggio; y < originale.height - raggio; y++) {
    for (int x = raggio; x < originale.width - raggio; x++) {
      
      PImage intorno = originale.get(x - raggio, y - raggio, N, N);
      intorno.loadPixels();
      
      float[] valori = new float[intorno.pixels.length];
      for (int i = 0; i < intorno.pixels.length; i++) {
        valori[i] = brightness(intorno.pixels[i]);
      }
      
      valori = sort(valori); // Ordina l'array per trovare il centro
      float mediano = valori[valori.length/2];
      
      int pos = x + y * originale.width;
      risultato.pixels[pos] = color(mediano);
    }
  }
  risultato.updatePixels();
  return risultato;
}
