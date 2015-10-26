#include <gtest/gtest.h>
#include "tobetest.c"

// WeakNormal test for Triangle
TEST(TrianglTest, WeakNormal) {
    EXPECT_STREQ("Equilateral", Triangle(5, 5, 5));
    EXPECT_STREQ("Isosceles", Triangle(2, 2, 3));
    EXPECT_STREQ("Scalene", Triangle(3, 4, 5));
    EXPECT_STREQ("NotATriangle", Triangle(4, 1, 2));
}

// WeakRobust test for Triangle
TEST(Triangle, WeakRobust) {
    EXPECT_STREQ("Invalid input", Triangle(-1, 5, 5));
    EXPECT_STREQ("Invalid input", Triangle(5, -1, 5));
    EXPECT_STREQ("Invalid input", Triangle(5, 5, -1));
}

// StrongRobust test for Triangle
TEST(Triangle, StrongRobust) {
    EXPECT_STREQ("Invalid input", Triangle(-1, -1, 5));
    EXPECT_STREQ("Invalid input", Triangle(-1, 5, -1));
    EXPECT_STREQ("Invalid input", Triangle(5, -1, -1));
}

// WN for NextDay
TEST(NextDay, WeakNormal) {
    // 润年
    EXPECT_STREQ("1912/2/29", NextDay(1912, 2, 28));
    EXPECT_STREQ("2000/2/29", NextDay(2000, 2, 28));
    EXPECT_STREQ("1900/3/1", NextDay(1900, 2, 28));

    // 小月
    EXPECT_STREQ("2014/5/1", NextDay(2014, 4, 30));

    // 大月
    EXPECT_STREQ("2014/6/1", NextDay(2014, 5, 31));

    // 12月
    EXPECT_STREQ("2015/1/1", NextDay(2014, 12, 31));
}

// WR for NextDay
TEST(NextDay, WeakRobust) {
    // invalid day
    EXPECT_STREQ("Invalid input", NextDay(2015, 6, -1));
    EXPECT_STREQ("Invalid input", NextDay(2015, 6, 32));
    
    // invalid month
    EXPECT_STREQ("Invalid input", NextDay(2015, -1, 15));
    EXPECT_STREQ("Invalid input", NextDay(2015, 13, 15));

    // invalid year
    EXPECT_STREQ("Invalid input", NextDay(-1, 6, 15));
}

// SR for NextDay
TEST(NextDay, StrongRobust) {
    // invalid day month
    EXPECT_STREQ("Invalid input", NextDay(2015, -1, 32));
    EXPECT_STREQ("Invalid input", NextDay(2015, 13, -1));
    
    // invalid day year
    EXPECT_STREQ("Invalid input", NextDay(-1, 6, -1));
    EXPECT_STREQ("Invalid input", NextDay(-1, 6, 32));

    // invalid month year
    EXPECT_STREQ("Invalid input", NextDay(-1, -1, 15));
    EXPECT_STREQ("Invalid input", NextDay(-1, 13, 15));
}

// WR for Commission
TEST(Commission, WeakRobust) {
    // invalid locks
    EXPECT_STREQ("Invalid input", Commission(-1, 40 ,45));
    EXPECT_STREQ("Invalid input", Commission(71, 40, 45));

    // invalid stocks
    EXPECT_STREQ("Invalid input", Commission(35, -1, 45));
    EXPECT_STREQ("Invalid input", Commission(35, 81, 45));

    // invalid barrels
    EXPECT_STREQ("Invalid input", Commission(35, 40, -1));
    EXPECT_STREQ("Invalid input", Commission(35, 40, 91));
}

// SR for Commission
TEST(Commission, StrongRobust) {
    // invalid locks and stocks
    EXPECT_STREQ("Invalid input", Commission(-1, 81, 45));
    EXPECT_STREQ("Invalid input", Commission(71, -1, 45));
    // invalid locks and barrels
    EXPECT_STREQ("Invalid input", Commission(-1, 40, 91));
    EXPECT_STREQ("Invalid input", Commission(71, 40, -1));
    // invalic stocks and barrels
    EXPECT_STREQ("Invalid input", Commission(35, -1, 91));
    EXPECT_STREQ("Invalid input", Commission(35, 81, -1));

}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

