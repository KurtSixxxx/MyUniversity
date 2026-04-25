Ball b; //Singola pallina. Abbiamo chiamato b una variabile di tipo Ball
Ball b2;
int K; //K ci serve come numero di palline
Ball[] bs;  //Array di palline, il nostro array [] di tipo Ball si chiama bs

ArrayList<Ball> abs; //ARRAYLIST di palline. Stiamo dicendo solo che esiste. E' un array dinamico, quindi a lunghezza variabile

void setup()
{
  background(0);
  size(1000,500);
  K=10;  //Impostiamo K = 10
  
  bs=new Ball[K]; //Nel nostro array fisso mettiamo 10 palline
  abs=new ArrayList<Ball>(); //Nel nostro array dinamico invece allochiamo quante palline vogliamo. Stiamo allocando.
  //Volendo potremmo fare anche tutto in una riga: ArrayList<Ball> abs = new ArrayList<Ball>();  // tutto in una riga
  for(int i=0;i<K;i++)
  {
    //itera sull'array statico, e in ogni indice di i aggiunge una pallina
    bs[i]=new Ball(random(50,450),random(50,450),random(25,70),random(1,10),random(1,10));
  }
  
  /*
  for(int i=0;i<K;i++)
  {
    //La stessa cosa si più fare con l'ArrayList. Aggiunge con il metodo prestabilito .add()
    abs.add(new Ball(random(50,450),random(50,450),random(25,70),random(1,10),random(1,10)));
  }
  */
  
}

void draw()
{
  //background(0);
  fill(0,40);
  rect(0,0,width,height);
  
  
//Questi sono due cicli for per ArrayList
  //1. Modo classico
  for(int i=0; i<K;i++)
  {
    //bs[i].run();
  }
  
  /*
  for(int i=0; i<abs.size();i++)
  {
    abs.get(i).run(); //Vai all'elemento in posizione i dell'ArrayList con la funzione get, e per ognuno di questi chiami run
  }
  */
  
  //2. Modo compatto -> for-each. Si legge: "per ogni Ball b in abs, esegui b.run()"
  for(Ball b:abs) //Prendi ogni elemento di abs, lo metti in un array b di tipo Ball e lo esegui con run
    b.run();
  
}

void keyPressed()
{
  if((key=='N')||(key=='n'))
    abs.add(new Ball(random(50,450),random(50,450),random(25,70),random(1,10),random(1,10)));
}
