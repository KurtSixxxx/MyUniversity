```java
// ==========================================
// 1. MAN: STRUTTURA DEL MAIN
// ==========================================

// DICHIARAZIONE: Creiamo il riferimento alla lista dinamica
// Sintassi: ArrayList <TIPO> nome_variabile;
ArrayList<Oggetto> lista; 

void setup() {
  size(800, 600); // Impostiamo la canvas [cite: 127, 236]
  
 // INIZIALIZZAZIONE: Allocazione fisica della memoria (malloc)
  lista = new ArrayList<Oggetto>(); 
}

void draw() {
  background(0); // Pulizia dello schermo (background o scia)
  
 // CICLO DI ESECUZIONE: Per ogni 'o' contenuto in 'lista'
  for (Oggetto o : lista) {
    o.run(); // Chiamata al cervello dell'oggetto
  }
}

void mousePressed() {
  // CREAZIONE: Aggiunge un nuovo esemplare alla lista
  // 'new' alloca l'oggetto e chiama il suo costruttore
  lista.add(new Oggetto(mouseX, mouseY, 30, random(-5, 5))); 
}

void keyPressed() {
  // RESET: Svuota l'intera lista dalla memoria
  if (key == 'r' || key == 'R') {
    lista.clear(); 
  }
}

// ==========================================
// 2. MAN: STRUTTURA DELLA CLASSE MADRE
// ==========================================

class Oggetto {
  // ATTRIBUTI: Le variabili interne (la struct in C)
  float x, y, s, vx; 

  // COSTRUTTORE: Inizializza l'oggetto quando nasce
  Oggetto(float x, float y, float s, float vx) {
    this.x = x;  // 'this' risolve l'ambiguità tra attributo e parametro
    this.y = y;
    this.s = s;
    this.vx = vx;
  }

  // METODI: Le azioni che l'oggetto sa compiere
  void display() {
  // Codice per disegnare la forma (rect, ellipse, etc.)
  }

  void move() {
    x += vx; // Aggiornamento della posizione (fisica)
  }

  void bounce() {
  // Inversione della velocità ai bordi
    if (x < s/2 || x > width - s/2) {
      vx = -vx;// Invertiamo il segno della velocità
    }
  }

  // CERVELLO: Raggruppa le funzioni in ordine logico
  void run() {
    move();
    bounce();
    display(); // Prima calcoliamo, poi disegniamo
  }
}
```

