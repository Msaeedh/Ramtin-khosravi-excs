#include <iostream>
using namespace std ;

class A {
public:
  void f() { cout << "A::f" << endl ; }
  virtual void g() { cout << "A::g" <<endl ; }
  void h() { cout << "A::h" << endl ; f(); g(); }
};

class B : public A {
public:
  void f() { cout << "B::f" << endl ; } 				
  void g() { cout << "B::g" << endl ; }				
  void h() { cout << "B::h" << endl ; f(); g(); }	
};

int main()
{
	A a;
	B b;
	
	A* ap = &b;								
	ap->f();								// A::f
	ap->g();								// B::g overrided
	ap->h();								// A::h --> A::f , B::g
	
	return 0 ; 
}