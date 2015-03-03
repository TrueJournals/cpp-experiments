#include <chrono>
#include <iostream>

void needs_seconds(std::chrono::seconds time) {
    std::cout << __func__ << " got: " << time.count() << std::endl;
}

void needs_seconds_float(std::chrono::duration<double, std::ratio<1, 1>> time) {
    std::cout << __func__ << " got: " << time.count() << std::endl;
}

void needs_milliseconds(std::chrono::milliseconds time) {
    std::cout << __func__ << " got: " << time.count() << std::endl;
}

using seconds = std::chrono::duration<double, std::ratio<1, 1>>;
using milliseconds = std::chrono::duration<double, std::ratio<1, 1000>>;
using microseconds = std::chrono::duration<double, std::ratio<1, 1000000>>;

void needs_second_float2(seconds time) {
    std::cout << __func__ << " got: " << time.count() << std::endl;
}

void needs_milliseconds_float(milliseconds time) {
    std::cout << __func__ << " got: " << time.count() << std::endl;
}

int main(int, char**) {
    //needs_seconds(std::chrono::milliseconds(5));
    needs_seconds_float(std::chrono::microseconds(5));

    needs_milliseconds(std::chrono::seconds(5));

    needs_second_float2(microseconds(5));

    needs_milliseconds_float(std::chrono::microseconds(5));

    return 0;
}
