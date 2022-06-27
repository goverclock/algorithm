#include <iostream>
using namespace std;
class A {
   public:
    A() { cout << "A"; }
};
class B {
   public:
    B() { cout << "B"; }
};
class C : public A {
    B b;

   public:
    C() { cout << "C"; }
};
int main() {
    C obj;
    return 0;
}