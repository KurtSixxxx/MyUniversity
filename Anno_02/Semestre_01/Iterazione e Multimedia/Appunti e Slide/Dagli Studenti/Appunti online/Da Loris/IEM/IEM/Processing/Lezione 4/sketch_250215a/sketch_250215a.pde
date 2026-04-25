/*PFont f;
String scrivendo="";
String salvata="";

void setup(){
  size(500,500);
  f=createFont("Calibri", 16);
}

void draw(){
  background(255);
  int ind=25;
  textFont(f);
  fill(0);
  text("Click sulla finestra e scrivi.\nPremi invio per salvare.", ind, 40);
  text("Input: "+scrivendo, ind, 190);
  text("Testo salvato: "+salvata, ind, 230);
}

void keyPressed(){
  if(key == '\n'){
    salvata=scrivendo;
    scrivendo="";
  }else if(key==BACKSPACE && scrivendo.length()>0){
    scrivendo=scrivendo.substring(0, scrivendo.length()-1);
  }else{
    scrivendo+=key;
  }
}*/



/*void setup(){
  size(500,500);
  textSize(42);
  fill(0);
  String x= "questa è una frase più lunga di una parola";
  text(x, 10,30,500,500);
}

void draw(){
}*/



/*void setup(){
  size(500,500);
  textSize(64);
  textAlign(CENTER);
}

void draw(){
  background(0);
  text(key, width/2 , height/2);
}*/



//Funzione testo
/*size(500,500);
PFont f, g;
//f=createFont("Chalkboard-Bold-32", 30); //da non utilizzare mai
f = loadFont("Chalkboard-Bold-32.vlw");
g = loadFont("HiraginoSans-W6-32.vlw");
textFont(f);
//textSize(32);
text("clara scema", 10, 30);
fill(0,100,150);
text("clara scema", 10, 60);
fill(255,0,150, 50);
textFont(g);
text("clara scema", 10, 90);*/


/*void setup(){
  size(500,500);
}

void draw(){
  background(255);
  for(int x=20; x<width; x+=20){
    float rum = map(mouseX, 0, width, 0, 12);
    float rumi= random(-rum,+rum);
    float rumf= random(-rum,+rum);
    line(x+rumi, 20, x+rumf, 100);
  }
}

/*void setup(){
  size(500,500);
}*/

/*void draw(){
  background(100);
  fill(255);
  ellipse(width/2, height/2, 50,50);
  fill(0);
  float x=map(mouseX, 0, width, -15,15);
  float y=map(mouseY, 0, height, -15,15);
  ellipse(width/2+x, height/2+y, 5, 5);
}*/


/*void setup(){
  size(700,500);
}

void draw(){
  background(0);
  float r=map(mouseX, 0, width, 20, height/2); //primo argomento x, secondo argomento inputstart, terzo inputend, quarto outputstart, quinto outputend);
  fill(225, r, 0);
  ellipse(width/2, height/2, r,r);
}*/




/*int r=30;
int dir=1;
int x,y;
void setup(){
  size(500,500);
  ellipseMode(RADIUS);
  x=width/2;
  y=height/2;
}

void draw(){
  background(125);
  float d=dist(mouseX, mouseY,x,y);
  if(r>=width/2 || r<30){
    dir=-dir;
  }
  if(d<r){
    r+=dir;
    fill(0);
  }else{
    fill(255);
  }
  ellipse(x,y,r,r);
}*/




/*float [] y;

void setup(){
  size(500,500);
  noStroke();
  y=new float[width*2];
  fill(random(255),random(255),random(255), random(255));
  for(int i=0; i<y.length; i++){
    y[i]=random(-2*height,2/5*height); //iniziano al di fuori della canvas
  }
}

void draw(){
  background(255);
  for(int i=0; i<y.length; i++){
    y[i]++;
    if(y[i]>height){ //questo serve per renderlo infinito
      y[i]=random(-2*height, -30);
    }
    float x=i/2;
    rect(x,y[i],20,30);
  }
}*/
