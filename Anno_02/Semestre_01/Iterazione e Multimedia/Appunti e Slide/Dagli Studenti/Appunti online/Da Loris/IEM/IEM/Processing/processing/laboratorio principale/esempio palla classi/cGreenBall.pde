class GreenBall extends Ball {

  GreenBall(float x, float y, float s, float sx, float sy) {
    super(x, y, s, sx, sy); // usa il parametro s, non il campo
  }

  GreenBall(float x, float y, float s) {
    super(x, y, s, 0, 0);
  }

  void display() {
    fill(0, 255, 0);
    strokeWeight(4);
    stroke(255, 0, 255);
    ellipse(posX, posY, size, size);
  }

  void gravity() {
    sy += 0.5;
  }
}
