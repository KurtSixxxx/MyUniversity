void setup(){
  size(1000,1000);
  background(255);
}


void draw(){
  fill(255,50);
  noStroke();
  rect(0,0, width, height);
  fill(0,255,0);
  ellipse(mouseX, mouseY, 50, 50);
}
/*void setup(){
   size(500,500);
}

void draw(){
  background(125);
  //ellipse(mouseX, mouseY, 20, 20);
  arc(50,55,50,50,0,HALF_PI);
  strokeWeight(3);
  arc(width/2, height/2, 150, 150, 0, PI+QUARTER_PI, PIE);
  arc(width/2, 50, 150, 250, 0, PI, PIE);
}*/

/*size(500,500);
background(255);
line(10,10,width-10, height-10);
stroke(255,0,0);
strokeWeight(10);
point(10,10);
point(width-10, height-10);*/


/*size(500,500);
background(255);
fill(10, 255, 40);
//rectMode(CENTER);
rect(width/2, height/2, 200,200);
ellipseMode(CORNER);
fill(255);
ellipse(width/2, height/2, 200, 200);*/

/*size(500,500);
background(125);
colorMode(RGB, 10, 255, 40);
fill(10, 255, 40);
//rectMode(CENTER);
//rectMode(CORNER);
//rectMode(CORNERS);
rectMode(RADIUS);
rect(width/2, height/2, 200, 200);*/

/*size(500,500);
background(125);
colorMode(RGB, 10, 255, 40);
fill(10, 255, 40);
rectMode(CENTER);
rect(width/2, height/2, 200,200); //width e height sono più comodi(cose che so già)*/
