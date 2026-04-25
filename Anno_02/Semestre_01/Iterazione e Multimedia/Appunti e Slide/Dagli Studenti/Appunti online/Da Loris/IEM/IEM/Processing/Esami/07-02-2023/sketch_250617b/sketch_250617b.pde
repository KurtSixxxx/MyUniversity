ArrayList <Casa> c;
float x, y, velx;
void setup(){
  size(500,500);
  c = new ArrayList <Casa>();
}

void draw(){
  background(0);
  x = random(width);
  y = random(height);
  velx = random(2,10);
  for(Casa c : c){
    c.display();
  }
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    setup();
  }
}

void mousePressed(){
  if(mouseButton == LEFT){
    c.add(new Casa(x, y, velx));
  }else if(mouseButton == RIGHT){
    c.add(new Casetta(x,y,velx));
  }
}
