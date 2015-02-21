#include <iostream>

template<typename T>
class SimpleParent : public T {
public:
    template<typename... Args>
    SimpleParent(Args... values) : T(values...) { }
    virtual ~SimpleParent() = default;
protected:
    typedef T Parent;
    typedef SimpleParent<T> ConstructorParent;
};

class Base {
public:
    Base(const std::string& s) { std::cout << "Base::Base(" << s << ")" << std::endl; }
    virtual ~Base() = default;

    virtual void m1() { std::cout << "Base::m1" << std::endl; }
    virtual void m2() { std::cout << "Base::m2" << std::endl; }
};

class Child1 : public SimpleParent<Base>
{
public:
    Child1(std::string name) : ConstructorParent(name) { }
    virtual ~Child1() = default;

    virtual void m1() { std::cout << "Child1::m1" << std::endl; Parent::m1(); }
    virtual void m2() { Parent::m2(); }
};

int main(int, char**) {
    Child1 c1("something");
    c1.m1();
    Base& b = c1;
    b.m1();
    b.m2();

    return 0;
}
