#pragma once
#include <iostream>
#include <exception>
template <typename T>
class Array {
    T *_arr;
    unsigned int _size;
    public:
        Array() : _arr(NULL), _size(0){};
        Array(unsigned int n) : _arr(new T[n]()), _size(n){};
        Array(const Array &other){
            _arr = new T[other.size()]();
            for (unsigned int i = 0; i < other.size(); ++i)
                _arr[i] = other[i];
            _size = other.size();
        };
        const Array &operator=(const Array &other)
        {
            if (this != &other)
            {
                delete[] _arr;
                _arr = NULL;
                _size = other.size();
                if (_size > 0)
                {
                    _arr = new T[_size]();
                    for (unsigned int i = 0; i < _size; ++i)
                        _arr[i] = other[i];
                }
            }
            return *this;
        };
        ~Array() {delete[] _arr;};
        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::exception();
            return _arr[index];
        };

        const T &operator[](unsigned int index) const {
            if (index >= _size)
                throw std::exception();
            return _arr[index];
        };

        unsigned int size() const {return _size;};
};