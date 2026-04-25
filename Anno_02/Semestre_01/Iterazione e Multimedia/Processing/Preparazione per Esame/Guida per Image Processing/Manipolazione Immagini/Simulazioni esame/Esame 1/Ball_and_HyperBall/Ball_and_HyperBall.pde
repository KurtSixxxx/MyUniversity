Ball ball;
HyperBall hyper;

void setup() {
  size(512, 256);
  reset();
}

void draw() {
  background(200);
  ball.run();
  hyper.run();
}

void reset() {
  ball = new Ball();
  hyper = new HyperBall();
}

void keyPressed() {
  if (key == 'r' || key == 'R') {
    reset();
  }
}
