/*
Esercizio 1
- Implementare una classe Monitor con le seguenti caratteristiche: la classe è identificata da una posizione, una velocità lungo x, una lunghezza w di 60 px e una altezza h. Appare come un oggetto a forma di monitor di colore random, di dimensioni tali da avere altezza aspect ratio 16:9. Il bordo del monitor è spesso 5 pixel, anch'esso di colore random. Si muove in base alle sue velocità. Quando Monitor esce dalla parte destra dello schermo rientra dalla parte sinistra e viceversa.

- Estendere tramite ereditarietà la classe Monitor definendo OldMonitor. Questi differisce da Monitor poiché i suoi colori sono Verde (schermo) e Grigio (bordo), e la sua dimensione ha medesima lunghezza del monitor, ma aspect ratio a 4:3. In aggiunta, fintato che il puntatore del mouse si trova approssimativamente all'interno di OldMonitor, l'oggetto resta immobile.

[OBBLIGATORIO PER VALUTARE I PUNTI PRECEDENTI]
Alla pressione di "R" o "r" lo sketch viene resettato. Implementare uno sketch in cui si apre una finestra di dimensioni 512x512 e sfondo bianco. Ad ogni ciclo di draw la finestra viene aggiornata.
- Nella metà superiore istanziare un oggetto di tipo Monitor che si muove in base al comportamento definito. La posizione iniziale è a 10 px dal bordo in alto a sinistra, mentre la velocità iniziale è casuale e compresa tra -5 e 5, escluso lo zero.
- Nella metà inferiore dello schermo va istanziato un oggetto OldMonitor, a 10px dal bordo inferiore e da quello sinistro. Si muove e cambia dimensione in base al comportamento definito, velocità uguale per modulo a quella di Monitor, ma di verso opposto.
*/  
  
  ArrayList <Monitor> mo;
  
  void setup(){
    size(512,512);
    mo = new ArrayList<Monitor>();
    mo.add(new Monitor());
    mo.add(new OldMonitor());
  }
  
  void draw(){
    background(255);
    for(Monitor m : mo){
      m.run();
    }
  }
  
  void keyPressed(){
    if(key == 'R' || key == 'r'){
       mo.clear();
    }
  }
  
  
