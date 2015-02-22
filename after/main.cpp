#include <iostream>
#include <thread>
#include <chrono>

#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>

std::string demangle(const char* name) {
        int status = -4; // some arbitrary value to eliminate the compiler warning

        // enable c++11 by passing the flag -std=c++11 to g++
        std::unique_ptr<char, void(*)(void*)> res {
            abi::__cxa_demangle(name, NULL, NULL, &status),
            std::free
        };

        return (status==0) ? res.get() : name ;
}
#else
// does nothing if not g++
std::string demangle(const char* name) {
    return name;
}
#endif

template<typename _Rep, typename _Period, typename F>
void after(const std::chrono::duration<_Rep, _Period>& time, F&& call)
{
    std::thread worker([&time, &call]() {
        std::this_thread::sleep_for(time);

        try {
            call();
        } catch(const std::exception& e) {
            std::cerr << "Exception of type " << demangle(typeid(e).name()) 
                      << " caught in after: " << std::endl;
            std::cerr << "\t" << e.what() << std::endl;
        }
    });
    worker.detach();
}

int main(int, char**) {
    after(std::chrono::seconds(5), []() {
        std::cout << "5 seconds passed" << std::endl;
        throw std::runtime_error("Just a test");
    });

    for (auto i = 0; i < 10; ++i)
    {
        std::cout << "Counter: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
