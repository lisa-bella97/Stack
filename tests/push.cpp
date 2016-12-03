#include "catch.hpp"
#include <stack.hpp>

SCENARIO("after pushing an element in the stack count of elements in it must increase by one")
{
    GIVEN("stack and its size")
    {
        stack<int> st;
        st.push(1);
        st.push(2);
        auto count = st.count();

        WHEN("push an element")
        {
            st.push(3);

            THEN("count of elements in the stack must increase by one")
            {
                REQUIRE(st.count() == count + 1);
            }
        }
    }
}