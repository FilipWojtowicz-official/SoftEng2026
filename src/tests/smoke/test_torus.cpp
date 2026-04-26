#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"
#include <stdexcept>

using TorusTypes = ::testing::Types<float, double, long double>;

template <typename T> class TorusTypedTest : public ::testing::Test {};

TYPED_TEST_SUITE(TorusTypedTest, TorusTypes);

TYPED_TEST(TorusTypedTest, ComputeCorrectValues)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_RADIUS, static_cast<TypeParam>(5));
    param.set_attrib(PARAM_RADIUS_2, static_cast<TypeParam>(2));

    Torus<TypeParam> torus(param);

    ShapeResult<TypeParam> result = torus.compute();

    TypeParam volume = result.get_attrib(RESULT_VOLUME);
    TypeParam surface = result.get_attrib(RESULT_SURFACE);

    const TypeParam PI = static_cast<TypeParam>(M_PI);

    TypeParam expected_volume = static_cast<TypeParam>(2) * PI * PI
        * static_cast<TypeParam>(5) * static_cast<TypeParam>(2)
        * static_cast<TypeParam>(2);

    TypeParam expected_surface = static_cast<TypeParam>(4) * PI * PI
        * static_cast<TypeParam>(5) * static_cast<TypeParam>(2);

    ASSERT_NEAR(static_cast<double>(volume),
                static_cast<double>(expected_volume), 1e-6);

    ASSERT_NEAR(static_cast<double>(surface),
                static_cast<double>(expected_surface), 1e-6);
}

TYPED_TEST(TorusTypedTest, ZeroTubeRadius)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_RADIUS, static_cast<TypeParam>(5));
    param.set_attrib(PARAM_RADIUS_2, static_cast<TypeParam>(0));

    Torus<TypeParam> torus(param);

    ShapeResult<TypeParam> result = torus.compute();

    ASSERT_EQ(result.get_attrib(RESULT_VOLUME), static_cast<TypeParam>(0));
    ASSERT_EQ(result.get_attrib(RESULT_SURFACE), static_cast<TypeParam>(0));
}

TYPED_TEST(TorusTypedTest, LargeValuesOverflow)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_RADIUS, std::numeric_limits<TypeParam>::max());
    param.set_attrib(PARAM_RADIUS_2, static_cast<TypeParam>(2));

    Torus<TypeParam> torus(param);

    ASSERT_THROW(torus.compute(), std::overflow_error);
}

TYPED_TEST(TorusTypedTest, NegativeRadius)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_RADIUS, static_cast<TypeParam>(-5));
    param.set_attrib(PARAM_RADIUS_2, static_cast<TypeParam>(2));

    Torus<TypeParam> torus(param);

    ASSERT_THROW(torus.compute(), std::invalid_argument);
}

TYPED_TEST(TorusTypedTest, NegativeTubeRadius)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_RADIUS, static_cast<TypeParam>(5));
    param.set_attrib(PARAM_RADIUS_2, static_cast<TypeParam>(-2));

    Torus<TypeParam> torus(param);

    ASSERT_THROW(torus.compute(), std::invalid_argument);
}

TYPED_TEST(TorusTypedTest, InvalidTorusGeometry)
{
    ShapeParam<TypeParam> param;

    param.set_attrib(PARAM_RADIUS, static_cast<TypeParam>(5));
    param.set_attrib(PARAM_RADIUS_2, static_cast<TypeParam>(5));

    Torus<TypeParam> torus(param);

    ASSERT_THROW(torus.compute(), std::invalid_argument);
}

TEST(test_torus, PrintContainsValues)
{
    ShapeParam<double> param;

    param.set_attrib(PARAM_RADIUS, 5.0);
    param.set_attrib(PARAM_RADIUS_2, 2.0);

    Torus<double> torus(param);

    std::string text = torus.print();

    ASSERT_NE(text.find("Torus"), std::string::npos);
    ASSERT_NE(text.find("5"), std::string::npos);
    ASSERT_NE(text.find("2"), std::string::npos);
}
