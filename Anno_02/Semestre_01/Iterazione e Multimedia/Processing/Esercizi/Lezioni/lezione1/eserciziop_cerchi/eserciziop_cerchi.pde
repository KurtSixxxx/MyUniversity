size(300, 300);
background(255);

//Linea di mezzo
stroke(0);
line(0, height/2, width, height/2);

//Cerchi
noFill(); //così non riempiamo i cerchi
int x = 100; // Coordinata x fissa per il bordo sinistro di tuti i cerchi
for(int i = 0; i < 7; i++){
  int diametro = 20 + i * 20; // Diametro crescente (20, 40, 60, ...)
  int y = height/2; // Coordinata y fissa (metà altezza)
  
  stroke(0) // Colore del bordo

// Calcola la posizione x del centro del cerchio
    int centerX = x + (diametro / 2); // Centro del cerchio. Questo fa si che il bordo sinistro di ogni cerchio si sovrapponga esattamente alla stessa coordinata x.
    ellipse(centerX, y, diametro, diametro); // Disegna il cerchio
  }
}
