/*void setup(){
  size(500,500);
  stroke(0);
  strokeWeight(10);
  background(255);
}
int d=40;
void draw(){
  if(mousePressed){
    line(pmouseX, pmouseY, mouseX, mouseY);
  }
}

void keyPressed(){
  if(key== 'c' || key=='C'){
    background(255);
  }
  
  if(key== 'r' || key=='R'){
    stroke(255,0,0);
  }
  
  if(key== 'g' || key=='G'){
    stroke(0,255,0);
  }
  
  if(key== 'b' || key=='B'){
    stroke(0,0,255);
  }
}*/

//SCIA CON LERP
float x,y;
float v=3;
void setup(){
  size(500,500);
  noStroke();
  background(0);
}

void draw(){
  fill(0,25);
  rect(0,0,width,height);
  fill(255);
  x=lerp(x, mouseX, 0.05);
  y=lerp(y, mouseY, 0.05);
  ellipse(x, y, 50,50);
}


//lerp()
/*size(500,500);
background(255);
int x1=15;
int y1=10;
int x2=80;
int y2=90;

line(x1,y1,x2,y2);
for(int i=0; i<11; i++){
  float x=lerp(x1,x2,i/10.0);
  float y=lerp(y1,y2,i/10.0);
  stroke(255,0,0);
  strokeWeight(5);
  point(x,y);
}*/
