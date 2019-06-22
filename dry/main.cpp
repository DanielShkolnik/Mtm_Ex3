#include <iostream>

class Base
{
    void virtual method() {std::cout << "from Base" << std::endl;}
public:
    virtual ~Base() {method();}
    Base(){method();}
    void baseMethod() { method();}
};
class A: public Base
{
    void method() {std::cout << "from A" << std::endl;}
public:
    ~A () { method();}
    A():Base(){method();}
};

int main (void)
{
    Base* base = new A();
    base -> baseMethod();
    delete base;
    return 0;
}

