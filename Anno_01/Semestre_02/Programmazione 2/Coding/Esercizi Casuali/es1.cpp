#include <iostream>
#include <cstdlib> //per rand e srand
#include <ctime> //per time()
#include <string> //per sasso carta forbice

using namespace std;

int main(){
int N;
    srand(time(0)); //rand() % (b-a+1) + a;

    do{
        cout << "\n--- MENU OPERAZIONI ---\n";
        cout << "1. Carta Forbice Sasso\n2. Dadi\n3. Esci\n";
        cout << "Scelta: ";
        cin >> N;
        cout << "\n";

    switch(N){
        case 1:{
        cout << "Hai selezionato " << N << "\n";
        cout << "Operazione corrispondete: Simula l'andamento di una partita a carta forbice sasso.\n";
        
        int playerA;
        int playerB;
        int n1;
        int scoreA, scoreB;
        scoreA = 0;
        scoreB = 0;

        do {
            cout << "Inserisci un numero di tentativi N (deve essere dispari): ";
            cin >> n1;
            
            if (n1 % 2 == 0) {
                cout << "Errore: " << n1 << " e' pari! Riprova.\n";
            }
        } while (n1 % 2 == 0); // Continua a tornare su while n1 è pari


        string nomi[] = {"Sasso", "Carta", "Forbice"}; 
        for(int i = 0; i < n1; i++){
            cout << "Tentativo numero " << i+1;
            cout << "\n";
            playerA = (rand() % 3);
            playerB = (rand() % 3);
            cout << "Player A = " << nomi[playerA] << "\t" << "Player B = " << nomi[playerB] << "\n";
            if (playerA == playerB) {
                cout << "Pareggio!\n";
            } else if ((playerB + 1) % 3 == playerA) {
                    cout << "Vince Player A\n";
                    scoreA += 1;
            } else {
                cout << "Vince Player B\n";
                scoreB += 1;
            }
            cout << "\n";
        }

        cout << "\n";

        if(scoreA == scoreB){
            cout << "Partita finita in pareggio.\n";
        }else if(scoreA > scoreB){
            cout << "Player A vince lo scontro!\n";
        }else if(scoreB > scoreA){
            cout << "Player B vince lo scontro!\n";
        }
        break;
        }
        
        case 2:{
        cout << "Hai selezionato " << N << "\n";
        cout << "Operazione corrispondete: Simula l'esito della somma del lancio di due dadi.\n";

        int D1 = 0;
        int D2 = 0;
        int n2;
        int sum = 0;

        cout << "Inserire il numero di lanci che si vogliono effettuare: ";
        cin >> n2;

        for(int i = 0; i < n2; i++){
            cout << "Lancio numero " << i+1 << "\n";
            D1 = (rand() % (6-1+1) + 1); //Come intervallo scelgo [1,6] per simulare il dado con le 6 facce
            D2 = (rand() % (6-1+1) + 1); 
            sum += D1 + D2;
            cout << "Dado 1: " << D1 << "\t" << "Dado 2: " << D2 << "\t" <<"Somma: " << sum << "\n";
            cout << "\n";
        }
        cout << "Somma finale: " << sum;
        break;
    }
        case 3:{
        cout << "Hai selezionato " << N << "\n";
        cout << "Operazione corrispondete: Uscita dal programma.\n";

        cout << "Procedo con l'uscita dal programma\n";
        exit(-1);
        break;
        }

        default:{
            cout << "Valore non definito, riprovare\n";
            cout << "Inserisci nuovamente un valore: ";
            cin >> N;
            }
        }
    }while (N != 3);

return 0;
}