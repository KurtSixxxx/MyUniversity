tutti gli appunti prima li ho perduti

erano la funzione map()

e... ???

Introduciamo il testo in Processing

```java
textSize(32); //per la dimensione del testo
text("word", 10, 30); //così diciamo cosa vogliamo scrivere e indichiamo l'angolo in alto a sinitra
fill(0,100,150); //con il fill gli diamo il colore
text("word", 10, 60);
fill(0,100,150,50); //ovviamente l'ultimo parametro è la trasparenza
text("word", 10, 90);
//possiamo anche cambiare il font
//createFont() 
//loadFont() possiamo caricare un font creato con processing

PFont f; //PFont sta per ProcessingFont, ed è una variabile dove mettiamo i font
f=createFont("Arial", 40); //Come stringa gli passiamo una delle famiglie di font installate sul sistema, e passiamo anche la dimensione
    //E' meglio usare il tool "Create Font" di processing
text("word",10,30); //così diciamo cosa vogliamo scrivere e indichiamo l'angolo in alto a sinitra
fill(0,100,150); //con il fill gli diamo il colore
text("word",10,60);
fill(0,100,150,50); //ovviamente l'ultimo parametro è la trasparenza
text("word",10,90);
PFont f; 
f=loadFont("Castellar-32.vlw"); 
textFont(f,28);

text("word",10,30); 
fill(0,100,150); 
text("word",10,60);
fill(0,100,150,50); 
text("word",10,90);
//Per creare un font, con l'utilizzo della funzione createFont(), basta andare in tools e selezionare il FontCreator, che crea il file .vlw  nella cartella data del nostro sketch
```

La prassi è:

- Andare su 'Tool'
- Selezionare 'Create Font'
- Selezionare un font
- Copiare il nome del font + estensione (.vlw)
- Nel codice creare una variabile di tipo 'PFont'
- Poi usare la funzione 'loadFont()' e passare come argomento sottoforma di stringa il nome completo del font con l'estensione
- Infine usare la funzione 'textFont()'' dove inseriamo il nome della variabile PFont e la size

```Java
void setup(){
  size(120,120);
  textSize(64);
  textAlign(CENTER); //Chiaramente serve per allineare il testo a sinitra, centro o a destra
}

void draw(){
  background(0);
  text(key, 60, 80); //con key prende il carattere che pigiamo sulla tastiera
}
void setup(){
  size(500,500); //Misura della canvas                                            
  textSize(42);  //Dimensione del testo
  fill(0);       //Colore del testo impostato uguale a nero
  String x = "questa è una frase più lunga di una parola";  //Stringa denominata x che contiene la frase tra virgolette
  //text(x,10,30);  //Posizionamento alle coordinate 10,10 del punto in alto sinistra del rettangolo che contiene la stringa x

  //Per fare in modo che il testo non venga troncato ed esca dallo schermo:
  //Esiste una versione della funzione text che accetta un 4 e 5 parametro che ci permettono di definire lunghezza e altezza del rettangolo che contiene il testo
  text(x,10,30, 200,300); //In questo caso il rettangolo che contiene il testo ha dimensione 200X300, e il suo angolo in alto a sinistra è posizionato a 10,30
}

void draw(){
}
```

```java
/*Questo codice: trasforma la tua finestra di Processing in un mini-programma di videoscrittura, tipo il Blocco Note. Ti permette di digitare con la tastiera, cancellare gli errori e "salvare" la frase premendo Invio.*/

PFont f; //Creiamo una variabile Processing Font 'f' che contiene il font
String scrivendo = ""; //Una strinfa vuota che serve a memorizzare, lettera per lettera, quello che stiamo digitando sil momento
String salvata = ""; //Un'altra stringa vuota. Qui viene inserito il testo dopo aver premuto 'invio', per fingere di averlo salvato

void setup(){
  size(500,500); //Misura della canvas                                            
  f=createFont("Calibri", 16); //Carica il font "Calibri" con grandezza 16 e lo inserisce nella variabile f
}

void draw(){
  background(255); //Carica il font "Calibri" con grandezza 16 e lo infila nella scatola f
  int ind = 25; //Una variabile usata solo per comodità: è il margine sinistro (x)
  textFont(f); //Diciamo a Processing: "Usa il font che ho caricato prima"
  fill(0); //Colore nero per il testo
    
  //Scriviamo sullo schermo usando: 'text("Frase", posizioneX, posizioneY)'
  text("Click sulla finestra.\nPremi invio per salvare. ", ind, 40);
  text("Input: "+scrivendo, ind, 190);
  text("Testo salvato: "+salvata, ind, 230);
}

//Questa funzione scatta in automatico solo e unicamente quando premi un tasto sulla tastiera. Processing salva il tasto che hai premuto in una variabile di sistema chiamata 'key'
void keyPressed(){
    // CASO 1: L'utente preme INVIO
    if(key=='\n'){
      salvata=scrivendo; //Copiamo la frase attuale dentro la variabile "salvata"
      scrivendo=""; 	 //Svuotiamo la riga di digitazione per ricominciare da capo!
    }
    // CASO 2: L'utente preme CANCELLA (Backspace)
    else if(key==BACKSPACE && scrivendo.length() > 0){
//scrivendo.length() > 0: Questo controllo serve a evitare che il programma crashi. Gli diciamo: "Cancella l'ultima lettera solo se c'è almeno una lettera scritta! Se la frase è già vuota, non fare niente".
        
      // Substring "taglia" la parola: prende tutto dalla prima lettera (0) fino alla penultima.
//substring(inizio, fine): È un paio di forbici digitali. Se la stringa è "CIAO" (lunghezza 4), substring(0, 3) taglierà dalla lettera alla posizione 0 (la C) fino alla 3 esclusa. Risultato? "CIA", ha tolto la O!
      scrivendo=scrivendo.substring(0,scrivendo.length()-1);
    }
    // CASO 3: L'utente preme una qualsiasi altra lettera
    else{
      scrivendo+=key; //Aggiunge la lettera digitata alla fine della frase, quindi una dopo l'altra
    }
}
```

Chiariamo la sintassi che contiene i cosiddetti dot '.'
Tipica di Java.

In Java, una String (una parola) non è solo un contenitore di lettere: è un Oggetto. Un oggetto contiene l'informazione (la parola stessa), possiede anche gli altri strumenti (chiamati metodi) per farsi manipolare.

Il punto (`.`) è il modo in cui tu "premi il pulsante" per attivare uno di quegli strumenti su quell'oggetto specifico.

- `scrivendo.length()` significa: *"Ehi stringa `scrivendo`, dimmi la tua lunghezza!"*.

- `scrivendo.substring(...)` significa: *"Ehi stringa `scrivendo`, usa il tuo strumento interno per ritagliarti!"*.

Come funziona substring() in generale?
La parola `substring` significa letteralmente "sotto-stringa" (una porzione della stringa). Serve a estrarre un pezzetto di testo da una parola più lunga.

Per usarlo devi ricordarti la solita regola: **i computer iniziano a contare da 0, non da 1.** Immagina la stringa `"CIAO"`:

- La lettera **C** è nella posizione **0**
- La lettera **I** è nella posizione **1**
- La lettera **A** è nella posizione **2**
- La lettera **O** è nella posizione **3**

La sintassi di base è questa: `parola.substring(indiceDiPartenza, indiceDiArrivo);`

**⚠️ ATTENZIONE ALLA REGOLA TRABOCCHETTO:**

- L'`indiceDiPartenza` è **incluso** nel taglio.
- L'`indiceDiArrivo` è **escluso** dal taglio. Il computer si ferma *un attimo prima* di quel vagone.

**Esempi pratici con "CIAO":**

- `"CIAO".substring(0, 2)` ➔ Taglia da 0 a 1 (il 2 è escluso). Risultato: **"CI"**.
- `"CIAO".substring(1, 4)` ➔ Taglia da 1 a 3 (il 4 è escluso). Risultato: **"IAO"** 

------

Adesso abbiamo creato un motore fisico in miniatura. Stiamo simulando la gravità e l'attrito (la perdita di energia) nel mondo reale.

```java
float x = 240; //Coordinata x dell'angolo in alto a sinistra del rettangolo
float y = 0; //Coordinata y dell'angolo in alto a sinistra del rettangolo
float speed = 0; //La velocità iniziale è 0. Immagina di tenere l'oggetto in mano a mezz'aria prima di lasciarlo andare. Non sta ancora cadendo.
float gravity = 0.1; //La "forza" che spinge verso il basso. Vale 0.1 e agirà costantemente.

void setup(){
    size(500,250);
}

void draw(){  
//Qui niente di nuovo, pulisci lo schermo e disegni il rettangolino grigio. Nota l'ottima scelta di usare rectMode(CENTER): in questo modo la variabile y indica esattamente il centro del rettangolo, e non il suo angolo in alto a sinistra.
    background(255);
    fill(175);
    stroke(0);
    rectMode(CENTER); 
    rect(x,y,10,10);
    
    //La gravità in azione
    y+=speed; //La posizione Y cambia in base alla velocità. (Se la velocità è 2, il quadrato scende di 2 pixel).
    speed+=gravity; //Al primo giro la velocità è 0. Poi diventa 0.1, poi 0.2, poi 0.3... Più scende, più la sua velocità aumenta.
    
    //L'urto ed il rimbalzo
    if(y > height){ //In questo caso sta urtando con la parte bassa della canvas. Quindi deve rimbalzare, e per rimbalzare dobbiamo cambiare il senso della sua velocità.
      speed = speed * -0.95; //Il segno Meno (-) inverte la direzione. Se la velocità era, per esempio, +10 (verso il basso), moltiplicandola per un numero negativo diventa -9.5 (verso l'alto). Il 0.95 simula l'attrito (o la dispersione di energia). Significa: "mantieni solo il 95% della velocità che avevi al momento dello schianto". Quel 5% perso fa sì che ogni rimbalzo sia un po' più basso del precedente, finché non si ferma.
      y = height; //Quando il computer fa i calcoli, a volte il quadrato potrebbe trovarsi a Y = 252, "sfondando" un po' il pavimento (che è a 250). Questa riga lo "riacchiappa" e lo riposiziona esattamente a filo col pavimento, evitando che si incastri o faccia scatti strani.
    }
}
```

```java
int a = 0;

void setup(){
  size(500,500);
    //rectMode(CENTER); //Se vogliamo fare in modo che il rettangolo giri su se stesso
}

void draw(){
  background(0);
  translate(width/2,height/2);
  //Il foglio è sempre largo 500 e alto 500, ma ora le coordinate per muoverti sono cambiate: Il centro esatto è diventato (0, 0). L'angolo in alto a sinistra ora è a coordinate (-250, -250). L'angolo in basso a destra ora è a coordinate (+250, +250).
  //Se tu mettessi translate nel setup(), Processing sposterebbe l'origine al centro una volta sola all'avvio. Ma appena partirebbe il primo draw(), il sistema se ne dimenticherebbe all'istante, resettando la griglia in alto a sinistra. Ecco perché devi "ricordargli" di spostare il righello al centro 60 volte al secondo!
  rotate(radians(a)); //Questa è la funzione per la rotazione.
  rect(0,0, 50,50);
  a++;
}
```

```java
void setup(){
    size(500,500);
}

void draw(){
    background(0);
    translate(width/2, height/2); //Trasliamo il nostro sistema di riferimento. Adesso width/2 ed height/2 sono i nostri nuovi 0,0
    /*
    millis(): È un cronometro interno di Processing. Ti dice quanti millisecondi sono passati da quando hai premuto Play.
    * 0.001: Trasforma i millisecondi in secondi (es. 1500 millisecondi diventano 1.5 secondi).
    TWO_PI: È il valore di 360 gradi scritti in radianti (un giro completo).

    Significa "Fai un giro completo esatto ogni secondo"
    Dividendo il tutto per 10 (come nel primo rotate), significa: "Fai un giro completo ogni 10 secondi" (molto più lento!).
    */
    
    //Con millis * 0.001 stiamo convertendo i millisecodi in secondi. Con TWO_PI/10 stiamo dicendo "Ogni secondo fa un decimo di giro", quindi un giro completo ogni 10 secondi
    rotate(millis()*0.001*TWO_PI/10); //Rivoluzione attorno al Sole
    translate(80,0); //Spostati di 80px a destra, Quando usi rotate() e subito dopo translate(X, 0), non ti sposti a destra sullo schermo, ma cammini in avanti lungo il tuo asse appena ruotato. In questo caso, X diventa letteralmente il RAGGIO della tua orbita.
    rotate(millis()*0.001*TWO_PI); //Questa fa girare il pianeta su se stesso mentre sta compiendo l'orbita

    //Gestione della ellisse (Spessore, colore e posizione [posizione ovviamente con il nuovo sistema di riferimento])
    fill(255);
    noStroke();
    ellipseMode(CENTER);
    ellipse(0,0,40,40);
    
    //Gestione della linea (Spessore, colore e posizione [posizione ovviamente con il nuovo sistema di riferimento])
    strokeWeight(5);
    stroke(255,0,0);
    line(0,0,40,0);
}
```

```java
int x = 0;
void setup(){
    size(500,500);
    rectMode(CENTER);
}

void draw(){
//Essendo che rotate e translate sono due operazioni "Matriciali", possiamo creare dei movimenti indipendenti, e quindi evitare che più oggetti nello schermo seguano lo stesso movimento
//Questo viene fatto usano pushMatrix() e popMatrix(). Li usiamo come due fette di pane, che racchiudono nel panino tutto quello che riguarda oggetti e movimento

background(255);
//Facciamo un cubo verde con un movimento proprio ed una velocità propria
    pushMatrix();
    translate(x+300,200); //Occhio alla x, Se la togliessimo il cubo non si muoverebbe a destra
    rotate(radians(frameCount));
    fill(0,255,0);
    rect(0,0,40,40);
    popMatrix();

//Facciamo un cubo rosso con un movimento proprio ed una velocità propria
    pushMatrix();
    translate(x+100,200);  //Occhio alla x, Se la togliessimo il cubo non si muoverebbe a destra
    rotate(radians(frameCount)*2);
    fill(255,0,0);
    rect(0,0,40,40);
    popMatrix();

 //La x, inoltre incrementata sempre di 1, serve a far spostare verso destra i cubi
    x++;
}
```

