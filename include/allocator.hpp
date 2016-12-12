#ifndef STACK_ALLOCATOR_HPP
#define STACK_ALLOCATOR_HPP

#include <algorithm>

template <typename T>
class allocator
{
protected:
    allocator(size_t size = 0);
    allocator(const allocator &) = delete;
    ~allocator();

    auto operator = (const allocator &) -> allocator & = delete;
    auto swap(allocator & other) -> void;
    auto allocate() -> void;

    T * _ptr;
    size_t _size;
    size_t _count;
};

template <typename T>
allocator<T>::allocator(size_t size)
{
    _size = size;
    _count = 0;
    _ptr = static_cast<T*>(::operator new(_size * sizeof(T)));
}

template <typename T>
allocator<T>::~allocator()
{
    delete [] _ptr;
}

template <typename T>
auto allocator<T>::swap(allocator & other) -> void
{
    auto temp_ptr(std::move(_ptr));
    auto temp_size(std::move(_size));
    
    _ptr = std::move(other._ptr);
    _size = std::move(other._size);
    
    other._ptr = std::move(temp_ptr);
    other._size = std::move(temp_size);
}

template <typename T>
auto allocator<T>::allocate() -> void
{
    if (_count == _size)
    {
        auto size = (_size == 0) ? 1 : 2 * _count;
        allocator<T> a(size);
        std::copy(_ptr, _ptr + _count, a._ptr);
        swap(a);
    }
}

#endif
