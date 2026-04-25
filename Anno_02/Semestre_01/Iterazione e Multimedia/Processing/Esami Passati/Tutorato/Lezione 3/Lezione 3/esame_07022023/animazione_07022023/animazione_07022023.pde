ArrayList <Casa> c;

void setup(){
  size(500,500);
  c = new ArrayList<Casa>();
}
    
void draw(){
  background(0);
  for(Casa i: c)
    i.display();
}

void keyPressed(){
  if(key=='r' || key=='R')
    setup();
}

void mousePressed(){
  if(mouseButton==LEFT)
    c.add(new Casa());
  if(mouseButton==RIGHT)
    c.add(new Casetta());
}
