class HyperBall extends Ball {

  //Attributi
  color colore;

  //Costruttore
  HyperBall() {
    this.x = random(width/2, width - r);
    this.y = random(0, height - r);
    this.r = 40;
    colore = color(0, 0, 255);
  }

  //Metodi
  void pointer() {
    if (dist(x, y, mouseX, mouseY) <= r) {
      colore = color(random(255), random(255), random(255));
    }
  }
  
  void display() {
    noStroke();
    fill(colore);
    ellipseMode(RADIUS);
    ellipse(x, y, r, r);
  }

  void run() {
    display();
    move();
    bounce();
    pointer();
  }
}
