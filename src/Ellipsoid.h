#ifndef _ELLIPSOID_H
#define _ELLIPSOID_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
#include <cmath>
#include <iostream>
#include "ShapeParam.h"
#include <stdexcept>

using namespace std;

template <class T> class Ellipsoid : public Shape3D<T> {
private:
    ShapeParam<T> localParam;

public:
    inline virtual ShapeResult<T> compute();
    inline string print();
    inline Ellipsoid(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Ellipsoid<T>::compute()
{
    ShapeResult<T> results;
    const T PI = static_cast<T>(3.141592653589793);

    T a = localParam.get_attrib(static_cast<ShapeParamIndex>(0));
    T b = localParam.get_attrib(static_cast<ShapeParamIndex>(1));
    T c = localParam.get_attrib(static_cast<ShapeParamIndex>(2));

    T volume = (static_cast<T>(4) / 3) * PI * a * b * c;

    T p = static_cast<T>(1.6075);
    T term1 = pow(a * b, p);
    T term2 = pow(a * c, p);
    T term3 = pow(b * c, p);
    T surfaceArea = static_cast<T>(4) * PI
        * pow((term1 + term2 + term3) / static_cast<T>(3),
              static_cast<T>(1.0) / p);

    results.set_attrib(static_cast<ShapeResultIndex>(0), volume);
    results.set_attrib(static_cast<ShapeResultIndex>(1), surfaceArea);

    return results;
}

template <class T> inline string Ellipsoid<T>::print()
{
    return "Bryla: Elipsoida. Obliczono objetosc i pole powierzchni "
           "calkowitej.";
}

template <class T>
inline Ellipsoid<T>::Ellipsoid(const ShapeParam<T>& param)
    : Shape3D<T>(param), localParam(param)
{
    T a = param.get_attrib(static_cast<ShapeParamIndex>(0));
    T b = param.get_attrib(static_cast<ShapeParamIndex>(1));
    T c = param.get_attrib(static_cast<ShapeParamIndex>(2));

    if (a < 0 || b < 0 || c < 0)
    {
        throw std::invalid_argument("Wymiary elipsoidy nie moga byc ujemne!");
    }
}

#endif