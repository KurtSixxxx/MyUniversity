PImage im, ic, ir;
float mseO, mseP, mseR, psnrO, psnrP, psnrR;
void setup(){
  im=loadImage("lena.png");
  im.filter(GRAY);
  size(1536, 512);
  background(0);
  
  ic=im.copy();
  ic.resize(256,256);
  ic.resize(512,512);
  
  ir=im.copy();
  ir.resize(256, 256);
  ir=replication2x(ir);
  
  image(im, 0,0);
  image(ic, 512, 0);
  image(ir, 1024, 0);
  
  mseO=MSE(im,im);
  mseP=MSE(im,ic);
  mseR=MSE(im,ir);
  
  psnrO=PSNR(im,im);
  psnrP=PSNR(im,ic);
  psnrR=PSNR(im,ir);
  
  println("MSE con se stessa: "+mseO);
  println("MSE di processing: "+mseP);
  println("MSE replication "+mseR);
  println("PSNR con se stessa: "+psnrO);
  println("PSNR di processing: "+psnrP);
  println("PSNR replication: "+psnrR);
}

PImage replication2x(PImage I){
  PImage R=createImage(2*I.width, 2*I.height, RGB);
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      R.set(2*x, 2*y, I.get(x,y));
      R.set(2*x+1, 2*y, I.get(x,y));
      R.set(2*x, 2*y+1, I.get(x,y));
      R.set(2*x+1, 2*y+1, I.get(x,y));
    }
  }
  return R;
}

float MSE(PImage I1, PImage I2){
  float res=0;
  I1.loadPixels();
  I2.loadPixels();
  
  for(int i=0; i<I1.pixels.length; i++){
    res+=pow(red(I1.pixels[i])-red(I2.pixels[i]),2);
  }
  res=res/I1.pixels.length;
  return res;
}

float PSNR(PImage I1, PImage I2){
  float res=0;
  float mse=MSE(I1,I2);
  res=10*log(255*255/mse)/log(10);
  return res;
}

//la resize è migliore e quindi processing è migliore
