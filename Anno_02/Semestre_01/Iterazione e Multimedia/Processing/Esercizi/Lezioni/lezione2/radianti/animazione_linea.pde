int pos = 0; //posizione
int dir = 1; //direzione
int vel = 3; //velocità

void setup() {
  size(500, 500);
}

void draw() {
  background(255);
  line(pos % width, 20, pos % width, height);
  
  if (pos > width || pos < 0) {
    dir = -dir;
  }
  
  pos += dir * vel;
}
