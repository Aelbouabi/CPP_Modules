#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    *this = obj;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void ) obj;
    return *this;
}


static bool is_char(const std::string& s) {
    if (s.length() == 1 && s[0] >= 32 && s[0] <= 126) {
        return (true); 
    }
    return  false;
}

static bool is_limit(const std::string& s) {
    if (s == "nanf" || s == "+inff" || s == "-inff" ||
        s == "nan"  || s == "+inf"  || s == "-inf") {
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout << std::fixed << std::setprecision(1);
    if (is_char(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    if (is_limit(literal)) {
        std::string l = literal;
        if (l[l.size() - 1] == 'f'
            && (l[l.size() - 2] == 'f' || (l[l.size() - 2] == 'n' && l[l.size() - 3] == 'a')))
            l = l.substr(0, l.size() - 1);
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << l << "f\n";
        std::cout << "double: " << l << "\n";
        return;
    }

    std::stringstream iss(literal);
    int iv;
    if ((iss >> iv) && iss.peek() == EOF ) {
        if (iv >= 32 && iv <= 126)
        std::cout << "char: '" << static_cast<char>(iv) << "'\n";
        else if (iv >= 0 && iv <= 255)
        std::cout << "char: Non displayable\n";
        else
        std::cout << "char: impossible\n";
        std::cout << "int: " << iv << "\n";
        std::cout << "float: " << static_cast<float>(iv) << "f\n";
        std::cout << "double: " << static_cast<double>(iv) << "\n";
        return;
    }
    
    char* end = NULL;
    errno = 0;
    float fv = std::strtof(literal.c_str(), &end);
    if (*end == 'f' && (++end)[0] == '\0' && errno != ERANGE) {
        if (fv >= 32 && fv <= 126)
            std::cout << "char: '" << static_cast<char>(fv) << "'\n";
        else if (fv >= 0 && fv <= 255)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        if (fv > 2147483647 || fv < -2147483648)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(fv) << "\n";
        std::cout << "float: " << fv << "f\n";
        std::cout << "double: " << static_cast<double>(fv) << "\n";
        return;
    }

    errno = 0;
    double dv = std::strtod(literal.c_str(), &end);
    if (*end == '\0' && errno != ERANGE) {
        if (dv >= 32 && dv <= 126)
            std::cout << "char: '" << static_cast<char>(dv) << "'\n";
        else if (dv >= 0 && dv <= 255)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible\n";
        if (dv > 2147483647 || dv < -2147483648)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(dv) << "\n";
        std::cout << "float: " << static_cast<float>(dv) << "f\n";
        std::cout << "double: " << dv << "\n";
        return;
    }

    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}

ScalarConverter::~ScalarConverter() {}
