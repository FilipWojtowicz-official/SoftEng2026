#ifndef _TORUS_H
#define _TORUS_H


#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
#include <numbers>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Torus : public Shape3D<T> {
  public:
    inline virtual ShapeResultData<T> compute();

    inline string print();

    inline Torus(const ShapeParam<T> & param);

};

template<class T>
inline ShapeResultData<T> Torus<T>::compute() {

    ShapeResultData<T> result;

    T R = this->m_param.get(PARAM_RADIUS);
    T r = this->m_param.get(PARAM_RADIUS_2);

    const T PI = static_cast<T>(numbers::pi);

    T volume = 2 * PI * PI * R * r * r;
    T surface = 4 * PI * PI * R * r;

    result.set(RESULT_VOLUME, volume);
    result.set(RESULT_SURFACE, surface);

    return result;
}

template<class T>
inline string Torus<T>::print() {
    T R = this->m_param.get(PARAM_RADIUS);
    T r = this->m_param.get(PARAM_RADIUS_2);

    return "Torus(R=" + to_string(R) + ", r=" + to_string(r) + ")";
}

template<class T>
inline Torus<T>::Torus(const ShapeParam<T> & param) : Shape3D<T>(param) {
}

#endif
