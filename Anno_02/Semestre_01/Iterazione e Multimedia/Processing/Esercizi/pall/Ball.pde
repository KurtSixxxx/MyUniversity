class Ball {
  //Attributi
  float x, y, d, sy;

  //Costruttore
  Ball() {
    this.d = random(30, 60);
    this.x = random(d/2, width-d/2);
    this.y = random(d/2, height-d/2);
    this.sy = random(-3, 3);
  }

  //Metodi
  void display() {
    noStroke();
    fill(255, 0, 0);
    ellipse(x, y, d, d);
  }

  void move() {
    y += sy;
  }

  void rimbalza() {
    if (y + d/2 >= height || y - d/2 <= 0) {
      sy = -sy;
    }
  }

  //Metodo run -> chiama tutti i metodi di tipo void insieme
  void run() {
    display();
    move();
    rimbalza();
  }
}
