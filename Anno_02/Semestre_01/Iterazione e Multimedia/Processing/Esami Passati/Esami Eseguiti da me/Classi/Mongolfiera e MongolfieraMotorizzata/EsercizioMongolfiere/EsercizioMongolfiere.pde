Mongolfiera mongolfiera;
MongolfieraMotorizzata mongolfieramotorizzata;

void setup(){
  size(512,512);
  reset();
}

void draw(){
  background(255);
  
  mongolfiera.run();
  mongolfieramotorizzata.run();
  
  stroke(0);
  strokeWeight(3);
  line(0, height/2, width, height/2);
}


void reset(){
  mongolfiera = new Mongolfiera();
  mongolfieramotorizzata = new MongolfieraMotorizzata();
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    reset();
  }
}
