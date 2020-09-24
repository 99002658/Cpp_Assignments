#include<string>
class Fraction {
    int m_numerator, m_denominator;

  public:
    Fraction();
    Fraction(int, int);
    Fraction(int);
    Fraction operator+(const Fraction &);
    Fraction operator-(const Fraction &);
    Fraction operator*();
    Fraction operator+(int);
    Fraction operator-(int);
    bool operator==(const Fraction &);
    bool operator<(const Fraction &);
    bool operator>(const Fraction &);
    void simplify();
    void isSimplest();
    void display();
};
