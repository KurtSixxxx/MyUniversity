class Forma {
  //Attributi
  float x, y, size, speedX, speedY;
  color colore;

  //Costruttore
  Forma() {
    this.x = random(width);
    this.y = random(height);
    this.size = random(20, 50);
    this.speedX = random(-2, 2);
    this.speedY = random(-2, 2);
    this.colore = color(200);
  }

  //Metodi
  void move() {
    x += speedX;
    y += speedY;
  }

  void bounce() {
    // vuoto, sarà ridefinito nelle sottoclassi
  }

  void special() {
    // vuoto, sarà ridefinito
  }

  void display() {
    // vuoto, sarà ridefinito
  }

  void run() {
    move();
    bounce();
    display();
  }
}
