# Stringhe in C

> **Stringa**: sequenza di caratteri memorizzata in celle di memoria adiacenti (array)

### Rappresentazione delle stringhe in C

```c
char s[] = {'m' , 'y', '_', 's', 't', 'r', 'i', 'n', 'g', '\0'};
```

Necessita il carattere finale null terminator `’\0’` anche detto carattere `‘null'`.

Se non impostiamo il terminatore nullo la funzione strlen() - che opera su array di caratteri - non può identificare la fine della stringa.

Un altro modo per inizializzare una stringa è il seguente:

```c
char s[] = "my_string"; //OK
```

In questo caso il carattere di terminazione '\0' viene aggiunto automaticamente a tempo di compilazione.

Differente è la situazione qui:

```c
char *ps = "my_string" //dovrebbe essere di tipo const char
```

Questo è un **letterale stringa**: una costante memorizzata in una **zona di sola lettura** del programma.

Quindi:

- `"my_string"` è **di tipo** `const char *`

- Tu lo stai assegnando a un `char *` (quindi *non const*)

- Il compilatore **ti lascia fare**, ma sta **convertendo implicitamente da `const char *` a `char *`**, ed è potenzialmente pericoloso.

Se provi a fare:

```c
ps[0] = 'M'; //Comportamento indefinito! (probabile crash)
```

Il programma può **crashare a runtime**, perché stai provando a scrivere in **memoria costante**.

Dunque è buona norma inserire il qualificatore 'const'.

```c
const char *ps1 = "my_string"; //OK
ps1[3] = 'k'; //compilation error!
```

Qualsiasi tentativo di acceso in scrittura ad elemento dello array di caratteri (linea 2) darà errore di compilazione.

----

### Funzioni della libreria standard per array di caratteri

```c
#include <string.h> //libreria delle stringhe
```

##### Copia di stringhe | strcpy()

Copia la stringa source nell'area di memoria puntata da destination.

```c
char *strcpy (char * destination, const char * source);
//ovviamente la destinazione è la stringa in cui inseriremo la "parola"
//const char sorgente non permette di essere modificata dato che è di solo lettura e quindi è impostata su const
```

```c
char name[15];
strcpy(name, "pippo");
//Stiamo copiando 'pippo' nella stringa name[]
```

##### Confronto lessicografico | strcmp()

```c
int strcmp(const char *lhs, const char *rhs);
//confronta le due stringhe lessicograficamente
```

```c
strcmp("pippo", "paperino"); //restituisce int > 0
strcmp("paperino", "pippo"); //restituisce int < 0
strcmp("pippo", "pippo"); //restituisce zero
```

- Alla riga 1, dato che ”pippo” > ”paperino”, restituisce un int > 0.

- Alla riga 2, dato che ”paperino” < ”pippo”, restituisce un int < 0.

- Infine, restituisce zero in corrispondenza della riga 3 in quanto le due stringhe sono identiche.

La funzione `strcmp()` **non confronta** le lettere secondo l'ordine "umano" dell'alfabeto, **ma secondo il valore numerico dei caratteri nella tabella ASCII**.

Nella **tabella ASCII**:

- `'a'` → **97**

- `'b'` → 98

- ...

- `'i'` → **105**

- ...

- `'z'` → 122

Quindi:

```c
'i' > 'a'    // perché 105 > 97
```

Più un carattere è "avanti" nell’alfabeto, maggiore sarà il suo valore ASCII.

Ancora sul confronto lessicografico:

```c
char s 1[]= ”pippo";
char s2 []= ” paperino”;
if (s1==s2){ //NO!
// . . .
}
```

**Non** usare operatore ‘==‘ per confrontare il contenuto di array di caratteri!

##### "lenght-bounded"

+ Confronto lessicografico "lenght-bounded": limita il confronto ai primi count caratteri.
  
  ```c
  int strcmp(const char* lhs, const char* rhs, size_t count);
  ```
- Confronto di stringhe versione "lenght-bounded": copia i primi count caratteri di src nell'area puntata da dest. (src è la sorgente, dest è la destinazione)
  
  ```c
  char *strncpy(char *dest, const char *src, size_t count);
  ```

##### Ricerca di sottostrighe | strstr()

```c
char *strstr(const char *str1, const char *str2);
```

La funzione `strstr()` cerca la **prima occorrenza** della sottostringa `str2` nella stringa `str1`.

> Restituisce un **puntatore al primo carattere** della sottostringa trovata.  
> Se la sottostringa non viene trovata, restituisce `NULL`.

Esempio:

```c
char s[] = "SoleMareAmore";
    char *trovato = strstr(s, "Mare");

    if (trovato != NULL) {
        printf("%s\n", trovato);  // Output: MareAmore
    } else {
        printf("Sottostringa non trovata\n");
    }
```

`strstr()` **non modifica** la stringa originale. La stringa risultante stampata parte **dal punto in cui è stata trovata** la sottostringa.

##### Conversioni numeriche: Array di caratteri → Tipo numerico

```c
#include <stdlib.h>
```

Conversione di stringhe a interi (int, long o long long)

```c
int           atoi (const char *str);
long          atol (const char *str);
long long     atoll (const char *str);
```

```c
    char str1[] = "12345";

    int num1 = atoi(str1);
    long num2 = atol(str1);
    long long num3 = atoll(str1);

    printf("atoi: %d\n", num1);       // Output: 12345
    printf("atol: %ld\n", num2);      // Output: 12345
    printf("atoll: %lld\n", num3);    // Output: 12345
```

Le funzioni **non gestiscono errori**: se la stringa non è un numero valido, possono restituire `0` (o comportamenti inattesi).

Conversione di stringhe a numeri in virgola mobile (float/double):

```c
double atof(const char ∗str);
```

Il comportamento è identico a quello della funzione atoi/atol/atoll.

##### Famiglia di funzioni strtoX (float/double)

Le funzioni della **famiglia `strtoX`** in C, che permettono di **convertire stringhe in numeri**, con più controllo rispetto a `atoi`, `atol`, ecc.

```c
#include <stdlib.h>
long strtol(const char *nptr, char **endptr, int base);

double strtod(const char *nptr, char **endptr);
float strtof(const char *nptr, char **endptr);
long  double strtold(const char *nptr, char **endptr);
```

- `nptr`: la stringa da convertire

- `endptr`: un **puntatore a puntatore** a `char` che indica **dove termina il numero** nella stringa

- `base`: la base numerica (es. 10 per decimale, 16 per esadecimale, ecc.)

Esempio:

```c
    const char *s = "123abc";
    char *end;

    long val = strtol(s, &end, 10);

    printf("Numero convertito: %ld\n", val);       // 123
    printf("Parte non convertita: %s\n", end);     // "abc"
```

E possibile riconoscere il caso in cui nessuna conversione sia avvenuta, basta controllare che `*endptr=nptr`.

##### Funzione sscanf()

E' più "sofisticata" rispetto alla classica scanf(): permette di estrarre più elementi (non solo numeri) alla volta.

```c
int sscanf(const char* buffer, const char* format, ...);
```

Ricerca elementi (stringhe o numeri) da estrarre da una stringa (contenuta nell'argomento buffer) sulla base di pattern definiti nel secondo argomento (format).

Esempio. Lettura di un numero intero.

```c
int x;
const char *str = "1234";
sscanf(str, "%d", &x);
//Output atteso:
// Valore di x: 1234
```

Altri esempi dell'utilizzo di sscanf():

```c
char data[] = "42 3.14 Ciao";
int a;
float b;
char parola[10];

sscanf(data, "%d %f %s", &a, &b, parola);

// a = 42
// b = 3.14
// parola = "Ciao"
```

E' anche possibile specificare il numero di cifre del numero da leggere.

```c
int y;
const char *str = "123456789";
sscanf(str, "%6d", &y); // <---- %6d ci permette di stampare solo 6 cifre
printf("%d", y); //stampa 123456
```

---

### Tipo numerico --> stringa

##### Funzione ssprintf()

La funzione `sprintf()` in C **scrive in una stringa**, anziché stampare sullo schermo (come fa `printf`).

**Sintassi**:

```c
int sprintf(char *str, const char *format, ...);`
```

- `str`: è l'**array di caratteri** (stringa) dove verrà salvato l'output.

- `format`: è la **stringa di formato** (`%d`, `%s`, ecc.).

- `...`: sono i valori da formattare.

- **Valore di ritorno**: numero di caratteri scritti (escluso il `\0` finale).

**Esempio base**

```c
#include <stdio.h>

int main() {
    char buffer[50];
    int anno = 2025;
    sprintf(buffer, "L'anno è %d", anno);
    printf("%s\n", buffer);
    return 0;
}

//Output:     L'anno è 2025
```

**Cosa è successo?**

- `sprintf()` ha "stampato" la stringa `"L'anno è 2025"` dentro il `buffer[]`, non sul terminale.

- Poi `printf()` stampa `buffer`.

**Altro esempio con più variabili**

```c
char buffer[100];
char nome[] = "Giulia";
int età = 23;

sprintf(buffer, "%s ha %d anni.", nome, età);
printf("%s\n", buffer);
// buffer = "Giulia ha 23 anni."
```

---

### Funzioni che operano su singoli caratteri

```c
#include <ctype.h>
```

| Funzione | Valore di ritorno                                                                              |
|:--------:| ---------------------------------------------------------------------------------------------- |
| isalpha  | true se l'argomento è una lettera, false altrimenti                                            |
| isalnum  | true se l'argomento è lettera o numero, false altrimenti                                       |
| isdigit  | true se l'argomento è numero, false altrimenti                                                 |
| isxdigit | true se l'argomento è un carattere valido per la rappresentazione esadecimale: 0 - 9, a-f, A-F |

| Funzione | Valore di ritorno                                                     |
|:--------:|:--------------------------------------------------------------------- |
| isprint  | true se l’argomento è un carattere stampabile, false altrimenti       |
| ispunct  | true se l’argomento è un carattere di punteggiatura, false altrimenti |
| islower  | true se l’argomento è minuscolo, false altrimenti                     |
| isupper  | true se l’argomento è maiuscolo, false altrimenti                     |
| isspace  | true se l’argomento è uno spazio, false altrimenti                    |

Esempio di utilizzo:

```c
#include <stdio.h>
#include <ctype.h>

int main() {
 char c = 'A';
 char d = '7';
 char e = ' ';
 char f = '#';
 char g = 'f';

printf("Carattere: %c\n", c);
printf("isalpha:   %s\n", isalpha(c) ? "true" : "false");
printf("isalnum:   %s\n", isalnum(c) ? "true" : "false");
printf("isdigit:   %s\n", isdigit(c) ? "true" : "false");
printf("isxdigit:  %s\n", isxdigit(c) ? "true" : "false");
printf("isprint:   %s\n", isprint(c) ? "true" : "false");
printf("ispunct:   %s\n", ispunct(c) ? "true" : "false");
printf("islower:   %s\n", islower(c) ? "true" : "false");
printf("isupper:   %s\n", isupper(c) ? "true" : "false");
printf("isspace:   %s\n", isspace(c) ? "true" : "false");

printf("\nCarattere: %c\n", d);
printf("isdigit:   %s\n", isdigit(d) ? "true" : "false");
printf("isalnum:   %s\n", isalnum(d) ? "true" : "false");

printf("\nCarattere: '%c' (spazio)\n", e);
printf("isspace:   %s\n", isspace(e) ? "true" : "false");

printf("\nCarattere: %c\n", f);
printf("ispunct:   %s\n", ispunct(f) ? "true" : "false");

printf("\nCarattere: %c\n", g);
printf("isxdigit:  %s\n", isxdigit(g) ? "true" : "false");

return 0;
}
```

**Esempio pratico con `if`**

```c
#include <stdio.h>
#include <ctype.h>

int main() {
 char c = 'A';

if (isalpha(c)) {
    printf("%c è una lettera.\n", c);
}

if (isdigit(c)) {
    printf("%c è una cifra.\n", c);
} else {
    printf("%c NON è una cifra.\n", c);
}

if (isupper(c)) {
    printf("%c è una lettera maiuscola.\n", c);
}

return 0;

}
```

**Spiegazione**
Le funzioni di <ctype.h> restituiscono un intero diverso da zero se la condizione è vera, e 0 se è falsa.

Quindi:

```c
if (isalpha(c))  // equivalente a: if (isalpha(c) != 0)
```

è perfettamente corretto.

```c
#include <ctype.h>
int toupper(int c);
int tolower(int c);
```

Entrambe le funzioni `toupper()` e `tolower()` prevedono un parametro formale int che rappresenta un carattere.
La funzione toupper resituisce la versione maiuscola del carattere passato come argomento. La funzione tolower fa l'inverso.
