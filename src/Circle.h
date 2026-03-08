#ifndef _CIRCLE_H
#define _CIRCLE_H


#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Circle : public Shape2D<T> {
  public:
    inline ShapeResult<T> compute();

    inline string print();

    inline Circle(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResult<T> Circle<T>::compute() {
  return ShapeResult<T>();
}

template<class T>
inline string Circle<T>::print() {
  return "";
}

template<class T>
inline Circle<T>::Circle(const ShapeParam<T> & param) : Shape2D<T>(param) {
}

#endif
