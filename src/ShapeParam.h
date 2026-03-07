#ifndef _SHAPEPARAM_H
#define _SHAPEPARAM_H


#include <vector>
using namespace std;
#include "ShapeType.h"
#include "ShapeParamIndex.h"

template<class T>
class ShapeParam {
  private:
    vector<T> attribs;


  public:
    ShapeType type;

    inline T get(ShapeParamIndex ind) const;

    inline bool set(ShapeParamIndex ind, const T & val);

    inline bool validate() const;

};
template<class T>
inline T ShapeParam<T>::get(ShapeParamIndex ind) const {
<<<<<<< HEAD
<<<<<<< HEAD
    return attribs[ind];
=======
    if(ind<attribs.size()) return attribs[ind];
    return 0;
>>>>>>> 4f6dbd1a28bce0ee081e2ed242e58e521390b459
=======
    if(ind<attribs.size()) return attribs[ind];
    return 0;
>>>>>>> 4f6dbd1a28bce0ee081e2ed242e58e521390b459
}

template<class T>
inline bool ShapeParam<T>::set(ShapeParamIndex ind, const T & val) {
  if(ind>=attribs.size())attribs.resize(ind+1);
  attribs[ind]=val;
  return true;
}

template<class T>
inline bool ShapeParam<T>::validate() const {
  return true;
}

#endif
