#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<libgen.h>
#include "Cose.h"

bool compresoInt(size_t x)
{
    return ((x>=5) && (x<=20));
}

bool compresoAlpha(double x)
{
    return ((x>=10) && (x<=20));
}

bool compresoBeta(double x)
{
    return ((x>=1) && (x<=5));
}

/**
 * @brief Genera un numero pseudocasuale a 32 bit usando l'algoritmo multiply-with-carry.
 *
 * Implementa il generatore di numeri pseudocasuali Multiply-With-Carry (MWC)
 * con due stati statici che evolvono ad ogni chiamata. Utilizza costanti
 * moltiplicative (36969 e 18000) e manipolazioni di bit per combinare
 * due sequenze pseudocasuali indipendenti.
 *
 * @warning Gli stati iniziali sono fissi e noti; non usare per applicazioni
 *          che richiedono sicurezza crittografica. Per scenari sensibili,
 *          preferire /dev/urandom o una libreria di crittografia.
 *
 * @return Numero intero pseudocasuale a 32 bit.
 *
 * @note La funzione mantiene stato interno (static); è thread-unsafe.
 *       Per ambienti multithreaded, sincronizzare l'accesso o usare
 *       versioni reentrant.
 *
 * @see https://en.wikipedia.org/wiki/Multiply-with-carry
 */
uint32_t getRandom()
{
    static uint32_t m_w=123456;
    static uint32_t m_z=789123;
    m_z=36969*(m_z & ((1<<16)-1))+(m_z>>16);
    m_w=18000*(m_w & ((1<<16)-1))+(m_w>>16);
    return (m_z<<16)+m_w;
}

/**
 * @brief Legge e valida parametri da riga di comando per creare un'istanza di Elem.
 *
 * Esegue il parsing di quattro argomenti da riga di comando (a, b, alpha, beta) e li valida
 * rispetto a vincoli di range predefiniti. Se tutti i parametri sono validi,
 * alloca dinamicamente e restituisce un'istanza di Elem inizializzata;
 * altrimenti restituisce NULL.
 *
 * @param args Array di puntatori a stringhe (tipicamente argv); deve contenere
 *             almeno 5 elementi [0..4], dove args[1..4] sono i parametri numerici.
 *
 * @return Puntatore a una nuova istanza Elem allocata via malloc se tutti
 *               i parametri sono validi e compresoInt/compresoAlpha/compresoBeta
 *               restituiscono true; NULL altrimenti.
 *
 * @warning Il chiamante è responsabile di liberare la memoria con free() quando
 *          il valore di ritorno è non-NULL. La funzione non effettua controllo
 *          su argc; accedere a args[1..4] senza verificare bounds può causare
 *          comportamento indefinito (dereferenza di puntatore invalido).
 *
 * @warning atoi() e atof() non segnalano errori di parsing; input non numerico
 *          viene silenziosamente convertito a 0. Per parsing robusto con error
 *          handling, considerare strtol() e strtod().
 *
 * @note La funzione è thread-safe poiché non accede a variabili statiche globali.
 *
 * @see compresoInt(), compresoAlpha(), compresoBeta() per i criteri di validazione.
 */
Elem*readInput(char**args)
{
    Elem*elem=NULL;
    size_t a, b;
    double alpha, beta;
    if((compresoInt(a=atoi(args[1]))) && (compresoInt(b=atoi(args[2]))) && (compresoAlpha(alpha=atof(args[3]))) && (compresoBeta(beta=atof(args[4]))))
    {
        elem=malloc(sizeof(Elem));
        elem->a=a;
        elem->b=b;
        elem->alpha=alpha;
        elem->beta=beta;
    }
    return elem;
}

/**
 * @brief Alloca dinamicamente una matrice di puntatori a double.
 *
 * Crea una matrice tridimensionale di dimensioni a×b allocando:
 * - Un array di a puntatori a double** (primo livello)
 * - Per ogni riga i, un array di b puntatori a double* (secondo livello)
 *
 * La memoria viene allocata con calloc(), quindi inizializzata a zero.
 * Il terzo livello (i dati effettivi di tipo double) non viene allocato
 * da questa funzione; il chiamante deve allocare i singoli puntatori di double
 * per ogni mat[i][j] se necessario.
 *
 * @param a Numero di righe (prima dimensione) della matrice.
 * @param b Numero di colonne (seconda dimensione) della matrice.
 *
 * @return Puntatore alla matrice allocata se successo; NULL se
 *                   una o più chiamate a calloc() falliscono.
 *
 * @see freeMatrix() per la liberazione della memoria da parte della matrice.
 */
double***allocMatrix(size_t a, size_t b)
{
    double***mat=calloc(a,sizeof(double**));
    for(int i=0; i<=a-1; i++)
    {
        mat[i]=calloc(b,sizeof(double*));
    }
    return mat;
}

/**
 * @brief Riempie una matrice con valori pseudocasuali secondo criteri probabilistici.
 *
 * Popola una matrice allocata con mat[i][j] puntatori a double. Per ogni
 * posizione (i, j), genera un numero casuale p in [0,1]. Se p > 0.2 (80%
 * di probabilità), alloca un double e lo inizializza con un valore casuale
 * nell'intervallo [alpha - beta, alpha + beta]. Altrimenti, mat[i][j]
 * rimane NULL (non allocato).
 *
 * @param mat Matrice (double***) allocata precedentemente, con dimensioni
 *            almeno elem->a × elem->b. Il primo livello (mat) e il secondo
 *            livello (mat[i]) devono essere allocati; il terzo livello
 *            (mat[i][j]) viene allocato da questa funzione ove necessario.
 *
 * @param elem Puntatore a una struttura Elem contenente:
 *             - elem->a: numero di righe (prima dimensione della matrice).
 *             - elem->b: numero di colonne (seconda dimensione della matrice).
 *             - elem->alpha: limite superiore dell'intervallo di valori.
 *             - elem->beta: offset per calcolare i limiti (inferiore e superiore).
 *
 * @note Circa l'80% delle celle (p > 0.2) vengono allocate e riempite;
 *       il restante 20% rimane NULL, creando una matrice sparsa.
 *
 * @see getRandom() per il generatore di numeri pseudocasuali
 *      allocMatrix() per l'allocazione precedente della matrice.
 *      Elem per la struttura dei parametri.
 */
void fillMatrix(double***mat, Elem*elem)
{
    double a=elem->alpha-elem->beta, b=elem->alpha+elem->beta;
    for(int i=0; i<=elem->a-1; i++)
    {
        for(int j=0; j<=elem->b-1; j++)
        {
            double p=getRandom()/(double)UINT32_MAX;
            if(p>0.2)
            {
                mat[i][j]=malloc(sizeof(double));
                *mat[i][j]=a+(b-a)*(getRandom()/(double)UINT32_MAX);
            }
        }
    }
}

/**
 * @brief Crea la trasposta di una matrice, allocando una nuova matrice.
 *
 * Genera una nuova matrice con dimensioni scambiate (b × a anziché a × b)
 * e copia gli elementi dalla matrice originale alla trasposta. Se mat[i][j]
 * è allocato (non NULL), alloca mat1[j][i] e copia il valore; altrimenti
 * mat1[j][i] rimane NULL. La matrice originale non viene modificata.
 *
 * @param mat Matrice sorgente (double***) di dimensioni a × b allocata
 *            precedentemente. Gli elementi mat[i][j] possono essere NULL
 *            (struttura sparsa) o puntatori a double.
 *
 * @param elem Puntatore a una struttura Elem contenente:
 *             - elem->a: numero di righe della matrice originale.
 *             - elem->b: numero di colonne della matrice originale.
 *             La matrice trasposta avrà dimensioni elem->b × elem->a.
 *
 * @return Puntatore a una nuova matrice allocata dinamicamente,
 *         con dimensioni elem->b × elem->a (trasposta). Restituisce
 *         NULL se allocMatrix() fallisce.
 *
 * @note La funzione copia solo i valori dei dati (dereferenziamento);
 *       i puntatori NULL rimangono NULL nella trasposta (conserva la
 *       struttura sparsa originale).
 *
 * @see allocMatrix() per l'allocazione della nuova matrice.
 *      fillMatrix() per il riempimento della matrice originale.
 *      Elem per la struttura dei parametri.
 */
double***trasposeMatrix(double***mat, Elem*elem)
{
    double***mat1=allocMatrix(elem->b,elem->a);
    for(int i=0; i<=elem->a-1; i++)
    {
        for(int j=0; j<=elem->b-1; j++)
        {
            if(mat[i][j])
            {
                mat1[j][i]=malloc(sizeof(double));
                *mat1[j][i]=*mat[i][j];
            }
        }
    }
    return mat1;
}

/**
 * @brief Stampa a console una matrice sparsa in formato tabulare.
 *
 * Itera su tutti gli elementi della matrice (a × b) e stampa:
 * - Se mat[i][j] è allocato (non NULL): il valore con 2 decimali.
 * - Se mat[i][j] è NULL: il carattere 'N' per indicare assenza di dato.
 *
 * Gli elementi sono separati da tabulazioni all'interno di una riga;
 * ogni riga è terminata da un newline. Questa funzione è pensata per
 * visualizzare matrici sparse generate da fillMatrix() o trasposeMatrix().
 *
 * @param mat Matrice (double***) allocata e potenzialmente riempita.
 *            Gli elementi mat[i][j] possono essere NULL (struttura sparsa)
 *            o puntatori a double con valori validi.
 *
 * @param a Numero di righe della matrice (prima dimensione).
 *
 * @param b Numero di colonne della matrice (seconda dimensione).
 *
 * @warning La funzione assume che mat sia allocato correttamente con
 *          dimensioni a × b. Un mat invalido o dimensioni errate causano
 *          comportamento indefinito (accesso fuori limite).
 *
 * @warning Non esegue alcun controllo su a e b; il chiamante deve garantire
 *          che corrispondano alle effettive dimensioni di mat.
 *
 * @note Formato di output:
 *       - Valori allocati: stampa con format "%.2f" (2 decimali).
 *       - Valori NULL: stampa "N".
 *       - Separatore righe/colonne: tabulazione (\\t) tra elementi,
 *         newline (\\n) a fine riga.
 *
 * @see fillMatrix() per il riempimento della matrice.
 *      trasposeMatrix() per la trasposizione.
 */
void printMatrix(double***mat, size_t a, size_t b)
{
    for(int i=0; i<=a-1; i++)
    {
        for(int j=0; j<=b-1; j++)
        {
            if(mat[i][j])
            {
                printf("%.2f%s",*mat[i][j],((j<=b-2)?"\t":"\n"));
            }
            else
            {
                printf("N%s",((j<=b-2)?"\t":"\n"));
            }
        }
    }
}

/**
 * @brief Libera completamente la memoria di una matrice allocata dinamicamente.
 *
 * Esegue il cleanup completo di una matrice in tre livelli:
 * 1. Itera su ogni elemento mat[i][j] allocato (non NULL) e lo libera.
 * 2. Dopo ogni riga, libera l'array di puntatori mat[i].
 * 3. Infine, libera l'array principale mat.
 *
 * Imposta a NULL ogni puntatore dopo la liberazione per evitare dangling
 * pointer. Questa funzione è progettata per matrici sparse create da
 * allocMatrix(), fillMatrix() e/o trasposeMatrix().
 *
 * @param mat Puntatore alla matrice (double***) da liberare.
 *            Deve essere precedentemente allocata con allocMatrix() e
 *            potenzialmente riempita con fillMatrix() o trasposeMatrix().
 *
 * @param a Numero di righe della matrice (prima dimensione).
 *
 * @param b Numero di colonne della matrice (seconda dimensione).
 *
 * @warning La funzione assume che mat sia stato allocato correttamente
 *          con dimensioni a × b. Un mat invalido o dimensioni errate
 *          causano comportamento indefinito (accesso fuori limite, double free).
 *
 * @warning Non esegue controlli su a e b; il chiamante deve garantire che
 *          corrispondano alle effettive dimensioni di mat.
 *
 * @note La funzione è sicura per matrici sparse (con elementi NULL);
 *       i check if(mat[i][j]) evitano free() su puntatori NULL.
 *
 * @see allocMatrix() per l'allocazione della matrice.
 *      fillMatrix() per il riempimento della matrice.
 *      trasposeMatrix() per la trasposizione della matrice.
 */ 
void freeMatrix(double***mat, size_t a, size_t b)
{
    for(int i=0; i<=a-1; i++)
    {
        for(int j=0; j<=b-1; j++)
        {
            if(mat[i][j])
            {
                free(mat[i][j]);
                mat[i][j]=NULL;
            }
        }
        free(mat[i]);
        mat[i]=NULL;
    }
    free(mat);
}

int main(int argc, char**argv)
{
    if(argc!=5)
    {
        printf("usage: %s <num in [5;20]> <num in [5;20]> <num in [10.0;20.0]> <num in [1.0;5.0]>\n",basename(argv[0]));
    }
    else
    {
        Elem*elem;
        if(!(elem=readInput(argv)))
        {
            printf("usage: %s <num in [5;20]> <num in [5;20]> <num in [10.0;20.0]> <num in [1.0;5.0]>\n",basename(argv[0]));
        }
        else
        {
            double***mat=allocMatrix(elem->a,elem->b);
            fillMatrix(mat,elem);
            double***mat1=trasposeMatrix(mat,elem);
            printf("\x1b[1m*** Matrice mat (%zu x %zu) ***\x1b[0m\n",elem->a,elem->b);
            printMatrix(mat,elem->a,elem->b);
            printf("\n\x1b[1m*** Matrice mat1 (%zu x %zu) ***\x1b[0m\n",elem->b,elem->a);
            printMatrix(mat1,elem->b,elem->a);
            freeMatrix(mat1,elem->b,elem->a);
            freeMatrix(mat,elem->a,elem->b);
            free(elem);
            elem=NULL;
        }
    }
    exit(EXIT_SUCCESS);
}