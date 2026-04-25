/*allochi dinamicamente una matrice S di stringhe (char*) di dimensioni N x M;*/
/*allocateS: funzione per allocazione dinamica della matrice di dimensioni NxM, tale matrice va restituita come dato di ritorno al chiamante (funzione main());*/
char*** allocateS(int N, int M) {
 char ***S = calloc(N, sizeof(char**));
 for(int i=0; i< N; i++) {
 S[i] = calloc(M, sizeof(char*));
 }
 return S;
}
/*riempia la matrice S con NxM stringhe di lunghezza k composte di caratteri pseudocasuali in [a-z];*/
/*genString: funzione che restituisce una stringa della lunghezza specificata con caratteri pseudo-casuali in un ben determinato insieme specificato mediante 
opportuni parametri formali;*/
/*Si consideri la seguente funzione get_random() per la generazione di numeri pseudo-casuali interi positivi (qualora necessaria)*/
char* genString(int len, char min, char max) {
 char *s = calloc(len, sizeof(char*));
 for(int i=0; i<len; i++) {
 s[i] = get_random() % (max-min+1) + min;
 }
 return s;
}
/*fillS: funzione di riempimento della matrice S come specificato nel punto C;*/
void fillS(char ***S, int N, int M, int k) {
 for(int i = 0; i<N; i++) {
 	 for(int j=0; j<M; j++) {
 S[i][j] = genString(k, 'a', 'z');
 }
 }
}
/*ordini ogni colonna della matrice S in modo crescente (ordinamento lessicografico) con un algoritmo di ordinamento a scelta tra Insertion Sort e Bubble Sort;*/
/*sortS: funzione di ordinamento della matrice come specificato nel punto D; NB: si faccia uso, al suo interno, della funzione di libreria strcmp();*/
void sortS(char ***S, int N, int M) {
 for(int j=0; j<M; j++) { //scorro le colonne
 for(int pass=0; pass<N-1; pass++) {
 for(int i=0; i<N-1-pass; i++) {
 if(strcmp(S[i][j], S[i+1][j])>0) {
 char *tmp = S[i][j];
 S[i][j] = S[i+1][j];
 S[i+1][j] = tmp;
 }
 }
 }
 }
}
/*stampi la matrice sullo standard output;*/
/*printMatrix: funzione per la stampa della matrice S;*/
void printMatrix(char ***S, int N, int M) {
 for(int i=0; i<N; i++) {
 for(int j=0; j<M; j++) {
 printf("%s ", S[i][j]);
 }
 printf("\n");
 }
}
*allochi dinamicamente una matrice A di numeri double pseudo-casuali in [x,y] di
dimensioni N x N;*/
/*genMatrix: funzione che crea e restituisce una matrice con elementi double
generati dalla funzione genDouble;*/
double ** genMatrix(int N, float x, float y) {
 double **A = calloc(N, sizeof(double*));
 for(int i=0; i<N; i++) {
 A[i] = calloc(N, sizeof(double));
 for(int j=0; j<N; j++) {
 A[i][j] = genDouble(x, y);
 }
 }
 return A;
}
/*calcoli il minimo degli elementi della diagonale principale della matrice (sia mind),
e il massimo valore degli elementi della diagonale secondaria della matrice stessa
(sia maxd); si restituisca inoltre il numero di elementi della matrice aventi valori in
[mind, maxd];*/
/*computeMinMax: calcola mind e maxd e restituisce il numeri di elementi che
ricadono nell’intervallo [mind, maxd] come specificato nel punto C. La funzione
permette di restituire al chiamante anche i valori di mind e maxd;*/
int computeMinMax(double **A, int N, double *mind, double *maxd) {
 *mind = A[0][0];
 *maxd = A[N-1][0];
 for(int i=0; i<N; i++) {
 if(A[i][i]<*mind)
 *mind = A[i][i];
 if(A[i][N-1-i]>*maxd)
 *maxd = A[i][N-1-i];
 }
 int count = 0;
 for(int i=0; i<N; i++) {
 for(int j=0; j<N; j++) {
 if(A[i][j]<=*maxd && A[i][j]>=*mind) {
 count++;
 }
 }
 }
 return count;
}

