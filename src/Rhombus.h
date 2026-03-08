#ifndef _RHOMBUS_H
#define _RHOMBUS_H


#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Rhombus : public Shape2D<T> {
  public:
    inline ShapeResult<T> compute();

    inline string print();

    inline Rhombus(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResult<T> Rhombus<T>::compute() {
  return ShapeResult<T>();
}

template<class T>
inline string Rhombus<T>::print() {
  return "";
}

template<class T>
inline Rhombus<T>::Rhombus(const ShapeParam<T> & param) : Shape2D<T>(param) {
}

#endif
