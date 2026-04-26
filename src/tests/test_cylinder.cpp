#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include <stdexcept>

#include "Cylinder.h"
#include "ShapeParam.h"
#include "ShapeResultData.h"

TEST(CylinderTest, HappyPathStandardValues)
{
    ShapeParam<double> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 5.0);
    param.set_attrib(ShapeParamIndex::PARAM_HEIGHT, 10.0);
    param.type = ShapeType::PT_CYLINDER;

    Cylinder<double> cylinder(param);

    ShapeResult<double> result = cylinder.compute();

    double expectedVolume = M_PI * 5.0 * 5.0 * 10.0;
    double expectedSurface = 2.0 * M_PI * 5.0 * (5.0 + 10.0);

    EXPECT_NEAR(result.get_attrib(ShapeResultIndex::RESULT_VOLUME),
                expectedVolume, 1e-4);
    EXPECT_NEAR(result.get_attrib(ShapeResultIndex::RESULT_SURFACE),
                expectedSurface, 1e-4);
}

TEST(CylinderTest, BoundaryValuesZero)
{
    ShapeParam<double> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 0.0);
    param.set_attrib(ShapeParamIndex::PARAM_HEIGHT, 0.0);
    param.type = ShapeType::PT_CYLINDER;

    Cylinder<double> cylinder(param);
    ShapeResult<double> result = cylinder.compute();

    EXPECT_DOUBLE_EQ(result.get_attrib(ShapeResultIndex::RESULT_VOLUME), 0.0);
    EXPECT_DOUBLE_EQ(result.get_attrib(ShapeResultIndex::RESULT_SURFACE), 0.0);
}

TEST(CylinderTest, BoundaryValuesMaxFloat)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS,
                     std::numeric_limits<float>::max());
    param.set_attrib(ShapeParamIndex::PARAM_HEIGHT, 1.0f);
    param.type = ShapeType::PT_CYLINDER;

    Cylinder<float> cylinder(param);
    ShapeResult<float> result = cylinder.compute();

    EXPECT_TRUE(std::isinf(result.get_attrib(ShapeResultIndex::RESULT_VOLUME)));
}

TEST(CylinderTest, InvalidDataThrowsException)
{
    ShapeParam<double> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, -5.0);
    param.set_attrib(ShapeParamIndex::PARAM_HEIGHT, 10.0);
    param.type = ShapeType::PT_CYLINDER;

    Cylinder<double> cylinder(param);

    EXPECT_THROW({ cylinder.compute(); }, std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}