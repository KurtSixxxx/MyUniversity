void setup(){
  size(512, 512);
  PImage Im = loadImage("lena.png");
  Im.resize(512, 512);
  PImage Ir = wow(Im, random(0,2.0));
  image(Ir, 0, 0);
}

void draw(){}


PImage wow(PImage I, float fact){
  PImage R = I.copy();
  R.loadPixels();
  I.loadPixels();
  PImage left = I.get(0, 0, width/3, height);
  PImage right = I.get(2*width/3, 0, width/3, height);
  
  float r,g,b;
  /*for(int i=0; i<left.width; i++){
    for(int j=0; j<left.height; j++){
      r = red(R.get(i, j));
      g = green(R.get(i,j));
      b = blue(R.get(i,j));
      r = fact/2;
      left.set(i, j, color(r,g,b));
    }
  }*/
  
  for(int i=0; i<left.pixels.length; i++){
    r = red(left.pixels[i]) / fact;
    g = green(left.pixels[i]);
    b = blue(left.pixels[i]);
    left.pixels[i] = color(r, g, b);
  }
  
  for(int i=0; i<right.pixels.length; i++){
    r = red(right.pixels[i]) * fact;
    g = green(right.pixels[i]);
    b = blue(right.pixels[i]);
    right.pixels[i] = color(r, g, b);
  }
  
  R.set(2*width/3, 0, left);
  R.set(0, 0, right);
  
  R.updatePixels();
  
  return R;
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    setup();
  }
}
