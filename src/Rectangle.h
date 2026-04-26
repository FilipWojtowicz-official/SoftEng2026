#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;
#include "ShapeParam.h"

template <class T> class Rectangle : public Shape2D<T> {
public:
    inline virtual ShapeResult<T> compute();
    inline string print();
    inline Rectangle(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Rectangle<T>::compute()
{
    ShapeResult<T> res;

    T a = this->m_param.get_attrib(PARAM_WIDTH);
    T b = this->m_param.get_attrib(PARAM_HEIGHT);

    if (a < static_cast<T>(0) || b < static_cast<T>(0))
    {
        throw invalid_argument("Rectangle dimensions cannot be negative");
    }

    T area = a * b;
    T perimeter = static_cast<T>(2) * (a + b);

    if (!isfinite(area) || !isfinite(perimeter))
    {
        throw overflow_error("Numeric overflow during rectangle computation");
    }

    res.set_attrib(RESULT_AREA, area);
    res.set_attrib(RESULT_PERIMETER, perimeter);

    return res;
}

template <class T> inline string Rectangle<T>::print()
{
    T a = this->m_param.get_attrib(PARAM_WIDTH);
    T b = this->m_param.get_attrib(PARAM_HEIGHT);

    return "Rectangle(a=" + to_string(a) + ", b=" + to_string(b) + ")";
}

template <class T>
inline Rectangle<T>::Rectangle(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif