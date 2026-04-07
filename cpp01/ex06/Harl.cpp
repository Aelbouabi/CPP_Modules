#include "Harl.hpp"

void Harl::debug( void ) {
    std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}
void Harl::info( void ) {
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}
void Harl::warning( void ) {
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}
void Harl::error( void ) {
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string level) {
    void (Harl::*p[4])()={&Harl::debug, &Harl::info, &Harl::warning ,&Harl::error};
    std::string s[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == s[i]) {
            switch (i)
            {
                case 0:
                    for (int j = i; j < 4; j++) {
                        (this->*p[j])(); }
                    break;
                case 1:
                    for (int j = i; j < 4; j++) {
                        (this->*p[j])(); }
                    break;
                case 2:
                    for (int j = i; j < 4; j++) {
                        (this->*p[j])(); }
                    break;
                case 3:
                    for (int j = i; j < 4; j++) {
                        (this->*p[j])(); }
                    break;
            }
            return ;
        }
    }
    std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
    
}

Harl::Harl() {}

Harl::~Harl() {}