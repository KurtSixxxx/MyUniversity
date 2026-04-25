PImage originale;
PImage modificata;
float f;

void reset(){
  f = random(0,2);
  println("Nuovo fattore f: "+nf(f, 1, 2));
  modificata = wow(originale);  // <-- usa originale, non sovrascrivere
}

PImage wow(PImage I){
  PImage output = I.copy();
  output.loadPixels();
  
  int w = I.width;
  int h = I.height;
  int w3 = w/3;
  
  PImage left = I.get(0,0, w3,h);
  PImage right = I.get(w3*2,0, w3,h);
  PImage center = I.get(w3,0, w3,h);
  
  //modifichiamo sinistro
  left.loadPixels();
  for(int i = 0; i < left.pixels.length; i++){
    color c = left.pixels[i];
    float r = red(c) / f;
    r = constrain(r, 0, 255);  // lo "taglia" nel range valido
    left.pixels[i] = color(r, green(c), blue(c));
  }
  left.updatePixels();
  
  //modifichiamo destro
  right.loadPixels();
  for(int i = 0; i < right.pixels.length; i++){
    color c = right.pixels[i];
    float r =red(c) * f;
    r = constrain(r, 0, 255);  // lo "taglia" nel range valido
    right.pixels[i] = color(r, green(c), blue(c));
  }
  right.updatePixels();
  
  output.set(0,0, right);
  output.set(w3,0, center);
  output.set(w3*2,0, left);
  
  output.updatePixels();
  return output;
}

void setup(){
  size(512,512);
  originale = loadImage("lena.png");
  originale.resize(512,512);
  reset();  // <-- chiama reset che usa originale
}

void draw(){
  background(0);
  image(modificata, 0, 0);  // <-- mostra modificata
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
     reset();
  }
}
