ArrayList <Cifra> c;

void setup(){
  size(700,700);
  c=new ArrayList<Cifra>();
}

void draw(){
  background(0);
  for(Cifra i : c){
    i.display();
  }
}

void keyPressed(){
  if(key >= '0' && key <= '4'){
    c.add(new Cifra(width, key));
  }
  if(key>='5' && key <= '9'){
    c.add(new Cifrotta(width, key));
  }
  
  if(key == 'r' || key == 'R'){
    setup();
  }
}
