#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, std::string, char, float> getStuff() {
    return std::make_tuple( 7, "Testing", 'a', 8.4 );
}

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    int a;
    std::string b;
    float d;

    std::tie(a, b, std::ignore, d) = getStuff();

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << d << std::endl;

    return 0;
}
