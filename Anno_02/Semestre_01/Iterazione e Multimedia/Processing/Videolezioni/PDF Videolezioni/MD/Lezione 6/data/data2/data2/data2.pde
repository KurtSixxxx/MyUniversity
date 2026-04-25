//MODIFICHIAMO LA COMPONENTE DI ROSSO DI UN'IMMAGINE
PImage I;
float r,g,b; //il valore di ogni componente
color c,c1; //due colori
int vr; //variazione di rosso, perché vogliamo variare la componente di rosso

void setup(){
  I=loadImage("lena.png");
  size(512,512);
  vr=0;
}

void draw(){
  image(I,0,0);
}

void keyPressed(){
  //Vogliamo fare che se premiamo r sottraiamo componente di rosso, con R invece aggiungiamo componente di rosso
  if(key=='r'){
    vr--;
  }else if(key=='R'){
    vr++;
  }
  println(vr);

  //A questo punto vogliamo cambiare il valore di rosso per ogni pixel dell'immagine. Come? O abbiamo un for che scorre ogni riga e colonna e usiamo un get che preleva ogni valore.
  //Oppure usiamo la matrice di pixel, che è un metodo differente da quello sopra, che rende una matrice bidimensionale in una monodimensionale chimata "matrice linearizzata"
  //Per farlo facciamo così:
  I.loadPixels(); //in questo caso all'interno di I ci sarà una struttura dati array chiamata Pixels che non è altro che è un array che è la matrice linearizzata della matrice immagine
  for(int i = 0; i < I.pixels.length; i++){
    c1 = I.pixels[i];
    c1 = color(red(c1)+vr, green(c1), blue(c1));
    I.pixels[i]=c1;
  }
  I.updatePixels(); //forziamo l'aggiornameto della matrice di pixel  
}
