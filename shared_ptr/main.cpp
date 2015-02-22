#include <iostream>
#include <map>
#include <stdexcept>

template<typename T>
class shared_ptr
{
    static std::map<T*, unsigned int>& get_reference_count() {
        static std::map<T*, unsigned int> reference_count;
        return reference_count;
    };

    T* ptr;
public:
    shared_ptr(T* ptr) : ptr(ptr)
    {
        if (get_reference_count().find(ptr) != get_reference_count().end())
        {
            get_reference_count()[ptr] += 1;
        }
        else
        {
            get_reference_count()[ptr] = 1;
        }

        std::cout << "Count for " << ptr << ": " << get_reference_count()[ptr] << std::endl;
    }

    shared_ptr(shared_ptr& other) : shared_ptr(other.ptr)
    {
    }

    shared_ptr operator=(shared_ptr& other)
    {
        shared_ptr new_obj(other.ptr);
        return new_obj;
    }

    T operator*()
    {
        if (ptr == nullptr)
            throw std::runtime_error("Cannot dereference nullptr");

        return *ptr;
    }

    T* operator->()
    {
        if (ptr == nullptr)
            throw std::runtime_error("Cannot dereference nullptr");

        return ptr;
    }

    virtual ~shared_ptr()
    {
        get_reference_count()[ptr] -= 1;
        std::cout << "Count for " << ptr << ": " << get_reference_count()[ptr] << std::endl;

        if (get_reference_count()[ptr] == 0)
        {
            std::cout << "Deleting " << ptr << std::endl;
            delete ptr;
        }
    }
};

struct A {
    int a;
    int b;
};

int doSomething(shared_ptr<int> val)
{
    std::cout << "Got val: " << *val << std::endl;
    return 1;
}

int main(int, char**)
{
    shared_ptr<int> a(new int(5));
    shared_ptr<int> b(new int(6));
    //shared_ptr<int> b(nullptr);
    std::cout << "Constructed" << std::endl;
    doSomething(a);
    doSomething(b);
    std::cout << "After doSomething" << std::endl;

    shared_ptr<A> shared_a(new A);
    std::cout << "Constructed shared_a" << std::endl;
    shared_a->a = 5;
    shared_a->b = 6;
    std::cout << "shared_a->b : " << shared_a->b << std::endl;
    std::cout << "Done with shared_a" << std::endl;

    return 0;
}
