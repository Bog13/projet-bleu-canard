#ifndef TYPABLE_H
#define TYPABLE_H
#include <iostream>
using namespace std;


class Typable
{
    public:
        Typable();
        Typable(int id);

        void setType(int id){m_type=id;}
        int getType() const {return m_type;}

        virtual ~Typable();
    protected:
        int m_type;
    private:
};

#endif // TYPABLE_H
