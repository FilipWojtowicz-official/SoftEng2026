#ifndef _PYRAMID_H
#define _PYRAMID_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

template<class T>
class Pyramid : public Shape3D<T> {
public:
    inline ShapeResultData<T> compute();
    inline string print();
    inline Pyramid(const ShapeParam<T> & param);
};

template<class T>
inline ShapeResultData<T> Pyramid<T>::compute() {
    const T width = this->m_param.get(PARAM_WIDTH);
    const T height = this->m_param.get(PARAM_HEIGHT);
    const T depth = this->m_param.get(PARAM_DEPTH);

    const double w = static_cast<double>(width);
    const double h = static_cast<double>(height);
    const double d = static_cast<double>(depth);

    const double slantWidth = sqrt(h * h + (d * d) / 4.0);
    const double slantDepth = sqrt(h * h + (w * w) / 4.0);

    const double volume = (w * d * h) / 3.0;
    const double surface = (w * d) + (w * slantWidth) + (d * slantDepth);

    ShapeResultData<T> result;
    result.set(RESULT_VOLUME, static_cast<T>(volume));
    result.set(RESULT_SURFACE, static_cast<T>(surface));

    return result;
}

template<class T>
inline string Pyramid<T>::print() {
    return "";
}

template<class T>
inline Pyramid<T>::Pyramid(const ShapeParam<T> & param) : Shape3D<T>(param) {
}

#endif
