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

SCENARIO("when popping an element stack must return the last one")
{
    GIVEN("stack")
    {
        stack<int> st;
        st.push(1);
        st.push(2);

        WHEN("pop an element")
        {
            auto elem = st.pop();

            THEN("popped element must be equal to 2")
            {
                REQUIRE(elem == 2);
            }
        }
    }
}

SCENARIO("if stack is empty, pop method must throw an exception")
{
    GIVEN("empty stack")
    {
        stack<int> st;

        WHEN("trying to pop an element")
        {
            THEN("an exception must be thrown")
            {
                REQUIRE_THROWS_AS(st.pop(), std::underflow_error &);
            }
        }
    }
}