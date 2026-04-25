PImage Im, Ic;
float p=random(0,100);

void setup(){
  size(512, 256);
  Im = loadImage("lena.png");
  Im.resize(256,256);
  image(Im,0,0);
}

void draw(){
  Ic = wow(Im, p);
  image(Ic, 256, 0);
}

void keyPressed(){
  if(key == '+' && p<=130){
    p++;
  }
  
  if(key == '-' && p>30){
    p--;
  }
}

PImage wow(PImage I, float perc){
  PImage R = I.copy();
  float row = perc*(I.width/100);
  float r,g,b;
  PImage left = R.get(0,0, R.width/2, R.height);
  PImage right = R.get(R.width/2, 0, R.width/2, R.height);
  R.set(0,0,right);
  R.set(R.width/2, 0, left);
  for(int i=0; i<R.height; i++){
    for(int j=0; j<row; j++){
      r = red(R.get(i, j));
      b = blue(R.get(i,j));
      g = green(R.get(i,j));
      if(j<row){
        R.set(i,j,color(b,g,r));
      }else{
        R.set(i,j,color(r,b,g));
      }
    }
  }
  
  return R;
}
