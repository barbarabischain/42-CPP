#include "Fixed.hpp"

Fixed::Fixed(void): _value(0){
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _value){
    // std::cout << "Int constructor called" << std::endl;
    this->_value = _value << this->_fractional;
}

Fixed::Fixed(const float _value){
    // std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(_value *( 1 << this->_fractional));
}

Fixed::~Fixed(void){
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): _value(other._value){
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        this->_value = other.getRawBits();
    }
    return(*this);
}

int Fixed::getRawBits(void) const{
    // std::cout << "getRawBits member function called" << std::endl;
    return(this->_value);
}

void Fixed::setRawBits(int const raw){
    // std::cout << "setRawBits member function called" << std::endl;
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

/* comparison operators */
bool Fixed::operator>(const Fixed &other) const{
    return(this->_value > other._value);
}
bool Fixed::operator<(const Fixed &other) const{
    return(this->_value < other._value);
}
bool Fixed::operator>=(const Fixed &other) const{
    return(this->_value >= other._value);
}
bool Fixed::operator<=(const Fixed &other) const{
    return(this->_value <= other._value);
}
bool Fixed::operator==(const Fixed &other) const{
    return(this->_value == other._value);
}
bool Fixed::operator!=(const Fixed &other) const{
    return(this->_value != other._value);
}

/* arithmetic operators */
Fixed Fixed::operator+(const Fixed &other) const{
    Fixed result;
    result.setRawBits(_value + other._value);
    return (result);
}
Fixed Fixed::operator-(const Fixed &other) const{
    Fixed result;
    result.setRawBits(_value - other._value);
    return (result);
}
Fixed Fixed::operator*(const Fixed &other) const{
    Fixed result;
    result.setRawBits((_value * other._value) >> this->_fractional);
    return (result);
}
Fixed Fixed::operator/(const Fixed &other) const{
    if (other._value == 0)
    {
        std::cout << "Error: Division by Zero!" << std::endl;
        exit(1);
    }
    Fixed result;

    result.setRawBits((_value / other._value) << this->_fractional);
    return (result);
}

/* increment/decrement */
Fixed Fixed::operator++(int){
    Fixed tmp = *this;
    this->_value += 1;
    return(tmp);
}

Fixed Fixed::operator--(int){
    Fixed tmp = *this;
    this->_value -= 1;
    return(tmp);
}

Fixed &Fixed::operator++(){
    this->_value += 1;
    return(*this);
}

Fixed &Fixed::operator--(){
    this->_value -= 1;
    return(*this);
}

/* min/max */
const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2){
    if (n1.getRawBits() < n2.getRawBits())
        return (n1);
    return (n2);
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2){
    if (n1.getRawBits() > n2.getRawBits())
        return (n1);
    return (n2);
}

Fixed& Fixed::min(Fixed &n1, Fixed &n2){
    if (n1.getRawBits() < n2.getRawBits())
        return (n1);
    return (n2);
}
Fixed& Fixed::max(Fixed &n1, Fixed &n2){
    if (n1.getRawBits() > n2.getRawBits())
        return (n1);
    return (n2);
}
