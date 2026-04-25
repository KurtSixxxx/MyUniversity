size(700,500);
background(0);
translate(width/2,(height/2)-50);
scale(1,-1);
float x0 = 0;
float x1 = 75;
float x2 = 350;
float x3 = 0;
float y0 = 0;
float y1 = 200;
float y2 = 0;
float y3 = -200;

fill(255,0,0);
bezier(x0, y0, x1, y1, x2, y2, x3, y3);
bezier(-x0, y0, -x1, y1, -x2, y2, -x3, y3);

strokeWeight(2);
stroke(0,255,0);
line(x0,y0,x1,y1);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x0,y0);
