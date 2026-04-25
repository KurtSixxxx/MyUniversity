ArrayList <Casa> Case;

void setup(){
  size(500,500);
  Case = new ArrayList<Casa>();
}

void draw(){
  background(0);
  for(Casa c : Case){
    c.run();
  }
}

void mousePressed(){
  float size = 30;
  if(mouseButton == LEFT){
    Case.add(new Casa(random(size, width-size), random(size, height-size), random(2,10), size));
  }
  if(mouseButton == RIGHT){
    Case.add(new Casetta(random(size, width-size), random(size, height-size), random(2,10), size));
  }
}
