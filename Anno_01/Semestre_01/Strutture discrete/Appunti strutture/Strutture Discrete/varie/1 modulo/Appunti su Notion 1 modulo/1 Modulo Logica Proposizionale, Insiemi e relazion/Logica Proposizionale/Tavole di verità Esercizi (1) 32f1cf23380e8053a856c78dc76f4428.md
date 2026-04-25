# Tavole di verità: Esercizi (1)

Costruisci le Tavole di Verità delle seguenti formule:

- $p \land q \land (r \vee s)$
- $p \vee q \vee (r \land s)$
- $p \land (q \vee (s \land ( \neg p \vee \neg q)))$
- $((p \vee \neg q \vee r) \land s) \vee t$

---

1. $p \land q \land (r \vee s)$
    
    
    | $p$ | $q$ | $r$ | $s$ | $r \vee s$ | $q \land (r \vee s)$ | $p \land q \land (r \vee s)$ |
    | --- | --- | --- | --- | --- | --- | --- |
    | V | V | V | V | V | V | V |
    | V | V | V | F | V | V | V |
    | V | V | F | V | V | V | V |
    | V | V | F | F | F | F | F |
    | V | F | V | V | V | F | F |
    | V | F | V | F | V | V | V |
    | V | F | F | V | V | F | F |
    | V | F | F | F | F | F | F |
    | F | V | V | V | V | V | F |
    | F | V | V | F | V | V | F |
    | F | V | F | V | V | V | F |
    | F | V | F | F | F | F | F |
    | F | F | V | V | V | F | F |
    | F | F | V | F | V | F | F |
    | F | F | F | V | V | F | F |
    | F | F | F | F | F | F | F |
2. $p \vee q \vee (r \land s)$
    
    
    | $p$ | $q$ | $r$ | $s$ | $r \land s$ | $q \vee (r \land s)$ | $p \vee q \vee (r \land s)$ |
    | --- | --- | --- | --- | --- | --- | --- |
    | V | V | V | V | V | V | V |
    | V | V | V | F | F | V | V |
    | V | V | F | V | F | V | V |
    | V | V | F | F | F | V | V |
    | V | F | V | V | V | V | V |
    | V | F | V | F | F | F | V |
    | V | F | F | V | F | F | V |
    | V | F | F | F | F | F | V |
    | F | V | V | V | V | V | V |
    | F | V | V | F | F | V | V |
    | F | V | F | V | F | V | V |
    | F | V | F | F | F | V | V |
    | F | F | V | V | V | V | F |
    | F | F | V | F | F | F | F |
    | F | F | F | V | F | F | F |
    | F | F | F | F | F | F | F |
3. $p \land (q \vee (s \land ( \neg p \vee \neg q)))$
    
    
    | $p$ | $\neg p$ | $q$ | $\neg q$ | $s$ | $( \neg p \vee \neg q)$ | $(s \land ( \neg p \vee \neg q)$ | $q \vee (s \land ( \neg p \vee \neg q))$ | $p \land (q \vee (s \land ( \neg p \vee \neg q)))$ |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | V | F | V | F | V | F | F | V | V |
    | V | F | V | F | F | F | F | V | V |
    | V | F | F | V | V | V | V | V | V |
    | V | F | F | V | F | V | F | F | F |
    | F | V | V | F | V | V | V | V | V |
    | F | V | V | F | F | V | F | V | V |
    | F | V | F | V | V | V | V | V | V |
    | F | V | F | V | F | V | F | F | F |
4. $((p \vee \neg q \vee r) \land s) \vee t$
    
    
    | $p$ | $\neg q$ | $r$ | $s$ | $t$ | $(p \vee \neg q \vee r)$ | $((p \vee \neg q \vee r) \land s)$ | $((p \vee \neg q \vee r) \land s) \vee t$ |
    | --- | --- | --- | --- | --- | --- | --- | --- |
    | V | V | V | V | V | V | V | V |
    | V | V | V | V | F | V | V | V |
    | V | V | V | F | V | V | F | V |
    | V | V | V | F | F | V | F | F |
    | V | V | F | V | V | F | F | V |
    | V | V | F | V | F | F | F | F |
    | V | V | F | F | V | F | F | V |
    | V | V | F | F | F | F | F | F |
    | V | V | V | V | V | V | V | V |
    | V | F | V | V | F | F | F | F |
    | V | F | V | F | V | F | F | V |
    | V | F | V | F | F | F | F | F |
    | V | F | F | V | V | F | F | V |
    | V | F | F | V | F | F | F | F |
    | V | F | F | F | V | F | F | V |
    | V | F | F | F | F | F | F | F |
    | F | F | V | V | V | F | F | V |
    | F | F | V | V | F | F | F | F |
    | F | V | V | F | V | F | F | V |
    | F | V | V | F | F | F | F | F |
    | F | V | F | V | V | F | F | V |
    | F | V | F | V | F | F | F | F |
    | F | V | F | F | V | F | F | V |
    | F | V | F | F | F | F | F | F |
    | F | V | V | V | V | F | F | V |
    | F | V | V | V | F | F | F | F |
    | F | F | V | F | V | F | F | V |
    | F | F | V | F | F | F | F | F |
    | F | F | F | V | V | F | F | V |
    | F | F | F | V | F | F | F | F |
    | F | F | F | F | V | F | F | V |
    | F | F | F | F | F | F | F | F |