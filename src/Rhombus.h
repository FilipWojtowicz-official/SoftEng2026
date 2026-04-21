#ifndef _RHOMBUS_H
#define _RHOMBUS_H

using namespace std;
#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
#include "ShapeParam.h"
#include "ShapeParamIndex.h"
#include "ShapeResultIndex.h"

template <class T> class Rhombus : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();

    inline string print();

    inline Rhombus(const ShapeParam<T>& param);
};
template <class T> inline ShapeResult<T> Rhombus<T>::compute()
{
    T d1 = this->m_param.get_attrib(ShapeParamIndex::PARAM_DIAGONAL);
    T d2 = this->m_param.get_attrib(ShapeParamIndex::PARAM_DIAGONAL_2);

    if (d1 <= 0 || d2 <= 0)
    {
        ShapeResult<T> res;
        res.set_attrib(RESULT_AREA, 0.f);
        return res;
    }

    ShapeResult<T> res;
    res.set_attrib(ShapeResultIndex::RESULT_AREA, (d1 * d2) / 2);
    return res;
}

template <class T> inline string Rhombus<T>::print()
{
    T d1 = this->m_param.get_attrib(ShapeParamIndex::PARAM_DIAGONAL);
    T d2 = this->m_param.get_attrib(ShapeParamIndex::PARAM_DIAGONAL_2);

    return "Rhombus(" + to_string(d1) + "," + to_string(d2) + ")";
}


template <class T>
inline Rhombus<T>::Rhombus(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif
