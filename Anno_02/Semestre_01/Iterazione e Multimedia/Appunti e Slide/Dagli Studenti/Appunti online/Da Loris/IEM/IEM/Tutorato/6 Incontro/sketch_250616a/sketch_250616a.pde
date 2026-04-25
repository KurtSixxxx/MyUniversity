ArrayList <Aquilone> a;
float x, y, v, d;
void setup(){
  size(512, 512);
  a = new ArrayList <Aquilone>();
}

void draw(){
  background(#00ffff);
  for(Aquilone i : a){
    i.display();
  }
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    setup();
  }
}

void mousePressed(){
  d = random(30, 50);
  x = random(d/2, width-d/2);
  y = random((d/2)*1.5, height - (d/2)*1.5);
  v = random(-5, 5);
  if(mouseButton == LEFT){
    a.add(new Aquilone(x, y, v, d));
  }else if(mouseButton == RIGHT){
    a.add(new ReverseAquilone(x, y, v, d));
  }
}
