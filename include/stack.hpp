#ifndef STACK_HPP
#define STACK_HPP

#include <algorithm>
#include <iostream>

template <typename T>
class stack
{
public:
    stack();
    ~stack();

    auto count() const noexcept -> size_t;
    auto push(const T & element) noexcept -> void;
    auto pop() noexcept -> void;
    auto top() const noexcept -> const T *;
    auto empty() const noexcept -> bool;

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
auto stack<T>::count() const noexcept -> size_t
{
    return _count;
}

template <typename T>
auto stack<T>::push(const T & element) noexcept -> void
{
    if (_count == _array_size)
    {
        _array_size = (_array_size == 0) ? 1 : 2 * _count;
        auto temp = new T[_array_size];

        try
        {
            std::copy(_array, _array + _count, temp);
        }
        catch (std::exception & ex)
        {
            std::cout << ex.what() << std::endl;
        }

        delete [] _array;
        _array = temp;
    }

    _array[_count++] = element;
}

template <typename T>
auto stack<T>::pop() noexcept -> void
{
    if (_count)
        _count--;
}

template <typename T>
auto stack<T>::top() const noexcept -> const T *
{
    if (_count)
        return &_array[_count - 1];
    else
        return nullptr;
}

template <typename T>
auto stack<T>::empty() const noexcept -> bool
{
    return !_count;
}

#endif