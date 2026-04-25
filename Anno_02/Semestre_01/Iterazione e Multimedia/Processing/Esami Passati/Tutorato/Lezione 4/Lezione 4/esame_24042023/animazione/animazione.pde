ArrayList<Voto> v;

void setup(){
  size(500,500);
  v = new ArrayList<Voto>();
}

void draw(){
  background(0);
  for(Voto i : v)
    i.display();
}

void keyPressed(){
  if(key=='r' || key=='R')
    setup();
}

void mousePressed(){
  if(mouseButton==LEFT)
    v.add(new Voto());
  if(mouseButton==RIGHT)
    v.add(new Votone());
}
