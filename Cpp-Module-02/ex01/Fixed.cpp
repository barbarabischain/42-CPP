#include "Fixed.hpp"

Fixed::Fixed(void): _value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _value){
    std::cout << "Int constructor called" << std::endl;
    this->_value = _value << this->_fractional;
}

Fixed::Fixed(const float _value){
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(_value *( 1 << this->_fractional));
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): _value(other._value){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->_value = other.getRawBits();
    }
    return(*this);
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_value);
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

int Fixed::toInt(void) const{
    return(this->_value >> this->_fractional);
}

float Fixed::toFloat(void) const{
    return((float) this->_value /(1 << this->_fractional));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return(out);
}
