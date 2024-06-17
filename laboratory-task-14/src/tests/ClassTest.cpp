#include "../class/student.hpp"
#include "../class/person.hpp"
#include "../class/professor.hpp"
#include "../class/studentEntered.hpp"
#include "../class/studentFirstSession.hpp"
#include "../class/studentSecondSession.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(StudentEnteredTest, ParameterizedConstructor)
{
    std::string name = "Alex";
    uint16_t course = 2;
    uint8_t group = 3;
    uint16_t recordNumber = 1234;
    StudentEntered s(name, course, group, recordNumber);
    EXPECT_EQ(s.getName(), "Alex");
    EXPECT_EQ(s.getCourse(), 2);
    EXPECT_EQ(s.getGroup(), 3);
    EXPECT_EQ(s.getRecordNumber(), 1234);
    EXPECT_EQ(s.getId(), 1);
}

TEST(StudentEnteredTest, SetName)
{
    std::string name = "Alex";
    StudentEntered s("Initial", 1, 1, 1111);
    s.setName(name);
    EXPECT_EQ(s.getName(), "Alex");
}

TEST(StudentEnteredTest, SetCourse)
{
    uint16_t course = 2;
    StudentEntered s("Initial", 1, 1, 1111);
    s.setCourse(course);
    EXPECT_EQ(s.getCourse(), 2);
}

TEST(StudentEnteredTest, SetGroup)
{
    uint8_t group = 3;
    StudentEntered s("Initial", 1, 1, 1111);
    s.setGroup(group);
    EXPECT_EQ(s.getGroup(), 3);
}

TEST(StudentFirstSessionTest, ConstructorTest)
{
    StudentFirstSession student("John Doe", 1, 1, 1, 90, 85, 88, 92);
    EXPECT_EQ(student.getName(), "John Doe");
    EXPECT_EQ(student.getCourse(), 1);
    EXPECT_EQ(student.getGroup(), 1);
    EXPECT_EQ(student.getRecordNumber(), 1);
}

TEST(StudentFirstSessionTest, CopyConstructorTest)
{
    StudentFirstSession student1("John Doe", 1, 1, 1, 90, 85, 88, 92);
    StudentFirstSession student2 = student1;
    EXPECT_EQ(student2.getName(), "John Doe");
    EXPECT_EQ(student2.getCourse(), 1);
    EXPECT_EQ(student2.getGroup(), 1);
    EXPECT_EQ(student2.getRecordNumber(), 1);
}

TEST(StudentFirstSessionTest, MidleTest)
{
    StudentFirstSession student("John Doe", 1, 1, 1, 90, 85, 88, 92);
    double expected_average = (90 + 85 + 88 + 92) / 4.0;
    EXPECT_DOUBLE_EQ(student.midle(), expected_average);
}

TEST(StudentSecondSessionTest, ConstructorTest)
{
    StudentFirstSession student1("John Doe", 1, 1, 1, 90, 85, 88, 92);
    StudentSecondSession student2(student1, 80, 75, 78, 82, 85);
    EXPECT_EQ(student2.getName(), "John Doe");
    EXPECT_EQ(student2.getCourse(), 1);
    EXPECT_EQ(student2.getGroup(), 1);
    EXPECT_EQ(student2.getRecordNumber(), 1);
}

TEST(StudentSecondSessionTest, CopyConstructorTest)
{
    StudentFirstSession student1("John Doe", 1, 1, 1, 90, 85, 88, 92);
    StudentSecondSession student2(student1, 80, 75, 78, 82, 85);
    StudentSecondSession student3 = student2;
    EXPECT_EQ(student3.getName(), "John Doe");
    EXPECT_EQ(student3.getCourse(), 1);
    EXPECT_EQ(student3.getGroup(), 1);
}

TEST(StudentSecondSessionTest, MidleTest)
{
    StudentFirstSession student1("John Doe", 1, 1, 1, 90, 85, 88, 92);
    StudentSecondSession student2(student1, 80, 75, 78, 82, 85);
    double expected_average = (90 + 85 + 88 + 92 + 80 + 75 + 78 + 82 + 85) / 9.0;
    EXPECT_DOUBLE_EQ(student2.midle(), expected_average);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}