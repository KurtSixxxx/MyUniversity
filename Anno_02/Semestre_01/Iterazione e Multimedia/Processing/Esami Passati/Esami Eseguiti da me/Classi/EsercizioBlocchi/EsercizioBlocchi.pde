Block block;
AmazingBlock amBlock;

void setup(){
  size(256,512);
  reset();
}

void draw(){
  background(0);
  block.run();
  amBlock.run();
}

void reset(){
      block = new Block(random(60,width-60),height/2-40,40,60);
      amBlock = new AmazingBlock(random(60,width-60),height/2+40,40,60);
}

void keyPressed() {
  if (key == 'r' || key == 'R') {
    reset(); // REINIZIALIZZA gli oggetti, non pulisce solo lo schermo
  }
}
