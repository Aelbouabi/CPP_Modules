#include <iostream>

int main() {
    std::string  line      = "HI THIS IS BRAIN";
    std::string* stringPTR = &line;
    std::string& stringREF = line;

    std::cout << "The memory address of the string variable : " << &line      << std::endl;
    std::cout << "The memory address held by stringPTR      : " << stringPTR  << std::endl;
    std::cout << "The memory address held by stringREF      : " << &stringREF << std::endl;

    std::cout << "• The value of the string variable        : " << line       << std::endl;
    std::cout << "• The value pointed to by stringPTR       : " << *stringPTR << std::endl;
    std::cout << "• The value pointed to by stringREF       : " << stringREF  << std::endl;
}