//PImage O = Immagine originale
//PImage R = Immagine risultante

PImage lena, lenaNegativa;

PImage negativo(PImage O){ // Prende come parametro l'immagine a cui appicare il filtro.
  PImage R = O.copy(); // Creo una copia dell'originale per non modificarlo direttamente.
  
  float r,g,b; // Variabili per le nuove componenti di colore.
  R.loadPixels();  // Carichiamo i pixel dell'immagine R in memoria.

// L'array 'pixels' è linearizzato: contiene tutti i valori di colore in una lunga lista.
  for(int i = 0; i < R.pixels.length; i++){
    r = 255 - red(R.pixels[i]);
    g = 255 - green(R.pixels[i]);
    b = 255 - blue(R.pixels[i]);
  
  R.pixels[i] = color(r,g,b); // Ricostruisco il nuovo colore e lo assegno alla stessa posizione nell'array
  }
  
  R.updatePixels(); // Dopo aver modificato 'pixels', devo chiamare updatePixels() per rendere effettive le modifiche.
  return R; // Restituisce l'immagine.
}

void setup(){
  size(1024,512);
  lena = loadImage("lena.png");
  lenaNegativa = negativo(lena);
  image(lena, 0, 0);
  image(lenaNegativa, 512, 0);
}
