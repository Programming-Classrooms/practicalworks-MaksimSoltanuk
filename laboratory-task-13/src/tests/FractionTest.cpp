#include <stdexcept>
#include <gtest/gtest.h>
#include "src/class/list/list.hpp"
#include "src/class/fraction/fraction.hpp"
#include "src/class/matrix/matrix.hpp"

TEST(FractionTest, DefaultConstructor)
{
    Fraction f;
    EXPECT_EQ(f.getNumerator(), 0);
    EXPECT_EQ(f.getDenominator(), 1);
}

TEST(FractionTest, ParameterConstructor)
{
    Fraction f(2, 3);
    EXPECT_EQ(f.getNumerator(), 2);
    EXPECT_EQ(f.getDenominator(), 3);
}

TEST(FractionTest, CopyConstructor)
{
    Fraction f1(2, 3);
    Fraction f2(f1);
    EXPECT_EQ(f2.getNumerator(), 2);
    EXPECT_EQ(f2.getDenominator(), 3);
}

TEST(FractionTest, MoveConstructor)
{
    Fraction f1(2, 3);
    Fraction f2(std::move(f1));
    EXPECT_EQ(f2.getNumerator(), 2);
    EXPECT_EQ(f2.getDenominator(), 3);
}

TEST(FractionTest, Addition)
{
    Fraction f1(2, 3);
    Fraction f2(1, 2);
    Fraction result = f1 + f2;
    EXPECT_EQ(result.getNumerator(), 7);
    EXPECT_EQ(result.getDenominator(), 6);
}

TEST(FractionTest, UnaryMinus)
{
    Fraction f1(2, 3);
    Fraction result = -f1;
    EXPECT_EQ(result.getNumerator(), -2);
    EXPECT_EQ(result.getDenominator(), 3);
}

TEST(FractionTest, InverseFraction)
{
    Fraction f1(2, 3);
    Fraction result = !f1;
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 2);
}

TEST(MatrixTest, DefaultConstructor)
{
    Matrix m;
    EXPECT_EQ(m.getRow(), 1);
    EXPECT_EQ(m.getCol(), 1);
    EXPECT_EQ(m[0][0], 0);
}

TEST(MatrixTest, ParameterConstructor)
{
    Matrix m(2, 3);
    EXPECT_EQ(m.getRow(), 2);
    EXPECT_EQ(m.getCol(), 3);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            EXPECT_EQ(m[i][j], 0);
        }
    }
}

TEST(MatrixTest, CopyConstructor)
{
    Matrix m1(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    Matrix m2(m1);
    EXPECT_EQ(m2.getRow(), 2);
    EXPECT_EQ(m2.getCol(), 3);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            EXPECT_EQ(m2[i][j], m1[i][j]);
        }
    }
}

TEST(MatrixTest, MoveConstructor)
{
    Matrix m1(2, 3);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[0][2] = 3;
    m1[1][0] = 4;
    m1[1][1] = 5;
    m1[1][2] = 6;
    Matrix m2(std::move(m1));
    EXPECT_EQ(m2.getRow(), 2);
    EXPECT_EQ(m2.getCol(), 3);
    EXPECT_EQ(m2[0][0], 1);
    EXPECT_EQ(m2[0][1], 2);
    EXPECT_EQ(m2[0][2], 3);
    EXPECT_EQ(m2[1][0], 4);
    EXPECT_EQ(m2[1][1], 5);
    EXPECT_EQ(m2[1][2], 6);
}

TEST(MatrixTest, Addition)
{
    Matrix m1(2, 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    Matrix m2(2, 2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;
    Matrix result = m1 + m2;
    EXPECT_EQ(result.getRow(), 2);
    EXPECT_EQ(result.getCol(), 2);
    EXPECT_EQ(result[0][0], 6);
    EXPECT_EQ(result[0][1], 8);
    EXPECT_EQ(result[1][0], 10);
    EXPECT_EQ(result[1][1], 12);
}

TEST(MatrixTest, Multiplication)
{
    Matrix m1(2, 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    Matrix m2(2, 2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;
    Matrix result = m1 * m2;
    EXPECT_EQ(result.getRow(), 2);
    EXPECT_EQ(result.getCol(), 2);
    EXPECT_EQ(result[0][0], 19);
    EXPECT_EQ(result[0][1], 22);
    EXPECT_EQ(result[1][0], 43);
    EXPECT_EQ(result[1][1], 50);
}

TEST(MatrixTest, Division)
{
    Matrix m(2, 2);
    m[0][0] = 2;
    m[0][1] = 4;
    m[1][0] = 6;
    m[1][1] = 8;
    Matrix result = m / 2;
    EXPECT_EQ(result.getRow(), 2);
    EXPECT_EQ(result.getCol(), 2);
    EXPECT_EQ(result[0][0], 1);
    EXPECT_EQ(result[0][1], 2);
    EXPECT_EQ(result[1][0], 3);
    EXPECT_EQ(result[1][1], 4);
}

TEST(MatrixTest, Equality)
{
    Matrix m1(2, 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    Matrix m2(m1);
    EXPECT_TRUE(m1 == m2);
}

TEST(MatrixTest, Inequality)
{
    Matrix m1(2, 2);
    m1[0][0] = 1;
    m1[0][1] = 2;
    m1[1][0] = 3;
    m1[1][1] = 4;
    Matrix m2(2, 2);
    m2[0][0] = 5;
    m2[0][1] = 6;
    m2[1][0] = 7;
    m2[1][1] = 8;
    EXPECT_TRUE(m1 != m2);
}

TEST(ListTest, DefaultConstructor)
{
    List<int> list;
    EXPECT_EQ(list.getCountElements(), 0);
}

TEST(ListTest, PushBack)
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.getCountElements(), 3);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 3);
}

TEST(ListTest, PushFront)
{
    List<int> list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    EXPECT_EQ(list.getCountElements(), 3);
    EXPECT_EQ(list[0], 3);
    EXPECT_EQ(list[1], 2);
    EXPECT_EQ(list[2], 1);
}

TEST(ListTest, PopBack)
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popBack();
    EXPECT_EQ(list.getCountElements(), 2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 2);
}

TEST(ListTest, PopFront)
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.popFront();
    EXPECT_EQ(list.getCountElements(), 2);
    EXPECT_EQ(list[0], 2);
    EXPECT_EQ(list[1], 3);
}

TEST(ListTest, FindElement)
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    EXPECT_EQ(list.FindElement(2), 1);
}

TEST(ListTest, DeleteByValue)
{
    List<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.deleteByValue(2);
    EXPECT_EQ(list.getCountElements(), 2);
    EXPECT_EQ(list[0], 1);
    EXPECT_EQ(list[1], 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
