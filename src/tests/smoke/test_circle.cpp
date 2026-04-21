#include "ShapeResultIndex.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include <limits>
#include <cmath>
#include "Circle.h"
#include "ShapeParam.h"

// 1. HAPPY PATH: Zwykłe wartości (np. r=5)
TEST(CircleTest, HappyPath_StandardValues)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_RADIUS, 5.0);

    Circle<double> circle(param);
    auto result = circle.compute();

    EXPECT_NEAR(result.get_attrib(RESULT_AREA), 78.5398, 0.01);
    EXPECT_NEAR(result.get_attrib(RESULT_PERIMETER), 31.4159, 0.01);
}

// 2. WARTOŚCI GRANICZNE: Obsługa zera (r=0)
TEST(CircleTest, EdgeCase_ZeroRadius)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_RADIUS, 0.0);

    Circle<double> circle(param);
    auto result = circle.compute();

    EXPECT_DOUBLE_EQ(result.get_attrib(RESULT_AREA), 0.0);
    EXPECT_DOUBLE_EQ(result.get_attrib(RESULT_PERIMETER), 0.0);
}

// 2. WARTOŚCI GRANICZNE: Ekstremalnie duże liczby
TEST(CircleTest, EdgeCase_MaxDoubleValue)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_RADIUS, std::numeric_limits<double>::max());

    Circle<double> circle(param);
    auto result = circle.compute();

    // Po pomnożeniu dwóch maksymalnych wartości przez siebie nastąpi
    // przepełnienie. Wynik pola będzie matematyczną nieskończonością (inf).
    EXPECT_TRUE(std::isinf(result.get_attrib(RESULT_AREA)));
}

// 3. DANE NIEPOPRAWNE / 4. LOGIKA GEOMETRYCZNA: Ujemny promień
TEST(CircleTest, InvalidData_NegativeRadiusThrowsException)
{
    ShapeParam<double> param;
    param.set_attrib(PARAM_RADIUS, -5.0);

    Circle<double> circle(param);

    // Oczekujemy rzucenia wyjątku invalid_argument z powodu ujemnego promienia
    EXPECT_THROW(circle.compute(), std::invalid_argument);
}