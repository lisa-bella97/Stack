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

    try
    {
        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;
        std::cout << st.pop() << std::endl;
    }
    catch (std::underflow_error & error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << st.count() << std::endl;

    return 0;
}
