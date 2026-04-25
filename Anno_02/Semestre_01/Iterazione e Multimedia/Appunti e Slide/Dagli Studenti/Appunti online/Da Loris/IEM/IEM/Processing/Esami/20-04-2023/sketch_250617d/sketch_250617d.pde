ArrayList <Voto> v;
float x,y,velx;

void setup(){
  size(500,500);
  v = new ArrayList<Voto>();
}

void draw(){
  background(0);
  x = random(width);
  y = random(height);
  velx = random(2,10);
  for(Voto v : v){
    v.display();
  }
}

void keyPressed(){
  if(key=='r'||key=='R'){
    setup();
  }
}

void mousePressed(){
  if(mouseButton == LEFT){
    v.add(new Voto(x, y, velx));
  }else if(mouseButton == RIGHT){
    v.add(new Votone(x,y,velx));
  }
}
