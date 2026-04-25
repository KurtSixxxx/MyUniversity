# Equivalenza: Esercizi (1)

Verificare che se si considerano i valori numerici 1 per vero e 0 per falso, e assegnati tali valori numerici alle variabili proposizionali p e q abbiamo che:

1. $\neg p \equiv 1 - p$
2. $p \vee q \equiv max(p,q)$
3. $p \land q \equiv min(p,q)$
4. $p \implies q = max(1-p,q)$
5. $p \iff q = min(max(1-p,q),max(p,1-q))$

---

Ho impostato V = 1 e F = 0

1. $\neg p \equiv 1 - p$
se p = 1, allora $\neg p = 0 \rightarrow 0 \equiv 1 - 1 \rightarrow 0 \equiv 0$ ✅
se p = 0, allora $\neg p = 1 \rightarrow 1 \equiv 1- 0 \rightarrow 1 \equiv 1$ ✅
2. $p \vee q \equiv max(p,q)$
se p = 0 e q = 0, allora $\rightarrow 0 \vee 0 \equiv max(0,0) \rightarrow 0 \equiv 0$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \vee 1 \equiv max(0,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \vee 1 \equiv max(1,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \vee 0 \equiv max(1,0) \rightarrow 1 \equiv 1$ ✅
3. $p \land q \equiv min(p,q)$
se p = 0 e q = 0, allora $\rightarrow 0 \land 0 \equiv min(0,0) \rightarrow 0 \equiv 0$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \land 1 \equiv min(0,1) \rightarrow 0 \equiv 0$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \land 1 \equiv min(1,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \land 0 \equiv min(1,0) \rightarrow 0 \equiv 0$ ✅
4. $p \implies q = max(1-p,q)$
se p = 0 e q = 0, allora $\rightarrow 0 \implies 0 \equiv max(1-0,0) \rightarrow 1 \equiv 1$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \implies 1 \equiv max(1-0,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \implies 1 \equiv max(1-1,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \implies 0 \equiv max(1-1,0) \rightarrow 0 \equiv 0$ ✅
5. $p \iff q = min(max(1-p,q),max(p,1-q))$
se p = 0 e q = 0, allora $\rightarrow 0 \iff 0 \equiv min(max(1,0),max(0,1)) \rightarrow 1 \equiv 1$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \iff 1 \equiv min(max(1,1),max(0,0)) \rightarrow 0 \equiv 0$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \iff 1 \equiv min(max(0,1),max(1,0)) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \iff 0 \equiv min(max(0,0),max(1,1)) \rightarrow 0 \equiv 0$ ✅