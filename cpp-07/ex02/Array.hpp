

template<typename T>
class Array {
    T *array;
    public:
        Array();
        Array(unsigned int n);
        Array(const &Array arr);
        const Array &operator=(const &Array arr);
        size_t size();
}