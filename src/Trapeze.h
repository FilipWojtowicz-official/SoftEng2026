#ifndef _TRAPEZE_H
#define _TRAPEZE_H


#include "Shape2D.h"
#include "ShapeResultData.h"
#include <string>
using namespace std;
#include "ShapeParam.h"

template<class T>
class Trapeze : public Shape2D<T> {
  public:
    inline virtual ShapeResult<T> compute();

    inline string print();

    inline Trapeze(const ShapeParam<T> & param);

};
template<class T>
inline ShapeResult<T> Trapeze<T>::compute() {

    ShapeResult<T> result;

    T a = this->m_param.get_attrib(PARAM_WIDTH);
    T b = this->m_param.get_attrib(PARAM_DEPTH);
    T h = this->m_param.get_attrib(PARAM_HEIGHT);

    T area = (a + b) * h / 2;

    result.set_attrib(RESULT_AREA, area);

    return result;
}

template<class T>
inline string Trapeze<T>::print() {

    T a = this->m_param.get_attrib(PARAM_WIDTH);
    T b = this->m_param.get_attrib(PARAM_DEPTH);
    T h = this->m_param.get_attrib(PARAM_HEIGHT);

    return "Trapeze(width=" + to_string(a) + ", depth=" + to_string(b)
        + ", height=" + to_string(h) + ")";
}

template<class T>
inline Trapeze<T>::Trapeze(const ShapeParam<T> & param) : Shape2D<T>(param) {
}

#endif
