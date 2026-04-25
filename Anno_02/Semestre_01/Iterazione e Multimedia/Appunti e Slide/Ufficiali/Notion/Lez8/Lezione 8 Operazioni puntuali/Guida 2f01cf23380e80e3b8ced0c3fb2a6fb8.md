# Guida

### **SINTESI FINALE PER IL TUO STUDIO ATTIVO**

Hai ora tra le mani una spiegazione integrata e discorsiva. Per trasformare questo in studio attivo, ti consiglio di fare così quando lo riscriverai:

1. **Ripercorri il flusso logico:** Inizia sempre dalla griglia di numeri (0-255) e dalla formula `g = T(f)`.
2. **Disegna i grafici LUT:** Per ogni operazione (negativo, logaritmo, gamma>1, gamma<1, binarizzazione), prendi un foglio e **disegna a mano** l'asse X e l'asse Y. Poi traccia la curva caratteristica. Questo è l'esercizio più importante.
3. **Fai esempi numerici:** Prendi tre valori: un pixel scuro (30), uno medio (128), uno chiaro (220). Applica mentalmente le regole e chiediti: "Questo operatore lo schiarisce o lo scurisce? Di molto o di poco?".
4. **Collega la formula al grafico:** Quando vedi `s = c * r^γ`, non memorizzarla. Pensa: "Ah, γ è l'esponente. Se è piccolo (<1), la curva sul grafico sarà convessa verso l'alto, quindi schiarirà le ombre".
5. **Rispondi alle domande nel testo:** Dove ti ho lasciato una domanda ("Domanda per te..."), fermati e prova a ragionare con la tua testa prima di cercare la risposta.

Il tuo obiettivo non è ricordare a memoria le formule, ma essere in grado di **guardare una curva LUT e prevedere l'effetto sull'immagine**, e viceversa, di **descrivere con parole tue l'effetto che vuoi ottenere e sapere che tipo di curva ti serve**.

Buon lavoro di riscrittura! È nel momento in cui rielaborerai questi concetti con le tue parole e i tuoi disegni che diventeranno davvero tuoi.