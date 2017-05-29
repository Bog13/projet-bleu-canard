#include "typable.h"

Typable::Typable()
{
    m_type=0;
}

Typable::Typable(int id)
{
    m_type=id;
}

Typable::~Typable()
{
    //dtor
}
