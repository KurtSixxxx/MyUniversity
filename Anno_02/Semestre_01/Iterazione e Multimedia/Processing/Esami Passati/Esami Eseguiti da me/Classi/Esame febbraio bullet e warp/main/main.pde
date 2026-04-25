int K;
ArrayList <Warp> warp;
ArrayList <Bullet> bullets = new ArrayList<Bullet>();

void setup(){
  size(600,600);
  K = 6;
  warp = new ArrayList <Warp>();
  for(int i = 0; i < K; i++){
    warp.add(new Warp());
  }
}

void draw(){
  background(255);
    for(Warp w : warp){
      w.display();
    } 
    
    for(Bullet b : bullets){
      b.run();
    }
}

void mousePressed() {
  for (Warp w : warp) {
    if (w.isIn()) {
      bullets.add(w.shot());
    }
  }
}
