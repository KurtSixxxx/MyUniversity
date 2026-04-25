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
