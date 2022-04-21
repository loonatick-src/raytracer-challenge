#include "util.hpp"
#include "vector.hpp"
#include "point.hpp"

#include <gtest/gtest.h>


// TODO: enclose in a test suite(?)
TEST(TupleTest, BasicAssertions) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 1.0f);
    EXPECT_EQ(a.x(), 4.3f);
    EXPECT_EQ(a.y(), -4.2f);
    EXPECT_EQ(a.z(), 3.1f);
    EXPECT_EQ(a.w(), 1.0f);
    // ASSERT_TRUE(rtc::is_point(a));
    // ASSERT_FALSE(rtc::is_vector(a));
}

TEST(TupleTest, IsPoint) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 1.0f);
    ASSERT_TRUE(rtc::is_point(a));
    ASSERT_FALSE(rtc::is_vector(a));
}

TEST(TupleTest, IsVector) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 0.0f);
    ASSERT_TRUE(rtc::is_vector(a));
    ASSERT_FALSE(rtc::is_point(a));
}

TEST(TupleTest, VectorEqTest) {
    const auto a = rtc::tuple<float>(4.3f, -4.2f, 3.1f, 0.0f);
    EXPECT_EQ(a.x(), 4.3f);
    EXPECT_EQ(a.y(), -4.2f);
    EXPECT_EQ(a.z(), 3.1f);
    EXPECT_EQ(a.w(), 0.0f);
    // ASSERT_FALSE(rtc::is_point(a));
    // ASSERT_TRUE(rtc::is_vector(a));
}

TEST(TupleTest, PointEqTest) {
    const auto p = rtc::point<float>(4, -4, 3);
    ASSERT_EQ(p, rtc::tuple<float>(4, -4, 3, 1));
    auto v = rtc::vector<float>(4, -4, 3);
    ASSERT_EQ(v, rtc::tuple<float>(4, -4, 3, 0));
}
