#ifndef _SPHERE_H
#define _SPHERE_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
#include <cmath>
using namespace std;
#include "ShapeParam.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

template <class T> class Sphere : public Shape3D<T> {
public:
    inline virtual ShapeResult<T> compute();
    inline string print();
    inline Sphere(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Sphere<T>::compute()
{
    T r = this->m_param.get_attrib(PARAM_RADIUS);

    T volume = (T)((4.0 / 3.0) * M_PI) * r * r * r;
    T surface = (T)(4 * M_PI) * r * r;

    ShapeResult<T> res;
    res.set_attrib(RESULT_SURFACE, surface);
    res.set_attrib(RESULT_VOLUME, volume);
    return res;
}

template <class T> inline string Sphere<T>::print() { return "Sphere"; }

template <class T>
inline Sphere<T>::Sphere(const ShapeParam<T>& param): Shape3D<T>(param)
{}

#endif