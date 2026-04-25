MALLOC

La formula per utilizzare *malloc* è:
            puntatore = (tipo*) malloc(dimensione); 
dove:
- puntatore è un puntatore al tipo di dato che vuoi allocare, 
- dimensione è il numero di byte che vuoi allocare.
Ad esempio, per allocare 10 interi, puoi usare:
            int* p = (int*) malloc(10 * sizeof(int));
-----------------------------------------------------------------------------------------------------------------------------------------------------------------      
CALLOC

La funzione *calloc* viene utilizzata per allocare memoria per un array di elementi con una dimensione specificata e inizializzare tutti gli elementi a zero. 
La formula per utilizzare calloc è:
           puntatore = (tipo*) calloc(numero_elementi, dimensione_elemento);           
dove:
- puntatore è un puntatore al tipo di dato che vuoi allocare,
- numero_elementi è il numero di elementi che vuoi allocare,
- dimensione_elemento è la dimensione di ogni elemento in byte. 
Ad esempio, per allocare un array di 10 interi inizializzati a zero, puoi usare:
            int* p = (int*) calloc(10, sizeof(int));
-----------------------------------------------------------------------------------------------------------------------------------------------------------------            
REALLOC

La funzione *realloc* viene utilizzata per modificare la dimensione di un blocco di memoria allocato dinamicamente. 
La formula per utilizzare realloc è:
           puntatore = realloc(puntatore_esistente, dimensione_nuova);
           
dove:
- puntatore_esistente è un puntatore al blocco di memoria che si desidera modificare,
- dimensione_nuova è la nuova dimensione del blocco di memoria in byte.
Ad esempio, se hai allocato un array di 10 interi con malloc e ora vuoi aumentare la sua dimensione a 15 interi, puoi usare:
            p = realloc(p, 15 * sizeof(int));
-----------------------------------------------------------------------------------------------------------------------------------------------------------------                        

In breve, malloc serve per allocare memoria di una dimensione specificata, calloc serve per allocare memoria per un array di elementi con una dimensione specificata 
e inizializzare tutti gli elementi a zero, e realloc serve per modificare la dimensione di un blocco di memoria allocato dinamicamente.
