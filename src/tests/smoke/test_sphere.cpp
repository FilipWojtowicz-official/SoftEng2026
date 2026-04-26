#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include <limits>
#include "ShapeFactory.h"

TEST(SphereTest, HappyPath_r1)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 1.f);
    param.type = PT_SPHERE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float surface = data.get_attrib(RESULT_SURFACE);
    float volume = data.get_attrib(RESULT_VOLUME);

    EXPECT_NEAR(surface, 4.f * M_PI * 1.f * 1.f, 0.001f);
    EXPECT_NEAR(volume, (4.f / 3.f) * M_PI * 1.f, 0.001f);
}

TEST(SphereTest, HappyPath_r5)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 5.f);
    param.type = PT_SPHERE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float surface = data.get_attrib(RESULT_SURFACE);
    float volume = data.get_attrib(RESULT_VOLUME);

    EXPECT_NEAR(surface, 4.f * M_PI * 25.f, 0.001f);
    EXPECT_NEAR(volume, (4.f / 3.f) * M_PI * 125.f, 0.001f);
}

TEST(SphereTest, EdgeCase_r0)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 0.f);
    param.type = PT_SPHERE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    EXPECT_NEAR(data.get_attrib(RESULT_SURFACE), 0.f, 0.001f);
    EXPECT_NEAR(data.get_attrib(RESULT_VOLUME), 0.f, 0.001f);
}

TEST(SphereTest, EdgeCase_LargeRadius)
{
    float maxVal = std::numeric_limits<float>::max();
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, maxVal);
    param.type = PT_SPHERE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    EXPECT_TRUE(std::isinf(data.get_attrib(RESULT_SURFACE)));
    EXPECT_TRUE(std::isinf(data.get_attrib(RESULT_VOLUME)));
}

TEST(SphereTest, InvalidData_NegativeRadius)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, -1.f);
    param.type = PT_SPHERE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();

    EXPECT_LT(data.get_attrib(RESULT_VOLUME), 0.f);
}

TEST(SphereTest, GeometricLogic_SurfaceVolumeRelation)
{
    ShapeParam<float> param;
    param.set_attrib(PARAM_RADIUS, 1.f);
    param.type = PT_SPHERE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ShapeResult<float> data = shape->compute();

    float surface = data.get_attrib(RESULT_SURFACE);
    float volume = data.get_attrib(RESULT_VOLUME);

    EXPECT_GT(surface, 0.f);
    EXPECT_GT(volume, 0.f);
    EXPECT_GT(surface, volume);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}