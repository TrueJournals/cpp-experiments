#include <iostream>
#include <limits>

template<typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
class SafeInteger {
public:
    SafeInteger(T value) : value(value) { }
    virtual ~SafeInteger() = default;

    explicit operator T() const { return value; }
    T get() const { return value; }

    //template<typename O, typename std::enable_if<sizeof(T)>=sizeof(O)>::type* = nullptr>
    //SafeInteger(const SafeInteger<O>& other) : SafeInteger((O)other) { }

    template<typename O,
        typename std::enable_if<
            // TODO: Some check with is_signed so min() doesn't freak out?
            (std::numeric_limits<T>::max() >= std::numeric_limits<O>::max()) &&
            (std::numeric_limits<T>::min() <= std::numeric_limits<O>::min()) &&
            (sizeof(T) >= sizeof(O))
        >::type* = nullptr>
    SafeInteger(const SafeInteger<O>& other) : SafeInteger((O)other) { }

    typedef T type;

protected:
    T value;
};

int main(int, char**) {
    SafeInteger<int32_t> i32(5);
    SafeInteger<int8_t>  i8 (7);
    SafeInteger<int16_t> i16(i8);
    //SafeInteger<int16_t> i16_2(i32); // COMPILATION ERROR!
    SafeInteger<int16_t> i16_3(i16);

    SafeInteger<uint32_t> u32(i32);
    //SafeInteger<uint16_t> u16(i32); // COMPILATION ERROR!
    //SafeInteger<int32_t> i32_2(u32); // COMPILATION ERROR!

    std::cout << "int32: " << (decltype(i32)::type)i32 << std::endl;
    std::cout << "int16: " << (decltype(i16)::type)i16 << std::endl;

    return 0;
}
