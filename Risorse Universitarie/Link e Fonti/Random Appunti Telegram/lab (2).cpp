#include <iostream>
#include<cmath>
#include <sstream>

using namespace std;


class C {	
private:
   float x;
	
public:
   C (float _x)  { x=_x; }

   virtual  double  f () = 0;
		
   float  getX() { return x; }

   virtual ostream &put(ostream & os) const {
      return  os << " [" << x;
   };
};// end class C


ostream & operator << (ostream & left, const C & obj)
   {
     return  obj.put(left); 
   }  


class D : public C {
private:
   char a;
	
public:
   D (float _x) : C(_x) { 
        a=(char)('a' + (int)(_x*1000000000) % 20);			
   }

   double  f () { 
        return sin(getX())*sin(getX());				
   }

   char  getChar () { return a; }
		
   ostream &put(ostream & os) const {
      return  C::put(os) << ", a=" << a << "] ";
   };
}; // end class D



class E : public C {
private:
   int n;
	
public: 
   E (float _x) : C(_x) { 
        n= (int)(_x*1000000000)%10; 		
   }

   double  f () { 
        return cos(getX())*cos(getX());				
   }

   int  getInt () { return n; }

   ostream &put(ostream & os) const {
      return  C::put(os) << ", n=" << n << "] ";
   } 
}; // end class E



class A {
protected: 
   C * obj1;
   C * obj2; 
	
public:
   A (float _x)  {
       obj1 = new D(_x);
       obj2 = new E(_x);
   }		
		
   //virtual 
   double g () const { 
	   return obj1->f() + obj2->f();
   }

   virtual ostream &put(ostream & os) const {
      return  os << typeid(*this).name() << *obj1 << ", " 
                 << *obj2 << " \t g()=" << g();
   }
}; // end class A



ostream & operator << (ostream & left, A & obj)
   {
     return  obj.put(left); 
   }  


class B : public A {	
public: 
   B (float _w) : A(_w) {  }
	
   string st ()  const { 
	   string s = "";
	   for	(int j=0; j<((E*)obj2)->getInt(); j++)
             s += ((D*)obj1)->getChar();
       
       ostringstream os;
       os << g();
       return  os.str() + s;
    }

   ostream &put(ostream & os) const {
      return  A::put(os) << " st()=" << st();
   }
}; // end class B




int main()
{
   const int DIM = 50;
   srand(328832748);
   A * vett [DIM];
 		
   for (int i=0; i<DIM; i++) {
	  if ( rand()%2 == 1 )    vett[i] = new A((float)rand()/INT_MAX);
				     else     vett[i] = new B((float)rand()/INT_MAX);
						
      cout << i << " \t" << *(vett[i])<< endl << endl;
   }	
			
   double sum1 =0.0; int  sum2=0;
   for (int i=0; i<DIM; i++) {
  	  sum1 += vett[i]->g();

      //  B * p = dynamic_cast<B*>(vett[i]);
      //  if (p)   
      if (typeid(*vett[i]) == typeid(B))
         for (int j=0; j<((B*)vett[i])->st().length(); j++) {
					sum2 += ((B*)vett[i])->st()[j];
      	 } 
   }			

   cout << "sum1= " << sum1 << "\nsum2=" << sum2 << endl;
		
   system("PAUSE");    // ns. comodo!
   return EXIT_SUCCESS;
} // End main()
