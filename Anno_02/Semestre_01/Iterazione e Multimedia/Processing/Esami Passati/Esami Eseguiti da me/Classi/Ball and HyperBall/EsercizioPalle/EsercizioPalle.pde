Ball ball;
HyperBall hyper;

void setup() {
  size(512, 256);
  reset(); // Uso una funzione esterna per poterla richiamare nel keyPressed
}

void reset() {
  float r = 40;
  // Posizione casuale: x tra 0 e metà finestra, y tra 0 e altezza
  ball = new Ball(random(r, width/2 - r), random(r, height - r), r);
  hyper = new HyperBall(random(width/2 + r, width - r), random(r, height - r), r);
}

void draw() {
  background(0);
  ball.run();
  hyper.run();
}

void keyPressed() {
  if (key == 'r' || key == 'R') {
    reset(); // REINIZIALIZZA gli oggetti, non pulisce solo lo schermo
  }
}

class Ball {
  float posX, posY;
  float sY = 5;
  float R;

  Ball(float x, float y, float r) {
    this.posX = x;
    this.posY = y;
    this.R = r;
  }

  void display() {
    noStroke();
    fill(255, 0, 0); // Rosso per Ball
    ellipseMode(RADIUS); // Imposto RADIUS così R è davvero il raggio
    ellipse(posX, posY, R, R);
  }

  void move() {
    posY += sY;
    if (posY >= height || posY <= 0) {
      sY *= -1;
    }
  }

  void run() {
    display();
    move();
  }
}

class HyperBall extends Ball {
  color c = color(0, 0, 255); // Default Blu

  HyperBall(float x, float y, float r) {
    super(x, y, r);
  }

  // Sovrascrivo display per usare il colore c
  void display() {
    noStroke();
    fill(c);
    ellipseMode(RADIUS);
    ellipse(posX, posY, R, R);
  }

  void isIn() {
    if (dist(mouseX, mouseY, posX, posY) <= R) {
      c = color(random(255), random(255), random(255));
    }
  }

  void run() {
    isIn(); // Controllo il mouse prima di disegnare
    display();
    move();
  }
}
