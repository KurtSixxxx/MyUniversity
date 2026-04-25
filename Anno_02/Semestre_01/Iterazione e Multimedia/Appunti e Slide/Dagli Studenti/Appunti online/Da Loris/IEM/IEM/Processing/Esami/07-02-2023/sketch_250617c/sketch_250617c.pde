void setup(){
  size(512, 256);
  float perc = random(0,100);
  PImage I = loadImage("lena.png");
  I.resize(256, 256);
  I.loadPixels();
  image(I, 0, 0);
  PImage Im = wow(I, perc);
  Im.loadPixels();
  image(Im, 256, 0);
}

PImage wow(PImage I, float p){
  PImage R = createImage(I.width, I.height, RGB);
  PImage left = I.get(0, 0, I.width/2, I.height);
  PImage right = I.get(I.width/2, 0, I.width, I.height);
  R.set(0, 0, right);
  R.set(R.width/2, 0, left);
  
  float perc = p*(R.pixels.length/100);
  
  for(int i=0; i<perc; i++){
    float r = red(R.pixels[i]);
    float g = green(R.pixels[i]);
    float b = blue(R.pixels[i]);
    R.pixels[i] = color(b,g,r);
  }
  for(int i=(int)perc; i<R.pixels.length; i++){
    float r = red(R.pixels[i]);
    float g = green(R.pixels[i]);
    float b = blue(R.pixels[i]);
    R.pixels[i] = color(r, b, g);
  }
  
  return R;
}

void draw(){}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    setup();
  }
}
