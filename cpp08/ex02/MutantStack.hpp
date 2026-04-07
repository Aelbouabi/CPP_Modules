#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <list>

#include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(MutantStack<T>& obj) {
            (void) obj;
        }
        MutantStack<T>& operator=(MutantStack<T>& obj) {
            return obj;
        }

        typedef typename Container::iterator iterator;
        iterator    begin() {
            return this->c.begin();
        }
        iterator    end() {
            return this->c.end();
        }
};


