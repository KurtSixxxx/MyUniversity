PImage Im, Ic, Ir;
/*  Abbiamo 3 immagini:
  - Im (Originale): E' l'immagine di partenza (che viene convertita poi in scala di grigi con filter(GRAY))
  - Ic (Processing): E' l'immagine che viene usata per testare il ridimensionamento integrato di Processingf (che di default usa il l'interpolazione bilinerare, più sfocata)
  - Ir (Replication): E' l'immagine che usiamo per testare la funzione scritta da noi. Con il metodo "Nearest Neighbor", più "pixelato".

  La funzione vuole fare zooming di una foto in 256, e renderla 512; quindi deve "Inventare" i pixel mancanti.
*/
PImage replication2x(PImage I) {
  PImage R = createImage(2 * I.width, 2 * I.height, RGB);  // Crea ua nuova immagine con dimenisioni doppie
  I.loadPixels(); // Carica i pixel
  for (int x = 0; x < I.width; x++) {  // Facciamo un doppio pfor per scansionare ogni singolo pixel dell'immagine 256x256
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

void setup() {
  size(1536, 512);
  Im = loadImage("lena.png"); // Carichiamo lena
  Im.filter(GRAY); // Applichiamo il filtro di grigio
  
  // Processing (Bilineare di default)
  Ic = Im.copy();
  Ic.resize(256, 256);
  Ic.resize(512, 512);
  
  // Replication (Nearest Neighbor manuale)
  Ir = Im.copy();
  Ir.resize(256, 256);
  Ir = replication2x(Ir); // Chiami la funzione
  
  image(Im, 0, 0);
  image(Ic, 512, 0);
  image(Ir, 1024, 0);
}
