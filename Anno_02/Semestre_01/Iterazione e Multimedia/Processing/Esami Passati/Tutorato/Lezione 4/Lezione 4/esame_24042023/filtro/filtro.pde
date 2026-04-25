PImage Im, Ir;

void setup(){
  size(1024,512);
  Im=loadImage("lena.jpg");
  Im.resize(512,512);
  image(Im,0,0);
  Ir=wow(Im);
  image(Ir,512,0);
}

void draw(){}

void keyPressed(){
  if(key=='r' || key=='R')
    setup();
}

PImage wow(PImage I){
  float f=random(0,2);
  PImage R = I.copy();
  PImage left = I.get(0,0,R.width/3,R.height);
  PImage right = I.get(2*R.width/3,0,R.width/3,R.height);
  
  float rl,gl,bl;
  float rr,gr,br;
  
  for(int i=0; i<left.pixels.length; i++){
    rl = red(left.pixels[i]);
    gl = green(left.pixels[i]);
    bl = blue(left.pixels[i]);
    
    left.pixels[i]=color(rl*f, gl, bl);
    
    rr = red(right.pixels[i]);
    gr = green(right.pixels[i]);
    br = blue(right.pixels[i]);
    
    right.pixels[i]=color(rr/f, gr, br);
  }
  
  R.set(0,0,right);
  R.set(2*R.width/3,0,left);
  
  return R;
}
