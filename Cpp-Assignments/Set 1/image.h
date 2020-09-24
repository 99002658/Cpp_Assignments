#include<string>
class Image {
  int m_x, m_y, m_width, m_height;

public:
  Image();
  Image(int, int, int, int);
  Image(const Image &);
  void move(int , int , int);
  void scale(int, int);
  int resize(int, int);
  void display();
};
