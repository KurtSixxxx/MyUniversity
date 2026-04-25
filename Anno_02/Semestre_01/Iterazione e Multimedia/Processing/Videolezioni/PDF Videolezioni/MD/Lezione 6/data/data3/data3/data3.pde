//Vogliamo colorare in giallo tutti i pixel che fanno parte della diagonale principale

PImage I;
float r,g,b;
color c,c1;
int vr;

void setup(){
  I=loadImage("lena.png");
  size(512,512);
  vr=0;
  c = color(255,255,0);
  I.loadPixels();
  for(int i = 0; i < I.width; i++){ //poiché l'immagine è quadrata basta muoverci solo per la dimensione di larghezza
    I.pixels[pos(i,i,I.width)] = c;
  }
  I.updatePixels();
}

void draw(){
  image(I,0,0);
}

//questa funzione calcola la posizione (1,1),(2,2),(3,3) e via dicendo della diagonale principale dopo che la nostra matrice è stata linearizzata
int pos(int x, int y, int w){
  return x+y*w;
}
