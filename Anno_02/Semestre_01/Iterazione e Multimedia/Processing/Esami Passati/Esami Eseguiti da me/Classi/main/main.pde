Stain myStain;
Sponge mySponge;

void setup(){
  size(700,700);
  myStain = new Stain();
}

void draw(){
   background(0,0,55); 
   myStain.run();
   mySponge.display();
   boolean value = mySponge.absorb(myStain);
   
   if(value == true){
     //Rimuovi
   }
}

void keyPressed(){
  if(key == 'S' || key == 's'){
    myStain = new Stain();
    myStain.posX = random(50,650);
    myStain.posY = -30;
    myStain.D = random(10,50);
    myStain.c = int(random(0,255));
  }
  
  if(key == 'R' || key == 'r'){
      mySponge = new Sponge();
      mySponge.L = 30;
      mySponge.c = color(200,200,100);
  }
}

class Stain {  
 float n1 = random(0,255);
 float n2 = random(0,255);
 float n3 = random(0,255);
  
  //Attributi
  float posX, posY;
  float D;
  color c;
  
  //Costruttore
  Stain(){
    this.posX = random(-1,1);
    this.posY = random(0,4);
    this.D = 20;
    this.c = color(n1,n2,n3);
  }
  
  //Metodi
  void display(){
    noStroke();
    fill(c);
    circle(posX, posY, D);
  }
  
  void move(){
    posX += 1;
    posY += 1;
  }
  
  void run(){
    display();
    move();
  }
}

class Sponge{
    
  //Attributi
  float posX, posY;
  float L;
  color c;
  
  //Costruttore
  Sponge(){
    this.posX = mouseX;
    this.posY = mouseY;
    this.L = 30;
    this.c = color(200,200,100);
  }
  
  //Metodi
  void display(){
    noFill();
    fill(c);
    rectMode(CENTER);
    square(posX,posY,L);
  }
  
  boolean absorb(Stain s){
    if(dist(mouseX,mouseY,posX,posY)<=0){
      L += s.D/2;
      c = color(int((s.c + c)/2));
      return true;
    }else{
      return false;
    }
  }

}
