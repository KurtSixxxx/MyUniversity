PImage filtroLocale(PImage originale){
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = originale.width; 
  int h = originale.height;
  
  for(int y = 0; y < h; y++){
    for(int x = 0; x < w; w++){
      int i = x + y * w;
      //Qui si elabora il pixel...
    }
  }
  
  risultato.updatePixels();
  return risultato;
}

//Definiamo la misura dell'intorno.
//Se abbiamo un intorno 3x3 allora N = 3. Il raggio è N/2 = 1.
//Significa che per ogni pixel (x,y), dobbiamo guardare i pixel con:
//    -- x da (x-1) a (x+1)
//    -- y da (y-1) a (y+1)

//Raccogliamo i piexel dall'intorno
int N = 3;
int raggio = N/2; // = 1

// Per il pixel (x,y), raccolgo tutti i vicini
for (int dy = -raggio; dy <= raggio; dy++) {
  for (int dx = -raggio; dx <= raggio; dx++) {
    int nx = x + dx;  // coordinata x del vicino
    int ny = y + dy;  // coordinata y del vicino
    
    // Attenzione: nx e ny potrebbero essere FUORI dall'immagine!
    // (questo è il problema dei bordi - lo gestiamo dopo)
  }
}
