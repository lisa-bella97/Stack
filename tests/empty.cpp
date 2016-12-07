#include "catch.hpp"
#include <stack.hpp>

SCENARIO("if stack is empty, empty method must return true")
{
    GIVEN("an empty stack")
    {
        stack<int> st;

        WHEN("check if the stack is empty")
        {
            THEN("empty method must return true")
            {
                REQUIRE(st.empty());
            }
        }
    }
}

SCENARIO("if stack is not empty, empty method must return false")
{
    GIVEN("the stack")
    {
        stack<int> st;
        st.push(1);

        WHEN("heck if the stack is empty")
        {
            THEN("empty method must return false")
            {
                REQUIRE_FALSE(st.empty());
            }
        }
    }
}