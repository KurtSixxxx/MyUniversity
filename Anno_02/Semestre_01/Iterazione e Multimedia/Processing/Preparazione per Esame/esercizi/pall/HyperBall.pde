class HyperBall extends Ball {
  //Attributi
  color c = cambiaColore();

  //Costruttore
  HyperBall() {
    super();
  }

  //Metodi
  void display() {
    noStroke();
    fill(c);
    ellipse(x, y, d, d);
  }

  color cambiaColore() {
    float r, g, b;
    r = random(0, 255);
    g = random(0, 255);
    b = random(0, 255);
    color c = color(r, g, b);
    return c;
  }
}
