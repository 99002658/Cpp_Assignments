class Box {
    int m_length;
    int m_height;
    int m_breadth;
  public:
    Box();
    Box(int, int, int);
    Box(int);
    Box(const Box &p);
    void length(int);
    void breadth(int);
    void height(int);
    void volume(int,int,int);
    void display();
};
