# Digital Forensics: Lez 4

---

## Il Reperto informatico: le 5 fasi

- **Identificazione**

- **Acquisizione**

- **Analisi**

- **Valutazione**

- **Presentazione**

#### Identificazione

Rilevazione cosa è effettivamente utile per l'indagine:

- Sistemi informatici

- Sistemi di comunicazione

- Supporti di memorizzazione esterna

- Suppporti non digitali e informazioni
  
  - Documenti, post-it...
  
  - Password, modalità di accesso a sistemi complessi

Quindi sostanzialmente dobbiamo capire cosa ci serverà analizzare per prelevare le prove.



### Acquisizione

Duplicare le informazioni in maniere fedele all'originale

- Cloni

- Immagini bit-a-bit

- Immagini bit-a-bit compresse

Obiettivi

- Acquisire il maggiore numero di dati

- Rendere l'attività di acquisizione ripetibile

- Limitare i tempo di inattività di server "importanti"

L'acquisizione deve essere: completa, accurata e incontaminata

Chi effettua le indagini deve poter ottenere i dati in modo completo con interfenze minime sui dati originali sotto esame. Tali dati possono essere stampati e copiati, anche se questo porta 

L'hash è l'impronta digitale di un file.
Tramite le funzioni hash otteniamo in outpt il digest di un file: una sequenza di simboli binari è una sequenza di simboli binari di lumghezza predefinita generata mediante l'applicazione alla prima di un'opportuna funzione di hash.
Non si può risalire al testo originale tramite un digest.

Collisioni dello stesso valore del digest da due fonti diverse sono quindi pressochè impossibili.

- Proprietà delle funzioni hash
  
  Nel linguaggio tenico, la funzione hash è una funzione iniettiva (e quini non invertibile) che mappa una stringa di lunghezza arbitraria in una stringa di lunghezza predefinita. Esistono numerosi algoritmi che realizzano funzioni hash con paritcolari proprietà che dipendono dall'applicazione. Nelle applicazioni cittografiche si richiedono alcune proprietà per la crittografia:
  
  - ressistenza alla preimmagine
  
  - resistenza alla seconda preimmagine
  
  - resistenza elle collisioni

MD5 (Message Digest algorithm 5): una tipologia di hash
Questo tipo di codifica prende in input una stringa di lunghezza arbitraria e ne restituisce una di 128bit.

SHA (Secure Hash Algorithm): famiglia di 5 algoritmi hash diversi.

### Analisi

Mettere in evidenza i datii con contenunto informatico per l'indagine, sia che sia a favore o a sfavore dell'immagine. Bisogna essere completamente imparziali, altrimenti si rischia di essere indagati per falsa testimonianza (sotto veste di informatico forense). Si potrebbe essere sanzionati o essere segnalati all'albo e perdere la certificazione.

E' inoltre importante documentare il processo di analisi.

Molto importante è che l'analisi va eseguita su una copia (bit a bit) e, naturalmente, deve essere riproducibile.

### Valutazione

Dopo aver analizzato e documentato tutte le prove si arriva alla valutazione. Bisogna elenacare anche tutti i tool che abbiamo utilizzato, ma è importante che quest'ultimi siano certificati, altrimenti l'analisi non risulta valids. Se invece decidiamo di creare un tool noi stessi, non possiamo farlo perchè potrebbero esserci errori nel codice e portare a risultati errati. Quindi, come nel caso precedente è importante dichiarare solo tool certificati.

Nella fase di valutazione si interpretano i dati evidenziat in fase di analisi per sostenere le proprie tesi, che siano a favore o a sfavore dell'imputato.

### Presentazione

In questa fase bisogna documentare cosa e come è stato fatto, cosa è emerso e che significato hanno i dati emersi.

Inoltre è importante adattare il registro verbale (ossia come esponiamo) per far comprendere anche al tecnico e al giurista.
