#include <iostream>
#include <thread>
#include <boost/lexical_cast.hpp>

#define OUTPUT(x) std::cout << #x << ": " << x << std::endl
#define TRY_OUTPUT(x) do { try { OUTPUT(x); } catch (const std::exception& e) { std::cout << "Caught: " << e.what() << std::endl; } } while(0)

template<typename T>
T lexical_cast(const std::string& s) {
    T value;
    std::istringstream(s) >> value;
    return value;
}

template<typename T>
T lexical_cast_impl(const std::string& s, T (*func)(const std::string&, std::size_t*, int))
{
    std::size_t end;
    auto ret = func(s, &end, 0);
    if (end != s.length())
    {
        throw std::runtime_error("Could not convert value");
    }
    return ret;
}

template<>
unsigned long long lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stoull);
}

template<>
unsigned long lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stoul);
}

template<>
unsigned int lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stoul);
}

template<>
unsigned short lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stoul);
}

template<>
unsigned char lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stoul);
}

template<>
long long int lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stoll);
}

template<>
long int lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stol);
}

template<>
int lexical_cast(const std::string& s) {
    return lexical_cast_impl(s, std::stoi);
}

template<typename T>
T lexical_cast_impl_float(const std::string& s, T (*func)(const std::string&, std::size_t*))
{
    std::size_t end;
    auto ret = func(s, &end);
    if (end != s.length())
    {
        throw std::runtime_error("Could not convert value");
    }
    return ret;
}


template<>
float lexical_cast(const std::string& s) {
    return lexical_cast_impl_float(s, std::stof);
}

template<>
double lexical_cast(const std::string& s) {
    return lexical_cast_impl_float(s, std::stod);
}

template<>
long double lexical_cast(const std::string& s) {
    return lexical_cast_impl_float(s, std::stold);
}

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    std::string line;
    while (std::getline(std::cin, line))
    {
        // TRY_OUTPUT(boost::lexical_cast<uint32_t>(line));
        // TRY_OUTPUT(boost::lexical_cast<uint16_t>(line));
        // TRY_OUTPUT(boost::lexical_cast<uint8_t>(line));
        // TRY_OUTPUT(boost::lexical_cast<float>(line));
        // TRY_OUTPUT(boost::lexical_cast<double>(line));
        TRY_OUTPUT(lexical_cast<unsigned long>(line));
        TRY_OUTPUT(lexical_cast<uint32_t>(line));
        TRY_OUTPUT(lexical_cast<uint16_t>(line));
        TRY_OUTPUT(lexical_cast<uint8_t>(line));
        TRY_OUTPUT(lexical_cast<int>(line));
        TRY_OUTPUT(lexical_cast<float>(line));
    }

    return 0;
}
