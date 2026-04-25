class Quadrato extends Forma {

  Quadrato() {
    super();
  }

  void bounce() {
    if (x + size/2 >= width || x - size/2 <= 0) {
      speedX = -speedX;
    } else if (y + size/2 >= height || y - size/2 <= 0) {
      speedY = -speedY;
    }
  }

  void display() {
    fill(colore);
    rectMode(CENTER);
    rect(x, y, size, size);
  }

  void special(){
    colore = color(random(255), random(255), random(255));
  }
}
