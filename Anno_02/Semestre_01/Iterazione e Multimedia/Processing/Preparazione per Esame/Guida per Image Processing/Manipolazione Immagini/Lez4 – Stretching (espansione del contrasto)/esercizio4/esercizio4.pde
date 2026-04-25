PImage lena, lenaStretching; //Carico le due immagini: l'originale e la risultante

PImage stretching(PImage originale) {
  PImage R = originale.copy();
  R.loadPixels();

  // Inizializza min e max per ogni canale
  float minR = 255, maxR = 0;
  float minG = 255, maxG = 0;
  float minB = 255, maxB = 0;

  // 1. Trova i valori minimi e massimi per ogni canale
  for (int i = 0; i < R.pixels.length; i++) {
    float r = red(R.pixels[i]);
    float g = green(R.pixels[i]);
    float b = blue(R.pixels[i]);

    //Troviamo il minimo e massimo di rosso
    if (r < minR) minR = r;
    if (r > maxR) maxR = r;

    //Troviamo il minimo e massimo di verde
    if (g < minG) minG = g;
    if (g > maxG) maxG = g;

    //Troviamo il minimo e massimo di blue
    if (b < minB) minB = b;
    if (b > maxB) maxB = b;
  }

  // 2. Applica lo stretching a ogni canale
  for (int i = 0; i < R.pixels.length; i++) {
    float r = red(R.pixels[i]);
    float g = green(R.pixels[i]);
    float b = blue(R.pixels[i]);

    r = 255 * (r - minR) / (maxR - minR);
    g = 255 * (g - minG) / (maxG - minG);
    b = 255 * (b - minB) / (maxB - minB);

    R.pixels[i] = color(r, g, b);
  }

  R.updatePixels();
  return R;
}

/* Altra implementazione (versione semplificata ma meno bella vista:

  PImage stretching(PImage originale) { //Creiamo la funzione 'stretching' che prende comme parametro una immagine
  PImage R = originale.copy(); //Facciamo la copia
  R.loadPixels();  //Carichiamo i pixels in memoria
  R.resize(256, 256);  //Ridimensioniamo l'immagine

  //Creiamo tutte le variabili necessarie: componenti colore (r, g, b), e minimo e massimo
  float r, g, b;
  float min, max;

  //Inizializziamo al momento entrambe a zero
  min = 255;
  max = 0;

  //Cerchiamo i valori di minimo e massimo
  for (int i = 0; i < R.pixels.length; i++) {
    if (brightness(R.pixels[i]) < min) min = brightness(R.pixels[i]);
    if (brightness(R.pixels[i]) > max) max = brightness(R.pixels[i]);
  }
  
  //Una volta ottenuti i valori di minimo e massimo, facciamo i calcoli per ogni componente colore
  for (int i = 0; i < R.pixels.length; i++) {
    r = 255 * ((red(R.pixels[i])) - min) / (max - min);
    g = 255 * ((green(R.pixels[i])) - min) / (max - min);
    b = 255 * ((blue(R.pixels[i])) - min) / (max - min);

    R.pixels[i] = color(r, g, b); //Aggiorniamo con il nuovo colore del pixel
  }

  R.updatePixels();  //Ricarichiamo i pixels aggiornati
  return R;  //Restituiamo l'immagine con il contrast stretching effettuato
}
*/

void setup() {
  size(768, 256);  //Selezioniamo la dimensione dello sketch
  reset();  //Chiamiamo reset una volta nel setup, che dà il via al primp stretching
}

void draw() {
  background(255);
  //Posizioniamo le due immagini sulla canvas
  image(lena, 0, 0);
  image(lenaStretching, 256, 0);
}

void reset() { //Reset ha il solo scopo di chiamare lo stretching su Lena
  lena = loadImage("lena.png"); //Carichiamo l'immagine di lena
  lena.resize(256, 256);  //La ridimensioniamo
  lenaStretching = stretching(lena);
}

void keyPressed() { //Con il tasto R si resetta tutto, e quindi avviene di nuovo il reset sull'immagine originalee
  if (key == 'r' || key == 'R') {
    reset();
  }
}
