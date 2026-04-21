#ifndef _PYRAMID_H
#define _PYRAMID_H

#include "Shape3D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

template <class T> class Pyramid : public Shape3D<T> {
public:
    inline ShapeResult<T> compute();
    inline string print();
    inline Pyramid(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Pyramid<T>::compute()
{
    T width = this->m_param.get_attrib(PARAM_WIDTH);
    T height = this->m_param.get_attrib(PARAM_HEIGHT);
    T depth = this->m_param.get_attrib(PARAM_DEPTH);

    double w = static_cast<double>(width);
    double h = static_cast<double>(height);
    double d = static_cast<double>(depth);

    double slantWidth = sqrt(h * h + (d * d) / 4.0);
    double slantDepth = sqrt(h * h + (w * w) / 4.0);

    double volume = (w * d * h) / 3.0;
    double surface = (w * d) + (w * slantWidth) + (d * slantDepth);

    ShapeResult<T> result;

    result.set_attrib(RESULT_VOLUME, static_cast<T>(volume));
    result.set_attrib(RESULT_SURFACE, static_cast<T>(surface));

    return result;
}

template <class T> inline string Pyramid<T>::print()
{
    T width = this->m_param.get_attrib(PARAM_WIDTH);
    T height = this->m_param.get_attrib(PARAM_HEIGHT);
    T depth = this->m_param.get_attrib(PARAM_DEPTH);

    ShapeResult<T> result = compute();

    ostringstream out;

    out << "=== SOLID: PYRAMID ===" << endl;
    out << "Width: " << width << endl;
    out << "Height: " << height << endl;
    out << "Depth: " << depth << endl;
    out << "Volume: " << result.get_attrib(RESULT_VOLUME) << endl;
    out << "Surface: " << result.get_attrib(RESULT_SURFACE) << endl;
    out << "=====================";

    return out.str();
}

template <class T>
inline Pyramid<T>::Pyramid(const ShapeParam<T>& param): Shape3D<T>(param)
{}

#endif
