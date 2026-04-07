#include "Span.hpp"

int main()
{
    try {
        Span sp(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        Span s = sp;
        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;
        std::vector<int> ne;
        ne.push_back(9);
        ne.push_back(0);
        ne.push_back(77);
        ne.push_back(98);
        ne.push_back(54);
        s.multyadd(ne.begin(), ne.end(), ne.size());
        std::cout << s.longestSpan() << std::endl;
        std::cout << s.shortestSpan() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}