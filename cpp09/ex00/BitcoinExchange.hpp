#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

class BitcoinExchange{
    private:
        std::map<std::string, double> data;
    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);
        BitcoinExchange (const BitcoinExchange &obj);
        BitcoinExchange &operator=(const BitcoinExchange &obj);
        void store();
        void in_B(std::string infl);
    };
