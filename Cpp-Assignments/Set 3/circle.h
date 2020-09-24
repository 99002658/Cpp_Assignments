#ifndef __CIRCLE_H
#define __CIRCLE_H

#include "shape.h"


class Circle : public IShape {
  double m_radius;

public:

  Circle(int r);
  double area();
  double circumference();
};

#endif
