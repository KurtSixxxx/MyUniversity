# Template per Esami di Processing

---

## 1° Parte: Animazioni e Classi

La prima parte riguarda sempre la creazione di classi che raffigurano case, monitor, cifre e via dicendo.
Queste classi sono soggette a forze fisiche, come gravità e velocità.

La creazione delle classi viene richiesta in due modi, per ereditarietà oppure come classi distinte.
Vediamo come sviluppare tutto.

### 1. Creazione di una classe

```java
class miaClasse{
    
   //Attributi
    float posizioneX, posizioneY;
    float velocitaX;
    float dimensione;
    
    //Costruttore (vedi appunti sul costruttore sotto)
    miaClasse(float x, float y, float v, float s){
        this.posizioneX = x
        this.posizioneY = y;
        this.velocitaX = v;
        this.dimensione = s;
    }
    
    //Metodi (ossia le funzioni della classe)
    void display(){ //Nei nostri esami la usiamo per far apparire l'oggetto
    	stroke(255,255,255);
        strokeWeight(3);
        noFill();
        ...
    }
    
    void metodo1(){
       ... 
    }
    
    void metodo2(){
        ...
    }
    
    void run(){ //run() è il metodo che usiamo per chiamare tutti i metodi della nostra classe
        display();
        metodo1;
        metodo2;
    }
    
}
```

### 2. Creazione di una classe per ereditarietà

```java
class ClasseEreditaria extends Classe{

  //Costruttore
  ClasseEreditaria(float x, float y, float v, float s){
    super(x,y,v,s); //super è una parola chiave che serve a fare riferimento alla Classe Madre, quindi sta chiamando il costruttore della classe madre.
  }
  
  //Metodi
  void display(){
  stroke(255);
  strokeWeight(3);
  noFill();
  
  size = 30;
  rectMode(CENTER);
  rect(posX,posY, size,size);
  fill(255);
  rect(posX,posY+10, 10,10);
  
  triangle(posX-size/2,posY-size/2, posX,posY-size/2*2, posX+size/2,posY-size/2);
  }
  
  void bounce(){
    if(posX >= width){
      posX = 0;
    }else if(posX <= 0){
      posX = width;
    }
  }
  
  void move(){
    posX -= 1 * vX;
   }
}
```

## 3. Chiamata delle due classi nel 'main' (per eridarietà)

```java
/*Con questa prima linea di codice dichiariamo un contenitore dinamico, equivalente dell'allocazione dinamica di C.
Tra <...> mettiamo i Generics, ossia stiamo dicendo che questa lista contiene esclusivamente oggetti di tipo miaClasse*/
ArrayList <miaClasse> mieClassi;

void setup(){
  size(500,500);
  mieClassi = new ArrayList<miaClasse>();
/*E qui lo iniziaizziamo, diciamo che allochiamo la memori per la lista. Senz questta riga l'ArrayList è 'null' e il programma crasherebbe.*/
}

void draw(){
  background(0);
    /*Questo ciclo si chaiam 'Enhanced For Loop', e stiamo dicendo:
    "per ogni elemento contenuto in mieClassi, chiamalo temporaneamete c ed esegui il codice tra le graffe"*/
  for(miaClasse c : mieClassi){
    c.run(); //e cosi per ogni oggetto chiamiamo il metodo 'run()' che abbiamo detto che chiama tutti gli altri metodi
  }
}
```

## Collegare due classi distinte (che non hanno un legame di parentela/ereditarietà)

Quando due classi non sono legate da ereditarietà (niente `extends`), possono lavorare insieme in due modi: una contiene l'altra (**Composizione**) o una interagisce con l'altra tramite i metodi (**Interazione**).

### 1. Composizione (La Classe A "possiede" la Classe B)

Si usa quando un oggetto fa parte integrante di un altro (es. un Monitor dentro una Casa)

```java
class miaClasseB { // La classe "componente"
  float x, y;
  
  miaClasseB(float x, float y) {
    this.x = x;
    this.y = y;
  }
  
  void display() {
    rect(x, y, 20, 20); // Disegna il componente
  }
}

class miaClasseA { // La classe "contenitore"
  float x, y;
  miaClasseB oggettoB; // Dichiarazione: la Classe A ha un attributo di tipo Classe B

  miaClasseA(float x, float y) {
    this.x = x;
    this.y = y;
    // Inizializzazione: Creiamo l'oggetto B dentro il costruttore di A
    this.oggettoB = new miaClasseB(x + 5, y + 5); 
  }

  void run() {
    rect(x, y, 60, 60); // Disegna il contenitore
    oggettoB.display(); // Chiamata: il contenitore comanda il metodo del componente
  }
}
```

### 2. Interazione (La Classe A "usa" la Classe B)

```java
class miaClasseA {
  float x, y;
  // ... costruttore ...

  // Metodo di interazione: accetta come parametro un OGGETTO di tipo miaClasseB
  void interagisci(miaClasseB b) {
    // Calcoliamo la distanza tra "questo" oggetto (this) e l'oggetto "b" ricevuto
    float d = dist(this.x, this.y, b.x, b.y);
    
    if (d < 50) {
       println("Collisione tra Classe A e Classe B!");
    }
  }
}

```

### 3. Gestione nel Main (Doppio Ciclo)

Per far interagire due liste di oggetti distinti, usiamo un ciclo annidato nel `draw()`.

```java
ArrayList<miaClasseA> listaA;
ArrayList<miaClasseB> listaB;

void setup() {
  size(500, 500);
  listaA = new ArrayList<miaClasseA>();
  listaB = new ArrayList<miaClasseB>();
}

void draw() {
  background(0);

  // Per ogni oggetto A...
  for (miaClasseA a : listaA) {
    a.run();
    
    // ...controlla ogni oggetto B (Interazione tra liste)
    for (miaClasseB b : listaB) {
      a.interagisci(b); // Passiamo l'oggetto b al metodo di a
    }
  }
}

```

---

## 2° Parte: Manipolazione di Immagini

