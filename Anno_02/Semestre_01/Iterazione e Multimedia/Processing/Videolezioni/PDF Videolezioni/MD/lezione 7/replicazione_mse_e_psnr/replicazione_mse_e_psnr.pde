PImage Im, Ic, Ir;
/*  Abbiamo 3 immagini:
  - Im (Originale): E' l'immagine di partenza (che viene convertita poi in scala di grigi con filter(GRAY))
  - Ic (Processing): E' l'immagine che viene usata per testare il ridimensionamento integrato di Processing (che di default usa il l'interpolazione bilinerare, più sfocata)
  - Ir (Replication): E' l'immagine che usiamo per testare la funzione scritta da noi. Con il metodo "Nearest Neighbor", più "pixelato".

  La funzione vuole fare zooming-in di una foto in 256, e renderla 512; quindi deve "Inventare" i pixel mancanti.
*/
PImage replication2x(PImage I) {
  PImage R = createImage(2 * I.width, 2 * I.height, RGB);  // Crea una nuova immagine con dimenisioni doppie
  I.loadPixels(); // Carica i pixel
  for (int x = 0; x < I.width; x++) {  // Facciamo un doppio for per scansionare ogni singolo pixel dell'immagine 256x256
    for (int y = 0; y < I.height; y++) {
      color c = I.get(x, y);
      // Copia il pixel in un blocco 2x2
      // Dato che adesso ogni pixel deve occupare lo spazio di quattro pixel, lo "spalma" su un quadratino 2x2 nella nuva immagine
      R.set(2*x,     2*y,     c); // In alto a sinistra
      R.set(2*x + 1, 2*y,     c); // In alto a destra
      R.set(2*x,     2*y + 1, c); // In basso a sinistra
      R.set(2*x + 1, 2*y + 1, c); // I basso a destra (nella matrice 2x2 ovviamente)
    }
  }
  return R;
}

float MSE (PImage I1, PImage I2){
    float res = 0;
    I1.loadPixels();
    I2.loadPixels();
    
    for(int i = 0; i < I1.pixels.length; i++){ //Prendiamo la matrice linearizzata
       res += pow(red(I1.pixels[i]) - red(I2.pixels[i]), 2); //Eleviamo al quadrato la differenza di pixel. Scegliamo il canale rosso ma potremmo sceglierne anche altri
    }
    res = res/I1.pixels.length; //Questo corrisponde a 1/MN
    return res;
}

float PSNR (PImage I1, PImage I2){
  float res = 0;
  float mse = MSE(I1, I2);
  
  res = 10 * log(255*255/mse)/log(10);
  return res;
} 

void setup() {
  size(1536, 512);
  Im = loadImage("lena.png"); // Carichiamo lena
  Im.filter(GRAY); // Applichiamo il filtro di grigio
  
  // Processing (Bilineare di default)
  Ic = Im.copy();
  Ic.resize(256, 256);
  Ic.resize(512, 512);
  
  // Replication
  Ir = Im.copy();
  Ir.resize(256, 256);
  Ir = replication2x(Ir); // Chiami la funzione
  
  image(Im, 0, 0);
  image(Ic, 512, 0);
  image(Ir, 1024, 0);
  
  float mseO = MSE(Im,Im);
  float mseP = MSE(Im,Ic);
  float mseR = MSE(Im,Ir);
  float psnrO = PSNR(Im, Im);
  float psnrP = PSNR(Im, Ic);
  float psnrR = PSNR(Im, Ir);
  
  println("MSE con se stessa: "+mseO);
  println("PSNR con se stessa: "+psnrO);
  
  println("MSE processing: "+mseP);
  println("PSNR processing: "+psnrP);
  
  println("MSE replication: "+mseR);
  println("PNSR replication: "+psnrR);

}
