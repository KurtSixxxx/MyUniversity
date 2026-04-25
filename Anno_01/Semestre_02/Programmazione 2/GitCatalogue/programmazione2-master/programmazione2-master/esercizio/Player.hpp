#include <iostream>
using namespace std;


class Player{
	string surname;
	string name;
	string circle;
	double score;
	int birthdayDate;

	public:
		Player(string surname, string name, string circle, double score, int birthdayDate) : surname(surname), name(name), circle(circle), score(score), birthdayDate(birthdayDate){}
		Player(){}

		void setSurname(string surname){
			this->surname = surname;
		}
		void setName(string name){
			this->name = name;
		}
		void setCircle(string circle){
			this->circle = circle;
		}
		void setScore(double score){
			this->score = score;
		}
		void setBirthdayDate(int birthdayDate){
			this->birthdayDate = birthdayDate;
		}
		string getSurname() const {
			return this->surname;
		}
		string getName() const {
			return this->name;
		}
		string getCircle() const { 
			return this->circle;
		}
		double getScore() const {
			return this->score;
		}
		int getBirthdayDate() const {
			return this->birthdayDate;
		}
		friend istream& operator >> (istream& in, Player& p){
			string scoreString;
			string birthdayDateString; 

			getline(in, p.surname, ';');
			getline(in, p.name, ';');
			getline(in, p.circle, ';');
			getline(in, scoreString, ';');
			getline(in, birthdayDateString, '\n');
			p.score = stod(scoreString);
			p.birthdayDate = stoi(birthdayDateString);
			return in;
		}
		friend ostream& operator << (ostream& out, const Player& p){
			out << "Giocatore : " << " cognome = " << p.getSurname() << " nome = " << p.getName() << " circolo = " << p.getCircle() << " punteggio = " << p.getScore() << " data di nascita = " << p.getBirthdayDate();
			return out;
		}
};