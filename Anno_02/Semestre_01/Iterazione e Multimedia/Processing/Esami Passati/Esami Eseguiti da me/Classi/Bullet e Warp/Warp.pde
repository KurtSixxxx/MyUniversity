class Warp {
  float x, y, v;
  color c;

  Warp(float x, float y, color c, float v) {
    this.x = x;
    this.y = y;
    this.c = c;
    this.v = v;
  }

  void display() {
    noStroke();
    fill(0);
    ellipse(x, y, 70, 70);
    fill(128);
    ellipse(x, y, 60, 60);
    fill(c);
    ellipse(x, y, 50, 50);
    fill(255);
    textAlign(CENTER, CENTER);
    textSize(40);
    text(int(v), x, y);
  }

  Bullet shot() {
    return new Bullet(x, y, v, c);
  }

  boolean isOver() {
    return dist(mouseX, mouseY, x, y) < 25;
  }
}
