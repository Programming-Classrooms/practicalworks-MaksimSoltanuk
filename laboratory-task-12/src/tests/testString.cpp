#include "../myString/myString.hpp" 
#include <gtest/gtest.h>

// Тестирование конструктора по умолчанию
TEST(MyStringTest, DefaultConstructor) {
    MyString str;
    EXPECT_EQ(str.getSize(), 0);
    EXPECT_EQ(str.getStr(), nullptr);
}

// Тестирование конструктора с параметром
TEST(MyStringTest, ConstructorWithParam) {
    const char* testStr = "Hello";
    MyString str(testStr);
    EXPECT_EQ(str.getSize(), std::strlen(testStr));
    EXPECT_STREQ(str.getStr(), testStr);
}

// Тестирование оператора сложения (+)
TEST(MyStringTest, AdditionOperator) {
    const char* testStr1 = "Hello";
    const char* testStr2 = " World";
    MyString str1(testStr1);
    MyString str2(testStr2);

    MyString result = str1 + str2;

    EXPECT_EQ(result.getSize(), std::strlen(testStr1) + std::strlen(testStr2));
    EXPECT_STREQ(result.getStr(), "Hello World");
}

// Тестирование оператора присваивания (=)
TEST(MyStringTest, AssignmentOperator) {
    const char* testStr = "Hello";
    MyString str1(testStr);
    MyString str2;

    str2 = str1;

    EXPECT_EQ(str2.getSize(), std::strlen(testStr));
    EXPECT_STREQ(str2.getStr(), testStr);
}

// Тестирование составного оператора присваивания (+=)
TEST(MyStringTest, CompoundAssignmentOperator) {
    const char* testStr1 = "Hello";
    const char* testStr2 = " World";
    MyString str1(testStr1);
    MyString str2(testStr2);

    str1 += str2;

    EXPECT_EQ(str1.getSize(), std::strlen(testStr1) + std::strlen(testStr2));
    EXPECT_STREQ(str1.getStr(), "Hello World");
}

// Тестирование оператора сравнения (== и !=)
TEST(MyStringTest, ComparisonOperators) {
    const char* testStr1 = "Hello";
    const char* testStr2 = "World";
    MyString str1(testStr1);
    MyString str2(testStr1);
    MyString str3(testStr2);

    EXPECT_TRUE(str1 == str2);
    EXPECT_FALSE(str1 == str3);
    EXPECT_TRUE(str1 != str3);
}

// Тестирование деструктора
TEST(MyStringTest, Destructor) {
    const char* testStr = "Hello";
    {
        MyString str(testStr);
    }
    // Проверка, что память была корректно освобождена после выхода из области видимости
    MyString str;
    EXPECT_EQ(str.getStr(), nullptr);
    EXPECT_EQ(str.getSize(), 0);
}

// Запуск всех тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}