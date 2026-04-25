size(1000,500);// larghezza - altezza
background(255,255,0);// colore di sfondo


//esercizio frecce
/*
int larghezza_freccia=150;
for(int x=0;x<width;x+=50)
{
 
  if((x+larghezza_freccia)<=width)
  {
    println(x);
     line(x,0,x+larghezza_freccia,height/2);
    line(x,height,x+larghezza_freccia,height/2); 
  }
  
}*/


//forma generica
/*beginShape();//obbligatoria
vertex(120,80);
vertex(230,80);
vertex(230,190);
vertex(340,190);
vertex(340,300);
vertex(120,300);
endShape(CLOSE);//obbligatoria
*/




//strokeJoin
/*strokeWeight(20);
rect(50,25,70,70);
strokeJoin(ROUND);
rect(150,25,70,70);
strokeJoin(BEVEL);
rect(250,25,70,70);
strokeJoin(MITER);
rect(350,25,70,70);*/



//strokeCap
/*strokeWeight(35);
line(50,25,150,150);
strokeCap(SQUARE);
line(150,25,250,150);
strokeCap(ROUND);
line(250,25,350,150);
strokeCap(PROJECT);
line(350,25,450,150);*/


//variabili
/*noStroke();
color yellow=#ffff00;
color red=color(255,0,0);
color green=color(0,255,0);
fill(yellow);
ellipse(150,150,50,50);
fill(green);
ellipse(250,150,50,50);
fill(red);
ellipse(350,150,50,50);
color green_copy=get(170,150);
fill(green_copy);
ellipse(450,150,50,50);*/


/*noStroke();
noFill();
stroke(0);
ellipseMode(CENTER);//modalità di interpretazione dei parametri di ellipse
ellipse(150,150,120,120);
rect(150,150,150,150);*/


/*strokeWeight(25);//grandezza del tratto
rect(100,100,200,200);//rettangolo*/



//canale alpha
/*
fill(255,0,0);//riempimento
ellipse(75,75,150,150);
fill(255,255,0,125);
//noFill();//no riempimento
ellipse(75+75,75,150,150);*/


//esempio mirino
/*noStroke();
fill(0);
ellipse(width*0.5,height/2,150,150);
fill(255);
ellipse(width/2,height/2,125,125);
fill(0);
ellipse(width/2,height/2,100,100);
fill(255);
ellipse(width/2,height/2,75,75);
fill(0);
ellipse(width/2,height/2,50,50);
fill(255);
ellipse(width/2,height/2,25,25);*/




/*point(100,100); //parametri coordinate
fill(255,0,0);//riempimento rosso
noStroke();//tratto trasparente
//ellipse(100,100,250,250);//ellisse x1,x2,d1,d2
stroke(255,0,0);//colore del tratto
line(0,0,width,height);//linea x1,y1,x2,y2
println(width);
println(height);*/
