#include "catch.hpp"
#include <stack.hpp>

SCENARIO("count of empty stack must be equal to 0")
{
    GIVEN("empty stack")
    {
        stack<int> st;

        WHEN("decide count")
        {
            THEN("count must be equal to 0")
            {
                REQUIRE(st.count() == 0);
            }
        }
    }
}

SCENARIO("count of non-empty stack must not be equal to 0")
{
    GIVEN("non-empty stack")
    {
        stack<int> st;
        st.push(1);
        st.push(2);

        WHEN("decide count")
        {
            THEN("count must not be equal to 0")
            {
                REQUIRE(st.count() != 0);
            }
        }
    }
}