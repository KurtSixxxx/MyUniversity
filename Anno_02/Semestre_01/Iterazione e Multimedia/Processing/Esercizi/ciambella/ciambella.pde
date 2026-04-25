//Dichiaro le variabili
PImage donutImage;
boolean donutIsOn = false; //Controlla se la ciambella esiste
float x, y;
float diameterEye = 100; //Diametro occhio
float distanceEyes = 80; //Distanza tra occhi
float pupilSize = 15;
int v = 3; //Velocità di spostamento --> dir += v significa spostati di tot px con tot velocità
float xDonut; //Coordinata asse x della ciambella 
float yDonut; //Coordinata asse y della ciambella
float radius = 50; //Raggio della ciambella

void setup(){
    size(800,800);
    //fullScreen(2);
    donutImage = loadImage("donutImage.png");
}

void draw(){
    background(220, 220, 0); //Sfondo

    noStroke(); //Per l'ellisse dell'ombra il bordo non ci serve
    fill(125, 100); //E l'ombra è grigia con un livello di trasparenza pari a 100
    ellipse(width/2-distanceEyes, height/2+10, diameterEye, diameterEye); //Ombra occhio sinistro
    ellipse(width/2+distanceEyes, height/2+10, diameterEye, diameterEye); //Ombra occhio destro

    stroke(0); //Impostiamo il bordo nero
    strokeWeight(3); //Spessore del cerchio
    fill(255); //Colore bianco dell'occhio

    ellipse(width/2-distanceEyes, height/2, diameterEye, diameterEye); //Occhio sinistro
    ellipse(width/2+distanceEyes, height/2, diameterEye, diameterEye); //Occhio destro
	
    fill(0); //Colore nero della pupilla
    ellipse((width/2-distanceEyes)+x, height/2+y, pupilSize, pupilSize); //Pupilla sinistra
    ellipse((width/2+distanceEyes)+x, height/2+y, pupilSize, pupilSize); //Pupilla destra

    if(donutIsOn == true){
        x = map(xDonut, 0, width, -30, 30); //mapping dell'asse x pupilla con ciambella
        y = map(yDonut, 0, height, -30, 30); //mapping dell'asse y pupilla con ciambella
        
        //?Ciambella disegnata
        /*ellipseMode(RADIUS);
        //Disegno della ciambella
        noStroke();
        fill(125, 100);
        ellipse(xDonut, yDonut+10, radius, radius);
        stroke(0);
        fill(#5e3107);
        ellipse(xDonut, yDonut, radius, radius);
        fill(#9e5109);
        ellipse(xDonut, yDonut, radius/2, radius/2);
        ellipseMode(CENTER);*/

        //?Ciambella con image
        imageMode(CENTER);
        stroke(0);
        strokeWeight(2);
        image(donutImage, xDonut, yDonut, 100, 100);

        //Questo gestisce lo spostamento della ciambella e la velocità
        yDonut +=v;

    if(yDonut > height+100){
            donutIsOn = false;
            yDonut = -50;
    }

    }else{
        x = map(mouseX, 0, width, -30, 30);
        y = map(mouseY, 0, height, -30, 30);
    }  
}

void mouseClicked(){
    donutIsOn = true;
    xDonut = random(50, width-50); //Coordinata asse x della ciambella 
    yDonut = -100; //Coordinata asse y della ciambella
}
