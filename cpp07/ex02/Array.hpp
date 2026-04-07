#include <iostream>

template <typename T>
class Array
{
    private:
        T *data;
        unsigned int len; 
    public:
        Array() {
            len = 0;
            data = NULL;
        }
        
        Array(unsigned int n) : len(n) {
            data = new T[n]();
        }
        
        Array(const Array& copy) : data(NULL)
        {
            copy = this;
        }
        
        Array& operator=(const Array& obj) {
            delete[] data;
            data = new T[obj.len];
            this->len = obj.len ;
            for (size_t i = 0; i < len; i++)
            this->data[i] = obj.data[i];
            return *this;
        }
        
        T& operator[](unsigned int index) {
            if (index >= this->len)
                throw 
                    std::out_of_range("index is out of range");
            return data[index];
        }

        unsigned int size() const {
            return this.len;
        }

        ~Array() {
            delete[] data;
        }
};