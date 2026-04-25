PImage I;
String url="https://media.laregione.ch/files/domains/laregione.ch/images/4by1/s_-homer-quando-va-essere-quel-pdcb.jpg";;
int g=0;

void settings(){
  I=loadImage(url);
  I.resize(int(I.width/2.5),int(I.height/2.5));
  size(I.width,I.height);

}

void draw(){
  image(I,0,0);
}

void keyTyped(){
  
  if(key=='+')
  {
    g++;
    I.filter(BLUR,g);
  }
  
  if(key=='r')
  {
    I=loadImage(url);
    I.resize(int(I.width/2.5),int(I.height/2.5));
    g=0;
  }

}
