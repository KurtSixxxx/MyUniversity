PImage Im, I1, I2;
float r1,g1,b1;
float r2,g2,b2;
int h, n, s;

void setup(){
  size(256*3, 256);
  Im = loadImage("lena.jpg");
  Im.resize(256,256);
  image(Im,0,0);
  r1 = random(0,255);
  g1 = random(0,255);
  b1 = random(0,255);
  r2 = random(0,255);
  g2 = random(0,255);
  b2 = random(0,255);
  I1 = grid(Im, color(r1,g1,b1), color(r2,g2,b2));
  r1 = random(0,255);
  g1 = random(0,255);
  b1 = random(0,255);
  n = int(random(5,15));
  h = int(random(80,200));
  s = int(random(50,100));
  I2 = g_mas(Im, color(r1,g1,b1), h, n, s);
  image(I1,256,0);
  image(I2,512,0);
}

void draw(){}

void keyPressed(){
  if(key=='R' || key=='r')
    setup();
}

PImage grid(PImage I, color c1, color c2){
  PImage O = createImage(I.width, I.height, RGB);
  float r,g,b;
  float R,G,B;
  PImage left_up = I.get(0,0,I.width/2,I.height/2);
  PImage left_down = I.get(0,I.height/2,I.width/2,I.height/2);
  PImage right_up = I.get(I.width/2,0,I.width/2,I.height/2);
  PImage right_down = I.get(I.width/2,I.height/2,I.width/2, I.height/2);
  
  for(int i=0; i<left_up.pixels.length; i++){
    r = red(right_down.pixels[i]);
    
    g = green(left_down.pixels[i]);
    
    b = blue(right_up.pixels[i]);
    
    R = 255-red(left_up.pixels[i]);
    G = 255-green(left_up.pixels[i]);
    B = 255-blue(left_up.pixels[i]);
    
    right_down.pixels[i] = color(r,0,0);
    left_down.pixels[i] = color(0,g,0);
    right_up.pixels[i] = color(0,0,b);
    left_up.pixels[i] = color(R,G,B);
  }
  
  O.set(0,0,right_down);
  O.set(I.width/2,I.height/2,left_up);
  O.set(0,I.height/2,right_up);
  O.set(I.width/2,0,left_down);
  
  for(int i=0; i<O.pixels.length; i+=O.width+1){
    O.pixels[i]=c1;
  }
  
  for(int i=O.width-1; i<O.pixels.length; i+=O.width-1){
    O.pixels[i]=c2;
  }
  
  return O;
}

PImage g_mas(PImage I, color c, int h, int n, int s){
  PImage R = grid(I, c, c);
  int x = I.width/2-h/2;
  int y = I.height/2-h/2;
  float r,g,b;
  PImage center = R.get(x,y,h,h);
  for(int i=0; i<center.pixels.length; i++){
    r = red(center.pixels[i]);
    g = green(center.pixels[i]);
    b = blue(center.pixels[i]);
    center.pixels[i] = color((r+g+b)/3);
  }
  center = mas(center, n);
  R = bw(R,s);
  R.set(x,y,center);
  return R;
}

PImage mas(PImage I, int n){
  PImage R = createImage(I.width, I.height, RGB);
  PImage tmp;
  float[] tmpF = new float [n*n];
  int off = n/2;
  
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      tmp = I.get(x-off, y-off, n, n);
      for(int i=0; i<tmp.pixels.length; i++)
        tmpF[i]=red(tmp.pixels[i]);
      R.set(x,y,color(max(tmpF)));
    }
  }
  return R;
}

PImage bw(PImage I, int s){
  PImage R = I.copy();
  PImage left = R.get(0,0,R.width/2,R.height);
  PImage right = R.get(R.width/2,0,R.width/2,R.height);
  R.set(0,0,right);
  R.set(R.width/2,0,left);
  R.filter(GRAY);
  float x,y;
  
  for(int i=0; i<R.pixels.length; i++){
    x = red(R.pixels[i]);
    if(x>s)
      R.pixels[i]=color(255);
    else
      R.pixels[i]=color(0);
  }
  
  PImage up = R.get(0,0,R.width,R.height/2);
  PImage down = R.get(0,R.height/2,R.width,R.height/2);
  
  for(int i=0; i<down.pixels.length; i++)
    down.pixels[i]=color(255-red(down.pixels[i]));
    
  R.set(0,0,down);
  R.set(0,I.height/2,up);
  
  return R; 
}
