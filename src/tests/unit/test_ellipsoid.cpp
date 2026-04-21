#include <gtest/gtest.h>
#include "Ellipsoid.h"
#include "ShapeParam.h"
#include <stdexcept>
#include <limits>

TEST(EllipsoidTest, HappyPath)
{
    ShapeParam<double> param;
    param.set_attrib(static_cast<ShapeParamIndex>(0), 2.0);
    param.set_attrib(static_cast<ShapeParamIndex>(1), 3.0);
    param.set_attrib(static_cast<ShapeParamIndex>(2), 4.0);

    Ellipsoid<double> e(param);
    ShapeResult<double> result = e.compute();

    EXPECT_DOUBLE_EQ(result.get_attrib(static_cast<ShapeResultIndex>(0)),
                     100.53096491487338);
}

TEST(EllipsoidTest, BoundaryValuesZero)
{
    ShapeParam<double> param;
    param.set_attrib(static_cast<ShapeParamIndex>(0), 0.0);
    param.set_attrib(static_cast<ShapeParamIndex>(1), 0.0);
    param.set_attrib(static_cast<ShapeParamIndex>(2), 0.0);

    Ellipsoid<double> e(param);
    ShapeResult<double> result = e.compute();

    EXPECT_DOUBLE_EQ(result.get_attrib(static_cast<ShapeResultIndex>(0)), 0.0);
}

TEST(EllipsoidTest, BoundaryValuesMaxFloat)
{
    ShapeParam<double> param;
    param.set_attrib(static_cast<ShapeParamIndex>(0),
                     std::numeric_limits<double>::max());
    param.set_attrib(static_cast<ShapeParamIndex>(1), 1.0);
    param.set_attrib(static_cast<ShapeParamIndex>(2), 1.0);

    Ellipsoid<double> e(param);
    ShapeResult<double> result = e.compute();

    EXPECT_GT(result.get_attrib(static_cast<ShapeResultIndex>(0)), 0.0);
}

TEST(EllipsoidTest, InvalidDataNegative)
{
    ShapeParam<double> param;
    param.set_attrib(static_cast<ShapeParamIndex>(0), -2.0);
    param.set_attrib(static_cast<ShapeParamIndex>(1), 3.0);
    param.set_attrib(static_cast<ShapeParamIndex>(2), 4.0);

    EXPECT_THROW(Ellipsoid<double>{ param }, std::invalid_argument);
}