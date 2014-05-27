#ifndef HOUSE_H
#define HOUSE_H

#include <vector>
#include "letterbox.h"
#include "building.h"

class House: public Building
{
    public:
        House();
        virtual ~House();
    protected:
        LetterBox* m_letterBox;
    private:
};

#endif // HOUSE_H
