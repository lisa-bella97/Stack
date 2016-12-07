#include "catch.hpp"
#include <stack.hpp>

SCENARIO("top method must return the last one")
{
    GIVEN("stack")
    {
        stack<int> st;
        st.push(1);
        st.push(2);

        WHEN("top an element")
        {
            auto elem = st.top();

            THEN("the element must be equal to 2")
            {
                REQUIRE(*elem == 2);
            }
        }
    }
}

SCENARIO("if stack is empty, top method must return nullptr")
{
    GIVEN("an empty stack")
    {
        stack<int> st;

        WHEN("trying to top")
        {
            auto elem = st.top();

            THEN("the element must be equal to nullptr")
            {
                REQUIRE(elem == nullptr);
            }
        }
    }
}