#include <iostream>
using namespace std;

class A {
public:
  void f() { cout << "A::f"; }
  virtual void g() = 0;
  void h() { cout << "A::h"; f(); g(); }
private:
  int a;
  void k() { cout << "A::k"; }
};

class B : public A {
public:
  int f() { cout << "B::f"; return 0; }
  int f(int x) { return x + a; }		// A::a is private
  int k() { cout << "B::k"; }
protected:
  void h() { cout << "B::h"; }
};

class C : public A {
public:
  void g() { cout << "C::g"; }
};

int main() {
  A a; 						// can not create an instace of a abstract class
  B b;						// B is also abstract beacuse it did not override A::g
  C c;
  A* ap = &c;
  ap->g();
  B* bp = &c; 					// B is not a base class for C
  bp->g();
}











