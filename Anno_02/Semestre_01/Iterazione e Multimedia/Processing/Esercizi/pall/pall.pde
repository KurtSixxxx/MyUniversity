ArrayList<Ball> balls;
ArrayList<HyperBall> hyperballs;

void setup() {
  size(600, 400);
  balls = new ArrayList<Ball>();
  hyperballs = new ArrayList<HyperBall>();

  for (int i = 0; i < 3; i++) {
    balls.add(new Ball());
  }

  for (int i = 0; i < 2; i++) {
    hyperballs.add(new HyperBall());
  }
}

void draw() {
  background(200);
  
    for(Ball b : balls){
      b.run();
    }
    
    for(HyperBall hb : hyperballs){
      hb.run();
    }
}

void keyPressed() {
  if (key == 'b' || key == 'B') {
    balls.add(new Ball());
  }

  if (key == 'h' || key == 'H') {
    hyperballs.add(new HyperBall());
  }

  if (key == 'c' || key == 'C') {
    
    for(HyperBall hb : hyperballs){
      hb.c = hb.cambiaColore();
    }
  }

  if (key == 'r' || key == 'R') {
    clear();
  }
}

void clear() {
  for (int i = balls.size() - 1; i >= 0; i--) {
    balls.remove(i);
  }

  for (int i = hyperballs.size() - 1; i >= 0; i--) {
    hyperballs.remove(i);
  }
}
