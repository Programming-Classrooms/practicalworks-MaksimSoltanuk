
#include "gtest/gtest.h"
// ("(\\s+)")

TEST(TDequeTest, InsFront)
{
    TDeque<int> deque;
    deque.InsFront(1);
    EXPECT_EQ(deque.GetByIndex(0), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}