#ifndef _ELLIPSOID_H
#define _ELLIPSOID_H


#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Ellipsoid : public Shape3D<T> {
  public:
    inline virtual ShapeResult<T> compute();

    inline string print();

    inline Ellipsoid(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResult<T> Ellipsoid<T>::compute() {
  return ShapeResult<T>();
}

template<class T>
inline string Ellipsoid<T>::print() {
  return "";
}

template<class T>
inline Ellipsoid<T>::Ellipsoid(const ShapeParam<T> & param) : Shape3D<T>(param) {
}

#endif
