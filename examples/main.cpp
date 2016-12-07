#include <stack.hpp>
#include <iostream>

int main()
{
    stack<int> st;
    std::cout << st.count() << std::endl;

    st.push(5);
    st.push(6);
    st.push(7);
    std::cout << st.count() << std::endl;

    while (!st.empty())
    {
        std::cout << *st.top() << std::endl;
        st.pop();
    }

    if (st.top())
        std::cout << st.count() << std::endl;

    return 0;
}