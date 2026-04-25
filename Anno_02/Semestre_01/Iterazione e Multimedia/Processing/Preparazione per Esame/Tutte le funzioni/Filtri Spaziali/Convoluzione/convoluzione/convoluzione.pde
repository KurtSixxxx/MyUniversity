float[][] convoluzione(PImage I, float [][] K){
// La matrice risultato R ha dimensioni: altezza x larghezza dell'immagine originale.
  float[][] R = new float[I.height][I.width];
 
  // Dimensioni del kernel (M = righe, N = colonne)
  int M = K.length; // Altezza del kernel
  int N = K[0].length; // Larghezza del kernel. Accede alla prima riga e conta le celle, avendo così il numero di colonne.
  
  PImage tmp; //Finestra di kernel corrente estratta dall'immagine
  float res; //Risultato della convoluzione per il pixel(x,y)
  
  //Scorriamo TUTTI i picel dell'immagine
  for(int x = 0; x < I.width; x++){
    for(int y = 0; y < I.height; y++){
      // Estraggo un intorno NxM centrato in (x,y).
      // x-N/2, y-M/2 è l'angolo in alto a sinistra dell'intorno.
      // Se l'intorno esce dai bordi, Processing gestisce automaticamente il problema restituendo un'immagine più piccola (solo la parte interna).
      tmp = I.get(x - N/2, y - M/2, N, M);
      //get(x, y, w, h): Restituisce una porzione dell'immagine (oggetto PImage) definita dal rettangolo con angolo superiore sinistro in x, y, larghezza w e altezza h. 
      res = 0; //Azzero il risultato del pixel corrente.
      
      //Convoluzioe: somma pesata dei pixel dell'intorno con i coefficienti del kernel.
      //p e q scorrono le dimensioni dell'intorno (quindi del kernel)
      for(int p = 0; p < N; p++){
        for(int q = 0; q < M; q++){
          //Prendiamo il valore del pixel, moltiplico per il kernel e accumulo
          res = res + red(tmp.get(p,q)) * K[q][p];
          //get con solo due parametri restituisce il colore
        }
      }
      
    R[y][x] = res;
    //Si fa R[y][x] per rispettare la struttura standard delle matrici matematiche e informatiche: [riga][colonna].
    }
  }
  
  return R;
}
