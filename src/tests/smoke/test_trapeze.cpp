#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>

#include "Trapeze.h"
#include "ShapeParam.h"
#include "ShapeResultData.h"

TEST(test_trapeze, ComputeArea)
{
    bool res = true;

    ShapeParam<float> param;

    res = param.set_attrib(PARAM_WIDTH, 4.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(PARAM_DEPTH, 6.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(PARAM_HEIGHT, 2.f);
    ASSERT_NE(res, false);

    res = param.validate();
    ASSERT_NE(res, false);

    Trapeze<float> trapeze(param);

    ShapeResult<float> data = trapeze.compute();

    float area = data.get_attrib(RESULT_AREA);

    ASSERT_FLOAT_EQ(area, 10.f);
}

TEST(test_trapeze, NegativeValues)
{
    bool res = true;
    ShapeParam<float> param;
    param.set_attrib(PARAM_WIDTH, -4.f);
    param.set_attrib(PARAM_DEPTH, 5.f);
    param.set_attrib(PARAM_HEIGHT, 2.f);

    res = param.validate();
    ASSERT_NE(res, false);
}

TEST(test_trapeze, ValuesEqualZero)
{
    bool res = true;
    ShapeParam<float> param;
    param.set_attrib(PARAM_WIDTH, 0.f);
    param.set_attrib(PARAM_DEPTH, 5.f);
    param.set_attrib(PARAM_HEIGHT, 2.f);

    res = param.validate();
    ASSERT_NE(res, false);
}