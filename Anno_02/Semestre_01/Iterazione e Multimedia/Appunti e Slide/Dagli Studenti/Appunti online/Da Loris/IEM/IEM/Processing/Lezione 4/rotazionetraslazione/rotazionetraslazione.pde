int x=0;

void setup(){
  size(500,500);
  rectMode(CENTER);
}

void draw(){
  background(255);
  
  //push e pop matrix servono per separare il codice dal resto, tutto quello che viene messo dentro si ferma li e non vale per le altre figure
  pushMatrix();
  translate(x+300,200);
  rotate(radians(frameCount));
  fill(0,255,0);
  rect(0,0,40,40);
  popMatrix();
  
  pushMatrix();
  translate(x+100, 200);
  rotate(radians(frameCount));
  fill(255,0,0);
  rect(0,0,40,40);
  popMatrix();
  
  x++; //questo per spostare i quadratini
}




/*void setup(){
  size(500,500);
}

void draw(){
  background(0);
  translate(width/2, height/2);
  fill(255,255,0);
  ellipse(0,0,30,30);
  rotate(millis()*0.001*TWO_PI/10); //rivoluzione attorno al sole
  translate(80,0);
  rotate(millis()*0.001*TWO_PI); //velocità di rotazione
  
  fill(255);
  noStroke();
  ellipseMode(CENTER);
  ellipse(0,0,30,30);

  strokeWeight(5);
  stroke(255,0,0);
  line(0,0,40,40);
}*/



/*int a=0;
void setup(){
  size(500,500);
  frameRate(30);
  rectMode(CENTER); //in modo che il rettangolo giri intorno a se stesso
}

void draw(){
  background(0);
  translate(width/2, height/2); //cambia il sistema di riferimento
  rotate(radians(a)); //ruota la canvas da solo, bisonga fare la translate
  fill(255);
  rect(0, 0, 50,50); //attenzione alle coordinate
  fill(255,0,0);
  rect(60,30,50,50);
  a++;
}*/
