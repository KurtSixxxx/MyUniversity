Ball b;
ArrayList <Ball> ab;

void setup(){
  size(800,500);
  ab=new ArrayList <Ball>();
}

void draw(){
  noStroke();
  fill(0,40);
  rect(0,0,width, height);
  for(Ball b: ab){
    b.run();
  }
}

void keyPressed(){
  if(key == 'n' || key== 'N'){
    ab.add(new Ball(random(50, 750), random(50,450), random(20,70), random(1,10), random(1,10)));
  }
  
  if(key == 'g' || key== 'G'){
    ab.add(new GreenBall(random(50, 750), random(50,450), random(20,70), random(1,10), random(1,10)));
  }
  
  switch(key){
    case 'p':{
      noLoop();
      break;
    }
    
    case 's':{
      loop();
      break;
    }
    default:{}
  }
}
