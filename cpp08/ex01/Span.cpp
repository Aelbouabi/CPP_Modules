#include "Span.hpp"

Span::Span(unsigned int nbr) : N(nbr)
{
}

void Span::addNumber(int add)
{
    if (v1.size() >= N)
        throw
        std::out_of_range("already N elements stored");
    this->v1.push_back(add);
}

int Span::shortestSpan()
{
    if (N == 0 || v1.size() <= 1)
        throw
            std::out_of_range("already N elements stored");
    std::sort(v1.begin(), v1.end());
    int sh = v1[1] - v1[0];
    for (size_t i = 2; i < v1.size(); i++)
    {
        int tmp = v1[i] - v1[i - 1];
        if (tmp < sh)
            sh = tmp;
    }
    return sh;
}

int Span::longestSpan()
{
    if (N == 0 || v1.size() <= 1)
        throw
            std::out_of_range("already N elements stored");
    int longest = *std::max_element(v1.begin(), v1.end()) - *std::min_element(v1.begin(), v1.end());
    return (longest);
}

Span::Span(Span &obj){
    *this = obj;
}

Span& Span::operator=(Span &obj) {
    if (this != &obj)
    {
        this->N = obj.N;
        this->v1 = obj.v1;
    }
    return *this;
}

void Span::multyadd(std::vector<int>::iterator begin, std::vector<int>::iterator end, unsigned int i)
{
    if (v1.size() + i > N)
        throw std::out_of_range("N elements not fit");
    v1.insert(v1.end(), begin, end);
}

Span::~Span()
{
}
