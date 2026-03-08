#ifndef _CONE_H
#define _CONE_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
#include <cmath> 
#include "ShapeParam.h"
#include "ShapeParamIndex.h"

using namespace std;

template<class T>
class Cone : public Shape3D<T> {
  public:
    inline virtual ShapeResult<T> compute();

    inline string print();
    inline Cone(const ShapeParam<T> & param);
};

template<class T>
inline ShapeResult<T> Cone<T>::compute() {
    ShapeResult<T> res;
    
    T r = this->m_param.get_attrib(PARAM_RADIUS); 
    T h = this->m_param.get_attrib(PARAM_HEIGHT);
    T pi = static_cast<T>(3.141592653589793);

    // Tworząca stożka l = sqrt(r^2 + h^2)
    T l = sqrt(r * r + h * h);

    T volume = (static_cast<T>(1.0) / 3.0) * pi * r * r * h;
    T surfaceArea = pi * r * (r + l);

    res.set_attrib(RESULT_VOLUME, volume);
    res.set_attrib(RESULT_SURFACE, surfaceArea);

    return res;
}

template<class T>
inline string Cone<T>::print() {
    return "Cone (Stożek) - R: " + to_string(this->m_param.get_attrib(PARAM_RADIUS)) + 
           ", H: " + to_string(this->m_param.get_attrib(PARAM_HEIGHT));
}

template<class T>
inline Cone<T>::Cone(const ShapeParam<T> & param) : Shape3D<T>(param) {}

#endif