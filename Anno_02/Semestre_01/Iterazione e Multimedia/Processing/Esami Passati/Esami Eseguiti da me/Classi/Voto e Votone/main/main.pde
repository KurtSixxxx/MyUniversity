ArrayList <Voto> vo;

void setup(){
  size(500,500);
  vo = new ArrayList <Voto>();
}

void draw(){
  background(0);
  for(Voto v : vo){
    v.run();
  }
}

void mousePressed(){
  if(mouseButton == LEFT){
    vo.add(new Voto());
  }else if(mouseButton == RIGHT){
    vo.add(new Votone());
  }
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    vo.clear();
  }
}
