// Esempio base - Copiare un pezzo

PImage originale; //Abbiamo la nostra immagine orginale
PImage pezzo; //Abbiamo il pezso che vogliamo copiare e rendere una immagine a sé stante

void setup() {
  size(512, 256);
  
  originale = loadImage("lena.png");
  originale.resize(256, 256);
  
  // Prendo il quadrante in alto a sinistra (128x128)
  pezzo = originale.get(0, 0, 128, 128);
  
  // Mostro originale e il pezzo ingrandito? No, così com'è
  image(originale, 0, 0);
  image(pezzo, 256, 0);  // il pezzo è 128x128, lo vedi piccolo
}
