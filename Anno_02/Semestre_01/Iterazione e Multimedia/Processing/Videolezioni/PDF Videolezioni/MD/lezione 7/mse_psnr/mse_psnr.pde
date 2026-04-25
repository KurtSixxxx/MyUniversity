float MSE (PImage I2, PImage I2){
    float res = 0;
    I1.loadPixels();
    I2.loadPixels();
    
    for(int i = 0; i < I1.pixels.length; i++){ //Prendiamo la matrice linearizzata
       res += pow(red(I1.pixels[i] - I2.pixels[i]), 2); //Eleviamo al quadrato la differenza di pixel. Scegliamo il canale rosso ma potremmo sceglierne anche altri
    }
    res = res/I1.pixels.length; //Questo corrisponde a 1/MN
    return res;
}

float PSNR (PImage I1, PImage I2){
  float res = 0;
  float mse = MSE(I1, I2);
  
  res = 10 * log(255*255/mse)/log(10);
  return res;
} 
