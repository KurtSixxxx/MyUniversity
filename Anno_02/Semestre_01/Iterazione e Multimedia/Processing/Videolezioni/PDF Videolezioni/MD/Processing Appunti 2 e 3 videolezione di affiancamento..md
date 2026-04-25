# Processing Appunti 2 e 3 videolezione di affiancamento.

```java
point(); //per fare un punto
line(); //per fare una linea
ellipse(); //per fare un ellisse
circle(); //per fare un cerchio, prende x,y del centro e ed il raggio -> 3 parametri
rect(); //per fare u rettangolo
quad(); //per fare un quadrilatero (4 vertici)
shape(); //per fare una forma con i vertici
```

```java
//[PRIMO FILE]
size(500,500);
//L'arco verrà disegnato in senso orario, quindi parte da un punto e torna all'altrosize(500,500);
//Disegno dimostrativo di tutti e 4 gli spicchi, di ogni metà, e della circonferenza chiusa
//arc(a,b,c,d,start,stop) ->ATTENZIONE: Stop > Start!!! deve essere così.
//a e b sono le coordinate del centro, c e d sono le dimensioni di larghezza e altezza, e start e stop sono angoli (in radianti) di inzio e fine.

/* In Processing, la funzione arc() ha un comportamento rigido:
- Il punto 0 (zero radianti) è a ore 3:00 (a destra).
- Disegna sempre in senso ORARIO (da Start verso Stop).
- Disegna solo se Stop > Start. */

arc(60, 60, 80, 80, PI, PI + HALF_PI); //1 quadrante
arc(160, 60, 80, 80, PI + HALF_PI, TWO_PI); //2 quadrante
arc(260, 60, 80, 80, 0, HALF_PI); //3 quadrane
arc(360, 60, 80, 80, HALF_PI, PI); //4 quadrante
/*Il punto "Ore 12:00" ha due nomi:
Nome lungo (giro completo): 270° (PI + HALF_PI).
Nome corto (indietro): -90° (-HALF_PI).*/


arc(60, 200, 80, 80, PI, TWO_PI); //metà in alto
arc(160, 200, 80, 80, 0, PI); //metà in basso
arc(260, 200, 80, 80, HALF_PI, PI + HALF_PI); //metà a sinistra
arc(360, 200, 80, 80, -HALF_PI, HALF_PI); //metà a destra

arc(60, 340, 80, 80, 0, TWO_PI);_PI);


//Introduciamo un'altra funzione, che ci servirà per disegnare pacman
//ossia la funzione 'radins()', se inseriamo un angolo in gradi lo converte in radianti
//quindi pacman sarebbe:
arc(width/2, height/2, 100, 100, radians(30), radians(330));


//Però la nostra "torta" rimarrà aperta e senza stroke che la chiude, per questo 'arc()' accetta un settimo parameto che sarebbe la MODE, e ne abbiamo 3
/*
- PIE: chiude la nostra "torta/pie"
- OPEN: lascia la linea aperta, ma non ha la forma a torta, collega i due punti con una retta, ma rimane aperta
- CHORD: collega i due punti con una linea chiusa, ossia con un suo stroke
Dunque il nostro pacman sarebbe:
*/

arc(width/2, height/2, 100, 100, radians(30), radians(330), PIE);
```

![](C:\Users\giuli\AppData\Roaming\marktext\images\2026-02-12-02-08-08-image.png)

```java
//[SECONDO FILE]
//Vediamo l'ultima funzione di disegno che ci rimane
//E la funzione è: 'bezier()'

/*Disegna una curva di Bézier sullo schermo.
Queste curve sono definite da una serie di punti di ancoraggio e di controllo.
I primi due parametri specificano il primo punto di ancoraggio e gli ultimi due parametri specificano l'altro punto di ancoraggio.
I parametri centrali specificano i punti di controllo che definiscono la forma della curva. */

void setup(){
  size(500,500);
  noFill();
}

void draw(){
  background(255); //Reimpostare il background serve per rendere il disegno una vera e propria animazione e non un disegno ripetuto uno sopra l'altro. Prova a rimuover questa istruzione per capire meglio.
  stroke(255,100,0);
  line(185,50, mouseX, mouseY);
  line(15,290, 190,300);
  stroke(0);
  //bezier(ancorPoint1_X, ancorPoint2_Y, controlPoint1_X, controlPoint1_Y, controlPoint2_X, controlPoint2_Y, ancorPoint1_X, ancorPoint1_Y);
  bezier(185,50, mouseX,mouseY, 190,300, 15,290);

}
```

```java
//[TERZO FILE]

//Facciamo la prima animazione
int pos1 = 0;
int pos2 = 0;

void setup(){
  size(500,500);

}


void draw(){
  background(255);
  line(pos1,20, pos2,height);
  pos1++;
  pos2++;
}

//Animazione di una semplice linea che si sposta da sinistra a destra
```

```java
//[QUARTO FILE]

int pos = 0; //Come sempre rendiamo globale lo scope della variabile che ci serve usare

void setup(){
  size(500,500);
  frameRate(200);
}

/*
In questo esercizio vogliamo una linea che si muove da sinistra a destra facendo l'effetto pacman, ossia che una volta arrivato alla fine dello schermo appare di nuovo a sinistra all'infinito.
Ovviamente impostiamo il nostro background ad ogni iterazione della funzione drawInizializziamo la nostra linea, una semplice linea verticale che attraversa tutta la canvas.
Adesso presta attenzione.
Se il nostro incremento sarà pos++ (quindi che aumenta la coordinata x di 1) allora il funzionerà tutto
Ma se il nostro incremento sarà pos+=3 allora non passeremo mai a pos == 500 (che è la nostra width) e dunque la condizione non sarà mai vera. Per questo è opportuno modificare la condizione come pos >= width, ciò vuol dire che se pos sarà comunque uguale o poco maggiore di 500 dovrà ripartire comunque da 0.
*/

//SCRIVO DUE FUNZIONI DRAW PER MOSTRARE LE DIFFERENZE, MA OVVIAMENTE POSSIAMO AVERNE SOLAMENTE UNA!!!

void draw(){
  background(255);
  line(pos,0, pos,height);
  pos++;
  if(pos == width){
    pos = 0;
  }
}

void draw(){
  background(255);
  line(pos,0, pos,height);
  pos+=3;
  if(pos >= width){
    pos = 0;
  }
}
```

```java
//[QUINTO FILE]
//Adesso vogliamo eliminare l'effetto pacman, e fare in modo che la linea rimbalzi a destra e sinista

int pos = 0;
int dir = 1; //direzione
int v = 3; //velocità

void setup(){
  size(500,500);

}

void draw(){
  background(255);
  line(pos,20, pos,height);
  //pos+=3 vuol dire pos += direzione * velocità, perchè si sposta di 3 per un framerate di 3
  //per fare avanti ed indietro dobbiamo solo aumentare e diminuire e poi aumentare e così via la dimensione.
   if(pos>width || pos<0){
   dir = -dir;
   }

   pos += dir * v;
}


/*1. Il Segreto del segno Meno (-)
In matematica e informatica, moltiplicare per -1 è l'equivalente di fare una inversione a U con l'auto.
Guarda cosa succede ai numeri se li moltiplichi per -1:
Se hai 1 (stai andando avanti) e lo moltiplichi per -1, ottieni -1 (vai indietro).
Se hai -1 (stai andando indietro) e lo moltiplichi per -1, ottieni 1 (meno per meno fa più -> torni ad andare avanti).

2. Cosa succede nel tuo codice?
Tu hai questa riga fondamentale alla fine: pos += dir * v;
Analizziamola in due scenari:
SCENARIO A: La marcia avanti (dir = 1) Stai iniziando il programma. dir è 1. Il calcolo diventa: pos = pos + (1 * 3). Ovvero: pos = pos + 3. La linea si sposta a destra: 0, 3, 6, 9... fino a 500.
SCENARIO B: Il Muro (dir = -dir) Appena tocchi il bordo (pos > width), il codice esegue: dir = -dir; Siccome dir era 1, ora diventa -1.
SCENARIO C: La retromarcia (dir = -1) Al frame successivo, il codice riesegue il calcolo di movimento: pos += dir * v; Sostituiamo i numeri: pos = pos + (-1 * 3). Ovvero: pos = pos - 3. Vedi? Ora sottrai 3! La linea torna indietro: 500, 497, 494...

In sintesi
Quella riga dir = -dir è un interruttore. È un modo velocissimo per dire al computer: "Qualunque cosa tu sia (1 o -1), diventa il tuo opposto".
Se sei positivo, diventa negativo.
Se sei negativo, diventa positivo.
È come sbattere contro un muro e rimbalzare: la tua velocità (v) è sempre 3 km/h, ma la tua direzione (dir) cambia verso.*/


//Rifacciamo la stessa animazione ma con la riga che si muove in orizzontale
int pos = 0;
int dir = 1;
int v = 3;

void setup(){
  size(500, 500);
}

void draw(){
  background(255);
  strokeWeight(2);
  line(0,pos, width,pos);

  if(pos>height || pos<0){ //Se il valore di y è > 500 o < di 0, allora rendi la direzione negativa -> torna indietro
    dir = -dir;
  }

  pos += dir*v; //per far muovere la linea si fa la posizione = posizione + (dir * v)
  //Ad esempio -> posizione (2) = 2 + (+1 * 3); 
}
```

```java
//[SESTO FILE]
//Esercizio di mattonelle sconnesse
size(500,500);
background(0,255,0);
noStroke();

//Usiamo la funzione 'random()', prende uno o due parametri.
//Se usiamo random(30) ci restituisce un float. Quindi da 0.0 a 29.999... Quindi non avremo mai 30
//Il casting in float si fa come nel C: (int)random(30)
//Se passiamo due parametri stiamo attivando un range più definito. Quindi se usiamo:
//random(10,15) avremo il range che va da 10.0 a 14.999...

int l=50; //lato della mattonella

for(int y=0; y<height; y+=l){
  for(int x=0; x<width;x+=l){
    fill(random(255),130); //Questa riga riempie casualmente e con varie tonalità i colori. Perché impostiamo livelli di grigio diversi di trasparenze diverse.
    rect(x+random(-5,5),y+random(-5,+5),l,l); //come al solito, i primi due parametri impostano l'angolo in alto a sinistra e gli altri due larghezza e altezza
    //Aggiungiamo 'x+random(-5,5),y+random(-5,+5)'. Quello che abbiamo fatto è stato spostare di 5 pixel a sinistra o destra o in alto o in basso
  }
}

//Ricordiamo i parametri accettati da 'fill()'
/*
- 3 parametri = RGB
- 1 paramrtro = livello di grigio
- 1 parametro = #esadeciamle
- 4 parametri = RGB e alpga
- 2 parametri = livello di grigio e alpha
*/
```

```java
//[SETTIMO FILE]
void setup(){
size(500,500);
background(0,255,0);
int l=50;
for(int y=0; y<height; y+=l){
  for(int x=0; x<width;x+=l){
    fill(random(255),130); 
    rect(x+random(-5,5),y+random(-5,+5),l,l);
    }
  }
}

void draw(){
}

void mousePressed(){ //Funzione che capisce se premi un tasto del mouse
setup();//ogni volta che premiamo un tasto richiama la funzione setup
}
```

```java
//[OTTAVO FILE]
void setup(){
  size(500,500);
}

void draw(){
  if(mousePressed){ //E' una variabile booleana. False se non premiamo nulla, True se premiamo qualcosa.
    //mouseButton conserva quale abbiamo premuto
    //mouseButton è una variabile di tipo intero
    if(mouseButton==LEFT){ //Se premiamo tasto sinistro stampa L
      println("L");
  }
    if(mouseButton==RIGHT){ //Se premiamo tasto destro stampa R
      println("R");
    }
  }

  if(keyPressed){ //keyPressed è booleana come mousePressed
  //key è una funzione di tipo char
    if(key == 'a' || key == 'A'){
      println("ho premuto 'a'");
    }
  }
}
```

```java
//[NONO FILE]
//creiamo un array di tipo float globalmente in modo che è accessibile ovunque
//new è l'equivalente del malloc in C, ed in questo caso abbiamo allocato un array di 10 valori, ossia 10 cerchi
float [] d = new float [10]; 

void setup(){
  size(800, 800);
  for (int i = 0; i < d.length; i++){ //riempiamo l'array
    d[i] = (i+1)*60; //ogni valore sarà quello precedente + 60
  }
}

void draw(){
  for (int i = d.length-1; i>=0; i--){ //Scorriamo l'array al contrario altrimenti i cerchi più grandi saranno disegnati su quelli più piccoli 
    fill(random(255), random(255), random(255)); //Riempiamo con colori random
    ellipse(width/2, height/2, d[i], d[i]); //Il centro di ogni ellisse sarà al centro della canvas, e i diametri avranno i valori che andiamo a leggere dall'array
  }

  if(mousePressed){
    if(mouseButton == LEFT){
        println("L");
        noLoop(); //interrompe l'esecuzione della funzione 'draw()' se noi premiamo il tasto sinistro del mouse
    }
    if(mouseButton == RIGHT){
        println("R");
        loop(); //Il loop qui non riprenderà, perchè una volta che abbiamo premuto il tasto sinistro per interrompere il Loop allora usciremo anche dalla funzine 'draw()', per questo allora dovremo usare le funzioni apposite. Mostrerò il funzionamento nel codice qui sotto 
    }
  }

}
```

> Considerando che veniamo dal C/C++, e non siamo esperti di Java, è importante chiarire la sintassi della dichiarazione di un array, e di una piccolezza nella condizione del for.
> Ecco spiegato tutto.
> 
> 1. La Dichiarazione e Allocazione
> 
> ```java
> float[] d = new float[10];
> ```
> 
> In C, per fare la stessa cosa dinamicamente, scriveresti qualcosa come:
> 
> ```c
> // C equivalente (approssimativo)
> float *d = (float*) calloc(10, sizeof(float));
> ```
> 
> Ecco le differenze fondamentali:
> 
> 1. **`float[] d` (Il Puntatore)**:
>       - In C scriveresti `float d[]` o `float *d`.
>    
>       - In Processing, le parentesi quadre `[]` si mettono preferibilmente *dopo il tipo* (`float[]`) per dire "Sto dichiarando un riferimento (puntatore) a un array di float".
>    
>       - In questo momento `d` è solo un riferimento, non contiene ancora i dati.
>    
> 2. **`new` (Il Malloc Potenziato)**:
> 
>       - Questa è la parola chiave magica. In C usi `malloc`. In Java/Processing usi `new`.
> 
>       - **Differenza cruciale:** `new` non solo alloca la memoria nello *Heap*, ma la **pulisce anche**.
> 
>       - Mentre in C un array creato nello stack contiene valori "spazzatura", in Processing `new float[10]` crea 10 caselle e le riempie tutte automaticamente con **`0.0`**.
> 
> 3. **`[10]` (La Dimensione)**:
> 
>       - Stai chiedendo spazio per 10 elementi. Una volta creato, l'array **non può cambiare dimensione** (proprio come un blocco `malloc` in C, a meno che non usi `realloc`, cosa che qui non esiste direttamente).
> 
> ---
> 
> ### 2. La gestione della dimensione (`.length`)
> 
> ```java
> for(int i = 0; i < d.length; i++) { ... }
> ```
> 
> In C, un array è "stupido": non sa quanto è grande. Devi sempre portarti dietro una variabile `int size` o fare calcoli con `sizeof`.
> 
> In Processing, gli array sono **oggetti intelligenti**.
> 
> - L'array `d` si porta dietro "nello zaino" la sua dimensione.
> 
> - `d.length` è una proprietà di sola lettura che ti restituisce `10`.
> 
> - È comodissimo: non rischi mai di andare fuori dai bordi (Buffer Overflow) senza accorgertene, perché se provi a leggere `d[11]`, Processing ti ferma subito con un errore, invece di leggere memoria a caso come farebbe C.
> 
> ---
> 
> ### Riassunto C vs Processing
> 
> | **Concetto**        | **C (classico)**                            | **Processing (Java)**                 |
> | ------------------- | ------------------------------------------- | ------------------------------------- |
> | **Dichiarazione**   | `float d[10];` (Stack) o `float *d;`        | `float[] d;`                          |
> | **Allocazione**     | `malloc(10 * sizeof(float))`                | `new float[10]`                       |
> | **Pulizia memoria** | Manuale (`memset` o `calloc`)               | Automatica (tutto a 0)                |
> | **Dimensione**      | Devi ricordartela tu (`sizeof` o var extra) | `d.length` (l'array lo sa)            |
> | **Deallocazione**   | `free(d)` (Obbligatorio!)                   | **Automatica** (Garbage Collector) 🎉 |

```java
//[DECIMO FILE]
//creiamo un array di tipo float globalmente in modo che è accessibile ovunque
//new è l'equivalente del malloc in C, ed in questo caso abbiamo allocato un array di 10 valori, ossia 10 cerchi
float [] d = new float [10]; 

void setup(){
  size(800, 800);
  for (int i = 0; i < d.length; i++){ //riempiamo l'array
    d[i] = (i+1)*60; //ogni valore sarà quello precedente + 60
  }
}

void draw(){
  for (int i = d.length-1; i>=0; i--){ //Scorriamo l'array al contrario altrimenti i cerchi più grandi saranno disegnati su quelli più piccoli 
    fill(random(255), random(255), random(255)); //Riempiamo con colori random
    ellipse(width/2, height/2, d[i], d[i]); //Il centro di ogni ellisse sarà al centro della canvas, e i diametri avranno i valori che andiamo a leggere dall'array
  }
  }


  //---FUNZIONI PER MOUSE---
  void mousePressed(){ //Adesso la nostra animazione riprenderà tranquillamente premendo tasto destro e si interromperà premendo tasto sinistro
     if(mouseButton == LEFT){
        println("L");
        noLoop();
    }
    if(mouseButton == RIGHT){
        println("R");
        loop();
    }
  }
  void mouseReleased(){
  }
  void mouseClicked(){
  }

  //---FUNZIONI PER TASTIERA---
  void keyPressed(){ //Vale anche se holdiamo il tasto
  }
  void keyReleased(){
  }
  void keyTyped(){
  }
```

```java
//[UNIDCESIMO FILE]
//Adesso: Vogliamo eliminare il funzionamento di tasto destro e tasto sinistreo per interrompere e riprendere l'animazione. E vogliamo utilizzare un solo tasto come se fosse un interruttore.
float [] d = new float [10]; 
//utilizziamo una variabile booleana
boolean vai = true;

void setup(){
  size(800, 800);
  for (int i = 0; i < d.length; i++){
    d[i] = (i+1)*60;
  }
}

void draw(){
  for (int i = d.length-1; i>=0; i--){
    fill(random(255), random(255), random(255));
    ellipse(width/2, height/2, d[i], d[i]);
  }
  }

  void mousePressed(){
  }
  void mouseReleased(){
  }
  void mouseClicked(){
    //Qui stiamo dicendo che la nostra animazione si attacca e si stacca, con qualunque tasto del mouse (sinistro, centro, destro)
    vai = !vai;
    if(vai == true){
        loop();
    }else{
        noLoop();
    }
  }

  void keyPressed(){
  }
  void keyReleased(){
  }
  void keyTyped(){
  }
```

```java
//[DODICESIMO FILE]
//Adesso lavoriamo sull'utilizzo delle freccette della tastiera
int x = 0;

void setup(){
   size(500,500); 
}

void draw(){
    background(0);
    rect(x,height/2, 50,50);
    if(keyPressed){
        if(key==CODED){
        if(keyCode==LEFT){ //Se il keyCode corrisponde al tasto della freccia sinistra, decrementiamo il valore di x.
            x-=5;
        }
        if(keyCode==RIGHT){ //Se il keyCode corrisponde al tasto della freccia destra, incrementiamo il valore di x.
            x+=5;
        }
    }
    }
}

void keyPressed(){ //Ci sono dei caratteri che sono codificati, detti 'CODED'.
/*    if(key==CODED){
        if(keyCode==LEFT){ //Se il keyCode corrisponde al tasto della freccia sinistra, decrementiamo il valore di x.
            x-=5;
        }
        if(keyCode==RIGHT){ //Se il keyCode corrisponde al tasto della freccia destra, incrementiamo il valore di x.
            x+=5;
        }
    }*/
} 

//HO CONSTATATO CHE A QUANTO PARE USARLO NEL DRAW è MEGLIO. OVVIAMENTE BISOGNA USARE IL BOOLEANO 'keyPressed' PER S
/*
Codici dei tasti CODED reperibili con keyCode;
UP, DOWN, LEFT, RIGHT, ALT, CONTROL e SHIFT

Mentre in key, non avendo bisogno di fare il controlo se key==CODED, abbiamo i seguenti caratteri speciali:
BACKSPACE, TAB, ENTER, RETURN, ESC, e DELETE.
L'invio si può "catturare" in due modi (key == ENTER) oppure (key == '\n').
Lo spazio è il carattere ' ' (c'è uno spazio tra i singoli apici)
*/
```

```java
//[TREDICESIMO FILE]
/*
    Esercizio di PacMan animato. Il personaggio dovrà aprire e chiudere la bocca e tornare avanti ed indietro.
*/

//Dichiariamo le variabili che ci serviranno
int x = 60;
int dir = 1; //direzione
int a = 30; //angolo = 30°
int dira = -1;
int v = 10; //velocità
int va = v/2; //velocità di apertura bocca
int r = 40; //raggio

void setup(){
    size(500,500);
    ellipseMode(RADIUS);  // CAMBIA IL MODO DI DISEGNARE: I parametri diventano il RAGGIO (metà larghezza), non il DIAMETRO. Senza questa riga, il Pacman sarebbe largo 40 totali (piccolo). Con questa riga, 40 è solo la metà, quindi il totale è 80 (grande il doppio).
}

void draw(){
    background(0); //Impostiamo lo sfondo nero
    fill(255, 255, 0); //Coloriamo di giallo il nostro pacman
    if(dir==1){ //Se il nostro pacman si muove verso destra...
    arc(x,height/2, r,r, radians(a), radians(360-a)); //...allora la bocca sarà a destra
    }
    if(dir==-1){ //Se il nostro pacman si muove verso destra...
        arc(x,height/2, r,r, radians(180+a), radians(360+180-a)); //...allora la bocca sarà a sinistra
    }
    fill(0); //Colore dell'occhio
    ellipse(x, height/2-20, 5,5); //Definizione dell'ellisse che sarà l'occhio
    //Questo è il controllo dell'occhio. 
    //Se x è maggiore uguale della larghezza della canvas meno il raggio (si aggiunge - r perché dobbiamo controllare che sia la bocca a toccare e non il centro)...7
    //Oppure se x è minore del raggio
    //allora cambia la direzione
    if(x >= width-r || x < r){ 
            dir = -dir; //dir = -dir è un interruttore. È un modo velocissimo per dire al computer: "Qualunque cosa tu sia (1 o -1), diventa il tuo opposto".
    }
    if(a > 30 || a <= 0){ //Questo comanda l'apertura della bocca.
    //Se a > 30 la bocca è aperta
    //Se a <= 0 la bocca è chiusa
        dira = -dira;
        /*Immagina dira come un interruttore del respiro.
        Quando dira è positivo (es. +1): Pacman sta INSPIRANDO. Ad ogni fotogramma aggiungi 1 all'angolo. La bocca si apre sempre di più. Angolo: 10°... 20°... 30° (Bocca spalancata! Aaaah!)
        Quando dira è negativo (es. -1): Pacman sta ESPIRANDO. Ad ogni fotogramma togli 1 all'angolo. La bocca si chiude sempre di più. Angolo: 30°... 20°... 10°... 0° (Bocca chiusa! Mmh!)
        Quindi cosa fa dira = -dira? È il comando che dice: "Inverti il respiro!"
        Il computer controlla continuamente:
        "Ehi, la bocca è arrivata a 30 (troppo aperta)?" -> SÌ! -> Allora fai dira = -dira. Da ora in poi chiudi.
        (Il tempo passa, la bocca si chiude...)
        "Ehi, la bocca è arrivata a 0 (troppo chiusa)?" -> SÌ! -> Allora fai dira = -dira. Da ora in poi apri.
        È un ciclo infinito: Apri -> Inverti -> Chiudi -> Inverti -> Apri... Proprio come un polmone o un cuore che batte.*/
    }
    a+=dira*va; //Ad ogni fotogrammala bocca si muove un po' (e con va comandiamo la velocità della bocca, che è proporzionale a v)
    x += dir * v; //Prendi la posizione x e aggiungi la velocità v nella direzione giusta dir. Questa riga cambia la direzione, la velocità di movimento è sempre v
}
```

```java
//[QUATTORDICESIMO FILE]
//Introduciamo l'interpolazione in processing: 'lerp()' [Linear Interpolation]
//Gli forniamo dei key frame, lui si muoverà da un punto ad un altro calcolando dei punti intermedi, dunque ci servirà per l'animazione.
//Come parametri prende: un punto di inizio, un punto di fine e la percentuale. Per un totale di 3 parametri.

//Proviamo prima su un disegno e poi su una animazione.

int x1 = 15;
int y1 = 10;
int x2 = 80;
int y2 = 90;
line(x1,y1,x2,y2);
for(int i = 0; i <= 10; i++){ 
    stroke(255, 0, 0);
    strokeWeight(3);
    float x = lerp(x1,x2, i/10.0); 
    float y = lerp(y1,y2, i/10.0);
    point(x,y);
}

//Quindi abbiamo disegnato dei puntini al 10%, 20%, 30%, 40%, 50%, 60%, 70%, 80%, 90%, 100%.
```

```java
//[QUINDICESIMO FILE]
 //Adesso utilizziamo la funzione di interpolazione nelle animazioni
float x;
float y;

void setup(){
    size(500,500);
    noStroke();
}

void draw(){
    background(0);
    //x=mouseX;  
    //y=mouseY;
    x = lerp(x, mouseX, 0.1); //0.1 riguarda lo spostamento
    y = lerp(y, mouseY, 0.1);
    ellipse(x,y,60,60);
}
```

```java
//[SEDICESIMO FILE]
//Facciamo una pallina che lascia la scia

float x;
float y;

void setup(){
    size(500,500);
    noStroke();
}

void draw(){
    //background(0);
    fill(0, 40);
    rect(0, 0, width, height);
    x = lerp(x, mouseX, 0.1);
    y = lerp(y, mouseY, 0.1);
    fill(255);
    ellipse(x,y,60,60);
}
```

```java
//[DICIASETTESIMO FILE]
 //Movimento randomico di una pallina

float x;
float y;

void setup(){
    size(500,500);

    x=width/2;
    y=height/2;
    noStroke();
}

void draw(){
    //background(0);
    fill(0, 25);
    rect(0, 0, width, height);
    x = x+random(-5,5);
    y = y+random(-5,5);
    fill(255);
    ellipse(x,y,60,60);
}
```

```java
//[DICIOTTESIMO FILE]
//Programmiamo una sorta di paint con 3 colori

void setup(){
    size(500,500);
     stroke(255, 0, 0);
    stroke(10);
    background(255);
}

void draw(){
    strokeWeight(5);
    if(mousePressed){
        //pmouse è una variabile che salva la posizione precedente del click del mouse
        line(pmouseX, pmouseY, mouseX, mouseY);
    }
}

void keyPressed(){
    if(key == 'r' || key == 'R'){
        stroke(255,0,0);
    }
    if(key == 'g' || key == 'G'){
        stroke(0,255,0);
    }
    if(key == 'b' || key == 'B'){
        stroke(0,0,255);
    }
    if(key == ' '){
        background(255);
    }
}
```
