/*schiaccio g o n e spuntano delle palline*/
/* ordinare i file in base a applicazione, file che contiene setup e draw deve essere il primo*/
ArrayList <Ball> ab;

void setup(){
  size(800,500);
  ab = new ArrayList <Ball> ();
}

void draw(){
  background(0);
  for(Ball b:ab){
    b.run();
  }
}

void keyPressed(){
  if(key=='n'){
    ab.add(new GreenBall(random(35,width-35),random(35,height-35),random(30,70),random(1,10),random(1,10)));
  }
  if(key=='g'){
    ab.add(new GreenBall(random(35,width-35),random(35,width-35),random(30,70),random(1,10),random(1,10)));
  }
  
}
