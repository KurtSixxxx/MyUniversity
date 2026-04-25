Rocket rocket = new Rocket();
RocketPro rocketPro = new RocketPro();

void setup(){
  size(512,512);
  reset();
}

void draw(){
  background(0);
  
  rocket.run();
  rocketPro.run();
}

void reset(){
  rocket = new Rocket();
  rocketPro = new RocketPro();
}


void keyPressed(){
  if(key == 'R' || key == 'r'){
    reset();
  }
}
