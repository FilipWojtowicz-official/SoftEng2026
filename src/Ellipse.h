#ifndef _ELLIPSE_H
#define _ELLIPSE_H

#include <cmath>
#include <string>
#include "Shape2D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include "ShapeParamIndex.h"
#include "ShapeResultIndex.h"

using namespace std;

template <class T> class Ellipse : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();
    inline string print();
    inline Ellipse(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Ellipse<T>::compute()
{
    ShapeResult<T> result;

    // Pobieramy parametry
    T a = this->m_param.get_attrib(PARAM_RADIUS);
    T b = this->m_param.get_attrib(PARAM_RADIUS_2);

    // Domyślnie ustawiamy pole na 0
    T area = 0;

    // Liczymy pole TYLKO wtedy, gdy oba promienie są dodatnie (logika
    // geometryczna)
    if (a > 0 && b > 0)
    {
        area = (T)3.141592653589 * a * b;
    }

    result.set_attrib(RESULT_AREA, area);

    return result;
}

template <class T> inline string Ellipse<T>::print()
{
    T a = this->m_param.get_attrib(PARAM_RADIUS);
    T b = this->m_param.get_attrib(PARAM_RADIUS_2);

    return "Ellipse(radius_x: " + to_string(a) + ", radius_y: " + to_string(b)
        + ")";
}

template <class T>
inline Ellipse<T>::Ellipse(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif
