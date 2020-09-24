using namespace std;
enum color_t {red, blue, green, yellow, black};
class Color {
    int m_r, m_g, m_b;
  public:
    Color();
    Color(int, int, int);
    Color(string);
    Color(color_t);
    void invert();
    void display();
};
