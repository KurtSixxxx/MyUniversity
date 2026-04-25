//Spiegazione di get() e set()

// get() ti permette di copiare un pezzo di immagine.
// Possiamo fare due cose.
//    1. Prendere un pixel singolo
color c = immagine.get(x, y);

//    2. Prendere un rettangolo (x, y, larghezza, altezza)
PImage pezzo = immagine.get(50,50, 100,100);
// questo crea una NUOVA immagine di 100x100 pixel

// set() ti permette di incollare un pezzo di immagine in una posizione.
// Possiamo fare due cose.
//    1. Incollare un pixel singolo
immagine.set(x, y, color(255,0,0));

//    2. Incollare un'intera PImage
immagine.set(100, 100, altraImmagine);
