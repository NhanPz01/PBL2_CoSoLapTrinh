#include "Matrix.h"
Matrix::Matrix(int r, int c, int t)
    :row(r), col(c)
{ 
    this->p = new int*[this->row];
    for(int i =0; i < this->row; i++){
        *(this->p+i) = new int[this->col];
        for (int j = 0; j < this->col; j++){
            *(*(this -> p+i)+j) = t;
        }
    }

}

Matrix::~Matrix()
{
    for(int i =0; i < this->row; i++){
        delete[] *(this->p+i);
    }
    delete[] this->p;
}

int& Matrix::operator()(const int& r, const int& c)
{
    static int data = 0;
    if (r >= 0 && r < this->row && c >= 0 && c < this->col )
        return *(*(this->p + r)+c);
    else
        return data;
}