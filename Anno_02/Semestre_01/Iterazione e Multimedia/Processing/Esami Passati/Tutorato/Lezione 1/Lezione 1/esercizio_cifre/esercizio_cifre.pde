ArrayList<Cifra> c;
Cifra last;

void setup(){
  size(500,500);
  c = new ArrayList<Cifra>();
}

void draw(){
  background(0);
  for(Cifra i : c)
    i.display();
}

void keyPressed(){
  if(key>='0' && key<='9'){
    if(key>='0' && key<='4')
      last = new Cifra(width,key);
    if(key>='5' && key<='9')
      last = new Cifrotta(width, key);
    c.add(last);
  }
  if(key=='R' || key=='r')
    setup();
  if(key=='S' || key=='s')
    stop();
  if(key=='l' || key=='L')
    loop();
  if(key=='n' || key=='N')
    noLoop();
  if(key=='q' || key=='Q')
    exit();
  if(key=='d' || key=='D'){
    c.remove(last);
    if(c.size()>0)
      last = c.get(c.size()-1);
  }
}
