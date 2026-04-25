PImage im;
PImage subim;

void setup(){
  size(600,600);
  background(255,255,0);
  im=loadImage("lena.png"); //se vogliamo caricare un'immagine da google, basta sostituire il link dell'immagine a lena.png
  println("Larghezza: "+im.width); //per vedere quanto è larga e alta l'immagine
  println("Altezza: "+im.height);
  im.filter(GRAY); //se vogliamo applicare un filtro all'immagine
  im.save(savePath("LenaGrigio.png"));
  image(im,0,0);
  subim=im.get(100,100,120,120);
  subim.save(savePath("LenaPorzione.png"));
}

void draw(){
}

void mouseClicked(){
  im.resize(im.width/2, im.height/2);
}

void keyTyped(){
  if(key=='s' || key=='S'){
    //println(savePath("lenaPiccola.png")); //per salvare l'immagine all'interno di data
    im.save(savePath("lenaPiccola.png"));
    //println("salvo la canvas.."); //per salvare la canvas completa con il background
    //saveFrame("lenaCanvas.png");
    //saveFrame("lena-####.png); //per salvare tutti i fotogrammi del video
    //per salvare i video, da Strumenti apri movie Maker, gli dici dove stanno tutti i fotogrammi dell'animazione appena fatta e Processing stesso farà un video
  }
}
