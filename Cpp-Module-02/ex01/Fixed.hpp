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
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
