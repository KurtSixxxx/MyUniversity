PImage minimo(PImage originale, int N) {
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = originale.width;
  int h = originale.height;
  int r = N/2;
  
  for(int y = 0; y < h; y++){
    for(int x = 0; x < w; x++){
      int i = x + y * w;
      
      float minimo = 255;
      
        for(int dy = -r; dy <= r; dy++){
          for(int dx = -r; dx < r; dx++){
            int nx = x + dx;
            int ny = y + dy;
            
            int posVicino = nx + ny * w;
            float valore = brightness(originale.pixels[posVicino]);
          
          if(valore < minimo) minimo = valore;
          
          }
        }
    }
  }
  risultato.updatePixels();
  return risultato;
}
