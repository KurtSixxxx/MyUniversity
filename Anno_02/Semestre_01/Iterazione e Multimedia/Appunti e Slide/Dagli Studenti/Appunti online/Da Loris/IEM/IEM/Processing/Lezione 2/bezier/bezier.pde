/*Ha due punti di ancoraggio e due punti di controllo.
Il segmento, per raggiungere i due punti di ancoraggio, cerca di raggiungerli
asintoticamente.*/

//Gestione canvas
/*int w=500;
int h=600;

/*void setting(){
  fullScreen();
}*/

//BEZIER
void setup(){
  size(500,500);
  //fullScreen();
}

void draw(){
  background(255);
  stroke(255,100,0);
  line(185,50,mouseX, mouseY);
  line(190,300,15,290);
  stroke(0);
  bezier(185,50,mouseX,mouseY,190,300,15,290);
  
  
//prende 8 argomenti, con ordine 1(x,y) punto di ancoraggio, 
//1(x,y) punto di controllo
//2(x,y) punto di ancoraggio, 
//2(x,y) punto di controllo 
}
