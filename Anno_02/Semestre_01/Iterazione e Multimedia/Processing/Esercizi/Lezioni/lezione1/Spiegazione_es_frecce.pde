//Codice dell'esercizio

int larghezza_freccia = 150; // 1. Definizione della larghezza della freccia

for (int x = 0; x < width; x += 50) { // 2. Inizio del ciclo for
    if ((x + larghezza_freccia) <= width) { // 3. Verifica se la freccia può essere disegnata
        println(x); // 4. Stampa il valore di x nella console
        line(x, 0, x + larghezza_freccia, height / 2); // 5. Disegna la linea superiore della freccia
        line(x, height, x + larghezza_freccia, height / 2); // 6. Disegna la linea inferiore della freccia
    }
}
/*_________________________________________________________________________________________________________________________________________________________________________________*/

/*
        1. Definizione della larghezza della freccia:


                            int larghezza_freccia = 150;
                            
Qui stai dichiarando una variabile intera chiamata larghezza_freccia, che rappresenta la lunghezza della freccia. In questo caso, è impostata a 150 pixel.



        2. Inizio del ciclo for:

                            for (int x = 0; x < width; x += 50) {

int x = 0: Inizializza la variabile x a 0. Questa variabile rappresenta la posizione orizzontale delle frecce.
x < width: Il ciclo continua finché x è minore della larghezza della finestra (width), che è una variabile predefinita che contiene la larghezza della finestra grafica.
x += 50: Ad ogni iterazione del ciclo, x aumenta di 50 pixel. Questo significa che le frecce saranno disegnate a intervalli di 50 pixel lungo l'asse x.



        3. Verifica se la freccia può essere disegnata:

                            if ((x + larghezza_freccia) <= width) {

 Questa condizione verifica se la freccia che stai per disegnare non supera il bordo destro della finestra.

(x + larghezza_freccia): Calcola la posizione finale della freccia. Se x è 0, questo diventa 150.
<= width: Controlla se la posizione finale è all'interno della larghezza della finestra. Se è vera, il codice all'interno dell'if verrà eseguito.



        4. Stampa il valore di x nella console:

println(x);

Questo comando stampa il valore attuale di x nella console di Processing. Ti permette di vedere quali posizioni stai utilizzando per disegnare le frecce.



        5. Disegna la linea superiore della freccia:

                            line(x, 0, x + larghezza_freccia, height / 2);

line(...): Questa funzione disegna una linea sulla finestra grafica.
x, 0: Il punto iniziale della linea è (x, 0), che rappresenta il punto in alto a sinistra della freccia.
x + larghezza_freccia, height / 2: Il punto finale della linea è (x + larghezza_freccia, height / 2), che è a metà della altezza della finestra.

        6. Disegna la linea inferiore della freccia:

                            line(x, height, x + larghezza_freccia, height / 2);

Qui stai disegnando la parte inferiore della freccia.
x, height: Il punto iniziale della linea è alla base della finestra.
x + larghezza_freccia, height / 2: Questo punto finale è lo stesso della linea superiore, creando l'effetto della freccia.
*/
