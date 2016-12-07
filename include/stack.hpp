#ifndef STACK_HPP
#define STACK_HPP

#include <cstring>
#include <stdexcept>

template <typename T>
class stack
{
public:
    stack();
    ~stack();

    auto count() const -> size_t;
    auto push(const T & element) -> void;
    auto pop() -> T;

private:
    T * _array;
    size_t _array_size;
    size_t _count;
};

template <typename T>
stack<T>::stack() : _array(nullptr), _array_size(0), _count(0) {}

template <typename T>
stack<T>::~stack()
{
    delete [] _array;
}

template <typename T>
auto stack<T>::count() const -> size_t
{
    return _count;
}

template <typename T>
auto stack<T>::push(const T & element) -> void
{
    if (_count == _array_size)
    {
        _array_size = (_array_size == 0) ? 1 : 2 * _count;

        auto temp = new T[_array_size];
        memcpy(temp, _array, sizeof(_array) * _count);
        
        delete [] _array;
        
        _array = temp;
    }

    _array[_count++] = element;
}

template <typename T>
auto stack<T>::pop() -> T
{
    if (_count)
        return _array[--_count];
    else
        throw std::underflow_error("Stack is already empty.");
}

#endif
