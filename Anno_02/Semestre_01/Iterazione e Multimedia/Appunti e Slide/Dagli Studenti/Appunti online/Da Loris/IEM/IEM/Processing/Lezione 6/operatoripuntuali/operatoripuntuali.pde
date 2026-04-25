PImage im, imn, img, iml;
void setup(){
  size(512,512);
  im=loadImage("lena.png");
  im.resize(im.width/2, im.height/2);
  image(im, 0,0);
  
  imn=negativo(im);
  image(imn, width/2, 0);
  
  img=gamma(im,2); //da 1 in su diventa più scura, da 0.1 a 0.9 diventa piu chiara
  image(img, 0, height/2);
  
  iml=logaritmo(im);
  image(iml, width/2, height/2);
}

void draw(){
}

PImage negativo(PImage I){
  PImage R=I.copy(); //fare una copia per evitare di modificare l'immagine originale
  R.loadPixels();
  float r,g,b;
  for(int i=0; i<R.pixels.length; i++){
    r=255-red(R.pixels[i]);
    g=255-green(R.pixels[i]);
    b=255-blue(R.pixels[i]);
    R.pixels[i]=color(r,g,b);
    R.updatePixels();
  }
  return R;
}

PImage gamma(PImage I, float gm){
  PImage R=createImage(I.width, I.height, RGB); //stessa cosa di I.copy però creando una nuova immagine, conviene farlo con copy()
  R.loadPixels();
  I.loadPixels();
  float r,g,b;
  float C=1/pow(255, gm-1);
  for(int i=0; i<R.pixels.length; i++){
    r=C*pow(red(I.pixels[i]),gm);
    g=C*pow(green(I.pixels[i]),gm);
    b=C*pow(blue(I.pixels[i]),gm);
    R.pixels[i]=color(r,g,b);
  }
  R.updatePixels();
  return R;
}

PImage logaritmo(PImage I){
  PImage R=createImage(I.width, I.height, RGB); 
  R.loadPixels();
  I.loadPixels();
  float r,g,b;
  float C=255/(log(1+255)/log(10));
  for(int i=0; i<R.pixels.length; i++){
    r=C*(log(1+red(I.pixels[i]))/log(10)); //cambio di base da naturale a base 2 del logaritmo, non necessario in questa operazione
    g=C*log(1+green(I.pixels[i])/log(10));
    b=C*log(1+blue(I.pixels[i])/log(10));
    R.pixels[i]=color(r,g,b);
  }
  R.updatePixels();
  return R;
}
