#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &a, int i)
{
    typename T::iterator it = std::find(a.begin(), a.end(), i);
    if (it != a.end())
        return it;
    throw
        std::out_of_range("no occurrence is found");
}