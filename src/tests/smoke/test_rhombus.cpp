#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"
#include <limits>


TEST(test_rhombus, AreaHappyPath)
{
    ShapeParam<float> param;

    ASSERT_TRUE(param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, 6.f));
    ASSERT_TRUE(param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, 8.f));
    param.type = ShapeType::PT_RHOMBUS;
    ASSERT_TRUE(param.validate());

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    ASSERT_NEAR(area, 24.f, 0.001f);
}


TEST(test_rhombus, ZeroDiagonal)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, 0.f);
    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, 8.f);
    param.type = ShapeType::PT_RHOMBUS;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);


    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    ASSERT_EQ(area, 0.f);
}


TEST(test_rhombus, NegativeDiagonal)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, -5.f);
    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, 8.f);
    param.type = ShapeType::PT_RHOMBUS;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    ASSERT_EQ(area, 0.f);
}


TEST(test_rhombus, MaxFloat)
{
    ShapeParam<float> param;
    float max = std::numeric_limits<float>::max();

    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, max);
    param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, max);
    param.type = ShapeType::PT_RHOMBUS;

    ASSERT_TRUE(param.validate());

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);
    ASSERT_TRUE(std::isinf(area) || std::isfinite(area));
}


TEST(test_rhombus, SecondDiagonalZero)
{
    ShapeParam<float> param;

    ASSERT_TRUE(param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL, 6.f));
    ASSERT_TRUE(param.set_attrib(ShapeParamIndex::PARAM_DIAGONAL_2, 0.f));
    param.type = ShapeType::PT_RHOMBUS;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    ASSERT_EQ(area, 0.f);
}