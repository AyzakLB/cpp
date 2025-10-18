# pragma once

#include <vector>
#include <algorithm> 
#include <iterator>
#include <stdexcept>  
#include <cstddef>

class Span
{
    std::vector<int> _array;
    size_t _size;
    public:
        Span(void);
        Span(size_t n);
        Span(const Span& other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int num);
        size_t shortestSpan();
        size_t longestSpan();
        template <typename It>
        void addNumbers(It begin, It end)
        {
            size_t distance = std::distance(begin, end);
            if (_array.size() + distance > _size)
                throw std::runtime_error("exceeded maximum element range");
            _array.insert(_array.end(), begin, end);
        }
};


