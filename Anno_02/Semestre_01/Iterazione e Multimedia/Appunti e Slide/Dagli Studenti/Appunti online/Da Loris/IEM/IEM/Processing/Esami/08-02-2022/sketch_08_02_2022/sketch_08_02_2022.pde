ArrayList <Cifra> c;

void setup(){
  size(500,500);
  c = new ArrayList <Cifra>();
}

void draw(){
  background(0);
  for(Cifra c : c){
    c.display();
  }
}

void keyPressed(){
  if(key>='1' && key <='4'){
    c.add(new Cifra(key));
  }else if(key>='5' && key <='9'){
    c.add(new Cifrotta(key));
  }
}
