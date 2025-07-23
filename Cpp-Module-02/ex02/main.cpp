#include <iostream>
#include "Fixed.hpp"


int main( void ) {
    std::cout << "* * * PDF TESTE * * *" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;


    std::cout << std::endl;
    std::cout << "* * * COMPARISON OPERATORS * * *" << std::endl;
    Fixed c(1.1f);
    Fixed d(9.8f);
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;

    std::cout << std::endl;
    std::cout << "* * * ARITHMETIC OPERATORS * * *" << std::endl;
    Fixed e(10.0f);
    Fixed f(2.5f);
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;
    std::cout << "e + f: " << (e + f) << std::endl;
    std::cout << "e - f: " << (e - f) << std::endl;
    std::cout << "e * f: " << (e * f) << std::endl;
    std::cout << "e / f: " << (e / f) << std::endl;

    std::cout << std::endl;
    std::cout << "* * * POS INCREMENT/DECREMENT * * *" << std::endl;
    Fixed g(0);
    std::cout << "g++: " << g++ << std::endl;
    std::cout << "g:   " << g << std::endl;
    std::cout << "g--: " << g-- << std::endl;
    std::cout << "g:   " << g << std::endl;
    std::cout << "++g: " << ++g << std::endl;
    std::cout << "--g: " << --g << std::endl;

    std::cout << std::endl;
    std::cout << "* * * MIN / MAX * * *" << std::endl;
    Fixed const h(1);
    Fixed const i(2);
    Fixed j(3);
    Fixed k(4);
    std::cout << "const min: " << Fixed::min(h, i) << std::endl;
    std::cout << "const max: " << Fixed::max(h, i) << std::endl;
    std::cout << "min: " << Fixed::min(j, k) << std::endl;
    std::cout << "max: " << Fixed::max(j, k) << std::endl;

    return 0;
}
