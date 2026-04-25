//Map è una funzione di mappatura, permette in un determinato intervallo di trovare il valore voluto 
//map(x,1,10,1,100) dove x è il valore che passo io, 1 10 è il range della linea, 1 100 ritornerà il punto voluto in un'altra linea

//Lerp è interpolazione a tutti gli effetti, trova tutti i valori di una qualsiasi figura al tempo voluto
//lerp(c-a,d-b,t) dove t è il tempo 

//hanno la stessa formula gestita in modi diversi

//esempio di Lerp

float x, y;

void setup(){
  size(1000,1000);
  noStroke();
  background(0);
}

void draw(){
  fill(0,25);
  rect(0,0,width, height);
  x=lerp(x,mouseX, 0.2);
  y=lerp(y, mouseY, 0.2);
  fill(255);
  ellipse(x,y,100,100);
} 


/*size(500,500);
background(255);

int x1=150;
int y1=100;
int x2=800;
int y2=900;
strokeWeight(5);
line(x1,y1,x2,y2);
for(int i=0; i<=10; i++){
  float x=lerp(x1,x2, i/10.0)+200;
  float y=lerp(y1,y2, i/10.0)+200;
  point(x,y);
}*/
