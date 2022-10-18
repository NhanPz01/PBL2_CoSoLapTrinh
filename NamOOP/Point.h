class Point
{
    // ten thuoc tinh
    public:
    int xVal;
    int yVal;
    // ham thanh vien
    public:
    void TT(int);
    void Show();
    Point();
    Point(int,int);
    Point(const Point&);
    ~Point();
    friend Point operator+(const Point&, const Point&);
};