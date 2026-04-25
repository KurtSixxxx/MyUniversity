Auto auto;
AutoElettrica autoelett;

void setup(){
  size(512,512);
  reset();
}

void draw(){
  background(255);
  auto.run();
  autoelett.run();
}

void reset(){
    auto = new Auto();
    autoelett = new AutoElettrica();
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    reset();
  }
}
