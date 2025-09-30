#include "Span.hpp"

Span::Span(void) : _size(0) {}

Span::Span(size_t n) : _size(n) { _array.reserve(_size); }

Span::Span(const Span &other)
{
    _array = other._array;
    _size = other._size;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _array = other._array;
        _size = other._size;
    }
    return (*this);
}

Span::~Span(void){}

void Span::addNumber(int num)
{
    if (_array.size() >= _size)
        throw std::runtime_error("exceeded maximum element range");
    _array.push_back(num);
}

size_t Span::longestSpan()
{
    if (_array.size() < 2)
        throw std::runtime_error("Not enough elements");
    return *std::max_element(_array.begin(), _array.end()) - *std::min_element(_array.begin(), _array.end());
}

size_t Span::shortestSpan()
{
    if (_array.size() < 2)
        throw std::runtime_error("Not enough elements");
    std::vector<int> sorted_array = _array;
    std::sort(sorted_array.begin(), sorted_array.end());
    size_t shortest_span = sorted_array[1] - sorted_array[0];
    for (size_t i = 2; i < sorted_array.size(); ++i)
    {
        size_t distance = sorted_array[i] - sorted_array[i - 1];
        if (distance < shortest_span)
            shortest_span = distance;
    }
    return shortest_span;
}