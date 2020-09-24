#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "polygon.h"

class Rectangle : public Polygon {
  int  m_length;
  int  m_breadth;

public:
  Rectangle(int l,int b);
  double area();
  double circumference();
};

#endif
