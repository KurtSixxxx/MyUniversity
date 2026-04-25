PImage I, subI;
String url;

void setup() {
  size(432, 432);
  url = "https://media.laregione.ch/files/domains/laregione.ch/images/4by1/s_-homer-quando-va-essere-quel-pdcb.jpg";
  I = loadImage(url);
  I.resize(int(I.width / 2.5), int(I.height / 2.5));

  // Centro il ritaglio
  int w = 150;
  int h = 150;
  int startX = I.width / 2 - w / 2;
  int startY = I.height / 2 - h / 2;
  subI = I.get(startX, startY, w, h);

  // Grayscale
  I.filter(GRAY);

  // Disegno e salvo
  image(I, 0, 0);
  image(subI, width / 2, height / 2);
  
  subI.save("homerPorzione.png");
  saveFrame("composizione.png");
}

void draw() {}
