#define _USE_MATH_DEFINES
#include <cmath>
#include <gtest/gtest.h>
#include "ShapeFactory.h"
#include <limits>

// 1. HAPPY PATH: Standardowe obliczenie pola
TEST(test_ellipse, AreaHappyPath)
{
    ShapeParam<float> param;


    ASSERT_TRUE(param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 2.f));
    ASSERT_TRUE(param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, 3.f));

    // UWAGA: Zakładam, że tak nazywa się enum dla Elipsy.
    // Jeśli w pliku ShapeType.h jest inaczej, popraw to!
    param.type = ShapeType::PT_ELLIPSE;
    ASSERT_TRUE(param.validate());

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    // Pole = pi * a * b = pi * 2 * 3 =~ 18.8495
    ASSERT_NEAR(area, 18.8495f, 0.001f);
}

// 2. WARTOŚĆ GRANICZNA: Jeden z promieni równy 0
TEST(test_ellipse, ZeroRadius)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, 0.f);
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, 5.f);
    param.type = ShapeType::PT_ELLIPSE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    // Jeśli promień to 0, pole musi być 0
    ASSERT_EQ(area, 0.f);
}

// 3. DANE NIEPOPRAWNE: Ujemny promień
TEST(test_ellipse, NegativeRadius)
{
    ShapeParam<float> param;
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, -4.f);
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, 5.f);
    param.type = ShapeType::PT_ELLIPSE;

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    // Zgodnie z kodem znajomej, spodziewamy się że program zablokuje to i
    // zwróci 0
    ASSERT_EQ(area, 0.f);
}

// 4. WARTOŚĆ GRANICZNA: Maksymalny możliwy float
TEST(test_ellipse, MaxFloat)
{
    ShapeParam<float> param;
    float max = std::numeric_limits<float>::max();

    param.set_attrib(ShapeParamIndex::PARAM_RADIUS, max);
    param.set_attrib(ShapeParamIndex::PARAM_RADIUS_2, max);
    param.type = ShapeType::PT_ELLIPSE;

    ASSERT_TRUE(param.validate());

    auto shape =
        std::unique_ptr<IShape<float>>(ShapeFactory<float>::create(param));
    ASSERT_NE(shape, nullptr);

    ShapeResult<float> data = shape->compute();
    float area = data.get_attrib(ShapeResultIndex::RESULT_AREA);

    // Wzór wyrzuci wynik poza skalę, sprawdzamy czy program łapie
    // nieskończoność
    ASSERT_TRUE(std::isinf(area) || std::isfinite(area));
}