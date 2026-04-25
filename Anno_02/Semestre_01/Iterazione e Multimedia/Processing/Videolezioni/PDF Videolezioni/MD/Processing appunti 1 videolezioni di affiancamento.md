# Processing: appunti con videolezioni di affiancamento.

```java
//[PRIMO FILE]

//Se premiamo "play" abbiamo la nostra canvas, di default 100x100px
//Usiamo la funzione 'size()' pee definire la nostra dimensione di canvas
size(500,500);

//Adesso non abbiamo un colore di canvas, quindi è opportuno definirlo con 'background(R, G, B) oppure backgroud(valore in scala di grigio)'
  //background(0, 150, 255);
//Possiamo anche usare in strumenti il Color Selector, e possiam prelevare le coordinate RGB, HSB e Esadecimale
background(#9DE9FF);

/*Come sappiamo, nell'immagine processing il nostro punto di partenza sta in alto a sinistra.
Quindi l'asse x si sposta in maniera crescente verso destra
E l'asse y si muove in maniera crescente verso il basso
E' importante, passare alla funzione come coordinate, prima la 'x' e poi la 'y' */

/* Noi useremo spesso la funzione dell'ellisse, piuttosto che quella del cerchio.
Avendo un centro immaginiamo due diametri, che in realtà sono due assi, e come sempre passiamo pima il valore dell'asse orizzontale, e dopo quello verticale
  ellipse(x_c, y_c, d_x, d_y) dove le prime due coordinate sono quelle del punto centrale dell'ellissa mentre le altre due sono le diametri orizzontali e verticali */

//Adesso disegnamo un cerchio sulla nostra canvas
stroke(255,0,0); //I parametri equivalgono allo spazio RGB
ellipse(250,250,50,50);  //Abbiamo disegnato un cerchio al centro del foglio
//Di default disegna il cerchio bianco con un bordo nero. E adesso cambieremo il bordo, ossia il tratto, con questa funzione sotto:
// stroke(255,0,0);
//Lo inserisco sopra 'ellipse()' perché su Processing si usa un metodo procedurale

//Ora facciamo una diagonale orizzontale che attraversa la canvas
line(0, 0, 500, 500);
//Come sempre i punti sono x1,y1, x2,y2, ovvero dove parte e dove finisce la linea

//Ipotizziamo di voler cambiare la dimensione della canvas, ad esempio da 500,500 a 700,700
//Poichè le nostre figure non appariranno più al centro, ecco cosa possiamo fare per ovviare al problema
// line(0, 0, width, height);
// ellipse(width/2,height/2,50,50);
// le parole chiave width e height adesso equivalgono alle nostre misure e width/2 e height/2 alla metà, cioè al centro

//all'esame si potrà consultare la guida di riferimento di Processing, si accede anche tramite Help > Reference
//Oppure si seleziona una funzione e con tasto destro si va alla Reference che spiega tutto sulla funzione.

//Se vogliamo una figura senza bordom, basta fare:
// NoStroke(); //In processing i nomi delle funzioni che sono composti da più parole sono Camel Case

//Se invece vogliamo un bordo nero basta fare
// stroke(0);

//Adesso vediamo come utilizzare i colori con le componenti alpha

//Continuo nel secondo file dove svolgeremo un esercizio...
```

```java
//[SECONDO FILE]

size(1000,700);
background(255);
noStroke();
//Per cambiare il colore contenuto in una figura, cioè il riempimento si usa 'fill()'
fill(255,0,0,160); //160 è la trasparenza
ellipse(132,82,200,200);
fill(0,255,0,160);
ellipse(228,-16,200,200); //Possiamo usare anche coordinate negative
fill(0,0,255,160);    
ellipse(268,118,200,200);

//Oltre alla funzione 'noStroke()' esiste anche la funzione 'noFill()'. Ovviamente inserendo la funzione 'fill()' dopo, invalidiamo ciò che abbiamo scritto.
//Quello che farà la funzione noFill() sarà naturalmente quello di NON riempire la figura

//Esiste anche la funzione 'strokeWeight()' che di defualt è 1, e il suo scopo è quello di aumentare la dimensione del tratto

//Continuo nel terzo file dove svolgeremo un esercizio e presenteremo la funzione rettangolo...
```

```java
//[TERZO FILE]
size(1000, 700);
background(255);
noFill();

//Funzione per fare rettangoli e quadrati
  //rect(x,y,l,h);
    //x e y sono del vertice in alto a sinistra
    //l e h sono lunghezza e altezza
rect(50,60,80,80);

//Adesso facciamo un ellisse e un rettangolo con le stesse coordinate
ellipse(50,60,80,80);

//Ipotizziamo di voler cerchio inscritto nel quadrato.
//Ecco che introduciamo le funzioni di modalità.

/*DALLA GUIDA PROCESSING:
ellipseMode(CORNER) interpreta i primi due parametri di ellipse() come angolo superiore sinistro della forma, mentre il terzo e il quarto parametro sono la sua larghezza e altezza.
(Spiegare meglio)*/
ellipseMode(CORNER);
rect(150,60,80,80);
ellipse(150,60,80,80);

//Nel caso della modalità 'RADIUS' cambia il modo di interpretare il terzo ed il quarto parametro, prima erano il diametro, adesso il raggio
/*DALLA GUIDA PROCESSING:
ellipseMode(RADIUS) utilizza i primi due parametri di ellipse() come punto centrale della forma, ma utilizza il terzo e il quarto parametro per specificare metà della larghezza e dell'altezza della forma.
(Spiegare meglio)*/
ellipseMode(RADIUS);
rect(250,60,80,80);
ellipse(250,60,80,80);

//Come si torna alla modalità di deufault? Con 'CENTER'
ellipseMode(CENTER);
rect(350,60,80,80);
ellipse(350,60,80,80);

//L'ultima modalità è 'CORNERS'. Diamo angolo in alto a sinistra, angolo in alto a destra, e lui disegna in questa porzione
/*DALLA GUIDA DI PROCESSING:
ellipseMode(CORNERS) interpreta i primi due parametri di ellipse() come posizione di un angolo del riquadro di delimitazione dell'ellisse e il terzo e il quarto parametro come posizione dell'angolo opposto.
(Spiegare meglio)*/
ellipseMode(CORNERS);
rect(450,60,80,80);
ellipse(450,60,550,160);

//Link a tutte le modalità dell'ellipseMode che spiega bene e con disegni: https://processing.org/reference/ellipseMode_.html

//Esiste anche 'rectMode()' che fanno quasi la stessa cosa ma per i rettangoli

//Passiamo al quarto file...
```

```java
//[QUARTO FILE]

size(1000, 700);
//Andiamo a vedere come "conservare" un colore, e si fa con la variabile 'color'
color c1 = color(204,154,0); //Abbiamo chiamato la funzione 'color()' nella variabile 'color c1' perchhé non possiamo passare tre valori alla funzione, dunque se abbiamo un colore in RGB , dunque con le 3 componenit, lo passiamo alla funzione che si occupa di fare il casting e passarlo alla variabile 'color'
color c2 = #FFCC00;
noStroke();
fill(c1);
rect(0,0,40,height);
fill(c2);
rect(40,0,40,height);
color c3 = get(10,10); //'get()' serve per prelevare un colore nella coordinata corrispondente
fill(c3);
rect(80,0,40,height);
```

```java
//[QUINTO FILE]

size(1000, 700);
// strokeWeight(24);

//Queste linee hanno le punte arrotondate, e si chiamano Cap, se vogliamo modificarle, aggiungiamo prima delle linee delle funzioni
/*
    line(60,25,130,95);
    line(160,25,230,95);
    line(260,25,330,95);
    line(360,25,430,95);

Per la funzione che si usa è 'strokeCap()'
*/

    //line(60,25,130,95);
    //strokeCap(SQUARE);
    //line(160,25,230,95);
    //strokeCap(PROJECT);
    //line(260,25,330,95);
    //strokeCap(ROUND);
    //line(360,25,430,95);

//Qual è la differenza tra SQUARE e PROJECT?
/*
Quando noi abbiamo una linea che abbiamo definito con strokeWeight, Processing prende la nostra linea, e se il nostro strokeWeight equivale a 24 allora mette un margine di 12 da un lato e un lato di 12 da un altro. Per consegnarci uno spessore finale di 24.
- Nel caso di SQUARE allora i cap verranno tagliati
- Nel caso di PROJECT verranno aggiunti 12px alle estremità, ossia ai cap
Infatti una linea PROJECT è più lunga di una SQUARE 
*/

//Una funzione simile si può usare con i rettangoli, che si occupa delle diverse smussature degli spigoli/giunture. I joun sono i punti di giunture nello spigolo
//E la funzione che si usa si chiama 'strokeJoin()'
//strokeWeight(12);
//rect(60,25,70,70);
//strokeJoin(ROUND); //Modifica i jouin con una forma rotonda 
//rect(160,25,70,70);
//strokeJoin(BEVEL); //Modifica i join con una forma smussata
//rect(260,25,70,70);
//strokeJoin(MITER); //Riporta alla forma di defualt del rettangolo, con un forma squadrata (classica forma geometrica rettangolare)
//rect(360,25,70,70);

//Esiste anche la funzione triangle che richiede 6 parametri ((x,y) per ogni punto), l'ordine di inserimento dei vertici nella funzione non ha importaza. 
fill(21, 64, 120);
strokeWeight(10);
triangle(200,400, 200,100, 500,400);
```

```java
//[SESTO FILE]
//Introduciamo i costrutti loop e if/else

size(800,500);
for (int i = 20; i <=400; i+=20){
  stroke(0); //Ristabiliamo lo stroke nero
  line(i,0,i+i/2,height/2); //Linea superiore
  line(i,height,i+i/2,height/2); //Linea orizzontale
  stroke(255,0,0);
  line(20,i,60,i);
}
```

```java
//[SETTIMO FILE]

size(500,500);
background(0);
noStroke();
int d = 40;

for(int x = d/2; x <= height; x+=d){
  for(int y = d/2; y <= width; y+=d){
     ellipse(x,y, d,d);
 }
}
```

```java
//[OTTAVO FILE]
//Introduzione alla modalità interattiva
//Usiamo l'override (spiegare meglio)

//Introduciamo due funzioni di Processing, di tipo 'void' che sono setup e draw
void setup(){ //Qui mettiamo le istruzioni per l'avvio del programma. Viene eseguito una e una sola  volta
  //'print()', per stampare nella console e il cursore rimane lì
  //'println()', per stampare nella console ed andare a new line
  println("sono nel setup"); //Stampato solo una volta
  //frameRate(2); //per cambiare il frame rate, scriverà 2 "sono nel draw" per 2 volte al secondo.
   frameRate(30);
   background(0);
}

//void draw(){//Qui invece implementiamo un ciclo infinito, come se fosse un while == true. Viene eseguito ad 1 frame di default a 60 frame
  //println("sono nel draw "+frameCount+" frame sono passati"); //Stampato 60 volte al secondo //chiarire questa sintassi -> "+frameCount+"
  //frameCount è una variabile che ci fa sapere quanti fotogrammi sono passati dall'inizio dell'interazione
  //if(frameCount > 150){ //passano 5 secondi a 30 frame al secondo
    //ellipse(width/2, height/2, 50,50); //Disegna un elisse a dopo 5 secondi
  //}
//}

//Questo esercizio, dove viene utilizzato frameCount, può essere fatto usando la funzione 'millis()' al posto di frameCount, è una funzione che restituisce i millisecondi passati dall'inizio dell'esecuzione del programma.
//Commenterò l'esercizio con frameCount per mostrare millis()

void draw(){//Qui invece implementiamo un ciclo infinito, come se fosse un while == true. Viene eseguito ad 1 frame di default a 60 frame
  println("sono nel draw "+frameCount+" frame sono passati"); //Stampato 60 volte al secondo //chiarire questa sintassi --> "+frameCount+"
  //frameCount è una variabile che ci fa sapere quanti fotogrammi sono passati dall'inizio dell'interazione
  if(millis() > 5000){ //impostiamo 5000 perché 5 secondi in millisecondi sonoo 5000 (1000 millisecondi in un secondo)
    ellipse(width/2, height/2, 50,50); //Disegna un elisse a dopo 5 secondi
  }
}
```

```java
//[NONO FILE]
//Renderemo interattivo l'esercizio sui cerchi di prima

//mettiamo la variabile 'd' fuori dalle funzioni così ho uno scope più ampio e quidi è globale
  int d = 40;

void setup(){
  size(500,500);
  background(0);
  noStroke();
}

void draw(){

  for(int y = d/2; y <= height; y+=d){
    for(int x = d/2; x <= width; x+=d){
      if(dist(x,y, mouseX, mouseY) < d/2){ //usiamo una variabile che tramite coordinate (x,y) mantiene le coordinate del cursore del nostro mouse.
          //Tenendo conto del fatto che le variabili del nostro mouse sono mouseX e mouseY, quelle del centro del cerchio nella canvas sono xc e yc (dove c sta per centro). Per verificare la condizione verifichiamo le coordinate del mouse con quelle del centro del cerchio. E quindi scriviamo che la distanza di questi due punti è minore di quella del centro. Usiamo la funzione 'dist()' che fa il calcolo della distanza tra le coordinate e il centro).
          //Quindi come condizione abbiamo detto "se la distanza tra questi punti è minore del raggio, allora siamo dentro il cerchio e puoi colorarlo"
        fill(0,0,255);      
      }else{
        fill(255);
      }
      ellipse(x,y,d,d);
    }
  }
}
```

```java
//[DECIMO FILE]
//Cerchiamo di rendere l'esercizio di prima più interattivo, Facciamo in modo che all'aumentare delle coordinate dell'asse X aumenteremo la componente di rosso, e all'aumentare di quelle di Y avremo l'aumento della componente di verde.
//Vuol dire che se siamo nell'angolo in alto a sinistra avremo nero puro, in alto a destra i rosso puro, il basso a sinistra il verde puro e in basso a destra il giallo puro

int d = 40;

void setup(){
  size(500,500);
  background(0);
  noStroke();
  colorMode(RGB, width); //Impostiamo il range [0-500] al posto di [0-255] e usiamo lo spazio colore RGB
}

void draw(){
  for(int y = d/2; y <= height; y+=d){
    for(int x = d/2; x <= width; x+=d){
      if(dist(x,y, mouseX, mouseY) < d/2){
        fill(x,y, width);      
      }else{
        fill(x,y,0);
      }
      ellipse(x,y,d,d);
    }
  }
}
```

```java
//[UNDICESIMO FILE]
//Ipotizziamo di voler disegnare un poliedro, quindi non una delle semplici figura che abbiamo fatto ora
//Per farlo utilizzamo una funzione 'beginShape()', in cui inserire all'interno tutti i vertici 'vertex()' della nostra figura
//Disegnamo su paint e ci segniamo le coordinate della figura, per evitare i calcoli.

size(640, 280);

beginShape(); //unisce i punti forniti successivamente
//per cambiare fill e stroke si fa all'interno della funzione 'beginShape()'
fill(153,176,180); //colore di riempimento
vertex(180,82);
vertex(207,36);
vertex(214,63);
vertex(407,11);
vertex(412,30);
vertex(219,82);
vertex(226,109);
//endShape(); //la figura resta aperta
endShape(CLOSE); //chiude la figura (unisce l'ultimo vertice col primo)

//avremmo anche potuto riscrivere il primo vertice alla fine, come ultimo vertice
```
