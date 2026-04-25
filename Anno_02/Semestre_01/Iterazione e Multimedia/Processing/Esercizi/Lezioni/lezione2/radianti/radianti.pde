size(800,800);
background(0);
fill(255,255,0);
//0-90
arc(100,height/2,100,100,0,HALF_PI);
//0-270
arc(200,height/2,100,100,0,PI+HALF_PI);
//errore PI>0
arc(300,height/2,100,100,PI,0); //Il primo parametro deve essere sempre più piccolo

arc(400,height/2,100,100,PI,TWO_PI);

arc(500,height/2,100,100,PI,2*PI);

arc(600,height/2,100,100,QUARTER_PI,HALF_PI);
//0-30
arc(700,height/2,100,100,0,radians(30));
  
