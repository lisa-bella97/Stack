#include <stack.hpp>
#include <iostream>

class Widget
{
public:
    Widget() : _a(0) {}
    Widget(int a) : _a(a) {}
    static size_t count;
    static const size_t max_count;
    auto operator = (const Widget & other) -> Widget &
    {
        if (count == max_count)
        {
            throw std::logic_error("count of Widget is max");
        }
        else
        {
            ++count;
            _a = other._a;
        }
    }
    auto get_a() const -> int
    {
        return _a;
    }
private:
    int _a;
};

size_t Widget::count = 0;
const size_t Widget::max_count = 10;

int main()
{
    Widget w1(1), w2(5), w3(8), w4(-3), w5(2);
    stack<Widget> st;
    std::cout << st.count() << std::endl;

    st.push(w1);
    st.push(w2);
    st.push(w3);
    st.push(w4);
    st.push(w5);
    std::cout << st.count() << std::endl;

    while (!st.empty())
    {
        std::cout << st.top().get_a() << std::endl;
        st.pop();
    }
    
    try
    {
        std::cout << st.top().get_a() << std::endl;
    }
    catch (std::underflow_error & error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
