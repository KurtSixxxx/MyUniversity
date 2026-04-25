//Facciamo un esercizio dove abbiamo un'immagine 200x200 sulla nostra canvas al centro, e poi vogliamo colorare il bordo con il colore del pixel che abbiamo sotto il puntatore del mouse

/*
Vediamo come acquisire il colore di ogni singolo pixel

usiamo get() che prende due parametri, la coordinata x e y del pixel di cui vogliamo prelevare il valore
*/

PImage H;
color c;
int x,y;

void setup(){
  size(500,500);
  H=loadImage("lena.png");
  //Riduciamo la dimensione dell'immagine che è di 512x512
  H.resize(200,200);
  c=color(0);
  //Così posizioniamo l'immagine al centro. Potremmo usare anche ImageMode()
  x=width/2-H.width/2;
  y=height/2-H.height/2;
}

void draw(){
  background(c);
  c=H.get(mouseX-x,mouseY-y); //Il motivo per cui sottraiamo x e y allce coordinate mouseX e mouseY è che: poiché abbiamo messo l'immagine 200x200 al centro, usando width/2-100px (e la stessa cosa con height), noi trasliamo la cattura del colore solo nei campi dove si trova il mouse all'interno dell'immagine. Se noi non lo facessimo avremmo un "quadrato invsibile" di dimensione 200x200 nell'angolo in alto a sinistra e il colore verrebbe prelevato da lì, non passando il mouse sulla foto
  println("R: "+red(c)+"; G: "+green(c)+"; B: "+blue(c));
  image(H,x,y);
}
