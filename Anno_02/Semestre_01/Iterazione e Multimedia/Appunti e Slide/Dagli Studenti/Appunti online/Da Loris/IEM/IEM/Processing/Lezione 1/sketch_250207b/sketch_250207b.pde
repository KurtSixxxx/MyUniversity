void setup(){
  size(600,600);
  background(0);
  noStroke();
  colorMode(RGB, width); //modo di interpretare i colori
}


int d=40;
void draw(){
  for(int y=d/2; y<=height; y+=d){
    for(int x=d/2; x<=width; x+=d){
      if(dist(x,y, mouseX, mouseY)<d/2){ //per far si che cambia il colore nel momento in cui il mouse entra nei cerchi
        fill(x,y,width);
      }else{
        fill(x,y,0);
      }
      ellipse(x,y,d,d);
    }
  }
}
