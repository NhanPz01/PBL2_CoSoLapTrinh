
class Matrix{
    private:
        int **p;
        int col, row;
    public:
        Matrix(int = 2, int = 3, int = 2);
        ~Matrix();
        int& operator()(const int&, const int&);
};