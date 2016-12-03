#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template <typename T>
class stack
{
public:
    stack();
    ~stack();

    auto count() const -> size_t;
    auto push(const T & element) -> void;
    auto pop() -> void;

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

        auto temp = new T[_count];

        for (auto i = 0; i < _count; i++)
            temp[i] = _array[i];

        delete [] _array;
        _array = new T[_array_size];

        for (auto i = 0; i < _count; i++)
            _array[i] = temp[i];

        delete [] temp;
    }

    _array[_count++] = element;
}

template <typename T>
auto stack<T>::pop() -> void
{
    _count--;
}

#endif