# Lezione 5

ripassare lerp(), ossia linear interpolation
lerp(valore iniziale, valore finale, %)
lerp(A, B, 0.5)

#### Shear

`shearX()` e `shearY()` sono funzioni di trasformazione utilizzate per inclinare o distorcere gli oggetti lungo gli assi cartesiani. Queste funzioni "fanno scivolare" i punti di una forma in una direzione specifica, creando un effetto simile a quello di un rettangolo che diventa un parallelogramma.

Ecco come funzionano nello specifico:
* `shearX(angle)`: Inclina il sistema di coordinate lungo l'asse X. Immagina di spingere la parte superiore di un quadrato verso destra o verso sinistra mentre la base rimane fissa. Le linee verticali dell'oggetto diventeranno oblique, mentre quelle orizzontali rimarranno parallele all'asse X.
* `shearY(angle)`: Inclina il sistema di coordinate lungo l'asse Y. In questo caso, le linee orizzontali dell'oggetto diventano oblique, mentre quelle verticali rimangono parallele all'asse Y.

```java
float shX, shY;
float scale;

void setup(){
    size(500,500);
    shX = 0.1;
    shY = 0.1;
    scale = 0.1;
    fill(0,255,0);
    stroke(255,0,0);
    strokeWeight(5);
    rectMode(CENTER);
}

void draw(){
    background(255);
    //Per fare in modo che queste trasformazioni ricadano solo su una figura piuttosto che in tutte, bisogna usare pushMatrix() e popMatrix()
    pushMatrix();
    translate(150,200);
    shearX(shX);
    shearY(shY);
    //scale(scale);
    rect(0,0,50,50);
    popMatrix();
    //scale+=0.1;
    shX+=0.1;
    shY+=0.1;
}
```

Adesso introduciamo le classi.
Abbiamo l'oggetto Ball, e generiamo delle palline che premendo n spawnano e rimbalzano, con p mettiamo in pausa e con s facciamo ripartire.

```java
// MAIN
// Iniziamo dichiarando la lista. In C sarebbe come definire un puntatore a una struttura dinamica.
// La dicitura <Ball> è il "filtro": diciamo alla lista che può contenere solo oggetti Ball o i suoi "figli".
ArrayList <Ball> ab;

void setup(){
  size(800,500);
  
  // INIZIALIZZAZIONE: Qui creiamo fisicamente la "borsa" (la lista) in memoria.
  // Senza il 'new', la variabile 'ab' è vuota (NULL). È come fare una malloc in C: 
  // stiamo chiedendo lo spazio per far esistere la lista.
  ab = new ArrayList <Ball>(); 
}

void draw(){
  // EFFETTO SCIA (Trail): Invece di usare background() che pulisce tutto ogni volta, 
  // disegnamo un rettangolo nero grande quanto lo schermo ma quasi trasparente (opacità 40).
  // I disegni precedenti rimangono sotto, ma vengono "velati" di nero un po' alla volta 
  // fino a sparire, creando l'illusione della scia.
  noStroke();
  fill(0,40);
  rect(0,0,width,height);

  // CICLO FOR-EACH: È un modo rapido per dire a Processing:
  // "Prendi ogni pallina che trovi dentro la lista 'ab', chiamala 'b' per un istante, 
  // e fagli fare quello che c'è scritto tra le graffe".
  for(Ball b : ab){
    // Diciamo alla singola pallina 'b' di attivare la sua routine di vita.
    b.run();
  }
}

void keyPressed(){ 
  // Se premiamo 'n' o 'N', fabbrichiamo una nuova pallina e la infiliamo nella borsa (add).
  if (key == 'n' || key == 'N'){
    // Creiamo una pallina con posizione, dimensione e velocità casuali (random).
    ab.add(new Ball(random(50,450), random(50,450), random(25,70), random(1,10), random(1,10)));
  }
  
  // Lo switch gestisce lo stato della canvas (Pausa o Riparti).
  switch(key){
    case 'p' :{ 
      noLoop(); // Blocca il ciclo draw(): tutto si ferma come in un fermo immagine.
      break;
    }
    
    case 's' :{ 
      loop();   // Riattiva il ciclo draw(): il tempo ricomincia a scorrere.
      break;
    }
    
    default:{}
  }
}

//-----------------------------------------------------------------------------------

// CLASSE BALL
class Ball {
  // ATTRIBUTI: Le caratteristiche fisiche che ogni pallina "sa" di avere.
  float posX, posY, size; 
  float sx, sy; 

  // COSTRUTTORE PRINCIPALE: È il momento in cui la pallina "nasce".
  // Prende i valori che arrivano da fuori e li salva dentro le sue variabili (this).
  Ball(float x, float y, float s, float sx, float sy){ 
    this.posX = x; 
    this.posY = y;
    this.size = s;
    this.sx = sx;
    this.sy = sy;
  }
  
  // SECONDO COSTRUTTORE (Overloading): Per creare palline ferme.
  Ball(float x, float y, float s){ 
    // TRUCCO: Questo 'this(...)' dice a Processing di non riscrivere tutto il codice sopra,
    // ma di usare il costruttore principale passando però 0 come velocità X e Y.
    // È una scorciatoia per dire: "Fai tutto come sopra, ma forzala a stare immobile".
    this(x,y,s,0,0); 
  }
  
  void display(){ 
    fill(128,0,128); // Viola
    noStroke(); 
    ellipse(posX, posY, size, size); // Disegna la forma usando le sue coordinate.
  }
  
  void move(){ 
    // Aggiorniamo la posizione aggiungendo la velocità: lo spazio si percorre nel tempo.
    posX += sx;
    posY += sy;
  }
  
  void bounce(){ 
    // RIMBALZO X: Se tocca il bordo sinistro (0) o destro (width), invertiamo la velocità X.
    if(posX < size/2 || posX > width - size/2){ 
      sx = -sx; 
    }
    
    // RIMBALZO Y: Se tocca il bordo alto (0) o basso (height), invertiamo la velocità Y.
    // Usiamo size/2 perché la coordinata di una pallina è nel centro, quindi dobbiamo contare il raggio.
    if(posY < size/2 || posY > height - size/2){ 
      sy = -sy; 
      // Nota: Qui c'è il rischio teletrasporto se tocca il tetto, ma la logica è:
      // "Se hai colpito un bordo verticale, cambia direzione!"
    }
  }
  
  void gravity(){
    // La gravità è un'accelerazione: aggiunge costantemente un piccolo valore alla velocità Y.
    // Più passa il tempo, più la pallina "cade" velocemente.
    sy += 0.2; 
  }
  
  void run(){ 
    // Questo è il "Cervello": raggruppa tutte le azioni in ordine logico.
    // Prima calcoliamo la fisica, poi mostriamo il risultato.
    gravity();
    move();
    bounce();
    display();
  }
}
```

[Per la versione 1 dei commenti scritta da te vai al path: *`C:\Users\giuli\Desktop\Desktop\Universita\2 Anno\1 Semestre\Iterazione e Multimedia\Processing\Esercizi\Lezione 5\Classi 1\Prova 1 old`*]

Aggiungiamo la cosiddetta "Green Ball", che è semplicemente un immagine con aspetto diverso

```java
//Prova
// Iniziamo dichiarando la lista. In C sarebbe come definire un puntatore a una struttura dinamica.
// La dicitura <Ball> è il "filtro": diciamo alla lista che può contenere solo oggetti Ball o i suoi "figli".
ArrayList <Ball> ab;

void setup(){
  size(800,500);
  
  // INIZIALIZZAZIONE: Qui creiamo fisicamente la "borsa" (la lista) in memoria.
  // Senza il 'new', la variabile 'ab' è vuota (NULL). È come fare una malloc in C: 
  // stiamo chiedendo lo spazio per far esistere la lista.
  ab = new ArrayList <Ball>(); 
}

void draw(){
  // EFFETTO SCIA (Trail): Invece di usare background() che pulisce tutto ogni volta, 
  // disegnamo un rettangolo nero grande quanto lo schermo ma quasi trasparente (opacità 40).
  // I disegni precedenti rimangono sotto, ma vengono "velati" di nero un po' alla volta 
  // fino a sparire, creando l'illusione della scia.
  noStroke();
  fill(0,40);
  rect(0,0,width,height);

  // CICLO FOR-EACH: È un modo rapido per dire a Processing:
  // "Prendi ogni pallina che trovi dentro la lista 'ab', chiamala 'b' per un istante, 
  // e fagli fare quello che c'è scritto tra le graffe".
  for(Ball b : ab){
    // Diciamo alla singola pallina 'b' di attivare la sua routine di vita.
    b.run();
  }
}

void keyPressed(){ 
  // Se premiamo 'n' o 'N', fabbrichiamo una nuova pallina e la infiliamo nella borsa (add).
  if (key == 'n' || key == 'N'){
    // Creiamo una pallina con posizione, dimensione e velocità casuali (random).
    ab.add(new Ball(random(50,450), random(50,450), random(25,70), random(1,10), random(1,10)));
  }
  if (key == 'g' || key == 'G'){
    // Creiamo una pallina con posizione, dimensione e velocità casuali (random).
    ab.add(new GreenBall(random(50,450), random(50,450), random(25,70), random(1,10), random(1,10)));
  }
  
  // Lo switch gestisce lo stato della canvas (Pausa o Riparti).
  switch(key){
    case 'p' :{ 
      noLoop(); // Blocca il ciclo draw(): tutto si ferma come in un fermo immagine.
      break;
    }
    
    case 's' :{ 
      loop();   // Riattiva il ciclo draw(): il tempo ricomincia a scorrere.
      break;
    }
    
    default:{}
  }
}

//-----------------------------------------------------------------------------------
//Ball
class Ball {
  // ATTRIBUTI: Le caratteristiche fisiche che ogni pallina "sa" di avere.
  float posX, posY, size; 
  float sx, sy; 

  // COSTRUTTORE PRINCIPALE: È il momento in cui la pallina "nasce".
  // Prende i valori che arrivano da fuori e li salva dentro le sue variabili (this).
  Ball(float x, float y, float s, float sx, float sy){ 
    this.posX = x; 
    this.posY = y;
    this.size = s;
    this.sx = sx;
    this.sy = sy;
  }
  
  // SECONDO COSTRUTTORE (Overloading): Per creare palline ferme.
  Ball(float x, float y, float s){ 
    // TRUCCO: Questo 'this(...)' dice a Processing di non riscrivere tutto il codice sopra,
    // ma di usare il costruttore principale passando però 0 come velocità X e Y.
    // È una scorciatoia per dire: "Fai tutto come sopra, ma forzala a stare immobile".
    this(x,y,s,0,0); 
  }
  
  void display(){ 
    fill(255,255,0); // Viola
    noStroke(); 
    ellipse(posX, posY, size, size); // Disegna la forma usando le sue coordinate.
  }
  
  void move(){ 
    // Aggiorniamo la posizione aggiungendo la velocità: lo spazio si percorre nel tempo.
    posX += sx;
    posY += sy;
  }
  
  void bounce(){ 
    // RIMBALZO X: Se tocca il bordo sinistro (0) o destro (width), invertiamo la velocità X.
    if(posX < size/2 || posX > width - size/2){ 
      sx = -sx; 
    }
    
    // RIMBALZO Y: Se tocca il bordo alto (0) o basso (height), invertiamo la velocità Y.
    // Usiamo size/2 perché la coordinata di una pallina è nel centro, quindi dobbiamo contare il raggio.
    if(posY < size/2 || posY > height - size/2){ 
      sy = -sy; 
      // Nota: Qui c'è il rischio teletrasporto se tocca il tetto, ma la logica è:
      // "Se hai colpito un bordo verticale, cambia direzione!"
    }
  }
  
  void gravity(){
    // La gravità è un'accelerazione: aggiunge costantemente un piccolo valore alla velocità Y.
    // Più passa il tempo, più la pallina "cade" velocemente.
    sy += 0.2; 
  }
  
  void run(){ 
    // Questo è il "Cervello": raggruppa tutte le azioni in ordine logico.
    // Prima calcoliamo la fisica, poi mostriamo il risultato.
    gravity();
    move();
    bounce();
    display();
  }
}

//-----------------------------------------------------------------------------------
//GreenBall
class GreenBall extends Ball{ //GreenBall sta ereditanto i medoti di Ball. Ball è la classe madre, e di conseguenza GreeBall è la classe figlia

  //1° Costruttore
  GreenBall(float x, float y, float s, float sx, float sy){
  //Richiamiamo il costruttore della classe madre con "super"
  super(x,y,s,sx,sy);
  }
  
  //2° Costruttore
  GreenBall(float x, float y, float s){
    super(x,y,s);
  }
  
  void display(){
    fill(0,255,0);
    strokeWeight(5);
    stroke(255,0,255);
    ellipse(posX,posY,size,size);
  }
}
```

### Manipolazione di un'immagine

```java
PImage im; //PImage è il tipo di dato delle immagini

void setup(){
  size(600,600);
  im=loadImage("lena.png");
  println("Larghezza: "+im.width); //im.width preleva la larghezza dell'immagine
  println("Altezza: "+im.height);
}

//per vedere l'immagine la carichiamo nel draw
void draw(){
  background(0);
  image(im, 0, 0); //prende in input il nome della variabile immagine, e la posizione x, y. Un po' come per il testo
}

//Ora vediamo come possiamo modificare l'immagine
//Facciamo che ad un clic l'immagine è grande esattamente la metà

void mouseClicked(){
  // 1. IL CONTROLLO (La Guardia): Verifichiamo SUBITO se l'immagine è già troppo piccola.
  // Se la condizione è vera, stampiamo il messaggio ed ESCIAMO immediatamente.
  if((im.width <= 100) || (im.height <= 100)){
    println("Limite raggiunto! Non rimpicciolisco più.");
    return; // ??? -> "Eject": Fermati qui, non leggere le righe sotto e torna al draw().
  }

  // 2. L'AZIONE: Questa parte viene letta SOLO SE non siamo usciti con il return sopra.
  // Se arriviamo qui, significa che l'immagine era ancora > 100.
  im.resize(im.width/2, im.height/2); 

  // Stampiamo i nuovi valori per conferma
  println("Nuova Larghezza: " + im.width + " Nuova Altezza: " + im.height);
}

void keyTyped(){
  if(key=='s'){ //con s stiamo dicendo di salvare il nostro file con un nome in una cartella
    println(savePath("lenaPiccola.png")); //così ci stampa il path dove salviamo la foto
    im.save(savePath("lenaPiccola.png")); //così la salva e gli da un nome
    //im.save(savePath("data/lenaPiccola.png")); //così la salva nella cartella "data" e gli da un nome
  }
  if(key=='c'){
  println("salvo la canvas...");
  saveFrame("lenaCanvas.png"); //così salviamo l'ultimo frame della canvas
  }
}
```

```java
void setup(){
  size(500,500);
 
  rectMode(CENTER);
  
}

void draw(){
  translate(width/2,height/2);
  rotate(radians(frameCount%360));
  
  translate(50,50);
  rotate(radians(frameCount*10%360));
  
  fill(frameCount * 3 % 255, frameCount * 5 % 255,
      frameCount * 7 % 255);
  rect(0,0,100,100);
  saveFrame("frame-###.png"); //i questo modo salviamo tutti i frame dell'animazione, e inoltre con ### vengono numerati (il numero di cancelletti corrisponde al numero di cifre nel nome file)
}

/*
Una volta aver esportato tutti i frame possiamo realizzare un video dell'animazione
Andiamo su Strumenti > Creatore di filmati > Crea Filmato
E cosi realizzerà un file .mov della nostra animazione
Per salvare i frame in cartella in maiera più ordinata possiamo scrivere il comando saveFrame() così:
saveFrame("frames/###.png");
*/
```

Filtri immagini

```java
//Come caricare immagini dal web
//e applicare filtro in scala di grigio
PImage im;
PImage subIm;

void setup(){
 size(600,600);
 im = loadImage("https://i.pinimg.com/736x/0c/6e/73/0c6e738c750dfe7dddc61404490fa94a.jpg");
 println("Larghezza: "+im.width);
 println("Altezza: "+im.height);
 background(255,255,0);
 im.resize(500,500); //per ridimensionare la foto
 im.filter(GRAY); //per applcare il filtro
// im.save() restituisce TRUE se il file viene scritto correttamente sul disco.
  if (im.save(savePath("donna.png"))) {
    println("Foto salvata con successo nel percorso!");
  } else {
    println("Errore nel salvataggio!"); // In C: perror("Errore");
  }
 image(im,0,0);
 //ora salviamo metà immagine
 subIm=im.get(100,100,120,120); //Vai al punto 100,100 e taglia un quadrato di dimensione 120x120
 subIm.save(savePath("donnaGray.png"));
}

//per vedere l'immagine la carichiamo nel draw
void draw(){
  background(0);
}

//Ora vediamo come possiamo modificare l'immagine
//Facciamo che ad un clic l'immagine è grande esattamente la metà

void mouseClicked(){
  // 1. IL CONTROLLO (La Guardia): Verifichiamo SUBITO se l'immagine è già troppo piccola.
  // Se la condizione è vera, stampiamo il messaggio ed ESCIAMO immediatamente.
  if((im.width <= 100) || (im.height <= 100)){
    println("Limite raggiunto! Non rimpicciolisco più.");
    return; // ??? -> "Eject": Fermati qui, non leggere le righe sotto e torna al draw().
  }

  // 2. L'AZIONE: Questa parte viene letta SOLO SE non siamo usciti con il return sopra.
  // Se arriviamo qui, significa che l'immagine era ancora > 100.
  im.resize(im.width/2, im.height/2); 

  // Stampiamo i nuovi valori per conferma
  println("Nuova Larghezza: " + im.width + " Nuova Altezza: " + im.height);
}

void keyTyped(){
  if(key=='s'){ //con s stiamo dicendo di salvare il nostro file con un nome in una cartella
    println(savePath("lenaPiccola.png")); //così ci stampa il path dove salviamo la foto
    im.save(savePath("lenaPiccola.png")); //così la salva e gli da un nome
    //im.save(savePath("data/lenaPiccola.png")); //così la salva nella cartella "data" e gli da un nome
  }
  if(key=='c'){
  println("salvo la canvas...");
  saveFrame("lenaCanvas.png"); //così salviamo l'ultimo frame della canvas
  }
}
```

