#include "catch.hpp"
#include <stack.hpp>

SCENARIO("top method must return the last one")
{
    GIVEN("stack")
    {
        stack<int> st;
        st.push(1);
        st.push(2);

        WHEN("get the top of the stack")
        {
            auto elem = st.top();

            THEN("the top must be equal to 2")
            {
                REQUIRE(elem == 2);
            }
        }
    }
}

SCENARIO("if stack is empty, top method must throw an exception")
{
    GIVEN("empty stack")
    {
        stack<int> st;

        WHEN("trying to get the top of the stack")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(st.top(), std::underflow_error &);
            }
        }
    }
}