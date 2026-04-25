
/*
-Gli alberi sono strutture dati particolari, in cui ogni nodo può avere al massimo un genitore.
	

		Questo è un albero(un solo G)		 Questo non è un albero(due G)
			  [G]                                   [G]     [G]
		     | 	 |                                    |     |
		     v   v                                     >[F]<                                     
			[F]	[F]


-Un genitore può invece avere numero massimo di figli pari alla sua "arietà" (numero massimo di figli per genitore).


		   ---[G]---
           |   |   |
		   v   v   v		Albero di arietà 3 (3 figli)
 		  [F] [F] [F]


		   ---[G]---
           |   |   |
		   v   v   v		Albero di arietà 3 (3 figli)
 		  [F] [F] [F]		questo albero ha sempre arietà 3 perchè non ci sono nodi che superino questo numero di figli
               |
           ---------    
           |   |   | 
		   v   v   v
		  [F] [F] [F]


-Gli alberi che andiamo ad approfondire sono sempre alberi di arietà 2, che prendono cioè il nome di alberi binari.
-Il nodo più in alto prende il nome di radice (ROOT). Un nodo che non ha figli prende il nome di foglia (LEAF).
-Possono esistere anche alberi con un solo nodo, saranno alberi dove quest unico nodo viene detto radice

-Gli alberi possono essere suddivisi per livelli:

			[G]                --> livello 0 (1 nodo = 2^0) = (arietà = 2, livello = 0)  -->  (arietà^livello = 2^0 = 1)
		----  -----
		|         |
		v         v
	   [F1]      [F1]          --> livello 1  (2 nodi = 2^1) = (arietà = 2, livello = 1)  -->  (arietà^livello = 2^1 = 2)
	  ------    ------
	  |    |    |    |
	 [F2] [F2] [F2]  [F2]      --> livello 2  (4 nodi = 2^2) = (arietà = 2, livello = 2)  -->  (arietà^livello = 2^2 = 4)

-In ogni livello il numero di nodi seguono l'ordine delle potenze di 2. Il numero di nodi è anche esprimibile come arietà^livello
-Il numero di livelli totali in un albero è quindi sempre  uguale alla sommatoria per i che va da 1 al massimo livello di 2^i. Se chiamo n questo valore, allora l'altezza dell'albero h = log_2(n)

-Un'interessante proprietà degli alberi binari è la BINARY SEARCH TREE (BST): "Tutti i nodi nel sottoalbero sinistro di x devono essere <= di x mentre tutti i nodi del sottoalberi destro devono essere >= x"
 (la proprietà vale anche per i sottoalberi binari, guarda minuto 32:33 della lezione del  28 Maggio)

-E' ancora un albero binario di ricerca:

					[41]
					 |
					 v
					[15]	BTS (albero binario di ricerca degenere)
					 |
					 v
					...
					 |
					 v
					...

- Dati una serie di valori, si possono costruire più alberi di ricerca. Quale tra questi è il "migliore"?
  Il "migliore" tra tutti gli alberi costruibili con determinati valori è quello detto bilanciato, quello cui altezza 
  del sotto-albero destro è uguale all'altezza del sotto-albero sinistro.
    
  
					[9]                     (*1*)
			--------   --------
			|		          |
			v                 v
		   [4]              [15]
	      -    -           -    -
	     |     |          |     | 			altezza sotto-albero sinistro = 2  |    --> albero bilanciato
	     v     v          v     v           altezza sotto-albero destro = 2    |    
		[3]   [7]       [12]   [41]
	   -   	           -
	  |               |
	  v               v  
	 [1]            [10]
	 
	 	 	 
	 
					[15]                    (*2*)
			--------   --------
			|		          |
			v                 v
		   [4]              [41]
	   ----    ----               
	   |          |             			altezza sotto-albero sinistro = 3  |    --> albero sbilanciato (disparità di nodi tra i due sotto-alberi)
	   V          V        		            altezza sotto-albero destro = 1    |    
	  [1]        [10]
		    ---     ---
		   |	      |
		   V	      v
		  [9]    	[12]           
	    --  	           
	   |
	   v
	  [7]               
	                  

- Il mininimo in un BTS si trova sempre nel nodo(oppure nella foglia) più a sinistra, viceversa il massimo si trova sempre nel nodo(oppure nella foglia) più a destra.
- La visita in order dell'albero parte dalla Root e visita in ordine tutto l'albero. Il tempo impiegato da una visita in order è O(n) (dipendente cioè dal numero di nodi n)

*/


#include <iostream>
using namespace std;

template <class T>
class NodeBST{
	T key;
	NodeBST* left;
	NodeBST* right;
	NodeBST* parent;

	public:
		NodeBST(T key) : key(key), left(NULL), right(NULL), parent(NULL){}
		NodeBST() : NodeBST(0){}
		
		T getKey(){
			return this->key;
		}
		NodeBST<T>* getLeft() const{
			return this->left;
		}
		NodeBST<T>* getRight() const{
			return this->right;
		}
		NodeBST<T>* getParent() const{
			return this->parent;
		}
		friend ostream& operator << (ostream& stream, const NodeBST& n){
			stream << "Adress = " << &n << ", key = " << n.key << ", left = " << n.left << ", right = " << n.right;
			return stream;
		}
};

template <class T>
class BST{
	NodeBST<T>* root;
	
	public:
		BST(NodeBST<T>* root) : root(root){}
		BST() : BST(NULL){}
		
		void search(){
		}
		void inOrder(){
		}
		void predecessor(){
		}
		void successor(){
		}
		T min(){
			return "value";
		}
		T max(){
			return "value";
		}
		friend ostream& operator << (ostream& stream, const NodeBST& n){
			stream << "";
			return stream;
		}
};

//Continua 2h: 13m

int main(){
	NodeBST<int> n = NodeBST<int>(10);
	cout << n << endl;
	return 0;
}
