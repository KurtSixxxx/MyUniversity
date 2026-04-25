size(700,700);

beginShape();
fill(153,176,180);
vertex(180,82);
vertex(207,36);
vertex(214,63);
vertex(407,11);
vertex(412,30);
vertex(219,82);
vertex(226,109);
endShape(CLOSE);


/*strokeWeight(12);
rect(60,25,70,70);
strokeJoin(ROUND);
rect(160,25,70,70);
strokeJoin(BEVEL);
rect(260,25,70,70);
strokeJoin(MITER); //quello di default
rect(360,25,70,70);*/

//Linea
/*line(60,25,130,95);
strokeCap(SQUARE);
line(160,25,230,95);
//differenza tra square e project è che per square lo mette in base allo strokeweight
//per project lo proietta per 12 sopra e 12 sotto, semore in base allo strokeweight 
//(se fosse stato 50, avrebbe messo 25 sopra e 25 sotto)
strokeCap(PROJECT);
line(260,25,330,95);
strokeCap(ROUND); //default
line(360,25,430,95);*/

//Colori
/*color c1=color(204,154,0);
color c2=#FFCC00;
noStroke();
fill(c1);
rect(0,0,40,height);
fill(c2);
rect(40,0,40,height);
stroke(0);
color c3=get(width/2,height/2); //prende il colore che c'è in quel pixel
fill(c3);
rect(80,0,40,height);*/

//ellipseMode()
/*noFill();
rect(50,60,80,80);
ellipse(50,60,80,80);
ellipseMode(CORNER);
rect(150,60,80,80);
ellipse(150,60,80,80);
ellipseMode(RADIUS);
rect(250,60,80,80);
ellipse(250,60,80,80);
//CENTER è di default
ellipseMode(CENTER);
rect(350,60,80,80);
ellipse(350,60,80,80);
ellipseMode(CORNERS);
rect(450,60,80,80);
ellipse(450,60,550,160);*/




//Trasparenza
/*noFill();
strokeWeight(5);
//fill(255,0,0,160);
ellipse(132,82,200,200);
//fill(0,255,0,160);
ellipse(228,-16,200,200);
//fill(0,0,255,160);
ellipse(268,118,200,200);*/



//LINEE E CERCHI
/*stroke(255,0,0);
line(0,0,width,height); //i primi due punti da dove inizia, gli altri due dove finisce
noStroke();
ellipse(width/2,height/2,50,50); //primi due punti le coordinate, le altre due la grandezza*/
