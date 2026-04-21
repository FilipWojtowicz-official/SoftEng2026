#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape2D.h"
#include "ShapeParam.h"
#include "ShapeResultData.h"

#include <sstream>
#include <string>

template <class T> class Circle : public Shape2D<T> {
public:
    inline ShapeResult<T> compute();
    inline std::string print();
    inline Circle(const ShapeParam<T>& param);
};

template <class T> inline ShapeResult<T> Circle<T>::compute()
{
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    const double PI = 3.14159265358979323846;

    // Obliczenia na typie double dla precyzji
    double area =
        PI * static_cast<double>(radius) * static_cast<double>(radius);
    double perimeter = 2.0 * PI * static_cast<double>(radius);

    // Pakowanie wynikow do obiektu ShapeResultData
    ShapeResult<T> result;
    result.set_attrib(RESULT_AREA, static_cast<T>(area));
    result.set_attrib(RESULT_PERIMETER, static_cast<T>(perimeter));

    return result;
}

template <class T> inline std::string Circle<T>::print()
{
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    ShapeResult<T> result = compute();

    // Uzycie ostringstream do zbudowania wieloliniowego tekstu
    std::ostringstream out;
    out << "=== FIGURA: KOLO ===" << std::endl;
    out << "Promien: " << radius << std::endl;
    out << "Pole powierzchni: " << result.get_attrib(RESULT_AREA) << std::endl;
    out << "Obwod: " << result.get_attrib(RESULT_PERIMETER) << std::endl;
    out << "====================";

    return out.str();
}

template <class T>
inline Circle<T>::Circle(const ShapeParam<T>& param): Shape2D<T>(param)
{}

#endif // CIRCLE_H_