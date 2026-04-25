PImage lena, lenaBP;

PImage bitplane(PImage I, int nb){
  PImage R = I.copy();
  R.loadPixels();
  
  int x; //Valore del pixel (in 8 bit)
  int r; //Valore estatto dopo le operazioni di shifting
  
  for(int i = 0; i < R.pixels.length; i++){
    x = int(red(R.pixels[i])); //Prendiamo il valore del pixel i e lo castiamo ad int
    
    //Facciamo l'operazione principale: lo shift a destra
    //Spostiamo i bit di 'x' che abbiamo prelevato e castato ad int...
    //... di 'nb' posizioni a destra. nb è il parametro che passiamo a funzione
    // & 1 serve a mascherare tutti i bit tranne il meno significativo
    r = (x >> nb) & 1;
    
    R.pixels[i] = color(255 * r);
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(1024,512);
  //nb indica il numero di shit da fare
  int nb = 0;
  //0 è il piano più basso, 7 è il piano più alto -> 8 bitS
  lena = loadImage("lena.png");
  lenaBP = bitplane(lena, nb); 
  image(lena, 0,0);
  image(lenaBP, 512,0);
}
