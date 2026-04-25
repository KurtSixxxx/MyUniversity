PImage Im, Ic;
float p;

void setup(){
  size(512,256);
  p=50;
  Im = loadImage("lena.jpg");
  Im.resize(256,256);
  image(Im,0,0);
}

void draw(){
  Ic=wow(Im,p);
  image(Ic,256,0);
}

void keyPressed(){
  if(key=='+' && p<=100)
    p++;
  if(key=='-' && p>=0)
    p--;
}

PImage wow(PImage I, float p){
  PImage R = I.copy();
  float row = p*(I.height/100.0);
  float r,g,b;
  PImage left = R.get(0,0,R.width/2,R.height);
  PImage right = R.get(R.width/2,0,R.width/2,R.height);
  R.set(0,0,right);
  R.set(R.width/2,0,left);
  for(int i=0; i<R.height; i++){
    for(int j=0; j<R.width; j++){
    r = red(R.get(i,j));
    g = green(R.get(i,j));
    b = blue(R.get(i,j));
    if(j<row)
      R.set(i,j,color(b,g,r));
    else
      R.set(i,j,color(r,b,g));
    }
  }
  return R;
}
  
