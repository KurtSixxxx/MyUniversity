PImage I1, S1, E1;
PImage I2, S2, E2;

void setup(){
  size(768,512);
  I1=loadImage("lena.png");
  I1.resize(256,256);
  S1=stretching(I1);
  E1=equalizza(I1);
  image(I1,0,0);
  image(S1,256,0);
  image(E1,512,0);
  I2=loadImage("lena.jpg");
  I2.resize(256,256);
  S2=stretching(I2);
  E2=equalizza(I2);
  image(I2,0,256);
  image(S2,256,256);
  image(E2,512,256);
}

PImage stretching(PImage I){
  PImage R=I.copy();
  float maxR, minR, maxG, minG, maxB, minB;
  float r,g,b;
  R.loadPixels();
  maxR=red(R.pixels[0]);
  minR=red(R.pixels[0]);
  maxG=green(R.pixels[0]);
  minG=green(R.pixels[0]);
  maxB=blue(R.pixels[0]);
  minB=blue(R.pixels[0]);
  
  for (int i=0;i<R.pixels.length;i++){
    if (red(R.pixels[i])<minR){
      minR=red(R.pixels[i]);
    }
    if (red(R.pixels[i])>maxR){
      maxR=red(R.pixels[i]);
    }
    if (green(R.pixels[i])<minG){
      minG=green(R.pixels[i]);
    }
    if (green(R.pixels[i])>maxG){
      maxG=green(R.pixels[i]);
    }
    if (blue(R.pixels[i])<minB){
      minB=blue(R.pixels[i]);
    }
    if (blue(R.pixels[i])>maxB){
      maxB=blue(R.pixels[i]);
    }
  }
  
  for (int i=0;i<R.pixels.length;i++){
    r=255*(red(R.pixels[i])-minR)/(maxR-minR);
    g=255*(green(R.pixels[i])-minG)/(maxG-minG);
    b=255*(blue(R.pixels[i])-minB)/(maxB-minB);
    R.pixels[i]=color(r,g,b);
  }
  
  R.updatePixels();
  return R; 
}

PImage equalizza(PImage I){
  PImage R=I.copy();
  float [] H =istogramma(I);
  
  //Istogramma cumulativo
  for (int i=1;i<256;i++){
    H[i]=H[i-1]+H[i];
  }
  
  R.loadPixels();
  
  for (int i=0;i<R.pixels.length;i++){
    R.pixels[i]=color(255*H[int(red(R.pixels[i]))]);
  }
  
  R.updatePixels();
  return R;
}

float [] istogramma(PImage I){
  float[] H = new float[256];
  for (int i=0; i<256;i++){
    H[i]=0;
  }
  
  I.loadPixels();
  
  for (int i=0;i<I.pixels.length;i++){
    H[int(red(I.pixels[i]))]++;
  }
  
  for (int i=0; i<256;i++){
    H[i]=H[i]/I.pixels.length;
  }
  
  return H;
}
