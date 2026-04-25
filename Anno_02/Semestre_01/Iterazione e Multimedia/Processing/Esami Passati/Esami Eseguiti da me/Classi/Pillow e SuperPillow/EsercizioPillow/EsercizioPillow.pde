Pillow pillow;
SuperPillow sup;

void setup(){
  size(256,512);
  reset();
}

void draw(){
  background(0);
  pillow.run();
  sup.run();
}

void reset(){
  pillow = new Pillow();
  sup = new SuperPillow(); 
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    reset();
  }
}
