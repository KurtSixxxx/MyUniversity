PImage massimo(PImage originale, int N) {
  PImage risultato = originale.copy();
  risulato.updatePixels();
  
  int w = originale.width;
  int h = originale.height;
  
  int r = N/2;
  
  for(int y = r; y < h - r; y++){
    for(int x = r; x < w - r; w++){
      
      float massimo = 0;
      
//Questi sono i due for per espolare l'intorno -> Stiamo visitando tutti i punti che sono a distanza dx e dy dal pixel centrale.                  
/*
Se raggio = 1 (N=3), dy e dx vanno da -1 a 1:

dy = -1:  dx = -1, 0, 1   → visito (-1,-1), (0,-1), (1,-1)
dy =  0:  dx = -1, 0, 1   → visito (-1,0),  (0,0),  (1,0)
dy =  1:  dx = -1, 0, 1   → visito (-1,1),  (0,1),  (1,1)
In totale 9 pixel visitati!                                                          */      
      for(int dy = -r; dy <= r; dy++){
        for(int dx = -r; dx <= r; dx++){
/*CALCOLARE LE COORDINATE DEL VICINO
Se siamo al pixel centrale (x=10, y=10) e stiamo visitando (dx=-1, dy=-1):
nx = 10 + (-1) = 9
ny = 10 + (-1) = 9 */
          int nx = x + dx;
          int ny = y + dy;
          
          //TROVARE LA POSIZIONE NELL'ARRAY LINEARE
          int posVicino = nx + ny * w;
          //ESTRARRE IL VALORE DEL VICINO
          float valore = brightness(orginale.pixels[posVicino]);
          //CONFRONTARE CON IL MASSIMO ATTUALE
          if(valore > massimo){
            massimo = valore;
          }
        }
      }
      // Assegno il massimo al pixel centrale
      int posCentrale = x + y * w;
      risultato.pixels[posCentrale] = color(massimo);
      
    }
  }
  // Assegno il massimo al pixel centrale
  risultato.updatePixels();
  return risultato;
}
      
  
