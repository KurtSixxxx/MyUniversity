PImage I;
float r,g,b;
color c,c1;
int vr; //variazione rosso

void setup(){
  I=loadImage("lena.png");
  size(512,512);
  vr=0;
  c=color(255,255,0);
  I.loadPixels();
  for(int i=0; i<I.width; i++){
    I.pixels[pos(i,i,I.width)]=c;
  }
  I.updatePixels();
}

void draw(){
  image(I,0,0);
}

void keyPressed(){
  if(key=='r'){
    vr--;
  }else if(key=='R'){
    vr++;
  }
  println(vr);
  
  I.loadPixels(); //matrice linearizzata dell'immagine
  for(int i=0; i<I.pixels.length; i++){ //prende tutti i pixel
    c1=I.pixels[i];
    c1=color(red(c1)+vr, green(c1), blue(c1));
    I.pixels[i]=c1;
  }
  
  I.updatePixels(); //consigliato
}

int pos(int x, int y, int w){ //per la diagonale dell'immagine
  return x+y*w;
}


//Get del colore puntato dal mouse nell'immagine
/*PImage H;
color c;
int x,y;
void setup(){
  size(500,500);
  H=loadImage("lena.png");
  H.resize(200,200);
  c=color(0);
  x=width/2-H.width/2; //per visualizzarla al centro dell'immagine
  y=height/2-H.height/2;
}

void draw(){
  background(c);
  c=H.get(mouseX-x, mouseY-y);
  println("R: "+red(c)+" G: "+green(c)+" B: "+blue(c));
  image(H, x, y);
}*/
