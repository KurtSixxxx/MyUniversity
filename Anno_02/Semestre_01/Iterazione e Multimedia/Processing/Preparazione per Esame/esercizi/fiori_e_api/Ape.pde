class Ape{
  //Attributi
  float x, y, speedX, speedY, raggio;
  
  Ape(float x, float y, float speedX, float speedY){
    this.x = x;
    this.y = y;
    this.speedX = speedX; //Come si esclude lo zero?
    this.speedY = speedY; //Ho messo constrain per escludere lo zero ma non credo funzioni
    this.raggio = 15;
  }
  
  void move(){
    x+=speedX;
    y+=speedY;
  }
  
  void display(){
    noStroke();
    fill(255,255,0);
    ellipse(x, y, 2*raggio, 2*raggio);
    stroke(0);
    strokeWeight(2);
    line(x-raggio,y-raggio/2, x+raggio,y-raggio/2);
    line(x-raggio,y+raggio/2, x+raggio,y+raggio/2);
  }
  
  void interagisci(ArrayList<Fiore> fiori) {   // cambio nome in minuscolo
  for (int i = fiori.size() - 1; i >= 0; i--) {
    Fiore f = fiori.get(i);
    if (dist(x, y, f.x, f.y) <= (raggio + f.size/2)) {
      f.pollinate();
      if (f.size <= 10) {
        fiori.remove(i);
        }
      }
    }
  }
}
