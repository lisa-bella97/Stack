#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

#include "allocator.hpp"
#include <stdexcept>

template <typename T>
class stack : private allocator<T>
{
public:
    stack(size_t size = 0);

    auto count() const noexcept -> size_t;
    auto push(const T & element) noexcept -> void;
    auto pop() noexcept -> void;
    auto top() const /* strong */ -> T;
    auto empty() const noexcept -> bool;
};

template <typename T>
stack<T>::stack(size_t size) : allocator<T>(size) {}

template <typename T>
auto stack<T>::count() const noexcept -> size_t
{
    return allocator<T>::_count;
}

template <typename T>
auto stack<T>::push(const T & element) noexcept -> void
{
    try
    {
        allocator<T>::allocate();
        allocator<T>::_ptr[allocator<T>::_count] = element;
        allocator<T>::_count++;
    }
    catch (...) {}
}

template <typename T>
auto stack<T>::pop() noexcept -> void
{
    if (allocator<T>::_count)
        allocator<T>::_count--;
}

template <typename T>
auto stack<T>::top() const /* strong */ -> T
{
    if (allocator<T>::_count)
        return allocator<T>::_ptr[allocator<T>::_count - 1];
    else
        throw std::underflow_error("Stack is already empty.");
}

template <typename T>
auto stack<T>::empty() const noexcept -> bool
{
    return !allocator<T>::_count;
}

#endif