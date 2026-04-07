#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void) {
    this->store();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) {
   *this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj) {
    this->data = obj.data;
    return *this;
}

void BitcoinExchange::store() {
    std::string date;
    std::string valeu;
    
    char    *end;
    double  v;
    std::ifstream inputFile("data.csv");
    std::getline(inputFile, valeu, '\n');
    if (!inputFile.is_open() || valeu.empty()) {
        throw std::invalid_argument("Failed: file Error.") ;
    }
    while (std::getline(inputFile, date, ','))
    {
        std::getline(inputFile, valeu, '\n');
        v = strtod(valeu.c_str(),&end);
        data[date] = v;
    }
}

bool check_year(int y) {
    return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
}

bool check_month(double m) {
    if (m == 4 || m == 6 ||m == 9 || m == 11)
        return false;
    return true;
}

bool date_v(std::string date) {
    
    std::string year, month, day;
    char *end;
    for (size_t i = 0; i < date.size() - 1; i++)
    {
        if (!std::isdigit(date[i]) && date[i] != '-') {
            return false;
        }
    }
    std::stringstream iss(date);
    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day);
    errno = 0;
    double y = strtod(year.c_str(),&end);
    if (*end != '\0' || y < 2009 || y > 2025){
        return false;
    }
    double m = strtod(month.c_str(),&end);
    if (*end != '\0' || m < 1 || m > 12)
        return false;
    double d = strtod(day.c_str(),&end);
    if (*end != ' ')
        return (false);
    else
        end++;
    if (*end != '\0' || (m == 2 && (d < 1 || (check_year(y) && d > 29)
        || (!check_year(y) && d > 28))))
        return false;
    if (*end != '\0'  || d < 1 || (check_month(m) && d > 31)
        || (!check_month(m) && d > 30) )
        return false;
    if (errno == ERANGE)
        return false;
    return true;
}

bool b_number(double v, char    *end, std::string line, std::string val) {
    
    if (val[0] != ' ' || !std::isdigit(val[1]) || *end != '\0') {
        std::cout << "Error: bad input => "<< line << std::endl;
        return false;
    }
    else if (errno == ERANGE || v > 2147483647) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    else if (v < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::in_B(std::string infl) {
    std::string line;
    std::string date;
    std::string valeu;
    
    char    *end;
    double  v;
    std::ifstream inputFile(infl.c_str());
    if (!inputFile.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return ;
    }
    std::getline(inputFile, valeu, '\n');
    if (valeu != "date | value")
    {
        std::cout << "please the file must begin exactly like this : 'date | value' " << std::endl;
        return ;
    }
    errno = 0;
    while (std::getline(inputFile, line, '\n'))
    {
        std::stringstream ss(line);
        std::getline(ss,date, '|');
        std::getline(ss, valeu, '\n');
        if (!date_v(date) || valeu.empty()) {
            std::cout << "Error: bad input => "<< line << std::endl;
            continue;
        }
        v = strtod(valeu.c_str(),&end);
        if (!b_number(v, end, line, valeu))
            continue;
        std::map<std::string, double>::iterator it = data.find(date);
        if (it == data.end())
        {
            it = data.lower_bound(date);
            if (it != data.begin())
                it--;
        }
        double res = v * it->second;
        std::cout << date << " => " << valeu << " = " << res << std::endl;
    }
}
