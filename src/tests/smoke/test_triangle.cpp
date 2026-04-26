#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"
#include <stdexcept>

using TriangleTypes = ::testing::Types<float, double, long double>;

template <typename T> class TriangleTypedTest : public ::testing::Test {};

TYPED_TEST_SUITE(TriangleTypedTest, TriangleTypes);

TYPED_TEST(TriangleTypedTest, ComputeCorrectValues)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(PARAM_SIDE_A, static_cast<TypeParam>(3));
    param.set_attrib(PARAM_SIDE_B, static_cast<TypeParam>(4));
    param.set_attrib(PARAM_SIDE_C, static_cast<TypeParam>(5));

    Triangle<TypeParam> tri(param);

    ShapeResult<TypeParam> result = tri.compute();

    TypeParam perimeter = result.get_attrib(ShapeResultIndex::RESULT_PERIMETER);
    TypeParam area = result.get_attrib(ShapeResultIndex::RESULT_AREA);

    ASSERT_NEAR(static_cast<double>(perimeter), 12.0, 1e-6);
    ASSERT_NEAR(static_cast<double>(area), 6.0, 1e-6);
}

TYPED_TEST(TriangleTypedTest, ZeroSideThrows)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(PARAM_SIDE_A, static_cast<TypeParam>(0));
    param.set_attrib(PARAM_SIDE_B, static_cast<TypeParam>(4));
    param.set_attrib(PARAM_SIDE_C, static_cast<TypeParam>(5));

    Triangle<TypeParam> tri(param);

    ASSERT_THROW(tri.compute(), std::invalid_argument);
}

TYPED_TEST(TriangleTypedTest, NegativeSideThrows)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(PARAM_SIDE_A, static_cast<TypeParam>(-3));
    param.set_attrib(PARAM_SIDE_B, static_cast<TypeParam>(4));
    param.set_attrib(PARAM_SIDE_C, static_cast<TypeParam>(5));

    Triangle<TypeParam> tri(param);

    ASSERT_THROW(tri.compute(), std::invalid_argument);
}

TYPED_TEST(TriangleTypedTest, InvalidTriangleThrows)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(PARAM_SIDE_A, static_cast<TypeParam>(1));
    param.set_attrib(PARAM_SIDE_B, static_cast<TypeParam>(2));
    param.set_attrib(PARAM_SIDE_C, static_cast<TypeParam>(5));

    Triangle<TypeParam> tri(param);

    ASSERT_THROW(tri.compute(), std::invalid_argument);
}

TYPED_TEST(TriangleTypedTest, LargeValuesOverflow)
{
    TypeParam max_val = std::numeric_limits<TypeParam>::max() / 3;
    ShapeParam<TypeParam> param;
    param.set_attrib(PARAM_SIDE_A, max_val);
    param.set_attrib(PARAM_SIDE_B, max_val);
    param.set_attrib(PARAM_SIDE_C, max_val);

    Triangle<TypeParam> tri(param);

    ShapeResult<TypeParam> result = tri.compute();

    ASSERT_NE(result.get_attrib(ShapeResultIndex::RESULT_AREA), 0);
    ASSERT_EQ(result.get_attrib(ShapeResultIndex::RESULT_PERIMETER),
              max_val * 3);
}

TYPED_TEST(TriangleTypedTest, PrintContainsValues)
{
    ShapeParam<TypeParam> param;
    param.set_attrib(PARAM_SIDE_A, static_cast<TypeParam>(3));
    param.set_attrib(PARAM_SIDE_B, static_cast<TypeParam>(4));
    param.set_attrib(PARAM_SIDE_C, static_cast<TypeParam>(5));

    Triangle<TypeParam> tri(param);

    std::string text = tri.print();

    ASSERT_NE(text.find("Triangle"), std::string::npos);
    ASSERT_NE(text.find("3"), std::string::npos);
    ASSERT_NE(text.find("4"), std::string::npos);
    ASSERT_NE(text.find("5"), std::string::npos);
}