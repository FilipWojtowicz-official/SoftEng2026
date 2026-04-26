#include <gtest/gtest.h>
#include <limits>
#include <stdexcept>
#include "Rectangle.h"
#include <cmath>

using RectangleTypes = ::testing::Types<float, double, long double>;

template <typename T> class RectangleTypedTest : public ::testing::Test {};

TYPED_TEST_SUITE(RectangleTypedTest, RectangleTypes);

TYPED_TEST(RectangleTypedTest, ComputeCorrectValues)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_WIDTH, static_cast<TypeParam>(4));
    param.set_attrib(PARAM_HEIGHT, static_cast<TypeParam>(3));

    Rectangle<TypeParam> rect(param);

    ShapeResult<TypeParam> result = rect.compute();

    ASSERT_EQ(result.get_attrib(RESULT_AREA), static_cast<TypeParam>(12));

    ASSERT_EQ(result.get_attrib(RESULT_PERIMETER), static_cast<TypeParam>(14));
}

TYPED_TEST(RectangleTypedTest, ZeroDimensions)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_WIDTH, static_cast<TypeParam>(0));
    param.set_attrib(PARAM_HEIGHT, static_cast<TypeParam>(5));

    Rectangle<TypeParam> rect(param);

    ShapeResult<TypeParam> result = rect.compute();

    ASSERT_EQ(result.get_attrib(RESULT_AREA), static_cast<TypeParam>(0));
    ASSERT_EQ(result.get_attrib(RESULT_PERIMETER), static_cast<TypeParam>(10));
}

TYPED_TEST(RectangleTypedTest, NegativeWidth)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_WIDTH, static_cast<TypeParam>(-4));
    param.set_attrib(PARAM_HEIGHT, static_cast<TypeParam>(3));

    Rectangle<TypeParam> rect(param);

    ASSERT_THROW(rect.compute(), std::invalid_argument);
}

TYPED_TEST(RectangleTypedTest, NegativeHeight)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_WIDTH, static_cast<TypeParam>(4));
    param.set_attrib(PARAM_HEIGHT, static_cast<TypeParam>(-3));

    Rectangle<TypeParam> rect(param);

    ASSERT_THROW(rect.compute(), std::invalid_argument);
}

TYPED_TEST(RectangleTypedTest, LargeValuesOverflow)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_WIDTH, std::numeric_limits<TypeParam>::max());
    param.set_attrib(PARAM_HEIGHT, static_cast<TypeParam>(2));

    Rectangle<TypeParam> rect(param);

    ASSERT_THROW(rect.compute(), std::overflow_error);
}

TEST(test_rectangle, PrintContainsValues)
{
    ShapeParam<double> param;

    param.set_attrib(PARAM_WIDTH, 4.0);
    param.set_attrib(PARAM_HEIGHT, 3.0);

    Rectangle<double> rect(param);

    std::string text = rect.print();

    ASSERT_NE(text.find("Rectangle"), std::string::npos);
    ASSERT_NE(text.find("4"), std::string::npos);
    ASSERT_NE(text.find("3"), std::string::npos);
}
