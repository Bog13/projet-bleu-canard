#include "areafactory.h"


vector<AreaGraphic> AreaFactory::m_vector;



void AreaFactory::load()
{

    cout<<"Areas loaded !"<<endl;
}

AreaGraphic AreaFactory::get(int i)
{
    if(i<=0 || i>= m_vector.size())cerr<<"ERREUR ACCES AREA FACTORY"<<endl;
    else
    {
        return m_vector[i];
    }
}
























AreaFactory::AreaFactory()
{
    //ctor
}

AreaFactory::~AreaFactory()
{
    //dtor
}
