PImage Im, Ic;

float n = 3;//deve essere dispari
float k = 1.0/(n*n);

float [][] n_3box={{k,k,k},{k,k,k},{k,k,k}};

float[][] lapl={{-1,0,-1},{0,4,0},{-1,0,-1}};
                 
float [][] sobX={{-1,-2,-1},{0,0,0},{1,2,1}};

float [][] sobY={{-1,0,1},{-2,0,2},{-1,0,1}};

float [][] prewittX={{-1,-1,-1},{0,0,0},{1,1,1}};

float [][] prewittY={{-1,0,1},{-1,0,1},{-1,0,1}};

float [][] sharp={{-1,0,-1},{0,5,0},{-1,0,-1}};

float [][] binomiale_3={{1,2,1},{2,4,2},{1,2,1}};
//tutti  per *1/16

float [][] binomiale_5={{1,4,6,4,1},{4,16,24,16,4},{6,24,36,24,6},{4,16,24,16,4},{1,4,6,4,1}};
//tutti per *1/256

ArrayList<float[][]> kernel = new ArrayList<float [][]>();
int t=0;

void setup(){
  n = 5;
  k = 1.0/(n*n);
  float [][] n_5box={{k,k,k,k,k},{k,k,k,k,k},{k,k,k,k,k},{k,k,k,k,k},{k,k,k,k,k}};
  
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      binomiale_3[i][j]*=1.0/16.0;
    }
  }
      
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      binomiale_5[i][j]*=1.0/256.0;
    }
  }
  
  kernel.add(n_3box);
  kernel.add(n_5box);
  kernel.add(binomiale_3);
  kernel.add(binomiale_5);
  kernel.add(sobX);
  kernel.add(sobY);
  kernel.add(prewittX);
  kernel.add(prewittY);
  kernel.add(lapl);
  kernel.add(sharp);
      
  size(1000,500);
  Im = loadImage("lena.jpg");
  Im.resize(500,500);
  Im.filter(GRAY);
}

void draw(){
  Ic = convoluzione(Im, kernel.get(t));
  image(Im,0,0);
  image(Ic,500,0);
}

void keyPressed(){
  if(key=='+'){
    if(t<9)
      t++;
    else
      t=0;
  }
  if(key=='-'){
    if(t>0)
      t--;
    else
      t=9;
  }
}
  

PImage convoluzione(PImage I, float[][] K){

  float[][] R=new float[I.height][I.width];
  int N=K[0].length;
  int M=K.length;
  PImage tmp;
  float res;
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height;y++){
      tmp=I.get(x-N/2, y-M/2, N, M);
      res=0;
      
      for(int p=0; p<N; p++){
        for(int q=0; q<M;q++){
          res+=green(tmp.get(p,q))*K[q][p];//attenzione agli indici
        }
      }
      R[y][x]=res;     
      
    }
  }  
  return converti(R);
}

PImage converti(float[][] F){
  PImage R=createImage(F[0].length,F.length,RGB);
  
  float res=0;
  for(int x=0; x<R.width;x++){
    for(int y=0; y<R.height;y++){
      res=constrain(F[y][x],0,255);//attenzione agli indici
      R.set(x,y,color(res));
    }
  } 
  return R;
}
