
class Currency {
    int m_rupees, m_paise;
  public:
    Currency();
    Currency(int, int);
    Currency(int);
    Currency operator+(const Currency &);
    Currency operator-(const Currency &);
    Currency operator+(int);
    Currency operator-(int);
    Currency operator++();
    Currency operator++(int);
    bool operator==(const Currency &);
    bool operator<(const Currency &);
    bool operator>(const Currency &);
    void display();
};
