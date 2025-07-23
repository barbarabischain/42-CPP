#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed{
    private:
        int _value;
        static const int _fractional = 8;

    public:
        Fixed(void);
        Fixed(const int _value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        ~Fixed(void);
        Fixed &operator=(const Fixed &other);

        int getRawBits( void ) const;
        void setRawBits(int const raw);
        int toInt( void ) const;
        float toFloat( void ) const;

        /* comparison operators */
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        /* arithmetic operators */
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;


        /* increment/decrement */
        Fixed operator++(int); // Pos increment
        Fixed operator--(int); // Pos decrement
        Fixed &operator++(); // Pre increment
        Fixed &operator--(); // Pre decrement

        /* min/max */
        static const Fixed& min(const Fixed &n1, const Fixed &n2);
        static const Fixed& max(const Fixed &n1, const Fixed &n2);
        static Fixed& min(Fixed &n1, Fixed &n2);
        static Fixed& max(Fixed &n1, Fixed &n2);

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
