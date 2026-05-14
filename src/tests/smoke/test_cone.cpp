include <gtest/gtest.h>
#include <memory>
#include "Cone.h"
#include "ShapeParam.h"
#include "ShapeParamIndex.h"

/**
 * Test poprawnosci obliczen (Happy Path).
 * Dla R=3 i H=4:
 * Objetosc: ~37.699
 * Pole: ~75.398
 */
TEST(ConeTest, CorrectCalculations)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_RADIUS, 3.0);
    param.set_attrib(PARAM_HEIGHT, 4.0);

    // Uzycie unique_ptr zapobiega wyciekom pamieci
    std::unique_ptr<Cone<double>> cone = std::make_unique<Cone<double>>(param);
    auto result = cone->compute();

    EXPECT_NEAR(result.get_attrib(RESULT_VOLUME), 37.699111843, 0.001);
    EXPECT_NEAR(result.get_attrib(RESULT_SURFACE), 75.398223686, 0.001);
}

/**
 * Test walidacji - czy program wyrzuci blad przy ujemnym promieniu.
 */
TEST(ConeTest, NegativeRadiusValidation)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_RADIUS, -1.0);
    param.set_attrib(PARAM_HEIGHT, 5.0);

    EXPECT_THROW({ Cone<double> cone(param); }, std::invalid_argument);
}

/**
 * Test dla wartosci granicznej (promien = 0).
 */
TEST(ConeTest, ZeroRadius)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_RADIUS, 0.0);
    param.set_attrib(PARAM_HEIGHT, 5.0);

    std::unique_ptr<Cone<double>> cone = std::make_unique<Cone<double>>(param);
    auto result = cone->compute();

    EXPECT_DOUBLE_EQ(result.get_attrib(RESULT_VOLUME), 0.0);
    EXPECT_DOUBLE_EQ(result.get_attrib(RESULT_SURFACE), 0.0);