ArrayList<Fiore> fiori;
ArrayList<Ape> api;

void setup(){
  size(600, 400);
  fiori = new ArrayList<Fiore>();
  api = new ArrayList<Ape>();
  reset();
}

void draw(){
  background(200,240,200);
  for(Fiore f : fiori){
    f.display();
  }
  
  for(Ape a : api){
    a.display();
    a.move();
    a.interagisci(fiori);
  }
}

void reset(){
  fiori.clear();
  api.clear();
  for(int i = 0; i < 5; i++){
    fiori.add(new Fiore(random(width), random(height), random(30, 60)));
  }
  
  for(int i = 0; i < 2; i++){
    api.add(new Ape(random(width), random(height), random(-2,2), random(-2,2)));
  }
}

void keyPressed(){
  if(key == 'f' || key == 'F'){
    fiori.add(new Fiore(random(width), random(height), 40));
  }
  
  if(key == 'a' || key == 'A'){
    api.add(new Ape(random(width), random(height), random(-2,2), random(-2,2)));
  }
  
  if(key == 'r' || key == 'R'){
    reset();
  }
}
