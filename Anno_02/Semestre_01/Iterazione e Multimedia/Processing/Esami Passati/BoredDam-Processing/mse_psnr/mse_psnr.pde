/*MSE = Errore Quadratico Medio
Misura quanto due immagini sono diverse pixel per pixel
Restituisce un valore numerico (più è basso, più le immagini sono simili)*/

float mse(PImage I1, PImage I2) { //Creiamo una funzione MSE che restituisce un float
  //Carica gli array di pixel di entrambe le immagini in memoria
  I1.loadPixels();
  I2.loadPixels();
  
/*Prende il numero di pixel più piccolo tra le due immagini
Se le immagini hanno dimensioni diverse, confronta solo i pixel comuni*/  
  int n = min(I1.pixels.length, I2.pixels.length); 

/*Per ogni pixel, calcola la luminosità (valore tra 0 e 255)
Calcola la differenza al quadrato (v1 - v2)²
Accumula il risultato in res*/ 
  float res = 0;
  for(int i = 0; i < n; i++) {
    float v1 = brightness(I1.pixels[i]);
    float v2 = brightness(I2.pixels[i]);
    res += sq(v1 - v2);
  }
  
/*Divide la somma totale per il numero di pixel
Restituisce l'errore quadratico medio*/  
  return res / n;
}

/*PSNR = Rapporto Segnale-Rumore di Picco
Misura la qualità in decibel (dB)
Più è alto, migliore è la qualità (tipicamente > 30 dB è buono)*/
float psnr(PImage I1, PImage I2) {
  
/*Calcola MSE
Se MSE = 0 (immagini identiche), PSNR è infinito*/
  float m = mse(I1, I2);
  if(m == 0) 
    return Float.POSITIVE_INFINITY;

/*Formula PSNR: 10 * log10(MAX² / MSE)
MAX = 255 (valore massimo di luminosità)
log() in Processing è logaritmo naturale, quindi dividiamo per log(10) per convertire in log10 */
  float maxI = 255.0;
  return 10.0 * log((maxI * maxI) / m) / log(10); 
}

PImage img1;
PImage img2;

//Carichiamo in img1 lena, e in img2 lena con un filtro di gamma
void setup() {
  img1 = loadImage("lena.png");
  img2 = loadImage("lena_gamma.png");
 
//Poiché sono a 512x512, ridimensioniamo
  img1.resize(256, 256);
  img2.resize(256, 256);

  size(512, 256);
}

void draw() {
  background(0);
  
//Posizionamento delle immagini
  image(img1, 0, 0);
  image(img2, 256, 0);
  
//Chiamate a funzione
  float m = mse(img1, img2);
  float p = psnr(img1, img2);
  
//Scriviamo a schermo i risultati di MSE e PSNR
  fill(255);
//nf(m, 1, 2) formatta il numero con almeno 1 cifra intera e 2 decimali
  text("MSE  = " + nf(m, 1, 2), 10, height - 25);
  text("PSNR = " + nf(p, 1, 2) + " dB", 10, height - 8);
}
