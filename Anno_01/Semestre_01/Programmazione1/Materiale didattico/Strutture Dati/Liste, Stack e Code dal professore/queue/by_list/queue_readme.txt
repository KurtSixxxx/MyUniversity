Una coda e' una struttura dati che segue il modello 
FIFO (First In First Out). Il primo ad entrare 
e' il primo ad essere servito. 

In una coda le operazioni di inserimento vengono fatte sempre alla 
fine di questa, ovvero in coda (tail). 

Invece gli elementi si rimuovo dalla testa (head). 

La coda si puo' implementare facilmente con una lista concatenata con collegamenti 
semplici oppure con una ``array circolare''. 

Nel caso in cui la coda sia implementata mediante una lista semplicemente concatenata, 
e' bene mantenere due riferimenti: 1) testa (head) 2) coda (tail) 

Seguendo i prototipi definiti definiti nel file header queue.h, implementare le 
seguenti operazioni sulle code: 

- inserimento in coda (enqueue) 
- rimozione di un elemento dalla testa (dequeue) 
- stampa degli elementi della coda
- funzione che verifica se la coda e' vuota 


