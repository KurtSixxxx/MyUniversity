size(800,800);
background(#A6E8F5);
stroke(91,167,96);
strokeWeight(3);
line(width/2, 300, width/2, 600);
noStroke();

fill(160,18,153);
ellipseMode(CORNER);
ellipse(width/2, 290, 200, 200);
ellipse(width/2, 110, 200, 200);
ellipse(width/2-200, 290, 200, 200);
ellipse(width/2-200, 110, 200, 200);


//angoli cerchi sinistra destra sopra sotto
fill(193,35,186);
ellipseMode(CENTER);
ellipse(width/2-75,300,170,170);
ellipse(width/2+75,300,170,170);
ellipse(width/2,225,170,170);
ellipse(width/2,375,170,170);


//angoli cerchio centrale
fill(255,88,247);
ellipseMode(CORNER);
ellipse(width/2, 300, 100,100);
ellipse(width/2, 200, 100,100);
ellipse(width/2-100, 300, 100,100);
ellipse(width/2-100, 200, 100,100);

//cerchio centrale
ellipseMode(CENTER);
fill(203,80,80);
ellipse(width/2, 300, 100,100);
