class Number
{
    private:
        double data;
    public:
    Number(double = 1.0);
    ~Number();
    operator int();
    operator double();
};