#include <iostream>
#include "bst.h"
using namespace std;

int main()
{

  /*
          8
         / \
        5   10
      /  \    \
     3    6    12
  */

  BST<int> alberoIntero;
  BST<char> alberoChar;

  alberoIntero.insert(8);
  alberoIntero.insert(5);
  alberoIntero.insert(10);
  alberoIntero.insert(3);
  alberoIntero.insert(6);
  alberoIntero.insert(12);

  cout << "**** VISUALIZZAZIONE BST DI INTERI ****" << endl;

  alberoIntero.preorder();

  cout << "\n\n**** CONTEGGIO SUCCUESSORI ****" << endl;

  cout << "Numero di successori di 3: " << alberoIntero.distanzaSuccessore(3) << endl;

  cout << "Numero di successori di 5: " << alberoIntero.distanzaSuccessore(5) << endl;

  cout << "Numero di successori di 6: " << alberoIntero.distanzaSuccessore(6) << endl;

  cout << "Numero di successori di 8: " << alberoIntero.distanzaSuccessore(8) << endl;

  cout << "Numero di successori di 10: " << alberoIntero.distanzaSuccessore(10) << endl;

  cout << "Numero di successori di 12: " << alberoIntero.distanzaSuccessore(12) << endl;

  cout << "Numero di successori di 15: " << alberoIntero.distanzaSuccessore(15) << endl;

  alberoChar.insert('a');
  alberoChar.insert('d');
  alberoChar.insert('c');
  alberoChar.insert('e');
  alberoChar.insert('h');
  alberoChar.insert('b');

  cout << "\n\n**** VISUALIZZAZIONE BST DI CHAR ****" << endl;

  alberoChar.inorder();

  cout << "\n\n**** VISUALIZZAZIONE SUCCESSORI  ****" << endl;

  cout << "Numero di successori di a: " << alberoChar.distanzaSuccessore('a') << endl;

  cout << "Numero di successori di b: " << alberoChar.distanzaSuccessore('b') << endl;

  cout << "Numero di successori di c: " << alberoChar.distanzaSuccessore('c') << endl;

  cout << "Numero di successori di d: " << alberoChar.distanzaSuccessore('d') << endl;

  cout << "Numero di successori di e: " << alberoChar.distanzaSuccessore('e') << endl;

  cout << "Numero di successori di h: " << alberoChar.distanzaSuccessore('h') << endl;

  cout << "Numero di successori di g: " << alberoChar.distanzaSuccessore('g') << endl;
};