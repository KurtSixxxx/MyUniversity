PImage im;
PImage subim;
int g=0;

void setup(){
  size(600,600);
  im=loadImage("lena.png"); //se vogliamo caricare un'immagine da google, basta sostituire il link dell'immagine a lena.png
  println("Larghezza: "+im.width); //per vedere quanto è larga e alta l'immagine
  println("Altezza: "+im.height);
}

void draw(){
  background(255,255,0);
  image(im,0,0);
}

void mouseClicked(){
  im.resize(im.width/2, im.height/2); //per diminuirla
  //im.resize(int(im.width*1.1), int(im.height*1.1)); //per ingrandirla
}

void keyTyped(){
  if(key=='s' || key=='S'){
    println(savePath("lenaPiccola.png")); //per salvare l'immagine all'interno di data
    im.save(savePath("lenaPiccola.png"));
  }
  
  if(key=='c'){
    println("salvo la canvas...");
    saveFrame("lenaCanvas.png");
  }
  
  if(key=='+'){
    g++;
    im.filter(BLUR,g);
    println("BLUR: "+g);
  }
}
