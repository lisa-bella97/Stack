#include "catch.hpp"
#include <stack.hpp>

SCENARIO("after popping an element from the stack count of elements in it must decrease by one")
{
    GIVEN("stack and its size")
    {
        stack<int> st;
        st.push(1);
        st.push(2);
        auto count = st.count();

        WHEN("pop an element")
        {
            st.pop();

            THEN("count of elements in the stack must decrease by one")
            {
                REQUIRE(st.count() == count - 1);
            }
        }
    }
}

SCENARIO("if stack is empty, pop method must not change its size")
{
    GIVEN("empty stack")
    {
        stack<int> st;

        WHEN("trying to pop an element")
        {
            st.pop();

            THEN("the size must be equal to 0")
            {
                REQUIRE(st.count() == 0);
            }
        }
    }
}