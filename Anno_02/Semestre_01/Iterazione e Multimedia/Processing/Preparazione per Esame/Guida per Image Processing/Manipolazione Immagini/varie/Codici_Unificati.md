# Raccolta Codici Processing

## Cartella: Bullet e Warp

### File: Bullet.pde
```java
class Bullet {
  float x, y, sx;
  color c;

  Bullet(float x, float y, float sx, color c) {
    this.x = x;
    this.y = y;
    this.sx = sx;
    this.c = c;
  }

  void move() {
    x += sx;
  }

  void display() {
    noStroke();
    fill(c);
    ellipse(x, y, 20, 20);
  }
}

```

### File: Warp.pde
```java
class Warp {
  float x, y, v;
  color c;

  Warp(float x, float y, color c, float v) {
    this.x = x;
    this.y = y;
    this.c = c;
    this.v = v;
  }

  void display() {
    noStroke();
    fill(0);
    ellipse(x, y, 70, 70);
    fill(128);
    ellipse(x, y, 60, 60);
    fill(c);
    ellipse(x, y, 50, 50);
    fill(255);
    textAlign(CENTER, CENTER);
    textSize(40);
    text(int(v), x, y);
  }

  Bullet shot() {
    return new Bullet(x, y, v, c);
  }

  boolean isOver() {
    return dist(mouseX, mouseY, x, y) < 25;
  }
}

```

### File: responsible_lilac.pde
```java
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

```

---

## Cartella: EsercizioBlocchi

### File: AmazingBlock.pde
```java
class AmazingBlock extends Block{
  float angle = random(0,360);
  
   AmazingBlock(float x, float y, float w, float h){
     super(x,y,w,h);
   }
  
    void display(){
      fill(angle%256, 255-angle%256, 255);
      noStroke();
      pushMatrix();
        translate(width/2, height/2+h);
        rotate(radians(angle));
        rectMode(CENTER);
        rect(0,0,w,h);
      popMatrix();
   }
  
    void move(){
    x += sx;
      if(x >= width || x+w/2 <= 0){
        sx = -sx;
      }
    angle += 5;
    }
  
  void run(){
    display();
    move();
  }
  
  
}

```

### File: Block.pde
```java
class Block{
  float x, y, w, h;
  float sx = 4;
  
  Block(float x, float y, float w, float h){
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
  }
  
  void display(){
    fill(0,255,0);
    noStroke();
    rect(x,y,w,h);
   }
   
  void move(){
    x += sx;
      if(x >= width || x+w/2 <= 0){
        sx = -sx;
      }
  }
  
  void run(){
    display();
    move();
  }
}

```

### File: EsercizioBlocchi.pde
```java
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

```

---

## Cartella: Rocket_e_RockePro

### File: Rocket.pde
```java
class Rocket{
float c1 = random(0,255);
float c2 = random(0,255);
float c3 = random(0,255);
  //Attributi
  float posX,posY,vY,widthR,heightR;
  
  //Costruttore
  Rocket(){
    posX = random(widthR, width/2-widthR);
    posY = random(heightR, height-heightR);
    vY = random(3,8);
    widthR = 40;
    heightR = 80;
  }
  
  void display(){
    stroke(0);
    strokeWeight(3);
    fill(c1,c2,c3);
    rect(posX, posY, widthR, heightR);
    triangle(posX,posY, posX+widthR/2,posY-heightR/2, posX+widthR,posY);
  }
  
  void move(){
    posY -= vY;
    
    if(posY + widthR <= -heightR){
      posY = height-10;
    }
  }
  
  void run(){
    display();
    move();
  }
}

```

### File: RocketPro.pde
```java
class RocketPro extends Rocket{
   
  RocketPro(){
    super();
    posX = random(width/2 + widthR, width-widthR); ;
    posY = random(heightR, height-heightR);
    vY *= 2;
  }
  
    void display(){
    stroke(0);
    strokeWeight(3);
    fill(255,0,0);
    rect(posX, posY, widthR, heightR);
    triangle(posX,posY, posX+widthR/2,posY-heightR/2, posX+widthR,posY);
    
    float posYc = posY;
    float alpha = 150;
    fill(255,255,0, alpha);
    circle(posX+widthR/2, posYc+heightR, widthR);
    
    disegnaScia();
  }
  
void disegnaScia(){
  noStroke();
  
  // Facciamo un ciclo di 10 cerchi che "escono" dal fondo del razzo
  for (int i = 0; i < 10; i++) {
    // Calcoliamo l'opacità: più i è alto (cerchio lontano), più alpha è basso
    float alpha = 150 - (i * 15); 
    
    // Calcoliamo la dimensione: il cerchio si rimpicciolisce man mano
    float diametro = widthR - (i * 2);
    
    // Il colore diventa più arancione man mano che si allontana
    fill(255, 255 - (i * 20), 0, alpha);
    
    // Posizioniamo il cerchio sotto il razzo
    // L'aggiunta di (i * 5) sposta ogni cerchio un po' più in basso del precedente
    circle(posX + widthR/2, posY + heightR + (i * 5), diametro);
    }
  }
}

/*
Metto il cerchio giallo al centro in basso del rect
poi creo una sua posy, tipo posyCer
e faccio
posyCer = posY
poi faccio posyCer++
e metto anche che all'aumentare di posyCer diminuisce l'opacità gialla di colore
*/

```

### File: Rocket_e_RockePro.pde
```java
Rocket rocket = new Rocket();
RocketPro rocketPro = new RocketPro();

void setup(){
  size(512,512);
  reset();
}

void draw(){
  background(0);
  
  rocket.run();
  rocketPro.run();
}

void reset(){
  rocket = new Rocket();
  rocketPro = new RocketPro();
}


void keyPressed(){
  if(key == 'R' || key == 'r'){
    reset();
  }
}

```

---

