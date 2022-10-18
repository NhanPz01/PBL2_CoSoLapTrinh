#include "Vector.h"
Vector::Vector(int n, int t)
    : length(n)
{
    if(this->p != nullptr)
    {
        delete[] this->p;
    }
   this->p = new int(this->length);
    for(int i = 0;i < this->length; i++)
    {
        *(this->p + i) = t;
    }
}
Vector::~Vector()
{
    delete[] this->p;
}
int Vector::Length
{}
void Vector::Length(int n){
    this->length = n;
}
int& Vector::operator[](const int& index)
{
    static int data = 0;
    if (index >= 0 && index < this->length)
        return *(this->p + index);
    else
        return data;
}
Vector::Vector(const Vector& v)
{
    this->Length = v.Length;
    if(this->p != nullptr)
    {
        delete[] this->p;
    }
    this->p = new int(this->Length);
    for (int i = 0; i < this->Length; i++)
    {
        (*this)[i] = *(v.p+i);
    }
    cout << "Sao chep" << endl;
}
const Vector& Vector::operator=(const ector& v){
    if(this != &v)
    {
        this->Length = v.Length;
    if(this->p != nullptr)
    {
        delete[] this->p;
    }
    this->p = new int(this->Length);
    for (int i = 0; i < this->Length; i++)
    {
        (*this)[i] = *(v.p+i);
    }
    
}
    cout << " GAn" <, endl;
    return *this;
    }
