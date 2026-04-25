# Lezione del 04 maggio 2022

### Ereditarietà, Polimorfismo e Template:

### Incapsulamento (Information Hiding)

Significa utilizzare dei modificatori di accesso in base ai dati che vogliamo rendere visibili o meno.

I principali modificatori di accesso sono:
* Private (-)
* Public (+)
* Protected (*)

### Ereditarietà e modificatori di accesso

Class B : **public** A

* private A -> B non accessibile
* protected A -> B protected
* public A -> B public

Class B : **protected** A

* private A -> B non accessibile
* protected A -> B protected
* public A -> B protected

Class B : **private** A

* private A -> B non accessibile
* protected A -> B private
* public A -> B private

### Template

Definiscono uno o più tipi generico di dato

```C++
template<class T1, class T2> //Attenzione se il template contiene più dati è obbligatorio usare class e non typename
```

### Friend

La keyword friend fornisce ad una funzione o ad una classe accesso ai membri privati e protetti della classe in cui appare.

Principali utilizzi:

1. Designare funzioni o membri di altre classi come friend della classe
2. Definire funzioni non membro all'interno delle classi friend
3. Designare classi che verranno utilizzate successivamente come friend della classe stessa