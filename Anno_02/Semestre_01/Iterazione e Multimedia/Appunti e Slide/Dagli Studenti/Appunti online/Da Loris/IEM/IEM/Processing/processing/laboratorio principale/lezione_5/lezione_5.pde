/*esempio 1: rotazione figura rettangolo con rilascio ombra
void setup(){
  size(500,500);
  rectMode(CENTER);
}

void draw(){
  translate(width/2,height/2);
  rotate(radians(frameCount%360));
  translate(50,50);
  rotate(radians(frameCount*10%360));
  fill(frameCount*3%255,frameCount*7%255,frameCount*5%255);
  rect(0,0,100,100);
}
*/
/*esempio 2: quadrato a rotazione diverse
int a1 = 0;
int a2 = 0;

void setup(){
  size(500,500);
  rectMode(CENTER);
}

void draw(){
  background(0);
  pushMatrix();
  translate(width/2,height/2);
  rotate(radians(a1));
  fill(255);
  rect(0,0,50,50);
  popMatrix();
  pushMatrix();
  translate(width/2+80,height/2);
  rotate(radians(a2));
  fill(255,0,0);
  rect(0,0,50,50);
  popMatrix();
  a1+=1;
  a2+=4;//per controllare la rotazione
}
*/
/*rotazione/rivoluzione*/
/*esempio 3:orologio che ruota
void setup(){
  size(500,500);
}

void draw(){
  background(0);
  translate(width/2,height/2);
  fill(255);
  noStroke();
  rotate(millis()*0.001*TWO_PI/10);
  translate(80,0);
  rotate(millis()*0.001*TWO_PI);
  ellipse(0,0,100,100);
  strokeWeight(5);
  stroke(255,0,0);
  line(0,0,20,0);
}
*/
/*esempio 4:rotazione quadrato
int a = 0;
void setup(){
  size(500,500);
  rectMode(CENTER);
}

void draw(){
  background(0);
  translate(width/2,height/2);
  rotate(radians(a));
  fill(255);
  rect(0,0,50,50);
  a++;
}
*/
/*esempio 5: font simile a programma word, programma di scrittura
PFont f;
String input="";
String saved="";

void setup(){
  size(500,500);
  f=createFont("Calibri",16);
  textFont(f);
  fill(0);
}

void draw(){
  background(255);
  text("Scrivi sulla canvas, invio per salvare",25,40);
  text("Input:"+input,25,190);
  text("Testo salvato:"+saved,25,300);
}

void keyPressed(){
  if(key=='\n'){
    saved = input;
    input="";
  }else{
    input=input+key;
  }
}
*/
/*esempio 6:contenitore di testo
size(500,500);
fill(0,100,150);
textSize(40);
String x="Una stringa più lunga di una singola parola";
text(x,10,40,100,220);
*/
/*esempio 8: allinamento testo sinistra,centro,destra(riporta i caratteri che scrivo)
void setup(){
  size(800,800);
  textSize(64);
  println(RIGHT);
  println(LEFT);
}

void draw(){
  background(0);
  textAlign(RIGHT);
  text(key,60,80);
  
  textAlign(CENTER);
  text(key,60,180);
  
  textAlign(LEFT);
  text(key,60,280);
}
*/
/*esempio 9: caricamento font
PFont cs;
cs = loadFont("ComicSansMS-55.vlw");
textFont(cs);
text("Comic Sans MS - 55",10,180);
*/
/*esempio 10: textFont
size(500,500);
background(0);
PFont c,a;
a = createFont("Arial",50);
c = createFont("Times New Roman",20);


textFont(a);
text("XXXXXX",10,70);

textFont(c);
text("YYYYYY",10,70);
*/
/*esempio 11: text size,color,ecc.
size(500,500);
background(255);
textSize(70);
text("word",10,70);
fill(0,100,150);
text("word",10,140);
fill(0,100,150,50);
text("word",10,210);
*/
