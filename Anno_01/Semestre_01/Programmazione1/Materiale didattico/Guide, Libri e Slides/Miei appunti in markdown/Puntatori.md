# I puntatori in C (&/*)

In C, come in altri linguaggi di programmazione, si ha a che fare con la memoria e con la sua allocazione.
Siamo soliti ad usare tipi di dati molto "semplici", ossia variabili in grado di memorizzare valori numerici o letterali.

Ad esempio, quando dichiariamo una variabile del tipo:

```c
int a = 5;
```

Stiamo dicendo che esiste un indirizzo di memoria con un nome alias detto "`a`" che contiene il valore `5`. Questo perché in programmazione, quando usiamo un IDE o un compilatore, è più facile per la mente umana memorizzare e attribuire nomi semplici e indicativi alle variabili; piuttosto che memorizzare lunghi indirizzi di memoria contenenti valori.

La variabile `int a` potrebbe essere indicata anche con il suo indirizzo di memoria, che possiamo ipotizzare come esadecimale `0x123abc`.
Dunque leggere:

```c
int a = 5;
//oppure
0x123abc = 5;
```

Sono sostanzialmente la stessa cosa, con l'unica differenza che `a` è molto più comodo e semplice da leggere e ricordare.

Quindi in sintesi:

- `a` è il **nome simbolico** assegnato a una cella di memoria (per comodità umana).

- In realtà la variabile corrisponde a un **indirizzo di memoria** (esadecimale) che contiene un valore.
  
  > Esempio: `0x123abc = 5`

Adesso parliamo del fulcro di questo documento: i **puntatori**.

Come detto in precedenza, finora siamo stati soliti ad utilizzare tipi di dati che contenessero valori numerici o letterali, come `int`, `double`, `float`, `char`…

**Le variabili puntatori invece contengono indirizzi di memoria.** 
Prima di introdurci nella spiegazione vera e propria, è opportuno chiarire il concetto di indirizzo di memoria.

<img title="" src="file:///C:/Users/giuli/OneDrive/Immagini/Screenshots/Screenshot%202025-09-03%20231931.png" alt="Screenshot 2025-09-03 231931.png" data-align="center" width="283">

Per rendere più chiara la comprensione di una visione astratta come quella dell'architettura della memoria all'interno dei calcolatori possiamo servirci dell'illustrazione soprastante.
Immaginiamo gli indirizzi di memoria come delle celle impilate una sopra l'altra. Come detto prima gli indirizzi di memoria sono dei numeri esadecimali composti da numeri e lettere, una cosa del genere per intenderci: `0x7fff927e2894`.

Ogni indirizzo di memoria attribuito ad un valore può essere facilmente analogato ad un concetto come la via di casa e l'abitante. Ossia:

- Via Napoli, 36 = indirizzo di memoria;

- Mario Rossi = valore dentro quella cella.

Via Napoli 36 sarebbe l'indirizzo di memoria, e Mario Rossi il valore contenuto all'interno. La stessa cosa che abbiamo visto con `0x123abc = 5`.

Quando immaginiamo un puntatore, allora l'immagine che ci viene subito in mente è questa:

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-04-15-30-36-image.png" alt="" width="567" data-align="center">

Vediamo che la variabile `int *p` ha una freccia diretta verso la variabile `int a`.

#### Dichiarazione di un puntatore.

```c
int *p;
```

- L’asterisco `*` indica che la variabile è un **puntatore**. L'asterisco assume il nome di "**operatore di dereferenziazione**"

- Il tipo (`int`, `char`, ecc.) serve per sapere **quanti byte leggere** all’indirizzo.

Solitamente una variabile di tipo int occupa 4 byte, e se pensiamo ad una cella di memoria di 1 byte allora una variabile di tipo int occuperà 4 celle di memoria.

In questo momento il puntatore non è stato attribuito a nessuna variabile, o meglio, non sta puntando a nessun indirizzo di memoria di alcuna variabile.

#### Assegnazione di un puntatore.

Per assegnare un indirizzo si usa l’operatore `&`:

```c
int a = 5;
int *p = &a;  // 'p' punta 'a'
```

Ora `p` contiene l’indirizzo di `a`.

L'operatore & (and commerciale) non fa altro che prelevare l'indirizzo di memoria di una variabile; per intenderci il numero esadecimale visto prima `0x7fff927e2894`.

In questo momento, allora, possiamo ritornare all'illustrazione precedente, che descriveremo subito.

![Screenshot 2025-09-04 153034.png](C:\Users\giuli\OneDrive\Immagini\Screenshots\Screenshot%202025-09-04%20153034.png)

Come possiamo vedere abbiamo due variabili:

- `int a = 42;`

- `int *p = 0x123;`

Questo vuol dire che:

1. La variabile `int a`, alias di `0x123`, contiene il valore `42`.

2. La variabile `int *p` (variabile puntatore), alias di `0x456`, contiene l'indirizzo di memoria `0x123`; ossia l'indirizzo di memoria della variabile `int a`.

3. Ciò vuol dire che modificando il valore di `*p`, modificheremo il valore di `int a`. Indirettamente, ossia, senza usare esplicitamente la variabile `int a`.

Quindi quello che sta succedendo in memoria è sostanzialmente questo: 

![](C:\Users\giuli\AppData\Roaming\marktext\images\2025-09-04-15-42-37-image.png)

**Perché quando dichiariamo un puntatore dobbiamo specificare il tipo di dato?**

> **Perché il tipo di dato indica a quanti byte deve saltare il puntatore e come interpretare il valore in memoria.**

In pratica:

- `int *p` → legge 4 byte (un intero).

- `char *p` → legge 1 byte (un carattere).

- `double *p` → legge 8 byte (un double).

Senza tipo, il puntatore non saprebbe **quanto spazio leggere** né **che significato dare** ai dati trovati.

#### Stampa di valori e indirizzi

Capiamo adesso come mostrare le nostre operazioni con i puntatori nell'output dei nostri terminali.

```c
int a = 5;
int *p = &a;

printf("%p", &a); // indirizzo di a
printf("%p", p);  // indirizzo di a (contenuto di p)
printf("%d", a);  // valore di a (5)
printf("%d", *p); // valore di a tramite p (5)
```

- **Stampa degli indirizzi:**
  Ricordando che in questo momento `int *p` sta puntando ad `int a`; abbiamo due modi per stampare l'indirizzo di memoria di `a`.
  
  - `printf("%p", &a);`
  
  - `printf("%p", p);`
  
  Notiamo in primo luogo un nuovo specificatore di formato: `%p`
  
  **`%p`** è lo **specificatore di formato per stampare un indirizzo di memoria**.
  
  E notiamo in secondo luogo che nella prima chiamata a `printf()` utilizziamo `&a` e nella seconda `p`.
  
  Questo perché come sappiamo `&` preleva l'indirizzo di memoria di qualunque variabile viene scritta dopo esso. E invece nella seconda chiamata a `printf()` gli passiamo il puntatore `p`, che in realtà è un indirizzo.

- **Stampa dei valori:**
  Abbiamo due modi per stampare i valori di int a e int *p:
  
  - `printf("%d", a);`
  
  - `printf("%d", *p);`
    
    Nel primo caso utilizziamo la classica stampa con lo specificatore di formato per i numeri interi, ossia `%d`. E passiamo la varibile `a` che contiene direttamente il valore `5`.
    
    Nel secondo caso utilizziamo sempre lo specificatore di formato `%d` dato che dobbiamo stampare l'intero, e passiamo la variabile `*p`. Utilizziamo l'operatore di dereferenziazione `*` per prelevare il valore. Sostanzialmente quando utilizziamo `*` stiamo dicendo al puntatore "Preleva il valore della variabile che stai puntando"

#### Modifica tramite puntatori

Come detto in precedenza, se una variabile puntatore sta puntando ad un'altra variabile, allora è in grado di modificare il valore di ciò a cui sta puntando indirettamente, ossia, senza usare esplicitamente la variabile puntata. Per chiarici meglio:

```c
a = 5;
*p = 6; //ora a = 6
```

Esempio con operazioni:

```c
printf("%d", *p+1); // stampa 7 se *p = 6
```

#### Array e puntatori

Array e puntatori sono strettamente collegati.

```c
int x[3] = {10, 20, 30};
```

`x` (nome dell'array) è un puntatore al primo elemento (`x[0]`).

E di conseguenza `&x[0]`, ossia indirizzo del primo indice, è uguale a `x`.

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-04-16-31-33-image.png" alt="" data-align="center" width="602">

Esempi:

```c
printf("%p", x);      // indirizzo di x[0]
printf("%p", &x[0]);  // indirizzo di x[0]
printf("%d", x[0]);   // valore del primo elemento (20)

int *p = x;           // p punta a x[0]
printf("%d", *p);     // 20
printf("%d", *(p+1)); // 30
```

Notiamo la **differenza** tra `*p+1` e `*(p+1)`:

 `*p + 1`

- Leggi il valore puntato da `p` e **aggiungi 1 a quel valore**.

- Se `*p = 5` → `*p + 1 = 6`.
  
  `*(p+1)`

- Sposta il puntatore di **1 elemento avanti**.

- Poi leggi quel nuovo valore.

- Se `p` punta a `x[0] = 5` → `*(p+1) = x[1]`.

Esempio:

```c
int x[2] = {5, 9};
int *p = x;

printf("%d\n", *p + 1);  // 6   (5+1)
printf("%d\n", *(p+1));  // 9   (valore successivo)
```

In sintesi:

- `*p + 1` → **modifico il valore** (matematica).

- `*(p+1)` → **mi sposto di un elemento** (aritmetica dei puntatori).

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-04-16-35-38-image.png" alt="" data-align="center" width="560">

#### Aritmetica dei puntatori

Abbiamo già visto che un puntatore è un indirizzo di memoria che "sa" di che tipo di dato si tratta.  
Quando usiamo operatori matematici con i puntatori, non ci spostiamo di **byte singoli**, ma di **elementi del tipo puntato**.

Esempio:

```c
int v[] = {10, 20, 30, 40};
int *p = v;  // p punta a v[0]
```

- `p + 1` non significa "vai 1 byte avanti", ma "vai all'elemento successivo", quindi a `v[1]`.

- `p + 2` significa "vai due elementi avanti", quindi a `v[2]`.
  
  Schema immaginato in memoria (supponendo `int = 4 byte`):
  
  ```c
  0x1000 -> 10   v[0]
  0x1004 -> 20   v[1]
  0x1008 -> 30   v[2]
  0x100C -> 40   v[3]
  ```

- `p = 0x1000`

- `p+1 = 0x1004`

- `*(p+2) = 30`

L’aritmetica dei puntatori è molto comoda per navigare negli array senza usare indici

#### Operatori unari ++ / --

Gli operatori di incremento/decremento funzionano anche con i puntatori.

- `++p` → spostati all’elemento successivo e poi usalo.

- `p++` → usa l’attuale elemento, poi spostati.

- Analogamente per `--p` e `p--`.

```c
int v[] = {1,2,3};
int *p = v;

printf("%d\n", *++p); // sposta prima: ora p -> v[1], stampa 2
printf("%d\n", *p--); // stampa 2, poi torna a v[0]
printf("%d\n", *p);   // di nuovo 1
```

Attenzione alla precedenza:

- `*p++` ≡ `*(p++)` → leggi il valore attuale, poi spostati.

- `(*p)++` → incrementa il valore puntato.

#### Operatori binari +, -, +=, -=

Si possono sommare o sottrarre interi a un puntatore.  
Allo stesso modo si possono usare `+=` e `-=`.

```c
int v[] = {10,20,30,40,50};
int *p = v;

p += 2;   // ora p -> v[2] (30)
printf("%d\n", *p); // 30

p -= 1;   // ora p -> v[1] (20)
printf("%d\n", *p); // 20
```

Serve a navigare avanti e indietro in un array.

#### Sottrazione tra puntatori

Se due puntatori appartengono allo stesso array, puoi sottrarli per sapere **la distanza in elementi**.

```c
int v[] = {10,20,30,40,50};
int *a = &v[1]; // v[1] = 20
int *b = &v[4]; // v[4] = 50

printf("%ld\n", b - a); // 3 (ci sono 3 elementi tra v[1] e v[4])
```

Non bisogna mai sottrarre elementi che non appartengono allo stesso array --> comportamento indefinito.

#### Puntatori a NULL

Un puntatore può non puntare a nulla.  
Per convenzione, si assegna `NULL`, che significa “nessun indirizzo valido”. `NULL` è una macro già presenta e definita per default in C.

Esempio:

```c
int *p = NULL;

if (p != NULL) {
    printf("%d\n", *p); // sicuro
}
```

Dopo `free(p)`, è buona abitudine scrivere `p = NULL;` per non avere puntatori "pendenti".  

Mai dereferenziare un `NULL`: porta a crash.

#### Operatori di confronto

Puoi confrontare puntatori:

- Confronto di indirizzi:

```c
if (p1 == p2) { /* puntano allo stesso posto */ }
```

- Confronto d’ordine (`<`, `>`) ha senso solo se appartengono allo stesso array.

- Per confrontare i valori puntati, serve dereferenziare:
  
  ```c
  if (*p1 == *p2) { /* i contenuti sono uguali */ }
  ```

#### Puntatori costanti vs puntatori a costanti

Tre casi classici:

```c
const int *p;     // puntatore a COSTANTE int
                  // non puoi modificare *p
                  // ma puoi spostare p

int * const p = &x;  // puntatore COSTANTE a int
                     // puoi modificare *p
                     // ma p non può puntare altrove

const int * const p = &x; // entrambi costanti
                          // né spostare p
                          // né modificare *p
```

Trucchetto:

- `const` a sinistra di `*` → il valore è costante.

- `const` a destra di `*` → il puntatore è costante.
