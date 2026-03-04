#include "../include/BitcoinExchange.hpp"

/* Constructors */
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): data(other.data){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    if (this != &other)
        this->data = other.data;
    return(*this);
}

BitcoinExchange::~BitcoinExchange(){}


/* Public */
void BitcoinExchange::loadDatabase(const std::string &filename){
    std::string line;

    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        std::exit(1);
    }
    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        std::string date = line.substr(0, commaPos);
        std::stringstream exchangeRateStr(line.substr(commaPos + 1));

        float exchangeRate;
        exchangeRateStr >> exchangeRate;
        data.insert(std::pair<std::string, float>(date, exchangeRate));
    }
    file.close();
}

static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

static float stringToFloat(const std::string &str)
{
    std::stringstream ss(str);
    float value;
    ss >> value;
    return value;
}

static int stringToInt(const std::string &str)
{
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}



bool BitcoinExchange::isValidDate(const std::string &date){
    // ''' Recebe data no formato ano-mes-formato e verifica se a data e valida '''
    size_t first = date.find('-');
    size_t second = date.find('-', first + 1);

    int year = stringToInt(date.substr(0, first));
    int month = stringToInt(date.substr(first + 1, second - (first + 1)));
    int day = stringToInt(date.substr(second + 1));

    if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day > 29)
                return (false);
        }
        else
        {
            if (day > 28)
                return (false);
        }
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    return (true);
}

void BitcoinExchange::printErrorMessage(const std::string &message, const std::string &errorType) const {
   std::cerr << "Error: " << message << " => " << errorType << std::endl;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, const std::string &line) const {
    std::string trimmed = trim(valueStr);
    if (trimmed.empty()) {
        printErrorMessage("bad input", line);
        return false;
    }
    std::stringstream ss(trimmed);
    float value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        printErrorMessage("bad input", line);
        return false;
    }
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::makeExchange(const std::string& date, float &rate) const{
	std::map<std::string, float>::const_iterator it;

    it = data.upper_bound(date);
    if (it == data.begin()){
        printErrorMessage("no available rate for date", date);
        return ;
    }
    --it;
    float result = rate * it->second;
    std::cout << date << " => " << rate << " = " << std::setprecision(2) << result << std::endl;
}

void BitcoinExchange::loadInputFile(const std::string &inputFile){
    std::string line;
    std::string date;
    std::string valueStr;

    std::ifstream file(inputFile.c_str());

    while (std::getline(file, line))
    {
        if (line == "date | value")
            std::getline(file, line);

        size_t verticalBarPos = line.find("|");
        if (verticalBarPos == std::string::npos){
            printErrorMessage("bad input", line);
            continue;
        }

        date = line.substr(0, verticalBarPos);
        if (!isValidDate(date)){
            printErrorMessage("invalid date", date);
            continue;
        }

        valueStr = line.substr(verticalBarPos + 1);
        if (isValidValue(valueStr, line)){
            float value = stringToFloat(valueStr);

            makeExchange(trim(date), value);
        }         

    }
    
    file.close();
}
