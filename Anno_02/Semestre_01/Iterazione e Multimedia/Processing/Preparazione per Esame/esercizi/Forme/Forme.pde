ArrayList<Forma> forme = new ArrayList<Forma>();

void setup() {
  //Ho scelto io una size dato che non me ne hai fornita una.
  size(512, 512);
  reset();
}

void draw() {
  background(255);
  for (Forma f : forme) {
    f.run();
  }
}

void keyPressed() {
  if (key == 'q' || key == 'Q') {
    forme.add(new Quadrato());
  }

  if (key == 'c' || key == 'C') {
    forme.add(new Cerchio());
  }

  if (key == 's' || key == 'S') {
    for (Forma f : forme) {
      f.special();
    }
  }

  if (key == 'r' || key == 'R') {
      reset();
  }
}

void reset(){
  forme.clear();
  for (int i = 0; i < 3; i++) {
     forme.add(new Quadrato());
    }

  //Aggiungo 2 cerchi
  for (int i = 0; i < 2; i++) {
    forme.add(new Cerchio());
    }
}
