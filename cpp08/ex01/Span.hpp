#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
    private:
        unsigned int N;
        std::vector<int> v1;
    public:
        Span(unsigned int nbr);
        ~Span();
        Span(Span &obj);
        Span& operator=(Span &obj);
        void addNumber(int add);
        int shortestSpan();
        int longestSpan();
        void multyadd(std::vector<int>::iterator begin, std::vector<int>::iterator end, unsigned int i);
};
