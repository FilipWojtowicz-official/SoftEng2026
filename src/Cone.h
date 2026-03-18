#ifndef _CONE_H
#define _CONE_H


#include "Shape3D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Cone : public Shape3D<T> {
  public:
    inline virtual ShapeResult<T> compute();

    inline string print();

    inline Cone(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResult<T> Cone<T>::compute() {
  return ShapeResult<T>();
}

template<class T>
inline string Cone<T>::print() {
  return "";
}

template<class T>
inline Cone<T>::Cone(const ShapeParam<T> & param) : Shape3D<T>(param) {
}

#endif
