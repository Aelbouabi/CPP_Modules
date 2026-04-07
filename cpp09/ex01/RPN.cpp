#include "RPN.hpp"

RPN::RPN(std::string &st) : str(st) {
    if (!str.size())
        throw std::invalid_argument("Error");
}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj)
    str = obj.str;
    return *this;
}

RPN::RPN(const RPN &obj)
{
    *this = obj; 
}

RPN::~RPN()
{
}

void  RPN::Reverse_Polish() {
    std::stack<long> stack;
    std::istringstream ss(str);
    std::string sp;
    char *end = NULL;
    while (ss >> sp)
    {
        if (sp.size() > 1 || (!std::isdigit(sp[0]) && sp[0] != '+' && sp[0] != '-'
            && sp[0] != '*' && sp[0] != '/'))
                throw std::invalid_argument("Error: invalid argument");
        if (std::isdigit(sp[0]))
        {
            long num = std::strtol(sp.c_str(), &end, 10);
            stack.push(num);
        }
        else if (!std::isdigit(sp[0]) && stack.size() > 1)
        {
            long num1 = stack.top();
            stack.pop();
            long num2 = stack.top();
            stack.pop();
            long res;
            if (sp[0] == '+')
                res = num2 + num1;
            else if (sp[0] == '-')
                res = num2 - num1;
            else if (sp[0] == '*')
                res = num2 * num1;
            else if (sp[0] == '/')
            {
                if (!num1)
                    throw std::invalid_argument("Error devide by 0");
                res = num2 / num1;
            }
            if (res > INT_MAX || res < INT_MIN)
                throw std::invalid_argument("Error: overflow");
             stack.push(res);
        }
        else 
            throw std::invalid_argument("Error: need more numbers");
    }
    if (stack.size() != 1)
        throw std::invalid_argument("Error: need more operators");
    std::cout << stack.top() << std::endl;
}