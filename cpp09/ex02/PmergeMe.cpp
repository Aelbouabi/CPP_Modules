#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}
PmergeMe::~PmergeMe()
{

}
PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        for (size_t i = 0; i < obj.vs.size(); i++)
        {
            this->vs[i] = obj.vs[i];
        }
        for (size_t i = 0; i < obj.ds.size(); i++)
        {
            this->ds[i] = obj.ds[i];
        }
    }
    return *this;
}

bool allspace(std::string arg)
{
    for (size_t i = 0; i < arg.size(); i++)
    {
        if (arg[i] != ' ')
            return false;
    }
    return true;
}

void PmergeMe::v_pars(int ac, char **av) {

    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        if (arg.empty() || allspace(arg))
            throw std::invalid_argument("Error");
        std::stringstream ss(arg);
        std::string word;
        while (ss >> word)
        {
            char *end;
            long v = std::strtol(word.c_str(), &end, 10);
            if (v > UINT_MAX || v < 0 || (*end != ' ' && *end != '\0'))
                throw std::invalid_argument("Error");
            vs.push_back(static_cast<unsigned int> (v));
        }
    }
}

void PmergeMe::d_pars(int ac, char **av) {

    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        if (arg.empty() || allspace(arg))
            throw std::invalid_argument("Error");
        std::stringstream ss(arg);
        std::string word;
        while (ss >> word)
        {
            char *end;
            long v = std::strtol(word.c_str(), &end, 10);
            if (v > UINT_MAX || v < 0 || (*end != ' ' && *end != '\0'))
                throw std::invalid_argument("Error");
            ds.push_back(static_cast<unsigned int> (v));
        }
    }
}

std::vector<int> jacob(int p_size)
{
    std::vector<int> seq;

    if (p_size == 1) return (seq.push_back(1), seq);
    if (p_size == 2) return (seq.push_back(1),seq.push_back(2), seq);
    seq.push_back(1);
    seq.push_back(3);

    for(int x = 2; x < p_size; x++)
    {
        int hold  = seq[x - 1] + 2 * seq[x - 2];
        if (hold <= p_size) seq.push_back(hold);
        else
            break;
    }
    if (seq[seq.size() - 1] < p_size)
        seq.push_back(p_size);

    std::vector<int>full_seq;
    
    for (size_t i = 0; i < seq.size(); i++)
    {
        if (full_seq.empty()){
            full_seq.push_back(seq[0]);
            continue;
        }
        int hold = seq[i - 1];
        full_seq.push_back(seq[i]);
        int n = full_seq[full_seq.size() - 1] - 1;
        while(n > hold)
        {
            full_seq.push_back(n);
            n--;
        }
    }
    return(full_seq);
}


void v_algo(std::vector<unsigned int> &seq) {
    if (seq.size() == 1)
        return ;
    long odd;
    if (seq.size() % 2) {
        odd = seq[seq.size() - 1];
        seq.pop_back();
    }
    else
        odd = -1;
    std::vector<std::pair<unsigned int, unsigned int> > pairs;
    for (size_t i = 0; i + 1 < seq.size(); i += 2) {
        unsigned int a = seq[i];
        unsigned int b = seq[i + 1];
        pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
    }
    std::vector<unsigned int> m_chain;
    std::vector<unsigned int> p_chain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        m_chain.push_back(pairs[i].first);
        p_chain.push_back(pairs[i].second);
    }
    v_algo(m_chain);
    std::vector<int> j_seq = jacob(p_chain.size());
    for (size_t j = 0; j < j_seq.size(); j++)
    {
        for (size_t i = 0; i < pairs.size(); i++)
        {
            if (p_chain[j_seq[j] - 1] == pairs[i].second)
            {
                std::vector<unsigned int>::iterator m_it = std::find(m_chain.begin(), m_chain.end(), pairs[i].first);
                std::vector<unsigned int>::iterator it = std::lower_bound(m_chain.begin(), m_it, p_chain[j_seq[j] - 1]);
                m_chain.insert(it, p_chain[j_seq[j] - 1]);
                break;
            }
        }
    }
    if (odd != -1) {
        std::vector<unsigned int>::iterator it = std::lower_bound(m_chain.begin(), m_chain.end(), odd);
        m_chain.insert(it, static_cast<unsigned int>(odd));
    }
    seq = m_chain;
}

void d_algo(std::deque<unsigned int> &seq) {
    if (seq.size() == 1)
        return ;
    long odd;
    if (seq.size() % 2) {
        odd = seq[seq.size() - 1];
        seq.pop_back();
    }
    else
        odd = -1;
    std::deque<std::pair<unsigned int, unsigned int> > pairs;
    for (size_t i = 0; i + 1 < seq.size(); i += 2) {
        unsigned int a = seq[i];
        unsigned int b = seq[i + 1];
        pairs.push_back(std::make_pair(std::max(a, b), std::min(a, b)));
    }
    std::deque<unsigned int> m_chain;
    std::deque<unsigned int> p_chain;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        m_chain.push_back(pairs[i].first);
        p_chain.push_back(pairs[i].second);
    }
    d_algo(m_chain);
    std::vector<int> j_seq = jacob(p_chain.size());
    for (size_t j = 0; j < j_seq.size(); j++)
    {
        for (size_t i = 0; i < pairs.size(); i++)
        {
            if (p_chain[j_seq[j] - 1] == pairs[i].second)
            {
                std::deque<unsigned int>::iterator m_it = std::find(m_chain.begin(), m_chain.end(), pairs[i].first);
                std::deque<unsigned int>::iterator it = std::lower_bound(m_chain.begin(), m_it, p_chain[j_seq[j] - 1]);
                m_chain.insert(it, p_chain[j_seq[j] - 1]);
                break;
            }
        }
    }
    if (odd != -1) {
        std::deque<unsigned int>::iterator it = std::lower_bound(m_chain.begin(), m_chain.end(), odd);
        m_chain.insert(it, static_cast<unsigned int>(odd));
    }
    seq = m_chain;
}

void arg(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        std::stringstream ss(arg);
        std::string word;
        while (ss >> word)
           std::cout << word << " " ;
    }
    std::cout << std::endl;
}

void PmergeMe::algo(int ac, char **av) {

    std::clock_t start = std::clock();
    v_pars(ac, av);
    v_algo(this->vs);
    std::clock_t end = std::clock();
    std::cout << "Before: ";
    arg(ac, av);
    std::cout << "After:  ";
    disp();
    double total_us = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
    std::cout << "Time to process a range of "<< vs.size() << " elements with std::vector : " << total_us << " us" << std::endl;

    start = std::clock();
    d_pars(ac, av);
    d_algo(this->ds);
    end = std::clock();
    total_us = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000.0;
    std::cout << "Time to process a range of "<< ds.size() << " elements with std::deque : " << total_us << " us" << std::endl;

}

void PmergeMe::disp() {

    for (size_t i = 0; i < vs.size(); i++)
    {
        std::cout << vs[i] << " ";
    }
    std::cout << std::endl;
}