PImage salePepe(PImage I, float k){
    PImage R = I.copy();
    R.loadPixels();
    float prob = k / 100.0; //Probabilità su 100;
    for(int i = 0; i < R.pixels.length; i++){
        float rnd = random(1);
        if(rnd < prob/2){
            R.pixels[i] = color(255);
        }else if(rnd < prob){
            R.pixels[i] = color(0);
        }
    }
    R.updatePixels();
    return R;
}