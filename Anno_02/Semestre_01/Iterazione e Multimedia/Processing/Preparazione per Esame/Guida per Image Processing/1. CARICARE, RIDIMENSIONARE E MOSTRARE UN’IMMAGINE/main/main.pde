//Come caricare e ridimensionare un'immagine

PImage Im; //Creiamo una variabile immagine

void setup(){
  size(768, 256);
  Im = loadImage("lena.png"); //carichiamo il file .png chiamato "lena"
  Im.resize(256,256); //stiamo ridimensionando in 256x256
  image(Im, 0, 0); //abbiamo posizionato l'immagine partendo dall'angolo in alto a sinsitra
}
