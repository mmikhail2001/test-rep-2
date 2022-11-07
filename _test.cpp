#include <iostream>

template <unsigned long N>
struct binary {
 static unsigned const value = binary<N / 10>::value << 1 | N % 10;
};
template <> struct binary<0> {
 static unsigned const value = 0;
};

int main()
{
    unsigned const three = binary<11>::value;
    unsigned const five = binary<101>::value;
    unsigned const one = binary<1>::value;
    std::cout << three << " " << five << " " << one << std::endl;

}