//  Filtri locali (MAX, MIN, MEDIANO)
// Finora abbiamo visto filtri puntuali (ogni pixel modificato indipendentemente).
// Ora vediamo filtri locali: il nuovo valore di un pixel dipende dai suoi vicini.

/*  1. Spieghiamo cos'è un INTORNO
    Per ogni pixel (x,y), consideriamo una finestra quadrata di dimensione N×N centrata su di esso.

    Esempio con N=3 (intorno 3x3):

    (x-1,y-1)  (x,y-1)  (x+1,y-1)
    (x-1,y)    (x,y)    (x+1,y)
    (x-1,y+1)  (x,y+1)  (x+1,y+1)
*/

//  2. Come estrarre l'intorno con get()
int N = 3;  // dimensione finestra (di solito 3,5,7...)
int raggio = N/2;  // es. per N=3, raggio=1

// Per il pixel a (x,y), l'intorno è:
int inizioX = x - raggio;
int inizioY = y - raggio;

PImage intorno = I.get(inizioX, inizioY, N, N);

// 3. Il problema dei BORDI (IMPORTANTISSIMO)
// Sui bordi, l'intorno esce dall'immagine! Due soluzioni:

//   Soluzione 1 (semplice, usala all'esame): Usa constrain per stare dentro i limiti
int inizioX = constrain(x - raggio, 0, I.width-1);
int inizioY = constrain(y - raggio, 0, I.height-1);
int fineX = constrain(x + raggio, 0, I.width-1);
int fineY = constrain(y + raggio, 0, I.height-1);
int larghezza = fineX - inizioX + 1;
int altezza = fineY - inizioY + 1;

PImage intorno = I.get(inizioX, inizioY, larghezza, altezza);

//  Soluzione 2 (più furba per l'esame):

// Ignora i bordi (lasciali originali)
for (int y = raggio; y < I.height - raggio; y++) {
    for (int x = raggio; x < I.width - raggio; x++) {
        // elabora solo pixel interni
    }
}
// I bordi rimangono invariati
