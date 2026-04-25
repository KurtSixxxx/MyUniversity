PImage Im, I1, I2;
float r1,g1,b1;
float r2,g2,b2;
int h = (int)random(120,200);
void setup(){
  size(768, 256);
  Im = loadImage("lena.png");
  Im.resize(256, 256);
  image(Im, 0,0);
  r1 = random(0,255);
  g1 = random(0,255);
  b1 = random(0,255);
  r2 = random(0,255);
  g2 = random(0,255);
  b2 = random(0,255);
  I1 = grid(Im, color(r1,g1,b1), color(r2,g2,b2));
  image(I1, 256, 0);
  r1 = random(0,255);
  g1 = random(0,255);
  b1 = random(0,255);
  I2 = g_med(Im, color(r1,g1,b1), h, 50);
  image(I2, 512, 0);
}

void draw(){}

void keyPressed(){
  if(key=='r' || key == 'R'){
    setup();
  }
}

PImage grid(PImage I, color c1, color c2){
  PImage O = createImage(I.width, I.height, RGB);
  float r,g,b;
  float R,G,B;
  PImage left_up = I.get(0,0,I.width/2, I.height/2);
  PImage left_down = I.get(0,I.height/2,I.width/2, I.height/2);
  PImage right_up = I.get(I.width/2,0,I.width/2, I.height/2);
  PImage right_down = I.get(I.width/2,I.height/2,I.width/2, I.height/2);
  
  for(int i=0; i<right_down.pixels.length; i++){
    r = red(right_down.pixels[i]);
    g = green(left_down.pixels[i]);
    b = blue(right_up.pixels[i]);
    
    R =255-red(left_up.pixels[i]);
    G =255-green(left_up.pixels[i]);
    B =255-blue(left_up.pixels[i]);
    
    right_down.pixels[i] = color(r,0,0);
    left_down.pixels[i] = color(0,g,0);
    right_up.pixels[i] = color(0,0,b);
    
    left_up.pixels[i] = color(R,G,B);
  }
  
  O.set(0,0, right_down);
  O.set(I.width/2,I.height/2, left_up);
  O.set(0,I.height/2, right_up);
  O.set(I.width/2, 0, left_down);
  
  for(int i=0; i<O.pixels.length; i+=O.width+1){
    O.pixels[i] = c1;
  }
  
  for(int i=O.width; i<O.pixels.length; i+=O.width-1){
    O.pixels[i] = c2;
  }
  
  return O;
}

PImage g_med(PImage I, color c, int h, int n){
  PImage R = grid(I,c,c);
  int x=I.width/2-h/2;
  int y= I.height/2-h/2;
  PImage center = R.get(x, y, h, h);
  float r,g,b;
  for(int i=0; i<center.pixels.length; i++){
    r = red(center.pixels[i]);
    g = green(center.pixels[i]);
    b = blue(center.pixels[i]);
    center.pixels[i] = color((r+g+b)/3);
  }
  R.set(x,y,center);
  return R;
}

PImage med(PImage I, int n){
  PImage R = createImage(I.width, I.height, RGB);
  PImage temp;
  float [] tempF = new float [n*n];
  int offset = n/2;
  
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      temp = I.get(x-offset, y-offset, n, n);
      for(int i=0; i<temp.pixels.length; i++){
        tempF[i] = red(temp.pixels[i]);
      }
      sort(tempF);
      if(tempF.length % 2 == 1){
        R.set(x,y,color(tempF[tempF.length/2]));
      }else if(tempF.length %2 ==0){
        R.set(x,y,color((tempF[tempF.length/2]+tempF[tempF.length/2+1])/2));
      }
    }
  }
  
  return R;
}

PImage mas(PImage I, int n){
  PImage R = createImage(I.width, I.height, RGB);
  PImage temp;
  float [] tempF = new float [n*n];
  int offset = n/2;
  
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      temp = I.get(x-offset, y-offset, n, n);
      for(int i=0; i<temp.pixels.length; i++){
        tempF[i] = red(temp.pixels[i]);
      }
      R.set(x,y, color(max(tempF)));
    }
  }
  
  return R;
}

PImage min(PImage I, int n){
  PImage R = createImage(I.width, I.height, RGB);
  PImage temp;
  float [] tempF = new float [n*n];
  int offset = n/2;
  
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      temp = I.get(x-offset, y-offset, n, n);
      for(int i=0; i<temp.pixels.length; i++){
        tempF[i] = red(temp.pixels[i]);
      }
      R.set(x,y, color(min(tempF)));
    }
  }
  
  return R;
}
