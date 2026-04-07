#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>
#include <climits>
#include <algorithm>
#include <ctime>

class PmergeMe{
    private:
        std::vector<unsigned int> vs;
        std::deque<unsigned int> ds;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe (const PmergeMe &obj);
        PmergeMe &operator=(const PmergeMe &obj);
        void v_pars(int ac, char **av);
        void d_pars(int ac, char **av);
        void algo(int ac, char **av);
        void disp();
    };
