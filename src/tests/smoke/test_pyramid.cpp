#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"

TEST(test_pyramid, Basic)
{
    bool res = true;

    ShapeParam<float> param;
    res = param.set_attrib(ShapeParamIndex::PARAM_WIDTH, 4.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(ShapeParamIndex::PARAM_HEIGHT, 6.f);
    ASSERT_NE(res, false);

    res = param.set_attrib(ShapeParamIndex::PARAM_DEPTH, 4.f);
    ASSERT_NE(res, false);

    param.type = ShapeType::PT_PYTAMID;

    res = param.validate();
    ASSERT_NE(res, false);

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));

    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    float volume = data.get_attrib(ShapeResultIndex::RESULT_VOLUME);

    ASSERT_GT(volume, 0.f);
}