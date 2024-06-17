#include "../class/List.hpp"
#include "../class/TDeque.hpp"
#include "gtest/gtest.h"

TEST(TDequeTest, InsFront)
{
    TDeque<int> deque;
    deque.InsFront(1);
    EXPECT_EQ(deque.GetByIndex(0), 1);
}

TEST(TDequeTest, InsRear)
{
    TDeque<int> deque;
    deque.InsRear(2);
    EXPECT_EQ(deque.GetByIndex(0), 2);
}

TEST(TDequeTest, DelFront)
{
    TDeque<int> deque;
    deque.InsFront(1);
    int info;
    deque.DelFront(info);
    EXPECT_EQ(info, 1);
}

TEST(TDequeTest, DelRear)
{
    TDeque<int> deque;
    deque.InsRear(2);
    int info;
    deque.DelRear(info);
    EXPECT_EQ(info, 2);
}

TEST(TDequeTest, GetByIndex)
{
    TDeque<int> deque;
    deque.InsFront(1);
    EXPECT_EQ(deque.GetByIndex(0), 1);
}

TEST(TDequeTest, SetByIndex)
{
    TDeque<int> deque;
    deque.InsFront(1);
    deque.SetByIndex(2, 0);
    EXPECT_EQ(deque.GetByIndex(0), 2);
}

TEST(TDequeTest, AssignmentOperator)
{
    TDeque<int> deque1;
    deque1.InsFront(1);
    deque1.InsRear(2);
    TDeque<int> deque2;
    deque2 = deque1;
    EXPECT_EQ(deque2.GetByIndex(0), 1);
    EXPECT_EQ(deque2.GetByIndex(1), 2);
}

TEST(ListTest, PushFront)
{
    List<int> list;
    list.pushFront(1);
    EXPECT_EQ(list[0], 1);
}

TEST(ListTest, PushBack)
{
    List<int> list;
    list.pushBack(2);
    EXPECT_EQ(list[0], 2);
}

TEST(ListTest, DeleteByValue)
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.deleteByValue(1);
    EXPECT_EQ(list[0], 2);
}

TEST(ListTest, OperatorSquareBrackets)
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
}

TEST(ListTest, OperatorEqual)
{
    List<int> list1;
    list1.pushBack(1);
    list1.pushBack(2);
    List<int> list2;
    list2 = list1;
    EXPECT_EQ(list2[0], 1);
    EXPECT_EQ(list2[1], 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
