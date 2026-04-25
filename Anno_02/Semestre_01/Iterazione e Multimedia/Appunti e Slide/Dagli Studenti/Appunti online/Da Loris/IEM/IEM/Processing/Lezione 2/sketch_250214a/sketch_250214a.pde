//Figura con più lati
/*size(500,500);
background(255);
beginShape();
fill(0);
vertex(180,82);
vertex(207,36);
vertex(214,63);
vertex(407,11);
vertex(412,30);
vertex(219,82);
vertex(226,109);
endShape(CLOSE);*/

//Animazione iniziale
int pos=0;
int yc=0;
int b=255;
int dir=1;
int v=3;
void setup(){
  size(500,500);
  frameRate(240);
}

void draw(){
  background(b);
   line(pos, 0, pos, height);
   pos+=v*dir;
   if(pos>width || pos<0){
     dir=-dir;
   }
   
   
   ellipse(width/2, yc, 30,30);
   if(yc>height){
     yc=0;
   }
   yc+=v*dir;
}

//Cerchi in tutto lo schermo
/*int d=40;
void setup(){
  size(800,500);
}

void draw(){
  background(0);
  for(int y=20; y<=height; y+=d){
    for(int x=20; x<=width; x+=d){
      ellipse(x, y, d, d);
    }
  }
  for(int y=20; y<=height; y+=d){
    for(int x=20; x<=width; x+=d){
      line(x, y, width/2, height/2);
    }
  }
}*/



/*void setup(){
  size(800,500);
  println("sono nel setup");
  frameRate(2);
}

//Linee speculari
void draw(){
  background(255);
  //println("sono nel draw, sono passati "+frameCount+" fotogrammi");
  for(int i=20; i<400; i+=20){
    stroke(0,0,255);
    line(i, 0, i+i/2, height/2);
    stroke(255,0,0);
    line(i+i/2,height/2, i, height);
    stroke(0,255,0);
    line(30, i, 80, i);
  }
}*/

//Gestione tempo
/*void setup(){
  size(500,500);
  println("sono nel setup");
  frameRate(2);
}

void draw(){
  background(0);
  println("sono nel draw, sono passati "+frameCount+" secondi");
  if(millis()>=5000){ //millisecondi
    ellipse(width/2, height/2, 50,50);
  }
}*/
