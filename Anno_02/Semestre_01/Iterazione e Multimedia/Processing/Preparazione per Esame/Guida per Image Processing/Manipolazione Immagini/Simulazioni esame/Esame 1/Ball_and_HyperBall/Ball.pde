class Ball {
  //Attributi
  float x, y, r, sy;

  //Costruttore
  Ball() {
    this.x = random(r, width/2);
    this.y = random(0, height - r);
    this.r = 40;
    this.sy = 5;
  }

  //Metodi
  void display() {
    noStroke();
    fill(255, 0, 0);
    ellipseMode(RADIUS);
    ellipse(x, y, r, r);
  }

  void move() {
    y += sy;
  }

  void bounce() {
    if (y >= height || y <= 0) {
      sy = -sy;
    }
  }

  void run() {
    display();
    move();
    bounce();
  }
}
