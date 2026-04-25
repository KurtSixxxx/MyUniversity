#ifndef DATA_H
    #define DATA_H
    struct dato {
      int value; 
    };

    // NB. modificare le definizione del dato a piaceimento, 
    // di conseguenza andranno modificate le funzioni 
    // (la loro implementazione) relative ai dati

    //typedef struct dato Dato; 
    
    /* restituisce 0 se i dati sono uguali, 
    oppure -1 se ((*d1).value < (*d2).value )
    oppure 1 se ((*d1).value > (*d2).value )
    */  
    int confronta_dati(const struct dato *d1, const struct dato *d2);

    /* Stampa i dati contenuti all'interno della struttura struct data */ 
    void printDato(const struct dato *d);

    /* Deallocazione di eventuali dati allocati dinamicamente
    * ai quali fanno riferimento eventuali campi presenti 
    * nella struttura data 
    */  
    void freeData(const struct dato *d); 

    /* funzione apposita  di copia che prende in considerazione 
    * eventuali dati allocati dinamicamente all'interno della 
    * struttura struct dato. Nel caso in cui 
    * non esistano puntatori a dati allocati dinamicamente, 
    * bastera' una invocazione alla funzione memcpy() (vedi 
    * pagina di manuale).  
    */ 
    void copyData(const struct dato *src, struct dato *dst);  
#endif 
