# Processing appunti 6 lezione di affiancamento

```Java
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
```

```java
//MODIFICHIAMO LA COMPONENTE DI ROSSO DI UN'IMMAGINE
PImage I;
float r,g,b; //il valore di ogni componente
color c,c1; //due colori
int vr; //variazione di rosso, perché vogliamo variare la componente di rosso

void setup(){
  I=loadImage("lena.png");
  size(512,512);
  vr=0;
}

void draw(){
  image(I,0,0);
}

void keyPressed(){
  //Vogliamo fare che se premiamo r sottraiamo componente di rosso, con R invece aggiungiamo componente di rosso
  if(key=='r'){
    vr--;
  }else if(key=='R'){
    vr++;
  }
  println(vr);

  //A questo punto vogliamo cambiare il valore di rosso per ogni pixel dell'immagine. Come? O abbiamo un for che scorre ogni riga e colonna e usiamo un get che preleva ogni valore.
  //Oppure usiamo la matrice di pixel, che è un metodo differente da quello sopra, che rende una matrice bidimensionale in una monodimensionale chimata "matrice linearizzata"
  //Per farlo facciamo così:
  I.loadPixels(); //in questo caso all'interno di I ci sarà una struttura dati array chiamata Pixels che non è altro che è un array che è la matrice linearizzata della matrice immagine
  for(int i = 0; i < I.pixels.length; i++){
    c1 = I.pixels[i];
    c1 = color(red(c1)+vr, green(c1), blue(c1));
    I.pixels[i]=c1;
  }
  I.updatePixels(); //forziamo l'aggiornameto della matrice di pixel  
}
```

```java
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
```

```java
/*Faremo gli operatori puntuali: negativo, gamma e logaritmo

- 01.13.50: Vogliamo fare una canvas divisa in 4.
  In alto a sinstra lena originale, poi lena in negativo, poi lena in gamma e poi lena in logaritmo*/

PImage Im, ImN, ImG, ImL;
void setup(){
 //rimpiccioliamo lena della metà cosi ne entrano 4 nella canvas
 size(512,512);
 Im=loadImage("lena.png");
 Im.resize(256,256);
 image(Im,0,0);

  ImN=negativo(Im);
  image(ImN,256,0);

  ImG=gamma(Im,2);
  image(ImG,0,256);

  ImL=logaritmo(Im);
  image(ImL,256,256);
}

void draw(){}

//Funzione che ci restituisce una immagine in negativo
PImage negativo(PImage I){
  PImage R=I.copy(); //Creiamo la copia dell'immagine. Quindi leggiamo da I e scriviamo su R
   R.loadPixels(); //carichiamo i pixel
   float r,g,b;  //abbiamo i valori delle componenti r g b
   for(int i = 0; i < R.pixels.length; i++){ //iteriamo sui pixel dell'immagine
     r=255-red(R.pixels[i]);
     g=255-green(R.pixels[i]);
     b=255-blue(R.pixels[i]);
     R.pixels[i]=color(r,g,b);
   }
   R.updatePixels();
   return R;
}

//Funzione che ci restituisce una immagine in gamma
PImage gamma(PImage I, float gm){
  PImage R=createImage(I.width,I.height,RGB);

  R.loadPixels();
  I.loadPixels();

  float r,g,b;
  float C=1/pow(255,gm-1);

  for(int i=0; i<R.pixels.length; i++){
    r=C*pow(red(I.pixels[i]),gm);
    g=C*pow(green(I.pixels[i]),gm);
    b=C*pow(blue(I.pixels[i]),gm);

    R.pixels[i]=color(r,g,b);
  }
  R.updatePixels();
  return R;
}

PImage logaritmo(PImage I)
{
  PImage R=createImage(I.width,I.height,RGB);

  R.loadPixels();
  I.loadPixels();

  float r,g,b;
  float C=255/(log(1+255)/log(2));

  for(int i=0; i<R.pixels.length; i++)
  {
    r=C*log(1+red(I.pixels[i]));
    g=C*log(1+green(I.pixels[i]));
    b=C*log(1+blue(I.pixels[i]));

    R.pixels[i]=color(r,g,b);
  }
  R.updatePixels();
  return R;
}
```

```java
// - 01.52.00 Iniziamo a studiare la quantizzazione in Processing

PImage Im, Iq;
int K = 2;

void setup(){
  size(1024,512);
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  image(Im, 0, 0);

  Iq = quantizza(Im, K);
  image(Iq,512,0);
}

void draw(){
}

PImage quantizza(PImage I, int k){
  PImage R = I.copy();
  R.loadPixels();
  int q;
  for(int i = 0; i < R.pixels.length; i++){
    q = floor(red(R.pixels[i])*k/256);
    //Un metodo uguale è: q = int(lerp(0,255,float(q)/(k-1)));
    q = int(float(q)/(k-1) * 255);
    R.pixels[i] = color(q);
  }
  R.updatePixels();
  return R;
}

void keyPressed(){
  if(key=='+' && K < 256){
    K++;
   }

   if(key=='-' && K > 2){
    K--;
   }

   println(K);
   image(quantizza(Im,K), 512, 0);
}
```

 Prossima lezione: algoritmo di zooming messo a confronto con l'algoritmo messo a confronto di resize usato da Processing. Con calcolo di MSE e di PSNR.