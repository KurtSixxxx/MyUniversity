ArrayList<Bullet> bullets = new ArrayList<Bullet>();
Warp[] warps;
int K = 5;

void setup() {
  size(600, 600);
  warps = new Warp[K];
  for (int i = 0; i < K; i++) {
    warps[i] = new Warp(random(50, 550), random(50, 550), color(random(255), random(255), random(255)), random(2, 5));
  }
}

void draw() {
  background(255);
  for (Warp w : warps) {
    w.display();
  }
  for (int i = bullets.size()-1; i >= 0; i--) {
    Bullet b = bullets.get(i);
    b.move();
    b.display();
    //if (b.x > width + 10) bullets.remove(i); Serve per rimuovere i bullet una volta usciti dallo schermo
  }
}

void mousePressed() {
  for (Warp w : warps) {
    if (w.isOver()) {
      bullets.add(w.shot());
    }
  }
}
