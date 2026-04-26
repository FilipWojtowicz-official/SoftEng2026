#ifndef _HEXAGON_H
#define _HEXAGON_H

#include <cmath>
#include "Shape2D.h"
#include "ShapeResultData.h"
#include "ShapeResultIndex.h"
#include <string>
using namespace std;
#include "ShapeParam.h"
#include "ShapeParamIndex.h"

template <class T> class Hexagon : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();
    inline string print();
    inline Hexagon(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Hexagon<T>::compute()
{

    ShapeResult<T> result;
    T a = this->m_param.get_attrib(PARAM_RADIUS);
    T area = (3 * sqrt(3) * a * a) / 2;
    T perimeter = 6 * a;
    result.set_attrib(RESULT_AREA, area);
    result.set_attrib(RESULT_PERIMETER, perimeter);

    return result;
}

template <class T> inline string Hexagon<T>::print()
{
    ShapeResult<T> result = compute();
    T area = result.get_attrib(RESULT_AREA);
    T perimeter = result.get_attrib(RESULT_PERIMETER);

    return "Hexagon | area: " + to_string(area)
        + ", perimeter: " + to_string(perimeter);
}

template <class T>
inline Hexagon<T>::Hexagon(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif