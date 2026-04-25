class Bullet {
  float x, y, sx;
  color c;

  Bullet(float x, float y, float sx, color c) {
    this.x = x;
    this.y = y;
    this.sx = sx;
    this.c = c;
  }

  void move() {
    x += sx;
  }

  void display() {
    noStroke();
    fill(c);
    ellipse(x, y, 20, 20);
  }
}
