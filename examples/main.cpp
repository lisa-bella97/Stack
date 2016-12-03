#include <stack.hpp>

int main()
{
    stack<int> st;
    std::cout << st.count() << std::endl;
    st.push(5);
    st.push(6);
    st.push(7);
    std::cout << st.count() << std::endl;
    st.pop();
    st.pop();
    st.pop();
    std::cout << st.count() << std::endl;

    return 0;
}