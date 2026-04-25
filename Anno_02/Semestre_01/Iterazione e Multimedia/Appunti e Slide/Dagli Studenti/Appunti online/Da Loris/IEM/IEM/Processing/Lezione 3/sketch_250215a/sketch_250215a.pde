/*int x=100;

void setup(){
  size(500,500);
}

void draw(){
  background(0);
  if(keyPressed && key == CODED){
    if(keyCode == LEFT){
      x-=5;
    }
    if(keyCode == RIGHT){
      x+=5;
    }
  }
  rect(x,height/2, 50,50);
}*/

/*Tasti codificati, keyCode
UP, DOWN, LEFT, RIGHT, ALT, CONTROL, SHIFT */

/*Key oltre le lettere
CODED, BACKSPACE, TAB, ENTER, RETURN, ESC, DELETE*/



//Spostamendo su, giu, sinistra, destra
/*int x=100;
int y=100;

void setup(){
  size(500,500);
}

void draw(){
  background(0);
  rect(x,y, 50,50);
  if(keyPressed){
    if(key =='d'){
      x+=2;
    }else if(key == 'a'){
      x-=2;
    }
  
    if(key=='w'){
      y-=2;
    }else if(key=='s'){
      y+=2;
    }
  }
}*/


//Esempio gestione
float [] d=new float[10];
boolean go=true;
void setup(){
  size(500,500);
  for(int i=0; i<d.length; i++){
    d[i]=i*50;
  }
}

//nel draw conviene farlo solo quando c'è da fare qualcosa di interattivo, di disegnare
void draw(){
  for(int i=d.length-1; i>=0; i--){
    fill(random(255), random(255), random(255));
    ellipse(width/2, height/2, d[i], d[i]);
  }
}

void mouseClicked(){
  go=!go;
  if(go){
    loop();
  }else{
    noLoop();
  }
}

//quando c'è la gestione della pressione del mouse o della tastiera
//meglio gestirle fuori dal setup e dal draw per evitare che ci siano errori
/*void mousePressed(){
  if(mouseButton == LEFT){
    noLoop();
  }
  if(mouseButton == RIGHT){
    loop();
  }
}*/

/*void mousePressed(){ 
  println("P");
}

void mouseReleased(){
  println("R");
}

void mouseClicked(){
  println("C");
}*/

//Gestione tasti Key e Mouse 
/*void setup(){
  size(500,500);
}

void draw(){
  if(keyPressed){
    if (key == 'a' || key == 'A'){
      println("Tasto a");
    }
  }
  
  if(mousePressed){
    if(mouseButton==RIGHT){
      println("ho premuto il destro");
    }
    if(mouseButton==LEFT){
      println("ho premuto il sinistro");
    }
  }
}

void mousePressed(){ 
  println("P");
}

void mouseReleased(){
  println("R");
}

void mouseClicked(){
  println("C");
}*/








//Funzione random
/*size(500,500);
background(0,255,0);
noStroke();

int l=50;
for(int y=0; y<=height; y+=l){
  for(int x=0; x<=width; x+=l){
    fill(random(255), 130);
    rect(x+random(-5,5),y+random(-5,5),l,l);
  }
}*/




/*int d=40;

void setup(){
  size(600,600);
  noStroke();
  colorMode(RGB, width); //gestione del colore 
}

void draw(){
  background(0);
  for(int y=0; y<=height; y+=d){
    for(int x=0; x<=width; x+=d){
      if(dist(x,y,mouseX, mouseY)<d/2){
        fill(x,y,width);
      }else{
        fill(x,y,0);
      }
      ellipse(x,y,d,d);
    }
  }
}*/
