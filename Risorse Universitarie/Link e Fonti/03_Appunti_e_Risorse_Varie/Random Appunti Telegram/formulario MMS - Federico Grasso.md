#RISOLUTORE DI ESERCIZI#
#COMANDI EXCEL IT/    - ENG#
- Media
    - ITA **=MEDIA(Valori)**
    - ENG **=AVERAGE(Valori)**

- Media pesata
    - ITA **=MATR.SOMMA.PRODOTTO(Valori, pesi)/SOMMA(Valori)**
    - ENG **=SUMPRODUCT(Valori, pesi)/SUM(Valori)**

- Mediana
    - ITA **=MEDIANA(Valori)**
    - ENG **=MEDIAN(Valori)**

- Moda
    - ITA **=MODA(Valori)**
    - ENG **=MODE(Valori)**

- Quartile
    - ITA **=QUARTILE(Valori,quartile)**

- Varianza
    - ITA **=VAR.POP(Valori)**
    - ENG **=VARP(Valori)**

- Deviazione standard
    - ITA **=DEV.ST(Valori)**
    - ENG **=STDEV(Valori)**

- Indice di simmetria
    - ITA **=ASIMMETRIA(Valori)**
    - ENG **=SKEW(Valori)**

- Curtosi
    - ITA **=CURTOSI(Valori)**
    - ENG **=KURT(Valori)**

- Correlazione
    - ITA **=CORRELAZIONE(MARTICEA, MATRICEB)**
    - ENG **=CORREL(MATRICEA,MATRICEB)**

- Covarianza
    - ITA **=COVARIANZA(MATRICEA,MATRICEB)**
    - ENG **=COVAR(MATRICEA,MATRICEB)**

- Metodo dei minimi quadrati
    - ITA **=REGR.LIN(colonnaY,colonnaX,vero,vero)**
    - ENG **=LINEST(colonnaY,colonnaX,vero,vero)**

    - ITA **=PENDENZA(y_nota, x_nota)**
    - ENG **=SLOPE(y_nota, x_nota)**

    - ITA **=INTERCETTA(y_nota, x_nota)**
    - ENG **=INTERCEPT(y_nota, x_nota)**

    - ITA **=TENDENZA(y_nota; x_nota; x)**
    - ENG **=TREND(y_nota; x_nota; x)**

- Coefficiente di Pearson(o coefficiente di correlazione lineare)
    - ITA **=PEARSON(valori_dip,valori_ind)**

- Distribuzione binomiale
    - ITA **=DISTRIB.BINOM(num_successi,prove,probabilità_s,cumulativo)**
    - ENG **=BINOMDIST(num_successi,prove,probabilità_s,cumulativo)**
se cumulativo = VERO viene distribuita la funzione di ripartizione, se FALSO viene restituita la distribuzione di probabilità

- Distribuzione di Poisson
    - ITA **=POISSON(x,media,cumulativo)**
se cumulativo = VERO viene distribuita la funzione di ripartizione, se FALSO viene restituita la distribuzione di probabilità

- Distribuzione di Weibull
    - ITA **=WEIBULL(x,alfa,beta,cumulativo)**
se cumulativo = VERO viene distribuita la funzione di ripartizione, se FALSO viene restituita la distribuzione di probabilità

- Distribuzione normale standardizzata
    - ITA **=DISTRIB.NORM(x,media,deviazione_standard,cumulativo)**
    - ENG **=NORMDIST(x,media,deviazione_standard,cumulativo)**
se cumulativo = VERO viene distribuita la funzione di ripartizione, se FALSO viene restituita la distribuzione di probabilità

- Distribuzione di chi-quadro
    - ITA **=DISTRIB.CHI(x,n_gradi_libertà)**
    - ENG **=CHIDIST(x,n_gradi_libertà)**

- Distribuzione t di student
    - ITA **=DISTRIB.T(x,n_gradi_libertà,coda)**
    - ENG **=TDIST(x,n_gradi_libertà,coda)**

- Intervallo di confidenza
    - ITA **=CONFIDENZA(alfa,dev_standard,dimensioni)**
    - ENG **=CONFIDENCE(alfa,dev_standard,dimensioni)**

- Test di student
    - ITA **=TEST.T(matrice1;matrice2;coda;tipo)**
    - ENG **=TTEST(matrice1;matrice2;coda;tipo)**

- Test chi-quadro
    - ITA **=TEST.CHI(int_effettivo;int_previsto)**
    - ENG **=CHITEST(int_effettivo;int_previsto)**
