#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange{
    private:
        std::map<std::string, float> data; // mudar o segundo item para float
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &valueStr, const std::string &line) const;
        void printErrorMessage(const std::string &message,const std::string &errorType) const;
        void makeExchange(const std::string& date, float &rate) const;
    
    public:
        BitcoinExchange(void);
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange(void);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        void loadDatabase(const std::string &inputFile);
        void loadInputFile(const std::string &inputFile);
        //fazer função para imprimir no formato
};

#endif
