#include <iostream>


template <typename T, typename F>
void iter (T *ar, size_t const len, F fun)
{
    if (ar)
        for (size_t i = 0; i < len; i++)
            fun(ar[i]);
}

