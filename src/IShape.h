#ifndef _ISHAPE_H
#define _ISHAPE_H


#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class IShape {
  public:
    virtual ShapeResult<T> compute() = 0;

    virtual string print() = 0;


  protected:
    ShapeParam<T> m_param;


  public:
    inline virtual ~IShape();

    inline IShape(const ShapeParam<T> & param);

};
template<class T>
inline IShape<T>::~IShape() {
}

template<class T>
inline IShape<T>::IShape(const ShapeParam<T> & param) : m_param(param) {
}

#endif
