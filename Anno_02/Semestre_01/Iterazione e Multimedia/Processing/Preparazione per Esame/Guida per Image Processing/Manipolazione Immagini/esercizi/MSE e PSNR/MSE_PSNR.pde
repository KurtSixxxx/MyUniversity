float MSE(PImage I1, PImage I2){
    float res  = 0;
    I1.loadPixels();
    I2.loadPixels();

    for(int i = 0; i < I1.pixels.length; i++){
        res += pow(red(I1.pixels[i]) - red(I2.pixels[i]), 2);
    }

    res = res / I1.pixels.length;
    return res;
}

float PSNR(PImage I1, PImage I2){
    float res = 0;
    float mse = MSE(I1, I2);

    res = 10 * log(255*255/mse)/log(10);
    return res;
}