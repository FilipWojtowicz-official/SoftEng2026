#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape2D.h"
#include "ShapeResultData.h"
#include "ShapeParam.h"
#include "ShapeResultIndex.h"
#include <string>
#include <sstream>
#include <stdexcept>

template <class T> class Circle : public Shape2D<T> {
public:
    // Definicje metod wewn¹trz klasy
    ShapeResult<T> compute();
    std::string print();
    Circle(const ShapeParam<T>& param);
};

// Implementacja metody compute
template <class T> ShapeResult<T> Circle<T>::compute()
{
    // this->m_param pochodzi z klasy bazowej Shape2D
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    const double PI = 3.14159265358979323846;

    if (radius < static_cast<T>(0))
    {
        throw std::invalid_argument("Promien kola nie moze byc ujemny!");
    }

    double area =
        PI * static_cast<double>(radius) * static_cast<double>(radius);
    double perimeter = 2.0 * PI * static_cast<double>(radius);

    ShapeResult<T> result;
    result.set_attrib(RESULT_AREA, static_cast<T>(area));
    result.set_attrib(RESULT_PERIMETER, static_cast<T>(perimeter));

    return result;
}

// Implementacja metody print
template <class T> std::string Circle<T>::print()
{
    T radius = this->m_param.get_attrib(PARAM_RADIUS);
    // Tutaj byla literowka w typie danych - teraz jest ShapeResult
    ShapeResult<T> result = compute();

    std::ostringstream out;
    out << "=== FIGURA: KOLO ===" << std::endl;
    out << "Promien: " << radius << std::endl;
    out << "Pole powierzchni: " << result.get_attrib(RESULT_AREA) << std::endl;
    out << "Obwod: " << result.get_attrib(RESULT_PERIMETER) << std::endl;
    out << "====================";

    return out.str();
}

// Konstruktor
template <class T>
Circle<T>::Circle(const ShapeParam<T>& param): Shape2D<T>(param)
{
}

#endif