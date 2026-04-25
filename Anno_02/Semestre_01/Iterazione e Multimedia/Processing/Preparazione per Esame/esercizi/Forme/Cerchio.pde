class Cerchio extends Forma {

  Cerchio() {
    super();
  }

  void display() {
    fill(255, 0, 0);
    ellipse(x, y, size, size);
  }
  
  void bounce() {
    if (x - size/2 <= 0 || x + size/2 >= width) {
      speedX = -speedX;
    } else if (y - size/2 <= 0 || y + size/2 >= height) {
      speedY = -speedY;
    }
  }

  void special() {
    float variazione = random(-5, 5);
    size += variazione;
    size = constrain(size, 10, 80);
  }
}
