#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <algorithm>
#include <exception>
#include <climits>

class RPN{
    private:
        std::string str;
    public:
        RPN(std::string &st);
        ~RPN(void);
        RPN (const RPN &obj);
        RPN &operator=(const RPN &obj);
        void  Reverse_Polish();
    };

