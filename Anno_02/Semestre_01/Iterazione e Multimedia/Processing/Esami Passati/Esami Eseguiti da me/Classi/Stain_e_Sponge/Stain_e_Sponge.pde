ArrayList <Stain> listStain;
Sponge mySponge;

void setup() {
  size(700, 700);
  listStain = new ArrayList<Stain>();
  mySponge = new Sponge();
}

void draw() {
  background(135, 206, 235);

  mySponge.posX = mouseX;
  mySponge.posY = mouseY;
  mySponge.display();

  for (int i = listStain.size() - 1; i >= 0; i--) {
    Stain s = listStain.get(i);
    s.run();
    boolean value = mySponge.absorb(s);

    if (value == true) {
      listStain.remove(i);
    }
  }
}

void keyPressed() {
  if (key == 'S' || key == 's') {
    float rx = random(50, 650);
    float rd = random(10, 50);
    color rc = color(random(0, 255), random(0, 255), random(0, 255));

    listStain.add(new Stain(rx, -30, rd, rc));
  }

  if (key == 'R' || key == 'r') {
    mySponge = new Sponge();
  }
}

class Stain {

  //Attributi
  float posX, posY;
  float D;
  color c;

  //Costruttore
  Stain(float x, float y, float d, color colorePassato) {
    this.posX = x;
    this.posY = y;
    this.D = d;
    this.c = colorePassato;
  }

  //Metodi
  void display() {
    noStroke();
    fill(c);
    circle(posX, posY, D);
  }

  void move() {
    posX += random(-1, 1);
    posY += random(0, 4);
  }

  void run() {
    display();
    move();
  }
}

class Sponge {

  //Attributi
  float posX, posY;
  float L;
  color c;

  //Costruttore
  Sponge() {
    this.posX = mouseX;
    this.posY = mouseY;
    this.L = 30;
    this.c = color(200, 200, 100);
  }

  //Metodi
  void display() {
    noStroke();
    fill(c);
    rectMode(CENTER);
    square(posX, posY, L);
  }

  boolean absorb(Stain s) {
    /*float distanza = dist(posX, posY, s.posX, s.posY);
    float raggioTotale = (L/2) + (s.D/2);
    if (distanza < raggioTotale) {
      L += s.D/2;
      float newR = (red(s.c) + red(c))/2;
      float newG = (green(s.c) + green(c))/2;
      float newB = (blue(s.c) + blue(c))/2;
      c = color(newR, newG, newB);
      return true;
    } else {
      return false;
    }*/
    // 1. Mi calcolo il raggio della macchia (il prof ricorda di usarlo!)
    float raggio = s.D / 2;
    
    // 2. Mi calcolo la distanza dal centro della spugna ai suoi bordi 
    // (essendo rectMode(CENTER), il bordo dista mezza lunghezza dal centro)
    float metaLato = this.L / 2;

    // 3. CONTROLLO I 4 CONFINI:
    // Il cerchio è interamente nel quadrato se si verificano TUTTE queste 4 condizioni:
    if (s.posX - raggio >= this.posX - metaLato && // Il lato sx del cerchio non esce a sx del quadrato
        s.posX + raggio <= this.posX + metaLato && // Il lato dx del cerchio non esce a dx del quadrato
        s.posY - raggio >= this.posY - metaLato && // La cima del cerchio non esce in alto dal quadrato
        s.posY + raggio <= this.posY + metaLato)   // Il fondo del cerchio non esce in basso dal quadrato
    {
      
      // Se entra in questo if, significa che il cerchio è tutto dentro!
      
      // A) Aumento la dimensione della spugna della metà del diametro (cioè il raggio)
      this.L = this.L + raggio; // [1]
      
      // B) Faccio la media dei colori canale per canale [1]
      float mediaRed = (red(this.c) + red(s.c)) / 2;
      float mediaGreen = (green(this.c) + green(s.c)) / 2;
      float mediaBlue = (blue(this.c) + blue(s.c)) / 2;
      
      this.c = color(mediaRed, mediaGreen, mediaBlue);
      
      // C) Restituisco true come richiede l'esame [1]
      return true;
      
    } else {
      
      // Se il cerchio non è TUTTO dentro, la traccia dice: 
      // "non accade nulla e viene restituito false" [1]
      return false;
      
    }
  }
}
