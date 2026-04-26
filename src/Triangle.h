#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
#include <cmath>
#include "ShapeParam.h"
#include "ShapeParamIndex.h"
#include "ShapeResultIndex.h"
#include <stdexcept>

using namespace std;

template <class T> class Triangle : public Shape2D<T> {
public:
    inline virtual ShapeResult<T> compute();

    inline string print();

    inline Triangle(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Triangle<T>::compute()
{
    ShapeResult<T> result;

    T a = this->m_param.get_attrib(PARAM_SIDE_A);
    T b = this->m_param.get_attrib(PARAM_SIDE_B);
    T c = this->m_param.get_attrib(PARAM_SIDE_C);

    if (a <= 0 || b <= 0 || c <= 0)
    {
        throw invalid_argument("Triangle sides must be positive");
    }

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        throw invalid_argument("Triangle inequality violated");
    }

    T perimiter = a + b + c;
    T s = perimiter / 2;
    T area = sqrt(s * (s - a) * (s - b) * (s - c));

    result.set_attrib(ShapeResultIndex::RESULT_AREA, area);
    result.set_attrib(ShapeResultIndex::RESULT_PERIMETER, perimiter);

    return result;
}

template <class T> inline string Triangle<T>::print()
{
    T a = this->m_param.get_attrib(PARAM_SIDE_A);
    T b = this->m_param.get_attrib(PARAM_SIDE_B);
    T c = this->m_param.get_attrib(PARAM_SIDE_C);

    return "Triangle(a=" + to_string(a) + ", b=" + to_string(b)
        + ", c=" + to_string(c) + ")";
}

template <class T>
inline Triangle<T>::Triangle(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif