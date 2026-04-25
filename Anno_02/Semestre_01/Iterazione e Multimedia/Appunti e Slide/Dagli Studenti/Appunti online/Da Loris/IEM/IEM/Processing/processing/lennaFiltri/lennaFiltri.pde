PImage lenna;
PImage [] filtri;
float[][] kernel = {{0,-1,0},{-1,5,-1},{0,-1,0}};

void setup(){
  size(256 * 5, 256 * 4);
  lenna = loadImage("lenna.png");
  lenna.resize(256,256);
  filtri = new PImage[] {
    lenna,
    gammaFunction(lenna,0.3),
    logFunction(lenna),
    negativeFunction(lenna),
    maxFunction(lenna,4),
    minFunction(lenna,3),
    medianaFunction(lenna,10),
    convoluzioneFunction(lenna,kernel),
    cutY(lenna),
    cutX(lenna),
    contrastStr(lenna),
    EQ(lenna)
  };
  
  for(int i = 0; i < filtri.length;i++){
    int col = i % 5;
    int row = i / 5;
    image(filtri[i],col * 256, row * 256);
  }
}

//gamma : c * f(x,y)^gamma
PImage gammaFunction(PImage image,float gamma){
  PImage out = image.copy();
  out.loadPixels();
  float c = 255 / pow(255,gamma);
  for(int i =0; i < image.pixels.length;i++){
    float nuColor = pow(green(out.pixels[i]),gamma);
    out.pixels[i] = color(nuColor * c);
  }
  out.updatePixels();
  return out;
}

//logaritmo: c * log(f(x,y))
PImage logFunction(PImage image){
  PImage out = image.copy();
  out.loadPixels();
  
  float c = 255 / log(255);
  for(int i = 0; i < out.pixels.length;i++){
    float nuColor = log(green(out.pixels[i]));
    out.pixels[i] = color(nuColor * c);
  }
  out.updatePixels();
  return out;
}

//negativo: 255 - f(x,y)
PImage negativeFunction(PImage image){
  PImage out = image.copy();
  out.loadPixels();
  
  for(int i = 0; i < out.pixels.length;i++){
    out.pixels[i] = 255 - out.pixels[i];
  }
  out.updatePixels();
  return out;
}

//massimo: max = color(max(arr)) out.set(x,y,max)
PImage maxFunction(PImage image,int n){
  PImage out = image.copy();
  float [] arr = new float[n * n];
  PImage subOut;
  color max;
  
  for(int x = 0; x < image.width;x++){
    for(int y = 0; y < image.height;y++){
      subOut = image.get(x - n/2, y - n/2,n,n);
      subOut.loadPixels();
      
      for(int i = 0; i < subOut.pixels.length;i++){
        arr[i] = green(subOut.pixels[i]);
      }
      
      max = color(max(arr));
      out.set(x,y,max);
    }
  }
  return out;
}

//minimo: min = color(min(arr)) out.set(x,y,min)
PImage minFunction(PImage image, int n){
  PImage out = image.copy();
  float [] arr = new float[n * n];
  PImage subOut;
  color min;
  int xs,ys;
  
  for(int x = 0; x < image.width;x++){
    for(int y = 0; y < image.height;y++){
        xs = x - n/2;
        ys = y - n/2;
      
      subOut = image.get(max(0,xs),max(0,ys),min(n, min(n+xs, image.width - xs)),min(n,min(n+ys,image.height - ys)));
      subOut.loadPixels();
      for(int i = 0; i < subOut.pixels.length;i++){
        arr[i] = green(subOut.pixels[i]);
      }
      
      min = color(min(arr));
      out.set(x,y,min);
    }
  }
  return out;
}

//mediana: if(arr.length % 2 == 0) mediano= floor + ceil / 2  mediano =color(arr[arr.length/2]); out.set(x,y,mediano)
PImage medianaFunction(PImage image, int n){
  PImage out = image.copy();
  float[] arr = new float[n * n];
  PImage subOut;
  color mediana;
  int xs, ys;

  for (int x = 0; x < image.width; x++) {
    for (int y = 0; y < image.height; y++) {
      xs = x - n/2;
      ys = y - n/2;

      int safeX = max(0, xs);
      int safeY = max(0, ys);
      int w = min(n, image.width - safeX);
      int h = min(n, image.height - safeY);

      subOut = image.get(safeX, safeY, w, h);
      subOut.loadPixels();

      for (int i = 0; i < subOut.pixels.length; i++) {
        arr[i] = green(subOut.pixels[i]);
      }

      arr = sort(arr);

      if (arr.length % 2 == 0) {
        mediana = color((arr[arr.length/2] + arr[arr.length/2 - 1]) / 2);
      } else {
        mediana = color(arr[arr.length / 2]);
      }

      out.set(x, y, mediana);
    }
  }

  return out;
}
//convoluzione: permette di modificare una immagine applicando una maschera
PImage convoluzioneFunction(PImage image,float[][] kernel){
  PImage out = image.copy();
  PImage subOut;
  int n = kernel.length; // altezza del kernel
  int m = kernel[0].length; // larghezza del kernel
  
  for(int x = 0; x < out.width;x++){
    for(int y = 0; y < out.height;y++){
      subOut = image.get(x - n/2,y- m/2,n,n);
      float nuValue = 0;
      
      //applica la convoluzione: somma dei prodotti (pixel * kernel)
      for(int h = 0;h < kernel[0].length;h++){
        for(int l = 0; l < kernel.length;l++){
          nuValue += green(subOut.get(h,l)) * kernel[l][h];
        }
      }
      nuValue = constrain(nuValue,0,255);
      out.set(x,y,color(nuValue));
    }
  }
  return out;
}
//inversione verticale: scambiare le due metà orizzontalid i una immagine: parte sinistra va a destra,
//parte destra va a sinistra
PImage cutY(PImage image){
  PImage out = image.copy();
  PImage left;
  PImage right;
  
  //estraggo la metà sinistra(da colonna zero a metà larghezza)
  left = out.get(0,0,out.width / 2,out.height);
  //estraggo la metà destra(da colonna metà alla fine)
  right = out.get(out.width / 2,0,out.width/2,out.height);
  
  //inserisce la parte destra nella sinistra
  out.set(0,0,right);
  //inserisce la parte sinistra nella destra
  out.set(out.width/2,0,left);
  
  return out;
}

//inversione orizzontale(scambiare la parte superiore con quella inferiore)
PImage cutX(PImage image){
  PImage out = image.copy();
  PImage upper;
  PImage lower;
  
  upper = out.get(0,0,out.width,out.height/2);
  lower = out.get(0,out.height/2,out.width,out.height/2);
  
  out.set(0,0,lower);
  out.set(0,height/2,upper);
  
  return out;
}
//espansione del contrasto
PImage contrastStr(PImage I) {
  PImage out = I.copy();
  out.loadPixels();
  float min = red(out.pixels[0]);
  float max = red(out.pixels[0]);
  for(int i=0; i<out.pixels.length; i++){
    
    if (min>red(out.pixels[i])) {
      min = red(out.pixels[i]);
    }
    if (max<red(out.pixels[i])) {
      max = red(out.pixels[i]);
    }
  }
  for(int i=0; i<out.pixels.length; i++){
    out.pixels[i] = color(map(red(out.pixels[i]), min, max, 0, 255));
  }
  out.updatePixels();  
  return out;
}
//istogramma e equalizzazione
float [] istogramma(PImage I) {
  float [] H = new float[256];

  for (int i = 0; i<256; i++) {
    H[i] = 0;
  }

  I.loadPixels();

  for (int i = 0; i<I.pixels.length; i++) {
    H[int(red(I.pixels[i]))]++;
  }

  for (int i = 0; i<256; i++) {
    H[i] = H[i]/I.pixels.length;
  }

  return H;
}


PImage EQ(PImage I) {
  PImage out = I.copy();

  float [] H = istogramma(I);

  // ISTOGRAMMA CUMULATIVO:
  for (int i=1; i<256; i++) {
    H[i] = H[i-1] + H[i];
  }

  out.loadPixels();

  for (int i=0; i<out.pixels.length; i++) {
    out.pixels[i] = color(255*H[int(red(out.pixels[i]))]);
  }
  out.updatePixels();

  return out;
}
