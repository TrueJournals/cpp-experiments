#include <iostream>
#include <tuple>

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

template<typename... Types>
class SimpleMultipleParent : public Types... {
public:
    template<typename... Args>
    SimpleMultipleParent(Args... values) : Types(values...)... { }
    virtual ~SimpleMultipleParent() = default;
protected:
    typedef std::tuple<Types...> Parents;
    typedef SimpleMultipleParent<Types...> ParentsConstructor;
    template<std::size_t i>
    struct GetParent {
        typedef typename std::tuple_element<i, Parents>::type type;
    };
};

class Base1 {
public:
    Base1(const std::string& str) { std::cout << "Base1::Base1(" << str << ")" << std::endl; }
    virtual ~Base1() = default;

    virtual void m3() { std::cout << "Base1::m3" << std::endl; }
};

class Child2 : public SimpleMultipleParent<Base, Base1>
{
public:
    Child2() : SimpleMultipleParent("Test") { }
    virtual ~Child2() = default;

    virtual void m3() { std::cout << "Child2::m3" << std::endl; GetParent<1>::type::m3(); }
};

int main(int, char**) {
    Child1 c1("something");
    c1.m1();
    Base& b = c1;
    b.m1();
    b.m2();

    Child2 c2;
    c2.m3();

    return 0;
}
