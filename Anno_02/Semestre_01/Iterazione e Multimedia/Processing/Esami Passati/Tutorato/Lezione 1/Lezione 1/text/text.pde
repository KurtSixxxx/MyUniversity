String abcd = "ABCD";
String efgh = "EFGH";
String ijkl = "IJKL";
float w1,w2,w3;
float ha,hd;

size(400, 400);
background(0);
noFill();
textSize(70);
w1 = textWidth(abcd);
w2 = textWidth(efgh);
w3 = textWidth(ijkl);
ha = textAscent();
hd = textDescent();

textAlign(RIGHT);
rectMode(CORNERS);
text(abcd, 200, 120);
stroke(0,255,0);
strokeWeight(1);
rect(200-w1, 120-ha, 200, 120);
stroke(255,0,0);
strokeWeight(5);
point(200,120);

textAlign(CENTER, CENTER);
rectMode(CENTER);
text(efgh, 200, 200);
stroke(0,255,0);
strokeWeight(1);
rect(200, 200, w2, ha);
stroke(255,0,0);
strokeWeight(5);
point(200,200);

textAlign(LEFT, TOP);
rectMode(CORNER);
text(ijkl, 200, 280);
stroke(0,255,0);
strokeWeight(1);
rect(200, 280, w3, ha);
stroke(255,0,0);
strokeWeight(5);
point(200,280);
