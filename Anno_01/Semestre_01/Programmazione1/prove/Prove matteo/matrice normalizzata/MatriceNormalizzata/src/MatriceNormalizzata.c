#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<libgen.h>
#include "MatriceNormalizzata.h"

bool compreso(int x)
{
    return (x>=5) && (x<=10);
}

/**
 * @brief Trova il valore massimo in una colonna della matrice.
 *
 * @param mat Puntatore triplo alla matrice di double (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Indice della colonna da analizzare.
 *
 * @return Il valore massimo trovato nella colonna m.
 *
 * @note La funzione assume che n > 0 e che m sia un indice valido.
 */
double getMax(double***mat, size_t n, size_t m)
{
    double max=*mat[0][m];
    for(int i=1; i<=n-1; i++)
    {
        if(max<=*mat[i][m])
        {
            max=*mat[i][m];
        }
    }
    return max;
}

/**
 * @brief Ordina in modo crescente gli elementi di una colonna usando insertion sort.
 *
 * Implementa l'algoritmo insertion sort per ordinare gli elementi della colonna m
 * della matrice in ordine crescente. Se la matrice contiene meno di 2 righe,
 * la funzione non esegue alcuna operazione.
 *
 * @param mat Puntatore triplo alla matrice di double (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Indice della colonna da ordinare.
 *
 * @complexity
 * - Caso migliore (array già ordinato): O(n) - il ciclo while non esegue scambi.
 * - Caso medio: O(n²) - in media il ciclo while esegue n/2 iterazioni per ogni i.
 * - Caso peggiore (array ordinato al contrario): O(n²) - il ciclo while esegue i iterazioni per ogni i.
 *
 * @note La funzione modifica la matrice originale in-place.
 * @warning Richiede che n >= 2 per ordinare; per n < 2 non fa nulla.
 */
void insertionsort(double***mat, size_t n, size_t m)
{
    if(n>=2)
    {
        for(int i=1; i<=n-1; i++)
        {
            double*key=mat[i][m];
            int j=i-1;
            while((j>=0) && (*mat[j][m]>*key))
            {
                mat[j+1][m]=mat[j][m];
                j--;
            }
            mat[j+1][m]=key;
        }
    }
}

/**
 * @brief Ordina in modo crescente gli elementi di una colonna usando bubble sort.
 *
 * Implementa l'algoritmo bubble sort per ordinare gli elementi della colonna m
 * della matrice in ordine crescente. Se la matrice contiene meno di 2 righe,
 * la funzione non esegue alcuna operazione. Include un'ottimizzazione che interrompe
 * il ciclo se nessuno scambio avviene in una passata.
 *
 * @param mat Puntatore triplo alla matrice di double (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Indice della colonna da ordinare.
 *
 * @complexity
 * - Caso migliore (array già ordinato): O(n) - la prima passata non esegue scambi e il ciclo si interrompe.
 * - Caso medio: O(n²) - in media sono necessarie n/2 passate per ordinare l'array.
 * - Caso peggiore (array ordinato al contrario): O(n²) - sono necessarie n passate complete.
 *
 * @note La funzione modifica la matrice originale in-place.
 * @warning Richiede che n >= 2 per ordinare; per n < 2 non fa nulla.
 */
void bubblesort(double***mat, size_t n, size_t m)
{
    if(n>=2)
    {
        for(int pass=0; pass<=n-1; pass++)
        {
            bool swapped=false;
            for(int i=0; i<n-1-pass; i++)
            {
                if(*mat[i][m]>*mat[i+1][m])
                {
                    double*a=mat[i][m];
                    mat[i][m]=mat[i+1][m];
                    mat[i+1][m]=a;
                    swapped=true;
                }
            }
            if(!swapped)
            {
                break;
            }
        }
    }
}

/**
 * @brief Ordina in modo crescente gli elementi di una colonna usando selection sort.
 *
 * Implementa l'algoritmo selection sort per ordinare gli elementi della colonna m
 * della matrice in ordine crescente. Se la matrice contiene meno di 2 righe,
 * la funzione non esegue alcuna operazione. Ad ogni iterazione trova l'elemento
 * minimo nella porzione non ordinata e lo scambia con l'elemento corrente.
 *
 * @param mat Puntatore triplo alla matrice di double (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Indice della colonna da ordinare.
 *
 * @complexity
 * - Caso migliore (array già ordinato): O(n²) - esegue comunque tutti i confronti.
 * - Caso medio: O(n²) - il numero di confronti non varia rispetto al caso peggiore.
 * - Caso peggiore (array ordinato al contrario): O(n²) - numero fisso di confronti.
 *
 * @note La funzione modifica la matrice originale in-place.
 * @note A differenza di bubble sort e insertion sort, selection sort ha sempre complessità O(n²).
 * @warning Richiede che n >= 2 per ordinare; per n < 2 non fa nulla.
 */
void selectionsort(double***mat, size_t n, size_t m)
{
    if(n>=2)
    {
        for(int i=0; i<=n-2; i++)
        {
            int min=i;
            for(int j=i+1; j<=n-1; j++)
            {
                if(*mat[j][m]<*mat[min][m])
                {
                    min=j;
                }
            }
            if(min!=i)
            {
                double*a=mat[i][m];
                mat[i][m]=mat[min][m];
                mat[min][m]=a;
            }
        }
    }
}

/**
 * @brief Ordina in modo crescente gli elementi di una colonna usando quick sort.
 *
 * Implementa l'algoritmo quick sort ricorsivo per ordinare gli elementi della colonna m
 * della matrice in ordine crescente. Utilizza il metodo della partizione di Hoare con
 * pivot scelto come elemento centrale dell'intervallo [sx, dx].
 *
 * @param mat Puntatore triplo alla matrice di double (mat[i][j]).
 * @param sx Indice sinistro dell'intervallo da ordinare (inclusivo).
 * @param dx Indice destro dell'intervallo da ordinare (inclusivo).
 * @param m Indice della colonna da ordinare.
 *
 * @complexity
 * - Caso migliore: O(n log n) - il pivot divide sempre l'array in due parti bilanciate.
 * - Caso medio: O(n log n) - in media il pivot produce divisioni ragionevoli.
 * - Caso peggiore: O(n²) - il pivot è sempre il minimo o massimo dell'intervallo.
 *
 * @note La funzione modifica la matrice originale in-place.
 * @note È una funzione ricorsiva; per ordinare l'intera matrice usare sx=0, dx=n-1.
 * @warning Richiede che sx <= dx e che gli indici siano validi.
 */
void quicksort(double***mat, ssize_t sx, ssize_t dx, size_t m)
{
    ssize_t i=sx, j=dx;
    double pivot=*mat[(i+j)>>1][m];
    while(i<=j)
    {
        while(*mat[i][m]<pivot)
        {
            i++;
        }
        while(*mat[j][m]>pivot)
        {
            j--;
        }
        if(i<=j)
        {
            double*a=mat[i][m];
            mat[i][m]=mat[j][m];
            mat[j][m]=a;
            i++;
            j--;
        }
    }
    if(sx<j)
    {
        quicksort(mat,sx,j,m);
    }
    if(i<dx)
    {
        quicksort(mat,i,dx,m);
    }
}

/**
 * @brief Legge e valida gli argomenti da riga di comando.
 *
 * Analizza gli argomenti da riga di comando e restituisce una struttura Elem
 * contenente il nome del file di input e le dimensioni della matrice (righe e colonne).
 * Valida che il numero di argomenti sia corretto e che le dimensioni rientrano
 * nell'intervallo consentito [5, 10].
 *
 * @param nArgs Numero di argomenti da riga di comando.
 * @param args Array di stringhe contenente gli argomenti da riga di comando.
 *
 * @return Puntatore a una struttura Elem contenente i dati validati, oppure NULL se
 *         il numero di argomenti è errato o le dimensioni non sono valide.
 *         La memoria allocata deve essere liberata dal chiamante.
 *
 * @note Il primo argomento (args[0]) è il nome del programma.
 *       Gli argomenti attesi sono: <file.txt> <righe> <colonne>.
 * @note In caso di errore, viene stampato un messaggio su stderr.
 * @warning Il chiamante è responsabile di liberare la memoria allocata con free().
 */
Elem*readInput(size_t nArgs, char**args)
{
    Elem*elem=NULL;
    if(nArgs!=4)
    {
        fprintf(stderr,"usage: %s <file.txt> <rows in [5;10]> <columns in [5;10]>\n",basename(args[0]));
    }
    else
    {
        char filename[FILENAME_MAX];
        strcpy(filename,args[1]);
        size_t n=atoi(args[2]), m=atoi(args[3]);
        if((compreso(n)) && (compreso(m)))
        {
            elem=malloc(sizeof(Elem));
            strcpy(elem->filename,filename);
            elem->n=n;
            elem->m=m;
        }
        else
        {
            fprintf(stderr,"%s: Rows and columns out of range\n",basename(args[0]));
        }
    }
    return elem;
}

/**
 * @brief Alloca dinamicamente una matrice di puntatori a double.
 *
 * Crea una struttura mat[i][j] dove ogni elemento è un puntatore a un double.
 * La memoria viene inizializzata a zero tramite calloc.
 *
 * @param n Numero di righe della matrice.
 * @param m Numero di colonne della matrice.
 *
 * @return Puntatore triplo (double***) alla matrice allocata. 
 *         La memoria allocata deve essere liberata dal chiamante.
 *
 * @note La memoria viene inizializzata a zero (calloc).
 * @warning Il chiamante è responsabile di liberare la memoria allocata con una
 *          funzione di deallocazione appropriata che libera prima le colonne,
 *          poi le righe, e infine la matrice stessa.
 */
double***allocateMatrix(size_t n, size_t m)
{
    double***mat=calloc(n,sizeof(double**));
    for(int i=0; i<=n-1; i++)
    {
        mat[i]=calloc(m,sizeof(double*));
    }
    return mat;
}

/**
 * @brief Legge i valori da un file e popola la matrice.
 *
 * Legge n*m valori double da un file e li assegna agli elementi della matrice.
 * Per ogni elemento, alloca memoria e legge il valore usando fscanf, ignorando
 * spazi, tabulazioni e caratteri di newline come separatori.
 *
 * @param fsd Puntatore al file aperto in lettura.
 * @param mat Puntatore triplo alla matrice da riempire (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Numero di colonne della matrice.
 *
 * @note La memoria per ogni elemento viene allocata singolarmente con malloc.
 * @note Il formato atteso nel file è: double separati da spazi, tabulazioni o newline.
 * @warning Il file deve contenere almeno n*m valori double, altrimenti il comportamento
 *          è indefinito. Il file deve essere già aperto in modalità lettura.
 */
void fillMatrix(FILE*fsd, double***mat, size_t n, size_t m)
{
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<=m-1; j++)
        {
            mat[i][j]=malloc(sizeof(double));
            fscanf(fsd,"%lf%*[ \n\t\r]",mat[i][j]);
        }
    }
}

/**
 * @brief Normalizza una matrice dividendo ogni elemento per il massimo della sua colonna.
 *
 * Per ogni colonna, trova il valore massimo e divide tutti gli elementi della colonna
 * per questo massimo, producendo una matrice normalizzata dove i valori di ogni colonna
 * sono compresi nell'intervallo [0, 1].
 *
 * @param mat Puntatore triplo alla matrice originale (mat[i][j]).
 * @param matNorm Puntatore triplo alla matrice normalizzata dove salvare i risultati.
 * @param n Numero di righe della matrice.
 * @param m Numero di colonne della matrice.
 *
 * @note La memoria per ogni elemento di matNorm viene allocata singolarmente con malloc.
 * @note La normalizzazione avviene per colonna: ogni elemento è diviso per il massimo della sua colonna.
 * @warning Richiede che la matrice originale sia già popolata con dati validi.
 *          Il comportamento è indefinito se una colonna contiene solo zeri.
 */
void normalize(double***mat, double***matNorm, size_t n, size_t m)
{
    for(int j=0; j<=m-1; j++)
    {
        double max=getMax(mat,n,j);
        for(int i=0; i<=n-1; i++)
        {
            matNorm[i][j]=malloc(sizeof(double));
            *matNorm[i][j]=*mat[i][j]/max;
        }
    }
}

/**
 * @brief Ordina tutte le colonne della matrice in modo crescente.
 *
 * Applica l'algoritmo di ordinamento quick sort a ogni colonna della matrice,
 * ordinando gli elementi di ogni colonna in ordine crescente. Le altre funzioni
 * di ordinamento (insertion sort, bubble sort, selection sort) sono commentate
 * e disponibili come alternative.
 *
 * @param mat Puntatore triplo alla matrice da ordinare (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Numero di colonne della matrice.
 *
 * @note La funzione modifica la matrice originale in-place.
 * @note È possibile sostituire quicksort con altre funzioni di ordinamento
 *       (insertionsort, bubblesort, selectionsort) decommentando la riga desiderata.
 * @warning Richiede che la matrice sia già popolata con dati validi.
 */
void sortMatrixCols(double***mat, size_t n, size_t m)
{
    for(int j=0; j<=m-1; j++)
    {
        /**
         * È possibile decommentare altri algoritmi di sort come alternative
         */
        //insertionsort(mat,n,j);
        //bubblesort(mat,n,j);
        //selectionsort(mat,n,j);
        quicksort(mat,0,n-1,j);
    }
}

/**
 * @brief Stampa una matrice su un file di output.
 *
 * Scrive gli elementi della matrice su un file, con elementi di ogni riga separati
 * da tabulazioni e righe separate da newline. Ogni elemento è stampato con precisione
 * in virgola mobile.
 *
 * @param mat Puntatore triplo alla matrice da stampare (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Numero di colonne della matrice.
 * @param fdd Puntatore al file aperto in scrittura dove stampare la matrice.
 *
 * @note Gli elementi sono separati da tabulazioni all'interno di ogni riga.
 * @note Ogni riga termina con un newline.
 * @note fflush() è chiamato dopo ogni elemento per assicurare l'immediata scrittura.
 * @warning Il file deve essere già aperto in modalità scrittura.
 */
void printMatrix(double***mat, size_t n, size_t m, FILE*fdd)
{
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<=m-1; j++)
        {
            fprintf(fdd,"%f%s",*mat[i][j],((j<=m-2)?"\t":"\n"));
            fflush(fdd);
        }
    }
}

/**
 * @brief Libera la memoria allocata per una matrice di puntatori a double.
 *
 * Deallocca tutta la memoria precedentemente allocata per la matrice, liberando
 * prima gli elementi singoli, poi le righe, e infine la struttura principale.
 * Controlla se ogni puntatore è valido prima di liberarlo.
 *
 * @param mat Puntatore triplo alla matrice da deallocare (mat[i][j]).
 * @param n Numero di righe della matrice.
 * @param m Numero di colonne della matrice.
 *
 * @note La funzione effettua controlli NULL prima di ogni free() per evitare
 *       comportamenti indefiniti.
 * @note Dopo la chiamata a questa funzione, il puntatore mat diventa invalido
 *       e non deve essere utilizzato.
 * @warning Il parametro mat deve essere un puntatore precedentemente allocato
 *          con allocateMatrix(), altrimenti il comportamento è indefinito.
 */
void freeMatrix(double***mat, size_t n, size_t m)
{
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<=m-1; j++)
        {
            if(mat[i][j])
            {
                free(mat[i][j]);
            }
        }
        if(mat[i])
        {
            free(mat[i]);
        }
    }
    if(mat)
    {
        free(mat);
    }
}

int main(int argc, char**argv)
{
    /**
     * Legge gli argomenti da riga di comando e valida i parametri di input
     */
    Elem*elem;                                                   // Puntatore alla struttura con i dati di input
    if((elem=readInput(argc,argv)))                              // Valida gli argomenti
    {
        /**
         * Apre il file di input in lettura
         */
        FILE*fsd;                                                // File stream di input
        if(!(fsd=fopen(elem->filename,"r")))                     // Tenta di aprire il file
        {
            fprintf(stderr,"%s: fopen: %s\n",basename(argv[0]),strerror(errno));
            free(elem);
            exit(EXIT_FAILURE);
        }
        
        /**
         * Alloca e popola la matrice originale dai dati letti dal file
         */
        double***mat=allocateMatrix(elem->n,elem->m);            // Alloca la matrice
        fillMatrix(fsd,mat,elem->n,elem->m);                     // Popola la matrice dal file
        fclose(fsd);                                             // Chiude il file di input
        
        /**
         * Alloca la matrice normalizzata e normalizza i dati
         */
        double***matNorm=allocateMatrix(elem->n,elem->m);        // Alloca la matrice normalizzata
        normalize(mat,matNorm,elem->n,elem->m);                  // Normalizza gli elementi
        
        /**
         * Apre il file di output in scrittura
         */
        FILE*fdd;                                                // File stream di output
        if(!(fdd=fopen("output.txt","w+")))                      // Tenta di aprire il file di output
        {
            fprintf(stderr,"%s: fopen: %s\n",basename(argv[0]),strerror(errno));
            freeMatrix(mat,elem->n,elem->m);
            freeMatrix(matNorm,elem->n,elem->m);
            free(elem);
            exit(EXIT_FAILURE);
        }
        
        /**
         * Stampa le matrici originale e normalizzata su stdout
         */
        printf("** A **\n");
        printMatrix(mat,elem->n,elem->m,stdout);                 // Stampa matrice originale su console
        printf("** B **\n");
        printMatrix(matNorm,elem->n,elem->m,stdout);             // Stampa matrice normalizzata su console
        
        /**
         * Stampa le stesse matrici sul file di output
         */
        fprintf(fdd,"** A **\n");
        printMatrix(mat,elem->n,elem->m,fdd);                    // Stampa matrice originale su file
        fprintf(fdd,"** B **\n");
        printMatrix(matNorm,elem->n,elem->m,fdd);                // Stampa matrice normalizzata su file
        
        /**
         * Ordina le colonne della matrice normalizzata
         */
        sortMatrixCols(matNorm,elem->n,elem->m);                 // Ordina ogni colonna in modo crescente
        
        /**
         * Stampa la matrice normalizzata con colonne ordinate
         */
        printf("** B (sorted columns) **\n");
        printMatrix(matNorm,elem->n,elem->m,stdout);             // Stampa matrice ordinata su console
        fprintf(fdd,"** B (sorted columns) **\n");
        printMatrix(matNorm,elem->n,elem->m,fdd);                // Stampa matrice ordinata su file
        
        /**
         * Chiude il file e libera tutta la memoria allocata
         */
        fclose(fdd);                                             // Chiude il file di output
        freeMatrix(mat,elem->n,elem->m);                         // Libera matrice originale
        freeMatrix(matNorm,elem->n,elem->m);                     // Libera matrice normalizzata
        free(elem);                                              // Libera struttura Elem
    }
    exit(EXIT_SUCCESS);
}