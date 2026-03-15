#ifndef _CYLINDER_H
#define _CYLINDER_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

template<class T>
class Cylinder : public Shape3D<T> {
  public:
    inline virtual ShapeResult<T> compute();

    inline string print();

    inline Cylinder(const ShapeParam<T>& param);
};
template<class T>
inline ShapeResult<T> Cylinder<T>::compute() {
    ShapeResult<T> resultData;

    T r = this->m_param.get_attrib(ShapeParamIndex::PARAM_RADIUS);
    T h = this->m_param.get_attrib(ShapeParamIndex::PARAM_HEIGHT);

    T pi = static_cast<T>(std::acos(-1.0));

    T volume = pi * r * r * h;
    T surfaceArea = static_cast<T>(2.0) * pi * r * (r + h);

    resultData.set_attrib(RESULT_VOLUME, volume);
    resultData.set_attrib(RESULT_SURFACE, surfaceArea);

    return resultData;
}

template<class T>
inline string Cylinder<T>::print() {
    std::ostringstream oss;

    T r = this->m_param.get_attrib(ShapeParamIndex::PARAM_RADIUS);
    T h = this->m_param.get_attrib(ShapeParamIndex::PARAM_HEIGHT);

    oss << "--- WALEC (Cylinder) ---\n";
    oss << "Parametry wejsciowe:\n";
    oss << "  Promien podstawy (r) = " << r << "\n";
    oss << "  Wysokosc (h)         = " << h << "\n";

    return oss.str();
}

template <class T>
inline Cylinder<T>::Cylinder(const ShapeParam<T>& param): Shape3D<T>(param)
{}

#endif
