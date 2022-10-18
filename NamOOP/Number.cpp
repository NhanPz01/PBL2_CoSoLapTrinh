#include "Number.h"
Number::Number(double t)
    :data(t)
{

}

Number::~Number()
{

}

Number::operator int()
{
    return int(this->data);
}
Number::operator double()
{
    return this->data;
}