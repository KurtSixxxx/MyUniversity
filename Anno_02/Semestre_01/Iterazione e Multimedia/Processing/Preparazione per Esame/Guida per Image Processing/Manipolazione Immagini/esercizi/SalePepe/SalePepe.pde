PImage SalePepeFisso(PImage I){
    PImage R = I.copy();
    R.loadPixels();
    for(int i = 0; i < R.pixels.length; i++){
        float rnd = random(1);
        if(rnd < 0.025){
            R.pixels[i] = color(255);
        }else{
            R.pixels[i] = color(0);
        }
    }
    R.updatePixels();
    return R;
}