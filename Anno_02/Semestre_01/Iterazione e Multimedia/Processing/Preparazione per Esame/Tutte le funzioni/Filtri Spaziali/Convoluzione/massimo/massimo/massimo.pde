PImage massimo(PImage I, int N){
  PImage R = createImage(I.width, I.height, RGB); //Crea immagine vuota con le stesse dimensioni delle immagini in ingresso
  PImage tmp;  //Crea immagine temporanea che contiene l'intorno/kernel
  int off = N
  /2;  //Offset per centrare la finestra
  float[] tmpF;  //Array per i valori di grigio dell'intorno
  
  for(int x = 0; x < I.width; x++){
    for(int y = 0; y < I.height; y++){
      //Estrae un intorno quadrato NxN centrato in (x,y)
      tmp = I.get(x-off, y-off, N,N);
      tmp.loadPixels();  //Carica in memoria i pixel dell'intorno
      
      //Alloca un array della dimensione N * N
      tmpF = new float[N * N];
      
      //Copia i valori di grigio (componente rossa) nell'array tmpF
      for(int i = 0; i < tmp.pixels.length; i++){
        tmpF[i] = green(tmp.pixels[i]);  
      }
      
      //Calcola il massimo dell'array e assegna il colore corrispondente al pixel (x,y)
      R.set(x, y, color(max(tmpF)));
    }
  }
  return R;

}
