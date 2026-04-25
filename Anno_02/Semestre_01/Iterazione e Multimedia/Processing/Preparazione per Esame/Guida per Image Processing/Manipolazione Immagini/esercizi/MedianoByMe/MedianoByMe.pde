PImage mediano(PImage I, int N){
    PImage R = createImage(I.width, I.height, RGB);
    R.loadPixels();
    
    PImage tmp;
    int offset = N/2;
    float[] tmpF;
    
    float med;

    int xs;
    int ys;

    for(int x = 0; x < R.width; x++){
        for(int y = 0; y < R.height; y++){
            xs = x - offset;
            ys = y - offset;

            tmp = I.get(max(0,xs), max(0,ys), min(N, min(N + xs, R.width - xs)), min(N, min(N + ys, R.height - ys)));
            tmp.loadPixels();

            tmpF = new float[tmp.pixels.length];

            for(int i = 0; i < tmp.pixels.length; i++){
                tmpF[i] = green(tmp.pixels[i]);
            }
            //Unico blocco di codice in più rispetto al minimo
            //----------------------------------------
            tmpF = sort(tmpF);
            int s = tmp.pixels.length;

            if(s % 2 == 1){
                med = tmpF[s / 2];
            }else{
                med = (tmpF[s / 2] + tmpF[s / 2 + 1]) / 2;
            }

            R.set(x,y, color(med));
            //----------------------------------
        }
    }
    return R;
}