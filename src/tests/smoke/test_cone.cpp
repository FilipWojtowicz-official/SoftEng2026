#include <gtest/gtest.h>
#include <memory>
#include <chrono>
#include "../../Cone.h"

template <typename T> class ConeTypeTest : public ::testing::Test {};

using MyTypes = ::testing::Types<float, double>;
TYPED_TEST_SUITE(ConeTypeTest, MyTypes);

TYPED_TEST(ConeTypeTest, FullAssignmentTest)
{
    using T = TypeParam;

    ShapeParam<T> badParam;
    badParam.set_attrib(PARAM_RADIUS, static_cast<T>(-5.0));
    badParam.set_attrib(PARAM_HEIGHT, static_cast<T>(10.0));

    EXPECT_THROW({ Cone<T> c(badParam); }, std::invalid_argument);

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 100; ++i)
    {
        ShapeParam<T> param;
        param.set_attrib(PARAM_RADIUS, static_cast<T>(3.0));
        param.set_attrib(PARAM_HEIGHT, static_cast<T>(4.0));

        std::unique_ptr<Cone<T>> cone = std::make_unique<Cone<T>>(param);
        auto res = cone->compute();

        ASSERT_GT(res.get_attrib(RESULT_VOLUME), 0);
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start)
            .count();

    EXPECT_LT(duration, 1000);
}