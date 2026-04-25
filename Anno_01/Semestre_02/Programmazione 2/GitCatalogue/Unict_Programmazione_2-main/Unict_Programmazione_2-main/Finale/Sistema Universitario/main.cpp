#include <iostream>

using namespace std;

class Student
{
public:
    Student(int fr, string n, string s, bool w) : freshman(fr), name(n), surname(s), student_worker(w) {}
    ~Student(){}

    int getFreshman() const {return freshman;}
    string getName() const {return name;}
    string getSurname() const {return surname;}
    bool getStudent_worker() const {return student_worker;}

    void print_student() const 
    {
        if(student_worker)
            cout << "ID:" << freshman << " " << name << " " << surname << " [Student Worker]"<< endl;
        else
            cout << "ID:" << freshman << " " << name << " " << surname << " [Student]"<< endl;
    }


private:
    string name;
    string surname;
    int freshman;
    bool student_worker;
};

class Course
{
public:
    Course(string t, string i, int p) : title(t), id(i), places_available(p) , count_s(0), capacity_s(p)
    {
        students = new Student*[capacity_s];
    }

    ~Course()
    {
        delete [] students;
    }

    string getTitle() const {return title;}
    string getId() const {return id;}
    int getPlace_avaible() const {return places_available;}

    bool available()
    {
        return places_available > 0;
    }

    bool registration(Student* s)
    {
        if(!available())
            return false;

        students[count_s++] = s;
        places_available--;
        return true;
    }

    bool cancellation(Student* s)
    {
        for(int i=0; i<count_s; i++)
        {
            if(students[i] == s)
            {
                for(int j=i; j<count_s-1; j++)
                {
                    students[j] = students[j+1];
                }

                students[count_s-1] = nullptr;
                count_s--;
                places_available++;
                return true;
            }
        }

        return false;
    }

    void print_student_worker() const
    {
        for(int i=0; i<count_s; i++)
        {
            if(students[i]->getStudent_worker())
                students[i]->print_student();
        }
    }

    void print_course() const
    {
        cout << "[Course] " << id << " " << title << " (P.Available:" << places_available << ")"<< endl;
    }

private:
    string title;
    string id;
    int places_available;

    Student** students;
    int count_s;
    int capacity_s;
};

class Entry
{
public:
    Entry(string id, Student *s, Course* c) : identification(id), student(s), course(c) {}
    ~Entry(){}

    string getIdentification() const {return identification;}
    Student* getStudent() const {return student;}
    Course* getCourse() const {return course;}

    bool start_registration()
    {
        if(!student || !course)
            return false;

        bool success = course->registration(student);

        if(success)
            return true;
        else
            return false;        
    }

    bool start_cancellation()
    {
        if(!student || !course)
            return false;

        bool success = course->cancellation(student);

        if(success)
            return true;
        else
            return false; 
    }

private:
    Student* student;
    Course* course;
    string identification;
};


class Teaching_Secretariat
{
public:
    Teaching_Secretariat(string n) : name(n), count_e(0), capacity_e(10), count_c(0), capacity_c(10), count_s(0), capacity_s(10)
    {
        entry = new Entry*[capacity_e];

        course = new Course*[capacity_c];

        student = new Student*[capacity_s];
    }

    ~Teaching_Secretariat()
    {
        
        for(int i=0; i<count_e; i++)
        {
            delete entry[i];
        }

        for(int i=0; i<count_c; i++)
        {
            delete course[i];
        }

        for(int i=0; i<count_s; i++)
        {
            delete student[i];
        }

        delete [] entry;
        delete [] course;
        delete [] student;
        
        
    }

    bool add_course(Course* c)
    {
        if(count_c >= capacity_c)
            resize(course,count_c,capacity_c);

        course[count_c++] = c;
        return true;
    }

    bool remove_course(Course* c)
    {

        //Questa parte prima non c'era
        for(int i = 0; i < count_e; i++)
        {
            if(entry[i]->getCourse() == c)
            {
                // Nota: Rimuoviamo l'iscrizione dall'array entry
                // (Simile alla logica di cancellazione, ma qui forziamo la rimozione)
                delete entry[i]; 
            
                // Shift degli elementi
                for(int j = i; j < count_e - 1; j++)
                {
                    entry[j] = entry[j+1];
                }
                entry[count_e - 1] = nullptr;
                count_e--;
                i--; // Decrementiamo i perché abbiamo shiftato l'array indietro
            }
        }
    
    
        for(int i=0; i<count_c; i++)
        {
            if(course[i] == c)
            {
                delete course[i];  //ho sbagliato prima con delete [] course;

                for(int j=i; j<count_c-1; j++)
                {
                    course[j] = course[j+1];
                }

                course[count_c-1] = nullptr;
                count_c--;
                return true;
            }
        }

        return false;
    }

    bool add_student(Student* s)
    {
        if(count_s >= capacity_s)
            resize(student,count_s,capacity_s);

        student[count_s++] = s;
        return true;
    }

    bool course_registration(string id, Student* s, Course* c)
    {
        if(count_e >= capacity_e)
            resize(entry,count_e,capacity_e);

        Student* found_s = find(student,count_s,s);
        Course* found_c = find(course,count_c,c);

        if(!found_s && !found_c)
        {
            cout << "=== Studente/Corso non trovato ===" << endl;
            return false;
        }

        Entry* ent = new Entry(id,s,c);

        if(!ent)
            return false;

        bool success = ent->start_registration();

        if(success)
        {
            entry[count_e++] = ent;
            cout << "===[TRUE] Iscrizione avvenuta con successo ===" << endl;
            return true;
        }
        else
        {
            cout << "===[FALSE] Iscrizione non avvenuta con successo ===" << endl;
            return false;
        }
    }

    bool cource_cancellation(string id, Student* s, Course* c)
    {
        Student* found_s = find(student,count_s,s);
        Course* found_c = find(course,count_c,c);

        if(!found_s && !found_c)
        {
            cout << "=== Studente/Corso non trovato ===" << endl;
            return false;
        }

        for(int i=0; i<count_e; i++)
        {
            if(entry[i]->getStudent() == found_s && entry[i]->getCourse() == found_c && entry[i]->getIdentification() == id)
            {
                entry[i]->start_cancellation();
    
                for(int j=i; j<count_e-1; j++)
                {
                    entry[j] = entry[j+1];
                }
                entry[count_e-1] = nullptr;
                count_e--;
                
                cout << "===[TRUE] Cancellazione al corso avvenuta con successo ===" << endl;
                return true;
            }
        }

        cout << "===[FALSE] Cancellazione al corso non avvenuta con successo ===" << endl;
        return false;
    }

    bool search_course(Course* c)
    {
        for(int i=0; i<count_c; i++)
        {
            if(course[i] == c && course[i]->available())
            {
                cout << "=== Corso Trovato: ===" << endl;
                course[i]->print_course();
            }
            else
            {
                cout << "=== Corso non disponibile (limite dei posti raggiunti) ===" << endl;
                return false;
            }
        }

        cout << "Corso non trovato" << endl;
        return false;
    }

    void Viewing_Study_Plan(Student* s) const
    {
        s->print_student();
        cout << endl;

        for(int i=0; i<count_e; i++)
        {
            if(entry[i]->getStudent() == s)
            {
                entry[i]->getCourse()->print_course();
            }
        }
    }

    void Workers_Report(Course* c) const
    {
        for(int i=0; i<count_c; i++)
        {
            if(course[i] == c)
            {
                course[i]->print_student_worker();
            }
        }
    }

    void print_all() const
    {
        cout << "=== Elenco Dei Corsi ===" << endl;
        for(int i=0; i<count_c; i++)
        {
            course[i]->print_course();
        }

        cout << "\n=== Elenco Degli Studenti ===" << endl;
        for(int i=0; i<count_s; i++)
        {
            student[i]->print_student();
        }
    }

private:
    string name;

    Entry** entry;
    int count_e;
    int capacity_e;

    Course** course;
    int count_c;
    int capacity_c;

    Student** student;
    int count_s;
    int capacity_s;

    template <typename T>
    void resize(T **&array,int count,int &capacity)
    {
        int newcapacity = capacity * 2;
        T** newarray = new T*[newcapacity];

        for(int i=0; i<count; i++)
        {
            newarray[i] = array[i];
        }

        for(int i=count; i<newcapacity; i++)
        {
            newarray[i] = nullptr;
        }

        delete [] array;
        array = newarray;
        capacity = newcapacity;
    }

    template <typename T>
    T* find(T **array,int count,T* key)
    {
        for(int i=0; i<count; i++)
        {
            if(array[i] == key)
                return array[i];
        }

        return nullptr;
    }


};

int main()
{
    Teaching_Secretariat segreteria("Unicit");

    Course* corso_1 = new Course("Programmazione 2","PROG2",5);
    Course* corso_2 = new Course("Elementi Di Analisi 2","EAM2",10);
    Course* corso_3 = new Course("Algoritmi","ALG0",5);
    Course* corso_4 = new Course("Interazione e Multimedia","IEM0",5);
    Course* corso_5 = new Course("Reti e Calcolatori","RET0",1);

    Student* student_1 = new Student(100061053,"Luca Mike","Motta",false);
    Student* student_2 = new Student(1000431062,"Mattia","Maresci",true);
    Student* student_3 = new Student(1000415255,"Ernesto","Triagono",false);
    Student* student_4 = new Student(1000451136,"Flavia","Lombardo",true);
    Student* student_5 = new Student(1000675487,"Francesca Aurora","Motta",true);
    Student* student_6 = new Student(1000123436,"Jessica","Channel",false);
    Student* student_7 = new Student(1000987652,"Oriana","Bonanno",true);
    Student* student_8 = new Student(1000764256,"Yuri","Vella",false);
    Student* student_9 = new Student(1000342515,"Checco","Zalone",false);
    Student* student_10 = new Student(1000924579,"Angelo","Terrone",false);

    segreteria.add_course(corso_1);
    segreteria.add_course(corso_2);
    segreteria.add_course(corso_3);
    segreteria.add_course(corso_4);
    segreteria.add_course(corso_5);

    segreteria.add_student(student_1);
    segreteria.add_student(student_2);
    segreteria.add_student(student_3);
    segreteria.add_student(student_4);
    segreteria.add_student(student_5);
    segreteria.add_student(student_6);
    segreteria.add_student(student_7);
    segreteria.add_student(student_8);
    segreteria.add_student(student_9);
    segreteria.add_student(student_10);

    cout << "=== TEST PRE-ELENCO ===" << endl;
    segreteria.print_all();
    
    
    cout << "\n==== TEST ISCRIZIONE ====" << endl;
    segreteria.course_registration("info1",student_1,corso_1);
    segreteria.course_registration("info1",student_1,corso_2);

    segreteria.course_registration("info2",student_2,corso_1);
    segreteria.course_registration("info2",student_2,corso_2);
    segreteria.course_registration("info2",student_2,corso_3);

    segreteria.course_registration("info3",student_3,corso_1);
    segreteria.course_registration("info3",student_3,corso_4);
    segreteria.course_registration("info3",student_3,corso_2);

    segreteria.course_registration("info4",student_4,corso_3);
    segreteria.course_registration("info4",student_4,corso_4);
    segreteria.course_registration("info4",student_4,corso_2);
    segreteria.course_registration("info4",student_4,corso_5);

    segreteria.course_registration("info5",student_5,corso_3);
    segreteria.course_registration("info5",student_5,corso_5);
    segreteria.course_registration("info5",student_5,corso_2);

    segreteria.course_registration("info6",student_6,corso_1);
    segreteria.course_registration("info6",student_6,corso_4);
    segreteria.course_registration("info6",student_6,corso_2);


    segreteria.course_registration("info7",student_7,corso_4);
    segreteria.course_registration("info7",student_7,corso_3);
    segreteria.course_registration("info7",student_7,corso_2);

    segreteria.course_registration("info8",student_8,corso_1);
    segreteria.course_registration("info8",student_8,corso_2);
    segreteria.course_registration("info8",student_8,corso_4);

    segreteria.course_registration("info9",student_9,corso_1);
    segreteria.course_registration("info9",student_9,corso_2);

    segreteria.course_registration("info10",student_10,corso_4);
    segreteria.course_registration("info10",student_10,corso_2);
    segreteria.course_registration("info10",student_10,corso_3);
    segreteria.course_registration("info10",student_10,corso_1);



    cout << "\n==== TEST CANCELLAZIONE ====" << endl;
    segreteria.cource_cancellation("info7",student_7,corso_3);
    segreteria.cource_cancellation("info8",student_8,corso_4);


    

    cout << "\n==== TEST RICERCA ====" << endl;
    segreteria.search_course(corso_2);
    segreteria.search_course(corso_5);

    cout << "\n=== TEST ISCRIZIONE ATTIVE DELLO STUDENTE ===" << endl;
    segreteria.Viewing_Study_Plan(student_10);
    

    cout << "\n=== TEST STAMPA STUDENTI-LAVORATORI DEL CORSO ===" << endl;
    segreteria.Workers_Report(corso_2);

    
    cout << "\n=== TEST POST-ELENCO ===" << endl;
    segreteria.remove_course(corso_1);
    segreteria.print_all();
    

    return 0;
}