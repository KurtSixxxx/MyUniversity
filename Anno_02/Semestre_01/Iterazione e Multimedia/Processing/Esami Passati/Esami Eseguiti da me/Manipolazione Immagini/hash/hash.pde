PImage I, Ris1, Ris2;

PImage hash(PImage I, int h, int k){
  PImage R = I.copy();
  R.filter(GRAY);
  R.loadPixels();
  
  int wi = R.width;
  int he = R.height;
  
  for(int y = 0; y < he; y++){
    for(int x = 0; x < wi; x++){
      int i = x + y * wi;
      
      if(x == h || x == k || y == h || y == k){
        R.pixels[i] = color(0);
      }
    }
  }
  R.updatePixels();
  R.resize(256,256);
  return R;
}

  PImage hashMax(PImage I, int h, int k, int N) {
    // Crea una nuova immagine vuota delle stesse dimensioni di I.
    PImage R = createImage(I.width, I.height, RGB);
    PImage tmp;          // Finestra corrente
    int off = N / 2;     // Offset per centrare la finestra
    float[] tmpF;        // Array per i valori di grigio dell'intorno
  
    for (int x = 0; x < I.width; x++) {
      for (int y = 0; y < I.height; y++) {
        // Estrae un intorno NxN centrato in (x,y)
        tmp = I.get(x - off, y - off, N, N);
        tmp.loadPixels(); // Carica i pixel dell'intorno
  
        // Alloca un array della dimensione giusta (N*N)
        tmpF = new float[N * N];
  
        // Copia i valori di grigio (canale verde) nell'array tmpF
        for (int i = 0; i < tmp.pixels.length; i++) {
          tmpF[i] = green(tmp.pixels[i]);
        }
  
        // Calcola il massimo dell'array e assegna il colore corrispondente al pixel (x,y)
        R.set(x, y, color(max(tmpF)));
      }
    }
    
    int wi = R.width;
    int he = R.height;
    
    for(int y = 0; y < he; y++){
      for(int x = 0; x < wi; x++){
        int i = x + y * wi;
        
        if(x == h || x == k || y == h || y == k){
          R.pixels[i] = color(0);
        }
      }
    }
  
    return R;
  }


void setup(){
  size(768,256);
  background(255);
  
  int h, k;
  h = int(random(1,256));
  k = int(random(1,256));

  I = loadImage("lena.png");
  I.resize(256,256);
  Ris1 = hash(I,h,k);
  image(I, 0,0);
  image(Ris1, 256, 0);
  Ris2 = hashMax(I,h,k,3);
  image(Ris2, 512, 0);
  
  
}

void draw(){
}

void reset(){
  setup();
}

void keyPressed(){
  if(key=='r' || key=='R'){
     reset(); 
  }
}
